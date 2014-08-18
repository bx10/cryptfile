#ifndef DATAFROMFILE_H
#define DATAFROMFILE_H

#include "abstrreaddatafromfile.h"
#include <QFile>

class DataFromFile : public AbstrReadDataFromFile
{
public:
	DataFromFile();

	bool setFileName(QString FileName);

	void closeFile();

	QByteArray readDataFromFile();

private:
	QFile file;

};

#endif // DATAFROMFILE_H
