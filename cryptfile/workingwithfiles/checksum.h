#ifndef CHECKSUM_H
#define CHECKSUM_H

#include <QThread>

class Checksum : public QThread
{
	Q_OBJECT
public:
	explicit Checksum(QObject *parent = 0);
	void setData(const QByteArray &data);
	
signals:
	void getChecksum(int checksum, QByteArray data);
	
private:
	int calcChecksum();
	QByteArray buf;

protected:
	void run();
	
};

#endif // CHECKSUM_H
