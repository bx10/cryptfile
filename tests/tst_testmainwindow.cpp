#include <QString>
#include <QtTest>
#include <QByteArray>
#include "cryptography/passwordgeneration.h"
#include "workingwithfiles/datatofile.h"

class TestMainWindow : public QObject
{
	Q_OBJECT
	
public:
	TestMainWindow();
	
private Q_SLOTS:
	void initTestCase();
	void cleanupTestCase();
	void testCase1();
	void testCase1_data();
	void testQString();
	void testCompressData();
	void testPasswordGeneration();
	void testSaveFile();
};

TestMainWindow::TestMainWindow()
{



}

void TestMainWindow::testSaveFile(){
	DataToFile b;
	QCOMPARE(b.setFileName("example.txt"),true);
}

void TestMainWindow::testPasswordGeneration(){
	PasswordGeneration b;
	//QCOMPARE(b.generateAllCharacterSet(8),b.generateAllCharacterSet(8));
}

void TestMainWindow::testCompressData(){

}


void TestMainWindow::initTestCase()
{

}

void TestMainWindow::cleanupTestCase()
{
}

void TestMainWindow::testCase1()
{
	QFETCH(QString, data);
	QVERIFY2(true, "Failure");
}

void TestMainWindow::testCase1_data()
{
	QTest::addColumn<QString>("data");
	QTest::newRow("0") << QString();
}

void TestMainWindow::testQString()
{
	QString str = "Hello";
	QVERIFY(str.toUpper() == "HELLO");
}

QTEST_APPLESS_MAIN(TestMainWindow)

#include "tst_testmainwindow.moc"
