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
    QString result1 = "XYZ v Xyz v xYZ v xYz";
    QVERIFY(ex1.getDvoistvFunc(testList1) == result1);
}

void myTestsClass::test_case2()
{   //false
    funcs ex2;
    QList<int> testList2 = {1, 6, 7, 2};
    QString result2 = "xyz v xYZ v Xyz v XYZ";
    QVERIFY(ex2.getDvoistvFunc(testList2) == result2);
}

void myTestsClass::test_case3()
{   //true
    funcs ex3;
    QList<int> testList3 = {3, 4, 5, 6, 7};
    QString result3 = "xyz v xyZ v Xyz";    //true XYZ v XYz v XyZ
    QVERIFY(ex3.getDvoistvFunc(testList3) != result3);
}

QTEST_APPLESS_MAIN(myTestsClass)

#include "tst_mytestsclass.moc"
