
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
#include "tst_addplayer.h"
#include "tst_removestaff.h"
#include "tst_removeplayer.h"
#include "tst_editstaff.h"
#include "tst_editplayer.h"
#include "tst_teamstatistics.h"
#include "tst_simulatematch.h"
// Include other test header files as needed


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int status = 0;
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "DB1");
    database.setDatabaseName("C:\\Users\\trung\\Downloads\\PlayerManagement.db");
    if(!database.open()){
        qDebug() << "Maintest: Error: Unable to open database..";
    }
    else{
        qDebug() << "Maintest: Database open successfully..";
    }

    TestAddStaff addStaffTest;
    status |= QTest::qExec(&addStaffTest, argc, argv);


    TestAddPlayer addPlayerTest;
    status |= QTest::qExec(&addPlayerTest, argc, argv);

    TestRemoveStaff removeStaffTest;
    status |= QTest::qExec(&removeStaffTest, argc, argv);

    TestRemovePlayer removePlayerTest;
    status |= QTest::qExec(&removePlayerTest, argc, argv);

    TestEditStaff editStaffTest;
    status |= QTest::qExec(&editStaffTest, argc, argv);

    TestEditPlayer editPlayerTest;
    status |= QTest::qExec(&editPlayerTest, argc, argv);

    TestTeamStatistics teamStatisticsTest;
    status |= QTest::qExec(&teamStatisticsTest, argc, argv);

    TestSimulateMatch simulateMatchTest;
    status |= QTest::qExec(&simulateMatchTest, argc, argv);

    // Create instances of other test classes and run their tests as needed

    database.close();
    QSqlDatabase::removeDatabase(database.connectionName());

    return status;
}
