#ifndef ABSTRSAVEDATATOFILE_H
#define ABSTRSAVEDATATOFILE_H

#include <QByteArray>
#include <QString>

class AbstrSaveDataToFile {

public:
	virtual bool setFileName(QString fileName) = 0;

	virtual void closeFile() = 0;

	virtual void writeDataToFile(QByteArray data) = 0;
};

#endif // ABSTRSAVEDATATOFILE_H
