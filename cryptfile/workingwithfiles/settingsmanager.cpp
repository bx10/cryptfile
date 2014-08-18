#include "settingsmanager.h"

SettingsManager* SettingsManager::singleInstance = 0;

void SettingsManager::getAppSettings(const QString &key, QVariant value){
	QMutex mutex;
	mutex.lock();
	QVariant buf = settings->value(key,"0");
	value = buf;
	mutex.unlock();

}


void SettingsManager::setAppSettings(const QString &key, const QVariant &value){
	QMutex mutex;
	mutex.lock();
	settings->setValue(key,value);
	mutex.unlock();
}
