#include "uncompressdataworker.h"

UncompressDataWorker::UncompressDataWorker(QObject *parent) :
	QThread(parent)
{
}

void UncompressDataWorker::doWork(){
	QByteArray uncompressData;
	uncompressData = qUncompress(buf);
	emit getData(uncompressData);
}

void UncompressDataWorker::setData(const QByteArray &data){
	buf = data;
	start();
}

void UncompressDataWorker::run(){
	doWork();
}
