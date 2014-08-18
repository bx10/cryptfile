#include "checksum.h"

Checksum::Checksum(QObject *parent) :
	QThread(parent)
{
}

void Checksum::run(){
	emit getChecksum(calcChecksum(),buf);
}

void Checksum::setData(const QByteArray &data){
	buf = data;
	start();
}

int Checksum::calcChecksum(){
	return qChecksum(buf,buf.length());
}
