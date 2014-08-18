#ifndef PASSWORDGENERATION_H
#define PASSWORDGENERATION_H

#include <QObject>
#include <QString>
#include <qglobal.h>
#include <QTime>

class PasswordGeneration : public QObject
{
	Q_OBJECT
public:
	explicit PasswordGeneration(QObject *parent = 0);
	QString generateNumbers(int size);
	QString generateSmallLetters(int size);
	QString generateLargeLetters(int size);
	QString generateAllCharacterSet(int size);
	
signals:
	
public slots:
	
};

#endif // PASSWORDGENERATION_H
