#include "teamstatistics.h"
#include "ui_teamstatistics.h"
#include <QSqlError> // Include this header for QSqlError
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

TeamStatistics::TeamStatistics(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeamStatistics)
{
    ui->setupUi(this);
    loadPlayerStats();
}

TeamStatistics::~TeamStatistics()
{
    qDebug() << "~RemovePlayer";
    delete ui;
}


//int teamNumGoals, teamNumAssists, teamNumYellowCards, teamNumRedCards;
//float teamAVGPass, teamAVGTackle, teamAVGDribble;

void TeamStatistics:: loadPlayerStats(){
    QSqlDatabase db = QSqlDatabase::database("DB1");

    // Check if the database is open
    if (!db.isOpen()) {
        qDebug() << "Error: connection with database failed:" << db.lastError().text();
        return;
    } else {
        qDebug() << "Database: connection ok";
    }

    // Insert value for Goals box
    QSqlQuery query(db);


    // Process the results of your query here
    query.prepare("SELECT Goals FROM Player");
    int teamNumGoals = 0; // Initialize the team goals counter
    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamNumGoals += query.value(0).toInt(); // Sum up the goals
        }
    } else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }
    ui->goalLabel->setText(QString::number(teamNumGoals)); //set the text of the goalLabel widget with the total number of goals.


    //Insert value for Assists box
    query.prepare("SELECT Assists FROM Player");
    int teamNumAssists = 0;
    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamNumAssists += query.value(0).toInt(); // Sum up the goals
        }
    } else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }
    ui->assistLabel->setText(QString::number(teamNumAssists)); //set the text of the assistLabel widget with the total number of assists.


    //Insert value for YellowCard box
    query.prepare("SELECT YellowCard FROM Player");
    int teamNumYellowCards = 0;
    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamNumYellowCards += query.value(0).toInt(); // Sum up the number of cards
        }
    } else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }
    ui->yellowLabel->setText(QString::number(teamNumYellowCards)); //set the text of the yellowCardLabel


    //Insert value for YellowCard box
    query.prepare("SELECT RedCard FROM Player");
    int teamNumRedCards = 0;
    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamNumRedCards += query.value(0).toInt(); // Sum up the number of cards
        }
    } else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }
    ui->redLabel->setText(QString::number(teamNumRedCards)); //set the text of the yellowCardLabel


    //Find the amount of players
    query.prepare("SELECT COUNT(Goals) FROM Player");
    int playerAmount = 0;
    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            playerAmount = query.value(0).toInt();
            qDebug() << "Amount of player: " << playerAmount;
        }
    } else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }


    //Insert value for PassCmpPer90 box
    query.prepare("SELECT PassCmpPer90 FROM Player");
    float teamAVGPass = 0.0;
    float teamAVGPassResult = 0.0;
    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamAVGPass += query.value(0).toInt(); // Sum up the percentage of pass
            teamAVGPassResult = teamAVGPass/playerAmount;
        }
    } else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }
    QString formattedPassResult = QString::number(teamAVGPassResult, 'f', 2);
    ui->passLabel->setText(formattedPassResult); //set the text of the passLabel


    //Insert value for TacklePer90 box
    query.prepare("SELECT TacklePer90 FROM Player");
    float teamAVGTackle = 0.0;
    float teamAVGTackleResult = 0.0;
    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamAVGTackle += query.value(0).toInt(); // Sum up the percentage of pass
            teamAVGTackleResult = teamAVGTackle/playerAmount;
        }
    } else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }
    // Limit the result to two decimal places
    QString formattedTackleResult = QString::number(teamAVGTackleResult, 'f', 2);
    ui->tackleLabel->setText(formattedTackleResult); // Set the text of the tackleLabel


    //Insert value for DribblePer90 box
    query.prepare("SELECT DribblePer90 FROM Player");
    float teamAVGDribble = 0.0;
    float teamAVGDribbleResult = 0.0;
    if (query.exec()) { // Execute the query
        while (query.next()) { // Iterate over the query results
            teamAVGDribble += query.value(0).toInt(); // Sum up the percentage of pass
            teamAVGDribbleResult = teamAVGDribble/playerAmount;
        }
    } else {
        // Handle query execution error
        qDebug() << "Error executing query:" << query.lastError();
    }
    QString formattedDribbleResult = QString::number(teamAVGDribbleResult, 'f', 2);
    ui->dribbleLabel->setText(formattedDribbleResult); //set the text of the dribbleLabel

}




void TeamStatistics::on_btnReload_clicked()
{
    loadPlayerStats();
}
