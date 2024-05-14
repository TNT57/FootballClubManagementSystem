#include "navigator.h"
#include "./ui_navigator.h"
#include "ui_navigator.h"
#include <QDebug>

Navigator::Navigator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Navigator)
{
    ui->setupUi(this);
    // initialise database
    database = QSqlDatabase::addDatabase("QSQLITE", "DB1");
    //database.setDatabaseName("D:\\University of Adelaide\\COMP SCI 1102\\Project-Cpp-OOP\\PlayerManagement.db");
    // ae tu sua dia chi database theo may minh nhe
    database.setDatabaseName("D:\\University of Adelaide\\COMP SCI 1102\\FootballClubManagementSystem\\PlayerManagement.db");

    // check the database is working or not
    if(!database.open()){
        qDebug() << "Error: Unable to open database";
    }
    else{
        qDebug() << "Database open successfully";
    }
    ptrPeople = new People();
    ptrMatchFixture = new MatchFixture();
    ptrTeamStatistics = new TeamStatistics();

}

Navigator::~Navigator()
{
    delete ui;
    delete ptrPeople;
    delete ptrMatchFixture;
    delete ptrTeamStatistics;
    database.close();
    QSqlDatabase::removeDatabase(database.connectionName());

}

// open people management feature
void Navigator::on_peopleButton_clicked()
{
    ptrPeople -> setWindowTitle("People");
    ptrPeople -> show();
}


void Navigator::on_matchButton_clicked()
{
    ptrMatchFixture -> setWindowTitle("Match Fixture");
    ptrMatchFixture -> show();
}


void Navigator::on_teamButton_clicked()
{
    ptrTeamStatistics -> setWindowTitle("Team Statistics");
    ptrTeamStatistics -> show();
}

