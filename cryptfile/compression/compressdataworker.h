#ifndef COMPRESSDATAWORKER_H
#define COMPRESSDATAWORKER_H

#include <QThread>
#include <QMutex>
#include <QByteArray>

class CompressDataWorker : public QThread
{
	Q_OBJECT
public:
	explicit CompressDataWorker(QObject *parent = 0);
	void setData(const QByteArray &data);

signals:
	void getData(const QByteArray &data);

private:
	QByteArray buf;
	void doWork();

protected:
	void run();
};

#endif // COMPRESSDATAWORKER_H
