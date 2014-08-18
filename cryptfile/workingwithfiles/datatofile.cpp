#include "datatofile.h"
#include <QDebug>

DataToFile::DataToFile()
{
}

bool DataToFile::setFileName(QString fileName){
	if (fileName == "" || fileName == NULL)
		return false;
	else{
			file.setFileName(fileName);
	}
	if(file.open(QIODevice::WriteOnly)){
	return true;
	}else{
	return false;
	};
}

void DataToFile::writeDataToFile(QByteArray data){
	file.write(data);
	closeFile();
}

void DataToFile::closeFile(){
	file.close();
}
