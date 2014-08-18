#ifndef UNCOMPRESSDATA_H
#define UNCOMPRESSDATA_H
#include "compression/uncompressdataworker.h"
#include "abstrclassworkwithdata.h"
#include <QThread>
#include <QObject>

class UncompressData : public AbstrClassWorkWithData
{
	Q_OBJECT
public:
	UncompressData();
	void setData(const QByteArray &data);

signals:
	void getData(const QByteArray &data);
	void error(QString msg);

public slots:
	void stop();

private slots:
	void getDataFromThread(const QByteArray &data);

};

#endif // UNCOMPRESSDATA_H
