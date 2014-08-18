#ifndef COMPRESSDATA_H
#define COMPRESSDATA_H
#include "compression/compressdataworker.h"
#include "abstrclassworkwithdata.h"
#include <QThread>
#include <QObject>
#include <QDebug>

class CompressData : public AbstrClassWorkWithData
{
	Q_OBJECT
public:
	explicit CompressData();
	void setData(const QByteArray &data);
	
signals:
	void getData(const QByteArray &data);
	void error(QString msg);

public slots:
	void stop();

private slots:
	void getDataFromThread(const QByteArray &data);

};

#endif // COMPRESSDATA_H
