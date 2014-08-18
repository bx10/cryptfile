#include "compressdata.h"

CompressData::CompressData() : AbstrClassWorkWithData()
{

}

void CompressData::setData(const QByteArray &data){
	QByteArray buf;
	buf = data;
	CompressDataWorker *worker = new CompressDataWorker();
	connect(worker,SIGNAL(getData(QByteArray)),this,SLOT(getDataFromThread(QByteArray)));
	worker->setData(buf);
}

void CompressData::getDataFromThread(const QByteArray &data){
	QByteArray buf = data;
	if (buf.isEmpty()) {
		emit error("Can't compress");
	}else{
		emit getData(buf);
	}
}

void CompressData::stop(){

}
