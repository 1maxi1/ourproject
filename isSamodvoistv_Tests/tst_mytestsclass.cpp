#include <QtTest>
#include "../server/funcs.h"
// add necessary includes here

class myTestsClass : public QObject
{
    Q_OBJECT

public:
    myTestsClass();
    ~myTestsClass();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
};

myTestsClass::myTestsClass()
{

}

myTestsClass::~myTestsClass()
{

}

void myTestsClass::test_case1()
{   //true
    funcs ex1;
    QList<int> testList1 = {1, 6, 7, 2};
    bool result1 = false;
    QVERIFY(ex1.isSamodvoistv(testList1) == result1);
}

void myTestsClass::test_case2()
{   //false
    funcs ex2;
    QList<int> testList2 = {1, 6, 7, 2};
    bool result2 = true;
    QVERIFY(ex2.isSamodvoistv(testList2) == result2);
}

void myTestsClass::test_case3()
{   //true
    funcs ex3;
    QList<int> testList3 = {3, 4, 5, 6, 7};
    //bool result3 = false;
    QCOMPARE(ex3.isSamodvoistv(testList3), false);
}

QTEST_APPLESS_MAIN(myTestsClass)

#include "tst_mytestsclass.moc"
