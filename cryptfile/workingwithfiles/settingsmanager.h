#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include <QSettings>
#include <QMutex>

class SettingsManager : public QObject
{
	Q_OBJECT
public:
	static SettingsManager* instance(){
		static QMutex mutex;
		if (!singleInstance){
			mutex.lock();
			if(!singleInstance)
			singleInstance = new SettingsManager;
			mutex.unlock();
		}


		return singleInstance;
	}

	static void drop(){
		static QMutex mutex;
		mutex.lock();
		delete singleInstance;
		singleInstance = 0;
		mutex.unlock();
	}



	void setAppSettings(const QString &key, const QVariant &value);
	void getAppSettings(const QString &key, QVariant value);

private:
	SettingsManager(){
		settings = new QSettings(QSettings::IniFormat,QSettings::UserScope,"cryptfile","config");
	}

	SettingsManager(const SettingsManager &);
	SettingsManager& operator = (const SettingsManager &);
	QSettings *settings;
	static SettingsManager *singleInstance;
};

#endif // SETTINGSMANAGER_H
