#include "uncompressdata.h"

UncompressData::UncompressData() : AbstrClassWorkWithData()
{
}

void UncompressData::setData(const QByteArray &data){
	QByteArray buf;
	buf = data;
	UncompressDataWorker *worker = new UncompressDataWorker();
	connect(worker,SIGNAL(getData(QByteArray)),this,SLOT(getDataFromThread(QByteArray)));
	worker->setData(buf);
}

void UncompressData::getDataFromThread(const QByteArray &data){
	QByteArray buf = data;
	if (buf.isEmpty()) {
		emit error("Can't uncompress");
	}else{
	emit getData(buf);
	}
}

void UncompressData::stop(){

}
