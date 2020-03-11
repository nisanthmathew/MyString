#include <QtTest>

// add necessary includes here
#include <iostream>
#include <sstream>
#include "mystring.h"

class MyStringTest : public QObject
{
    Q_OBJECT

public:
    MyStringTest();
    ~MyStringTest();

private slots:
    void test_case_operatoroverloading_mystring_empty();
    void test_case_operatoroverloading_mystring_normal();
    void test_case_operatoroverloading_mystring_copy();
    void test_case_operatoroverloading_assignmentop();
    void test_case_operatoroverloading_moveop();
    void test_case_operatoroverloading_negationop();
    void test_case_operatoroverloading_negationmixedcase();
    void test_case_operatoroverloading_negationemptystringcase();
    void test_case_operatoroverloading_additionop();
    void test_case_operatoroverloading_additionop_empty();
    void test_case_operatoroverloading_comparisonop();
    void test_case_operatoroverloading_comparisonop_empty();

};

MyStringTest::MyStringTest(){}
MyStringTest::~MyStringTest(){}

void MyStringTest::test_case_operatoroverloading_mystring_empty(){ //mystring class no args constructor test
    MyString operatoroverloading;
    std::ostringstream out;
    operatoroverloading.display(out);
    QCOMPARE(out.str(),"\n");
    QCOMPARE(operatoroverloading.getlength(),0);
    QCOMPARE(operatoroverloading.getmystring(),"\0");
}

void MyStringTest::test_case_operatoroverloading_mystring_normal(){ //mystring class overloaded constructor test
    MyString operatoroverloading{"Helo"};
    std::ostringstream out;
    operatoroverloading.display(out);
    QCOMPARE(out.str(),"Helo\n");
    QCOMPARE(operatoroverloading.getlength(),4);
    QCOMPARE(operatoroverloading.getmystring(),"Helo");
}

void MyStringTest::test_case_operatoroverloading_mystring_copy(){ //mystring class copy constructor test
    MyString operatoroverloading{"Helo"};
    MyString operatoroverloading_copy{operatoroverloading};
    std::ostringstream out;
    operatoroverloading_copy.display(out);
    QCOMPARE(out.str(),"Helo\n");
    QCOMPARE(operatoroverloading_copy.getlength(),4);
    QCOMPARE(operatoroverloading_copy.getmystring(),"Helo");
}

void MyStringTest::test_case_operatoroverloading_assignmentop(){ //assignment operator copy test
    MyString operatoroverloading{"Helo"};
    MyString operatoroverloading_empty;
    MyString operatoroverloading_copy{operatoroverloading_empty};
    operatoroverloading_empty = operatoroverloading;
    operatoroverloading_copy = operatoroverloading;
    QCOMPARE(operatoroverloading_empty.getmystring(),operatoroverloading.getmystring());
    QCOMPARE(operatoroverloading_copy.getmystring(),operatoroverloading.getmystring());

}

void MyStringTest::test_case_operatoroverloading_moveop(){ //assignmet operator overload move test
    MyString operatoroverloading{"Hello Move Constructor"};
    operatoroverloading = MyString {"testing"};
    QCOMPARE(operatoroverloading.getmystring(),"testing");
    operatoroverloading = "Hello move 2";
   }
void MyStringTest::test_case_operatoroverloading_negationop(){ //negation test
    MyString objectfornegation1{"HELLO OBJECT FOR NEGATION"};
    MyString negatedobject1 = -objectfornegation1;
    QCOMPARE(negatedobject1.getmystring(),"hello object for negation");
   }
void MyStringTest::test_case_operatoroverloading_negationemptystringcase(){ //edge case empty string test
    MyString objectfornegation2;
    MyString negatedobject2 = -objectfornegation2;
    QCOMPARE(negatedobject2.getmystring(),"");
    }
void MyStringTest::test_case_operatoroverloading_negationmixedcase(){ //mixed case test
    MyString objectfornegation3{"Hello"};
    MyString negatedobject3 = -objectfornegation3;
    QCOMPARE(negatedobject3.getmystring(),"hello");
}

void MyStringTest::test_case_operatoroverloading_additionop(){ //normal test case
    MyString objectforconcatanation{"Hello1 Hello2"};
    MyString concatenated = objectforconcatanation + objectforconcatanation;
    QCOMPARE(concatenated.getmystring(),"Hello1 Hello2Hello1 Hello2");
}

void MyStringTest::test_case_operatoroverloading_additionop_empty(){ //empty case test
    MyString objectforconcatanation;
    MyString object2forconcatanation{""};
    MyString object3forconcatanation{"hi there"};
    MyString concatenated = objectforconcatanation + object2forconcatanation + object3forconcatanation;
    QCOMPARE(concatenated.getmystring(),"hi there");
}

void MyStringTest::test_case_operatoroverloading_comparisonop(){ //normal test case
    MyString object1forcomparison{"Hello1 Hello2"};
    MyString object2forcomparison{"Hello1 Hello2"};
    QCOMPARE(object1forcomparison==object2forcomparison,true);
}

void MyStringTest::test_case_operatoroverloading_comparisonop_empty(){ //empty test case
    MyString object1forcomparison;
    MyString object2forcomparison{""};
    QCOMPARE(object1forcomparison==object2forcomparison,true);
}




QTEST_APPLESS_MAIN(MyStringTest)

#include "tst_mystringtest.moc"
