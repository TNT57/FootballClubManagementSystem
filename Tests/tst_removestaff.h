#ifndef TST_REMOVESTAFF_H
#define TST_REMOVESTAFF_H

#include <QObject>
#include <QtTest/QtTest>
#include "../removestaff.h"
#include "../ui_removestaff.h"

class TestRemoveStaff : public QObject
{
    Q_OBJECT

public:
    TestRemoveStaff();
    ~TestRemoveStaff();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_populateStaff();
    void test_on_staffRemoveConfirmButton_clicked();

private:
    RemoveStaff *removeStaff;
};

#endif // TST_REMOVESTAFF_H
