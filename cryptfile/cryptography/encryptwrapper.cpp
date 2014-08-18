#include "encryptwrapper.h"

EncryptWrapper::EncryptWrapper(QObject *parent) :
	QThread(parent)
{
}

void EncryptWrapper::run(){
	emit getData(encryptData());
}

void EncryptWrapper::setData(const QByteArray &data, QString pwd){
	enData = data;
	passwordBuf = pwd;
	cryptInit(pwd);
	start();
}

void EncryptWrapper::cryptInit(QString pwd){
	QByteArray key(EVP_MAX_KEY_LENGTH,0);
	QByteArray iv(EVP_MAX_IV_LENGTH,0);

//	convert QString to unsigned char
	unsigned char *password = (unsigned char *)malloc(sizeof(unsigned char));
	memcpy(password, pwd.toStdString().c_str(),pwd.size());

	if(!EVP_BytesToKey(EVP_aes_256_cbc(),EVP_sha1(), NULL,
					   (unsigned char *) password,
					   strlen((const char *)password), 1, (unsigned char *)key.data(), (unsigned char *)iv.data())){
		emit errors("EVP_BytesToKey failed: Password "+pwd+" doesn't create.");
		return;
	}
	EVP_CIPHER_CTX_init(&encrypt);
	EVP_EncryptInit(&encrypt, EVP_aes_256_cbc(), (const unsigned char*)key.constData(), (const unsigned char*)iv.constData());
}

QByteArray EncryptWrapper::encryptData(){
	int outLen, inLen, finalLen;
	inLen = enData.count();
	QByteArray outBuf(inLen+EVP_MAX_BLOCK_LENGTH,0);

	if(!EVP_EncryptUpdate(&encrypt, (unsigned char *)outBuf.data(), &outLen, (unsigned char *)enData.constData(), inLen)){
		emit errors("EVP_EncryptUpdate failed");
		return QByteArray();
	}

	if(!EVP_EncryptFinal(&encrypt, ((unsigned char*)outBuf.data())+outLen,&finalLen)){
		emit errors("EVP_EncryptFinal failed");
		return QByteArray();
	}

	outLen +=finalLen;
	EVP_CIPHER_CTX_cleanup(&encrypt);
	EVP_cleanup();
	outBuf.resize(outLen);
	return outBuf;
}
