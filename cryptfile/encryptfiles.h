#ifndef BASICSTEPS_H
#define BASICSTEPS_H

#include <QObject>
#include <QStringList>
#include "workingwithfiles/datafromfile.h"
#include "workingwithfiles/datatofile.h"
#include "cryptography/passwordgeneration.h"
#include "cryptography/encryptwrapper.h"
#include "cryptography/decryptwrapper.h"
#include "workingwithfiles/checksum.h"
#include "workingwithfiles/settingsmanager.h"
#include <QDebug>

class EncryptFiles : public QObject
{
struct Current {
	int iteratorId;
	int Checksum;
	QString fileName;
	QString path;
	QString pass;
};

	Q_OBJECT
public:
	explicit EncryptFiles(SettingsManager *s, QObject *parent = 0);
	~EncryptFiles();

signals:
	void getMessage(QString mgs);
	
public slots:
	void pathLists(QStringList);

private:
	AbstrReadDataFromFile *fromFile;
	AbstrSaveDataToFile *toFile;

	SettingsManager *settings;

	QStringList fileNameList;

	void openFile(QString fileName);
	void saveFile(QString fileName, QByteArray data);

	void initConnects();
	void initObjects();

	void pwdFile(QByteArray data, QString fName, int fChecksum);
	void currentFileParam(QByteArray data, QString fName);

	QString openPwdFile(QString fileName, int checksum);
	void savePwdFile();
	void saveEncryptedFile(QByteArray data);

	//crc
	Checksum *crcData;

	//cryptography
	PasswordGeneration *pwdGen;
	EncryptWrapper *enData;

	void encryptData(QByteArray data);

	Current currentFile;

	void workWithNextFile();

	void saveFiles(QByteArray data);

	QString getFilePath();
	QString checkSymLink(QString filePath);

private slots:
	void encryptedData(QByteArray data);
	void error(QString msg);
	void checksumResult(int crc, QByteArray data);

};

#endif // BASICSTEPS_H
