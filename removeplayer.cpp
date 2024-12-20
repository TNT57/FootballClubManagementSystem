#include "removeplayer.h"
#include "ui_removeplayer.h"

//Constructor
RemovePlayer::RemovePlayer(QWidget *parent): QWidget(parent), ui(new Ui::RemovePlayer) {
    ui -> setupUi(this);
    populatePlayers();

    // Set the size of the label to be a square
    ui -> infoLabel -> setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui -> infoLabel -> setStyleSheet("QLabel {"
                                     "border: 1px solid black;"
                                     "border-radius: 15px;" // Half of width/height
                                     "}");
}

//DefaulT Destructor
RemovePlayer::~RemovePlayer() {
    qDebug() << "~RemovePlayer";
    delete ui;
}

void RemovePlayer::populatePlayers() {
    QSqlDatabase db = QSqlDatabase::database("DB1"); //set database

    //Check if database is open
    if (!db.isOpen()) {
        qDebug() << "Database connection failed: ";
        return;
    }

    // set query
    QSqlQuery query(db);

    // check if query is executed
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
    QString playerInfo = ui -> playerNameComboBox -> currentText();
    QStringList infoParts = playerInfo.split(" - "); // Split the string to extract the shirt number and name

    if (infoParts.size() > 1) {
        int playerShirtNumber = infoParts.at(0).toInt(); // The player's shirt number is the first part
        QSqlDatabase db = QSqlDatabase::database("DB1"); // set database

        // set query
        QSqlQuery query(db);
        query.prepare("DELETE FROM Player WHERE ShirtNumber = :shirtNumber"); //use sql commands
        query.bindValue(":shirtNumber", playerShirtNumber);

        // check if query is executed
        if (query.exec()) {
            // update the combo box
            QMessageBox::information(this, "Success", "Player removed successfully\n"
                                                      "Please reload the table");
            ui -> playerNameComboBox -> removeItem(ui -> playerNameComboBox -> currentIndex());
        }

        else {
            QMessageBox::critical(this, "Error", "Could not remove player: " + query.lastError().text());
        }
    }

    else {
        QMessageBox::critical(this, "Error", "Invalid selection.");
    }
}
