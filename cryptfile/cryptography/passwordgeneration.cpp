#include "passwordgeneration.h"

PasswordGeneration::PasswordGeneration(QObject *parent) :
	QObject(parent)
{
	QTime now = QTime::currentTime();
	qsrand(now.msec());
}

QString PasswordGeneration::generateNumbers(int size){
	QString result = "";

	static const char characterSet[] = "1234567890";

	for(int i=0; i < size; ++i){
		result.append(characterSet[qrand() % (sizeof(characterSet)-1)]);
	}
	return result;
}

QString PasswordGeneration::generateSmallLetters(int size){
	QString result = "";
	static const char characterSet[] = "abcdefghijklmnopqrstuvwxyz";

	for(int i=0; i < size; ++i){
		result.append(characterSet[qrand() % (sizeof(characterSet)-1)]);
	}
	return result;
}

QString PasswordGeneration::generateLargeLetters(int size){
	QString result = "";
	static const char characterSet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for(int i=0; i < size; ++i){
		result.append(characterSet[qrand() % (sizeof(characterSet)-1)]);
	}
	return result;
}

QString PasswordGeneration::generateAllCharacterSet(int size){
	QString result = "";
	static const char characterSet[] =
			"1234567890"
			"abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"~!@#$%^&*()_+=-?";

	for(int i=0; i < size; ++i){
		result.append(characterSet[qrand() % (sizeof(characterSet)-1)]);
	}
	return result;
}
