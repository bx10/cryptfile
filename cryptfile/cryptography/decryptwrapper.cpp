#include "decryptwrapper.h"
#include <QDebug>

DecryptWrapper::DecryptWrapper(QObject *parent) :
	QThread(parent)
{
}

void DecryptWrapper::run(){
	QByteArray buf;
	buf = decryptData();
	emit getData(buf);
}

void DecryptWrapper::setData(const QByteArray &data, QString pwd){
	deData = data;
	passwordBuf = pwd;
	cryptInit(pwd);
	start();
}

void DecryptWrapper::cryptInit(QString pwd){
	QByteArray key(EVP_MAX_KEY_LENGTH,0);
	QByteArray iv(EVP_MAX_IV_LENGTH,0);

	//	convert QString to unsigned char
	unsigned char *password = (unsigned char *)malloc(sizeof(unsigned char));
	memcpy(password, pwd.toStdString().c_str(),pwd.size());

	if(!EVP_BytesToKey(EVP_aes_256_cbc(),EVP_sha1(), NULL,
					   (unsigned char *) password,
					   strlen((const char *)password), 1,
					   (unsigned char *)key.data(), (unsigned char *)iv.data())){
			emit errors("EVP_BytesToKey failed: Password "+pwd+" doesn't create.");
			return;
		}
	EVP_CIPHER_CTX_init(&decrypt);
	EVP_DecryptInit(&decrypt, EVP_aes_256_cbc(), (const unsigned char*)key.constData(), (const unsigned char*)iv.constData());
	EVP_CIPHER_CTX_set_padding(&decrypt, 0);
}

QByteArray DecryptWrapper::decryptData(){
	int outLen, inLen, finalLen;
	inLen = deData.count();
	QByteArray outBuf(inLen+EVP_MAX_BLOCK_LENGTH,0);

	if(!EVP_EncryptUpdate(&decrypt, (unsigned char *)outBuf.data(), &outLen, (unsigned char *)deData.constData(), inLen)){
		emit errors("EVP_EncryptUpdate failed");
		return QByteArray();
	}

	if(!EVP_EncryptFinal(&decrypt, ((unsigned char*)outBuf.data())+outLen,&finalLen)){
		emit errors("EVP_EncryptFinal failed");
		return QByteArray();
	}

	outLen +=finalLen;
	EVP_CIPHER_CTX_cleanup(&decrypt);
	EVP_cleanup();
	outBuf.resize(outLen);
	return outBuf;
}
