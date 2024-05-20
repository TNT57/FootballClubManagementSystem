#include "addmatchfixture.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include "ui_addmatchfixture.h"
AddMatchFixture::AddMatchFixture(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddMatchFixture)
{
    ui->setupUi(this);
    ui -> dateEdit -> setDisplayFormat("dd/MM/yyyy");
    ui -> dateEdit -> setDate(QDate::currentDate());
}

AddMatchFixture::~AddMatchFixture()
{
    delete ui;
}

void AddMatchFixture::on_confirmButton_clicked()
{
    QDate date = ui->dateEdit->date();
    QString formattedDate = date.toString("dd/MM/yyyy");
    QString time = ui->timeEdit->text();
    QString opponentTeamName = ui->opponentTeamNameEdit->text();
    QString location = ui->locationEdit->text();
    qDebug() << formattedDate << "," << time << " " << opponentTeamName << " " << location;
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);

    // Check if a match already exists for the selected date
    query.prepare("SELECT * FROM MatchRecord WHERE Date = :Date");
    query.bindValue(":Date", formattedDate);
    if (query.exec() && query.next()) {
        QMessageBox::critical(this, "Error", "A match already exists on this date.");
        return;
    }

    query.prepare("INSERT INTO MatchRecord (OpponentName, Date, Time, Location) VALUES "
                  "(:OpponentName,:Date,:Time,:Location)"); // Remove whitespace in placeholders
    query.bindValue(":OpponentName", opponentTeamName);
    query.bindValue(":Date", formattedDate);
    query.bindValue(":Time", time);
    query.bindValue(":Location", location);

    if (!query.exec()) {
        QSqlError error = query.lastError();
        QMessageBox::critical(this,
                              "Error",
                              "Failed to insert data into the database: " + error.text());
    }

    else {
        QMessageBox::information(this,
                                 "Add successfully",
                                 "Date: " + formattedDate + "\n" + "Time: " + time + "\n"
                                     + "Opponent Team Name: " + opponentTeamName
                                     + "\n"
                                       "Location: "
                                     + location + "\n");
    }
}
