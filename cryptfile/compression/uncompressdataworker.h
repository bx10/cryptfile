#ifndef UNCOMPRESSDATAWORKER_H
#define UNCOMPRESSDATAWORKER_H

#include <QThread>

class UncompressDataWorker : public QThread
{
	Q_OBJECT
public:
	explicit UncompressDataWorker(QObject *parent = 0);
	void setData(const QByteArray &data);

signals:
	void getData(const QByteArray &data);

private:
	QByteArray buf;
	void doWork();

protected:
	void run();
};

#endif // UNCOMPRESSDATAWORKER_H
