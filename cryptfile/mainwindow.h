#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "draganddropwidget.h"
#include "encryptfiles.h"
#include "decryptfiles.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
private:
	Ui::MainWindow *ui;
	DragAndDropWidget *DADWidgetDecrypt;
	DragAndDropWidget *DADWidgetEncrypt;
	EncryptFiles *enCr;
	DecryptFiles *deCr;
	SettingsManager *settings;
	void initWidgets();
	void initConnects();

private slots:
	void setMessageStatusBar(QString msg);

};

#endif // MAINWINDOW_H
