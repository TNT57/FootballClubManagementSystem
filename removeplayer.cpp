#include "removeplayer.h"
#include "ui_removeplayer.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>    // Include this header for Debug message
#include <QSqlError> // Include this header for QSqlError

//Constructor
RemovePlayer::RemovePlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RemovePlayer)
{
    ui->setupUi(this);
    populatePlayers();
}

//Defaul Destructor
RemovePlayer::~RemovePlayer()
{
    qDebug() << "~RemovePlayer";
    delete ui;
}

void RemovePlayer::populatePlayers() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("/Users/tom/Project-Cpp-OOP/PlayerManagement.db");
    db.setDatabaseName("D:\\University of Adelaide\\COMP SCI 1102\\FootballClubManagementSystem\\PlayerManagement.db");

    // Check if the database is open or not
    if (db.open()) {
        QSqlQuery query("SELECT ShirtNumber, Name FROM Player");
        while (query.next()) {
            int playerShirtNumber = query.value(0).toInt(); // Convert to int
            QString playerName = query.value(1).toString(); // Get the player's name
            QString playerInfo = QString::number(playerShirtNumber) + " - " + playerName; // Concatenate shirt number and name
            ui->playerNameComboBox->addItem(playerInfo); // Add the combined string to the combo box
        }
    } else {
        qDebug() << "Database connection failed: ";
    }
}


void RemovePlayer::on_confirmButton_clicked() {
    QString playerInfo = ui->playerNameComboBox->currentText();
    QStringList infoParts = playerInfo.split(" - "); // Split the string to extract the shirt number and name
    if (infoParts.size() > 1) {
        int playerShirtNumber = infoParts.at(0).toInt(); // The player's shirt number is the first part
        QSqlQuery query;
        query.prepare("DELETE FROM Player WHERE ShirtNumber = :shirtNumber");
        query.bindValue(":shirtNumber", playerShirtNumber);
        if (query.exec()) {
            QMessageBox::information(this, "Success", "Player removed successfully");
            ui->playerNameComboBox->removeItem(ui->playerNameComboBox->currentIndex());
        } else {
            QMessageBox::critical(this, "Error", "Could not remove player: " + query.lastError().text());
        }
    } else {
        QMessageBox::critical(this, "Error", "Invalid selection.");
    }
}



void RemovePlayer::on_playerNameComboBox_activated()
{
    //Leave empty for now
}
