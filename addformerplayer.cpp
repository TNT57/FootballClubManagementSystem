#include "addformerplayer.h"
#include "ui_addformerplayer.h"

AddFormerPlayer::AddFormerPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddFormerPlayer)
{
    ui->setupUi(this);
    populateFormerPlayers();
    ui -> dateEdit -> setDisplayFormat("dd/MM/yyyy");
    ui -> dateEdit -> setDate(QDate::currentDate());
}

AddFormerPlayer::~AddFormerPlayer()
{
    delete ui;
}

void AddFormerPlayer::populateFormerPlayers() {
    QSqlDatabase db = QSqlDatabase::database("DB1");

    if (!db.isOpen()) {
        qDebug() << "Database connection failed!";
        return;
    }

    QSqlQuery query(db);

    if (!query.exec("SELECT ShirtNumber, Name FROM Player")) {
        qDebug() << "Query execution failed: " << query.lastError();
        return;
    }

    while (query.next()) {
        int playerShirtNumber = query.value(0).toInt();
        QString playerName = query.value(1).toString();
        QString playerInfo = QString::number(playerShirtNumber) + " - " + playerName;
        ui -> playerNameComboBox -> addItem(playerInfo);
    }
}

void AddFormerPlayer::on_confirmButton_clicked()
{
    QString playerInfo = ui -> playerNameComboBox -> currentText();
    QStringList infoParts = playerInfo.split(" - ");

    if (infoParts.size() > 1) {
        int playerShirtNumber = infoParts.at(0).toInt();
        QString playerName = infoParts.at(1);
        QSqlDatabase db = QSqlDatabase::database("DB1");
        QSqlQuery query(db);
        query.prepare("DELETE FROM Player WHERE ShirtNumber = :shirtNumber");
        query.bindValue(":shirtNumber", playerShirtNumber);

        if (!query.exec()) {
            QMessageBox::critical(this, "Error", "Could not delete player from current data: " + query.lastError().text());
            return;
        }

        QDate date = ui->dateEdit->date();
        QString formattedDate = date.toString("dd/MM/yyyy");

        query.prepare("INSERT INTO FormerPlayer (Name, DayOfLeaving) VALUES (:Name, :DayOfLeaving)");
        query.bindValue(":Name", playerName);
        query.bindValue(":DayOfLeaving", formattedDate);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "Former player added successfully!");
            ui -> playerNameComboBox -> removeItem(ui -> playerNameComboBox -> currentIndex());
        }

        else {
            QMessageBox::critical(this, "Error", "Could not add former player: " + query.lastError().text());
            return;
        }
    }

    else {
        QMessageBox::critical(this, "Error", "Invalid selection.");
        return;
    }

}

void AddFormerPlayer::on_playerNameComboBox_activated()
{

}


