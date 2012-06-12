//#include <QObject>
#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QTest>
#include <QtCore>
#include <QtGui/QApplication>
#include <QDialog>
#include <QtGui>
#include <QtSql>
#include <QtNetwork>
#include "fmail.h"

class TestTest : public QObject
{
    Q_OBJECT
    
public:
    TestTest();
    
private Q_SLOTS:
 void testCase1();
 void testCase2();
 void testCase3();
 void testCase4();
 void testCase5();
 void testCase6();
 void testCase7();
 void testCase8();
};

TestTest::TestTest()
{
}

void TestTest::testCase1()
{
    fmail fm;
    bool state = fm.connectToHost("pop.yandex.ru", 110);
    QVERIFY2(state, "Test1 Failure!");
}

void TestTest::testCase2()
{
    fmail fm;
    bool flag = fm.login("test.pop.110@yandex.ru", "Asdfgh");
    QCOMPARE(true, flag);
}


void TestTest::testCase3()
{
    fmail fm;
    bool flag;
    if (fm.connectToHost("pop.yandex.ru")) {
        flag = fm.login("test.pop.110@yandex.ru", "Asdfgh");
    }
    QCOMPARE(true, flag);
}
void TestTest::testCase4()
{
    fmail fm;
    QString str = fm.mails();
    QCOMPARE(str, QString("bad"));
}
void TestTest::testCase5()
{
    fmail fm;
    bool flag = fm.close();
    QCOMPARE(true, flag);
}
void TestTest::testCase6()
{
    fmail fm;
    int flag = fm.list();
    QCOMPARE(flag, -1);
}
void TestTest::testCase7()
{
    fmail fm;
    QByteArray empty;
    QByteArray arr = fm.retr(1);
    QCOMPARE(arr, empty);
}
void TestTest::testCase8()
{
    fmail fm;
    QByteArray empty;
    QByteArray arr = fm.top(0, 10);
    QCOMPARE(arr, empty);
}

QTEST_MAIN(TestTest)

#include "tst_testtest.moc"
