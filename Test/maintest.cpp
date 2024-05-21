#include <QtTest>
#include <QApplication>
#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include "tst_addstaff.h"
// Include other test header files as needed


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int status = 0;
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "DB1");
    database.setDatabaseName("/Users/tom/PlayerManagement.db");
    if(!database.open()){
        qDebug() << "Maintest: Error: Unable to open database..";
    }
    else{
        qDebug() << "Maintest: Database open successfully..";
    }

    TestAddStaff addStaffTest;
    status |= QTest::qExec(&addStaffTest, argc, argv);

    // Create instances of other test classes and run their tests as needed

    database.close();
    QSqlDatabase::removeDatabase(database.connectionName());

    return status;
}
