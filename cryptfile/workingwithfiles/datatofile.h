#ifndef DATATOFILE_H
#define DATATOFILE_H

#include "abstrsavedatatofile.h"
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>
#include <QDir>

class DataToFile : public AbstrSaveDataToFile
{
public:
	DataToFile();

	bool setFileName(QString FileName);

	void closeFile();

	void writeDataToFile(QByteArray data);


private:
	QFile file;

};

#endif // DATATOFILE_H
