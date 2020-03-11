#include <QtTest>

// add necessary includes here

class MyStringTest : public QObject
{
    Q_OBJECT

public:
    MyStringTest();
    ~MyStringTest();

private slots:
    void test_case1();

};

MyStringTest::MyStringTest()
{

}

MyStringTest::~MyStringTest()
{

}

void MyStringTest::test_case1()
{

}

QTEST_APPLESS_MAIN(MyStringTest)

#include "tst_mystringtest.moc"
