#include "removematchfixture.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include "ui_removematchfixture.h"

RemoveMatchFixture::RemoveMatchFixture(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RemoveMatchFixture)
{
    ui->setupUi(this);

    // Add the team names to the QComboBox
    QStringList teams = {"Arsenal", "Liverpool", "ManCity", "PSG", "RealMadrid"};
    ui->opponentNameComboBox->addItems(teams);

    // Set the size of the label to be a square
    ui->infoLabel->setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui->infoLabel->setStyleSheet("QLabel {"
                                 "border: 1px solid black;"
                                 "border-radius: 15px;" // Half of width/height
                                 "}");

}

RemoveMatchFixture::~RemoveMatchFixture()
{
    delete ui;
}

void RemoveMatchFixture::on_confirmButton_clicked()
{
    QDate date = ui -> dateEdit -> date();
    QString formattedDate = date.toString("dd/MM/yyyy");
    QString time = ui -> timeEdit -> text();
    QString opponentTeamName = ui->opponentNameComboBox->currentText();
    QString location = ui -> locationEdit -> text().toLower(); // Convert user input to lowercase

    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);

    // Check if a match record exists for the selected date, time, opponent team name, and location
    query.prepare("SELECT * FROM MatchRecord WHERE Date = :Date AND Time = :Time AND OpponentName = :OpponentName AND LOWER(Location) = :Location"); // Convert database location to lowercase
    query.bindValue(":Date", formattedDate);
    query.bindValue(":Time", time);
    query.bindValue(":OpponentName", opponentTeamName);
    query.bindValue(":Location", location);

    if(!query.exec() || !query.next()){
        QMessageBox::information(this, "No Match Found", "No match fixture found with the provided details.");
        return;
    }

    // If a match record exists, proceed with the deletion
    query.prepare("DELETE FROM MatchRecord WHERE Date = :Date AND Time = :Time AND OpponentName = :OpponentName AND LOWER(Location) = :Location"); // Convert database location to lowercase
    query.bindValue(":Date", formattedDate);
    query.bindValue(":Time", time);
    query.bindValue(":OpponentName", opponentTeamName);
    query.bindValue(":Location", location);

    if(!query.exec()){
        QSqlError error = query.lastError();
        QMessageBox::critical(this, "Error", "Failed to remove data from the database: " + error.text());
    }

    else {
        QMessageBox::information(this, "Remove successfully", "Removed match with the provided details.");
    }
}
