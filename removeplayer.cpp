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
    QSqlDatabase db = QSqlDatabase::database("DB1");

    if (!db.isOpen()) {
        qDebug() << "Database connection failed: ";
        return;
    }

    QSqlQuery query(db);

    if (!query.exec("SELECT ShirtNumber, Name FROM Player")) {
        qDebug() << "Query execution failed: " << query.lastError();
        return;
    }

    while (query.next()) {
        int playerShirtNumber = query.value(0).toInt(); // Convert to int
        QString playerName = query.value(1).toString(); // Get the player's name
        QString playerInfo = QString::number(playerShirtNumber) + " - " + playerName; // Concatenate shirt number and name
        ui->playerNameComboBox->addItem(playerInfo); // Add the combined string to the combo box
    }
}

void RemovePlayer::on_confirmButton_clicked() {
    QString playerInfo = ui->playerNameComboBox->currentText();
    QStringList infoParts = playerInfo.split(" - "); // Split the string to extract the shirt number and name
    if (infoParts.size() > 1) {
        int playerShirtNumber = infoParts.at(0).toInt(); // The player's shirt number is the first part
        QSqlDatabase db = QSqlDatabase::database("DB1");
        QSqlQuery query(db);
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
