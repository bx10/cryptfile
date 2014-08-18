#ifndef DECRYPTWRAPPER_H
#define DECRYPTWRAPPER_H

#include <QThread>
#include <openssl/evp.h>

class DecryptWrapper : public QThread
{
	Q_OBJECT
public:
	explicit DecryptWrapper(QObject *parent = 0);
	void setData(const QByteArray &data, QString pwd);
	
signals:
	void errors(QString msg);
	void getData(QByteArray data);

protected:
	void run();

private:
	EVP_CIPHER_CTX decrypt;
	void cryptInit(QString pwd);
	QByteArray decryptData();
	QByteArray deData;
	QString passwordBuf;
	
};

#endif // DECRYPTWRAPPER_H
