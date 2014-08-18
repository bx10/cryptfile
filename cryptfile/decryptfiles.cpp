#include "decryptfiles.h"

DecryptFiles::DecryptFiles(SettingsManager *s, QObject *parent) :
	QObject(parent)
{
	initObjects();
	initConnects();
	settings = s->instance();
}

void DecryptFiles::initObjects(){
	deData = new DecryptWrapper();
	fromFile = new DataFromFile();
	toFile = new DataToFile();
	crcData = new Checksum();
}

void DecryptFiles::initConnects(){
	connect(deData, SIGNAL(getData(QByteArray)),this,SLOT(decryptedData(QByteArray)));
	connect(deData,SIGNAL(errors(QString)),this,SLOT(error(QString)));
	connect(crcData,SIGNAL(getChecksum(int, QByteArray)),this,SLOT(checksumResult(int, QByteArray)));
}

void DecryptFiles::pathLists(QStringList list){
	fileNameList = list;
	currentFile.iteratorId = 0;
	workWithNextFileName();
}

void DecryptFiles::workWithNextFileName(){
	if (currentFile.iteratorId < fileNameList.size()){
		openFile(fileNameList.at(currentFile.iteratorId));
		++currentFile.iteratorId;
	}
}

void DecryptFiles::openFile(QString fileName){
	QByteArray buf;
	QString file = checkSymLink(fileName);
	if (fromFile->setFileName(file)){
		getMessage("Opening "+file);
		buf=fromFile->readDataFromFile();
		if(file.split(".").back().toInt()>0){
			currentFileParam(buf,file);
		}else{
			if (file.split(".").back().toStdString() == "pwd")
				currentFilePwd(buf);
		}
	}
}

void DecryptFiles::currentFileParam(QByteArray data, QString fName){
	QFileInfo file(fName);
	currentFile.Checksum = fName.split(".").back().toInt();
	currentFile.path = file.absoluteFilePath();
	currentFile.fileName = file.completeBaseName();
	currentFile.fileNameWithCRC = file.fileName();
	openFile(currentFile.path + ".pwd");
	crcData ->setData(data);

}

void DecryptFiles::currentFilePwd(QByteArray data){
	QString pwd(data);
	currentFile.pass = data;
}

void DecryptFiles::error(QString msg){
	getMessage(msg+" "+currentFile.fileNameWithCRC);
}

void DecryptFiles::decryptData(QByteArray data){
	deData->setData(data,currentFile.pass);
}

void DecryptFiles::decryptedData(QByteArray data){
	getMessage("Decrypt data from "+currentFile.fileNameWithCRC+" done, trying to save.");
	saveUncryptedFile(data);
}

void DecryptFiles::checksumResult(int crc,QByteArray data){
	if (currentFile.Checksum == crc) {
		getMessage("Checksum of "+currentFile.fileNameWithCRC+" matches, trying to decrypt.");
		decryptData(data);
	}else{
		getMessage("Checksum of "+currentFile.fileNameWithCRC+" doesn't match.");
	}
}

DecryptFiles::~DecryptFiles(){
	settings->drop();
}

void DecryptFiles::saveUncryptedFile(QByteArray data){
	QString fileNameWithPath;
	fileNameWithPath = getFilePath()+"/"+currentFile.fileName;
	saveFile(fileNameWithPath,data);
	workWithNextFileName();
}

void DecryptFiles::saveFile(QString fileName, QByteArray data){
	if (toFile->setFileName(fileName)){
		toFile->writeDataToFile(data);
		getMessage("File "+currentFile.fileName+" encrypted and save.");
	}else{
		getMessage("Can't create "+fileName);
	}
}

QString DecryptFiles::checkSymLink(QString filePath){
	QFileInfo file(filePath);
	if (!file.isSymLink()) {
		return filePath;
		}else{
		return file.symLinkTarget();
		}
}

QString DecryptFiles::getFilePath(){
	QString filePath = QDir::homePath()+"/cryptfile";
	QDir dir = filePath;
	if (!dir.exists())
		if (!dir.mkpath(filePath)){
			return "";
			getMessage("Can't create "+filePath);
		}
	return filePath;
}
