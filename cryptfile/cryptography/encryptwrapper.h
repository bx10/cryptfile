#ifndef ENCRYPTWRAPPER_H
#define ENCRYPTWRAPPER_H

#include <QThread>
#include <openssl/evp.h>

class EncryptWrapper : public QThread
{
	Q_OBJECT
public:
	explicit EncryptWrapper(QObject *parent = 0);
	void setData(const QByteArray &data, QString pwd);
signals:
	void errors(QString msg);
	void getData(QByteArray data);

protected:
	void run();

private:
	EVP_CIPHER_CTX encrypt;
	void cryptInit(QString pwd);
	QByteArray encryptData();
	QByteArray enData;
	QString passwordBuf;

};

#endif // ENCRYPTWRAPPER_H
