#ifndef TST_ADDSTAFF_H
#define TST_ADDSTAFF_H

#include <QObject>
#include <QtTest>
#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include "../addstaff.h"

class TestAddStaff: public QObject
{
    Q_OBJECT

public:
    TestAddStaff();
    ~TestAddStaff();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_validateInput();

private:
    AddStaff *addstaff;
};

#endif // TST_ADDSTAFF_H
