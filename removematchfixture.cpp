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
    populateMatchDay();

    // Add the team names to the QComboBox
    //QStringList teams = {"Arsenal", "Liverpool", "ManCity", "PSG", "RealMadrid"};
    //ui->matchDayComboBox->addItems(teams);

    // Set the tooltip for the label
    ui->infoLabel->setToolTip("Click reload to see the most updated statistic of the team!");

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

void RemoveMatchFixture::populateMatchDay() {
    QSqlDatabase db = QSqlDatabase::database("DB1"); // set database

    //Check if database is open
    if (!db.isOpen()) {
        qDebug() << "Database connection failed: ";
        return;
    }

    QSqlQuery query(db);

    if (!query.exec("SELECT Date, Time, OpponentName, Location FROM MatchRecord")) {
        qDebug() << "Query execution failed: " << query.lastError();
        return;
    }

    while (query.next()) {
        QString date = query.value(0).toString();
        QString time = query.value(1).toString();
        QString opponentName = query.value(2).toString();
        QString location = query.value(3).toString();
        QString matchDayInfo = date + " - " + time + " - " + opponentName + " - " + location;
        ui -> matchDayComboBox -> addItem(matchDayInfo);
    }

}

void RemoveMatchFixture::on_confirmButton_clicked()
{
    QString matchDayInfo = ui -> matchDayComboBox -> currentText();
    QStringList infoParts = matchDayInfo.split(" - ");

    if (infoParts.size() > 1) {
        QString date = infoParts.at(0);
        QSqlDatabase db = QSqlDatabase::database("DB1");
        QSqlQuery query(db);
        query.prepare("DELETE FROM MatchRecord WHERE Date = :date");
        query.bindValue(":date", date);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "Match Day removed successfully\n"
                                                      "Please reload the calendar");
            ui -> matchDayComboBox -> removeItem(ui->matchDayComboBox->currentIndex());
        }

        else {
            QMessageBox::critical(this, "Error", "Could not remove match day" + query.lastError().text());
        }
    }

    else {
        QMessageBox::critical(this, "Error", "Invalid selection.");
    }
}
