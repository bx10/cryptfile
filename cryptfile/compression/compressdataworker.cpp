#include "compressdataworker.h"
#include <QDebug>

CompressDataWorker::CompressDataWorker(QObject *parent) :
	QThread(parent)
{

}

void CompressDataWorker::doWork(){
	QByteArray compressData;
	compressData = qCompress(buf);
	emit getData(compressData);
}

void CompressDataWorker::setData(const QByteArray &data){
	buf = data;
	start();
}

void CompressDataWorker::run(){
	doWork();
}
