#include "encryptfiles.h"

EncryptFiles::EncryptFiles(SettingsManager *s, QObject *parent) :
	QObject(parent)
{
	initObjects();
	initConnects();
	settings = s->instance();
}

void EncryptFiles::initObjects(){
	pwdGen = new PasswordGeneration();
	enData = new EncryptWrapper();
	fromFile = new DataFromFile();
	toFile = new DataToFile();
	crcData = new Checksum();
}

void EncryptFiles::initConnects(){
	connect(enData,SIGNAL(getData(QByteArray)),this,SLOT(encryptedData(QByteArray)));
	connect(crcData,SIGNAL(getChecksum(int,QByteArray)),this,SLOT(checksumResult(int,QByteArray)));
	connect(enData,SIGNAL(errors(QString)),this,SLOT(error(QString)));
}

void EncryptFiles::pathLists(QStringList list){
	fileNameList = list;
	currentFile.iteratorId = 0;
	workWithNextFile();
}

void EncryptFiles::workWithNextFile(){
	if (currentFile.iteratorId < fileNameList.size()){
		openFile(fileNameList.at(currentFile.iteratorId));
		++currentFile.iteratorId;
	}
}

void EncryptFiles::openFile(QString fileName){
	QString file = checkSymLink(fileName);
	QByteArray buf;
	if (fromFile->setFileName(file)){
		getMessage("Opening "+file);
		buf=fromFile->readDataFromFile();
		currentFileParam(buf,file);
	}
}

void EncryptFiles::currentFileParam(QByteArray data, QString fName){
	QFileInfo file(fName);
	encryptData(data);
	currentFile.fileName = file.fileName();
	currentFile.path = file.path();
	getMessage("Trying to encrypt "+currentFile.fileName);
}

void EncryptFiles::encryptData(QByteArray data){
	QString pwd;
	pwd = pwdGen->generateAllCharacterSet(8);
	currentFile.pass = pwd;
	enData->setData(data, pwd);
}

void EncryptFiles::encryptedData(QByteArray data){
	crcData->setData(data);
	getMessage("Encrypt "+currentFile.fileName+" is done. Calc checksum.");
}

void EncryptFiles::error(QString msg){
	getMessage(msg+" "+currentFile.fileName);
}

void EncryptFiles::checksumResult(int crc,QByteArray data){
	currentFile.Checksum = crc;
	getMessage("Trying save "+currentFile.fileName);
	saveFiles(data);
}

void EncryptFiles::saveFiles(QByteArray data){
	savePwdFile();
	saveEncryptedFile(data);
	getMessage("File "+currentFile.fileName+" encrypted and save.");
	workWithNextFile();
}

void EncryptFiles::savePwdFile(){
	QByteArray pass;
	pass.append(currentFile.pass);
	QString fileNameWithPath;
	fileNameWithPath = getFilePath()+"/"+currentFile.fileName+"."+QString::number(currentFile.Checksum)+".pwd";
	saveFile(fileNameWithPath,pass);
}

void EncryptFiles::saveEncryptedFile(QByteArray data){
	QString fileNameWithPath;
	fileNameWithPath = getFilePath()+"/"+currentFile.fileName+"."+QString::number(currentFile.Checksum);
	saveFile(fileNameWithPath,data);
}

void EncryptFiles::saveFile(QString fileName, QByteArray data){
	if (toFile->setFileName(fileName)){
		toFile->writeDataToFile(data);
	}else{
		getMessage("Can't create "+fileName);
	}
}

EncryptFiles::~EncryptFiles(){
	settings->drop();
}

QString EncryptFiles::checkSymLink(QString filePath){
	QFileInfo file(filePath);
	if (!file.isSymLink()) {
		return filePath;
		}else{
		return file.symLinkTarget();
		}
}

QString EncryptFiles::getFilePath(){
	QString filePath = QDir::homePath()+"/cryptfile";
	QDir dir = filePath;
	if (!dir.exists())
		if (!dir.mkpath(filePath)){
			return "";
			getMessage("Can't create "+filePath);
		}
	return filePath;
}
