#ifndef TST_EDITSTAFF_H
#define TST_EDITSTAFF_H

#include <QObject>
#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QtTest>
#include "../editstaff.h"
#include "../ui_editstaff.h"

class TestEditStaff : public QObject
{
    Q_OBJECT

public:
    TestEditStaff();
    ~TestEditStaff();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_loadStaff();
    void test_on_confirmButton_clicked();
    void test_validateInput();

private:
    EditStaff *editStaff;
};

#endif // TST_EDITSTAFF_H
