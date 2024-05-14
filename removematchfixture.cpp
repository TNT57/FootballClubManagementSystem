#include "removematchfixture.h"
#include "ui_removematchfixture.h"

RemoveMatchFixture::RemoveMatchFixture(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RemoveMatchFixture)
{
    ui->setupUi(this);
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
    QString opponentTeamName = ui -> opponentTeamNameEdit -> text();
    QString location = ui -> locationEdit -> text();

    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);

    // Check if a match record exists for the selected date, time, opponent team name, and location
    query.prepare("SELECT * FROM MatchRecord WHERE Date = :Date AND Time = :Time AND OpponentName = :OpponentName AND Location = :Location");
    query.bindValue(":Date", formattedDate);
    query.bindValue(":Time", time);
    query.bindValue(":OpponentName", opponentTeamName);
    query.bindValue(":Location", location);

    if(!query.exec() || !query.next()){
        QMessageBox::information(this, "No Match Found", "No match fixture found with the provided details.");
        return;
    }

    // If a match record exists, proceed with the deletion
    query.prepare("DELETE FROM MatchRecord WHERE Date = :Date AND Time = :Time AND OpponentName = :OpponentName AND Location = :Location");
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

