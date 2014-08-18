#ifndef ABSTRREADDATAFROMFILE_H
#define ABSTRREADDATAFROMFILE_H

#include <QByteArray>
#include <QString>

class AbstrReadDataFromFile{

public:
	virtual bool setFileName(QString FileName) = 0;

	virtual void closeFile() = 0;

	virtual QByteArray readDataFromFile() = 0;
};

#endif // ABSTRREADDATAFROMFILE_H
