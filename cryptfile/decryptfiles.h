#ifndef DECRYPTFILES_H
#define DECRYPTFILES_H

#include <QDebug>
#include <QObject>
#include <QStringList>
#include "workingwithfiles/datafromfile.h"
#include "workingwithfiles/datatofile.h"
#include "cryptography/decryptwrapper.h"
#include "workingwithfiles/checksum.h"
#include "workingwithfiles/settingsmanager.h"

class DecryptFiles : public QObject
{

struct Current {
	int iteratorId;
	int Checksum;
	QString fileNameWithCRC;
	QString fileName;
	QString path;
	QString pass;
};

	Q_OBJECT
public:
	explicit DecryptFiles(SettingsManager *s, QObject *parent = 0);
	~DecryptFiles();

signals:
	void getMessage(QString mgs);

public slots:
	void pathLists(QStringList);

private slots:
	void decryptedData(QByteArray data);
	void checksumResult(int crc,QByteArray data);
	void error(QString msg);

private:
	AbstrReadDataFromFile *fromFile;
	AbstrSaveDataToFile *toFile;

	void openFile(QString fileName);
	void saveFile(QString fileName, QByteArray data);

	void initConnects();
	void initObjects();

	QStringList fileNameList;

	SettingsManager *settings;

//	crc
	Checksum *crcData;

//	cryptography
	DecryptWrapper *deData;
	void decryptData(QByteArray data);

	Current currentFile;

	void pwdFile(QByteArray data, QString fName, int fChecksum);

	QString openPwdFile(QString fileName,int checksum);

	void currentFilePwd(QByteArray data);
	void currentFileParam(QByteArray data, QString fName);

	void workWithNextFileName();

	QString getFilePath();
	QString checkSymLink(QString filePath);

	void saveUncryptedFile(QByteArray data);

};

#endif // DECRYPTFILES_H
