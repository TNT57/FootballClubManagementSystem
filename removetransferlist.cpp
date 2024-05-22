#include "removetransferlist.h"
#include "ui_removetransferlist.h"

RemoveTransferList::RemoveTransferList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RemoveTransferList)
{
    ui->setupUi(this);
    populateTransferList();
}

RemoveTransferList::~RemoveTransferList()
{
    delete ui;
}

void RemoveTransferList::populateTransferList() {
    QSqlDatabase db = QSqlDatabase::database("DB1");

    if (!db.isOpen()) {
        qDebug() << "Database connection failed!";
        return;
    }

    QSqlQuery query(db);

    if (!query.exec("SELECT ShirtNumber, Position, Name FROM TransferList")) {
        qDebug() << "Query execution failed!" << query.lastError();
        return;
    }

    while (query.next()) {
        int playerShirtNumber = query.value(0).toInt();
        QString position = query.value(1).toString();
        QString playerName = query.value(2).toString();
        // int transferFee = query.value(3).toInt();
        // QString playerInfo = QString::number(playerShirtNumber) + " - " + position + " - " + playerName + " - " + QString::number(transferFee);
        QString playerInfo = QString::number(playerShirtNumber) + " - " + position + " - " + playerName;
        ui -> playerNameComboBox -> addItem(playerInfo);
    }
}

void RemoveTransferList::on_confirmButton_clicked()
{
    QString playerInfo = ui -> playerNameComboBox -> currentText();
    QStringList infoParts = playerInfo.split(" - ");


    if (infoParts.size() > 1) {
        int playerShirtNumber = infoParts.at(0).toInt();
        QSqlDatabase db = QSqlDatabase::database("DB1");
        QSqlQuery query(db);

        query.prepare("DELETE FROM TransferList WHERE ShirtNumber = :shirtNumber");
        query.bindValue(":shirtNumber", playerShirtNumber);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "Player successfully removed from Transfer List\n"
                                                       "Please reload the table");
            ui -> playerNameComboBox -> removeItem(ui -> playerNameComboBox -> currentIndex());
        }

        else {
            QMessageBox::critical(this, "Error", "Could not delete Player from Transfer List");
            return;
        }
    }

    else {
        QMessageBox::critical(this, "Error", "Invalid selection");
        return;
    }
}

void RemoveTransferList::on_playerNameComboBox_activated()
{

}

