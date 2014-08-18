#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QCoreApplication::setOrganizationName("Roga & Kopita");
	QCoreApplication::setApplicationName("CryptFile");
	MainWindow w;
	w.show();
	
	return a.exec();
}
