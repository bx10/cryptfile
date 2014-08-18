#include "datafromfile.h"

DataFromFile::DataFromFile()
{
}

bool DataFromFile::setFileName(QString FileName){
	if (FileName == "" || FileName == NULL)
		return false;
	else
		file.setFileName(FileName);
	if(file.open(QIODevice::ReadOnly)){
	return true;
	}else{
	return false;
	};
}

void DataFromFile::closeFile(){
	file.close();
}

QByteArray DataFromFile::readDataFromFile(){
	QByteArray infile;
	while ( !file.atEnd() )
	{
	infile += file.readLine();
	}
	closeFile();
	return infile;
}
