#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	//window stay always on top
	this->setWindowFlags(Qt::WindowStaysOnTopHint);

	this->setWindowTitle("CryptFile");
	initWidgets();
	initConnects();
	settings = settings->instance();
}

void MainWindow::initWidgets()
{
	DADWidgetEncrypt = new DragAndDropWidget();
	ui->mainGridLayout->addWidget(DADWidgetEncrypt);
	DADWidgetEncrypt->setHintText("Encrypt");

	DADWidgetDecrypt = new DragAndDropWidget();
	ui->mainGridLayout->addWidget(DADWidgetDecrypt);
	DADWidgetDecrypt->setHintText("Decrypt");

	enCr = new EncryptFiles(settings);
	deCr = new DecryptFiles(settings);

}

void MainWindow::initConnects()
{
	connect(DADWidgetDecrypt,SIGNAL(returnPathList(QStringList)),deCr,SLOT(pathLists(QStringList)));
	connect(DADWidgetEncrypt,SIGNAL(returnPathList(QStringList)),enCr,SLOT(pathLists(QStringList)));
	connect(deCr,SIGNAL(getMessage(QString)),this,SLOT(setMessageStatusBar(QString)));
	connect(enCr,SIGNAL(getMessage(QString)),this,SLOT(setMessageStatusBar(QString)));
}

void MainWindow::setMessageStatusBar(QString msg){
	ui->statusBar->showMessage(msg,5000);
}

MainWindow::~MainWindow()
{
	delete ui;
	delete DADWidgetDecrypt;
	delete DADWidgetEncrypt;
	delete enCr;
	delete deCr;
}
