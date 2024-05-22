#include "addtransferlist.h"
#include "ui_addtransferlist.h"

AddTransferList::AddTransferList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddTransferList)
{
    ui->setupUi(this);
    populateTransferList();

    // Set the size of the label to be a square
    ui->infoLabel->setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui->infoLabel->setStyleSheet("QLabel {"
                                 "border: 1px solid black;"
                                 "border-radius: 15px;" // Half of width/height
                                 "}");
}

AddTransferList::~AddTransferList()
{
    delete ui;
}

void AddTransferList::populateTransferList() {
    QSqlDatabase db = QSqlDatabase::database("DB1");

    if (!db.isOpen()) {
        qDebug() << "Database connection failed!";
        return;
    }

    QSqlQuery query(db);

    if (!query.exec("SELECT ShirtNumber, Position, Name FROM Player")) {
        qDebug() << "Query execution failed: " << query.lastError();
        return;
    }

    while (query.next()) {
        int playerShirtNumber = query.value(0).toInt();
        QString position = query.value(1).toString();
        QString playerName = query.value(2).toString();
        QString playerInfo = QString::number(playerShirtNumber) + " - " + position + " - " + playerName;
        ui -> playerNameComboBox -> addItem(playerInfo);
    }
}

bool AddTransferList::validateInput() {
    int transferFee = (ui -> transferFeeEdit -> text()).toInt();

    if (transferFee < 0) {
        return false;
    }

    QString transferFeeStr = ui -> transferFeeEdit -> text();
    int pos = 0;
    QIntValidator validator(0, INT_MAX);

    if (validator.validate(transferFeeStr, pos) != QValidator::Acceptable) {
        return false;
    }

    return true;
}

void AddTransferList::on_confirmButton_clicked()
{
    if (!validateInput()) {
        QMessageBox::critical(this, "Error", "Invalid transfer fee. It must be an integer and >= 0");
        return;
    }

    QString playerInfo = ui -> playerNameComboBox -> currentText();
    QStringList infoParts = playerInfo.split(" - ");

    if (infoParts.size() > 1) {
        int playerShirtNumber = infoParts.at(0).toInt();
        QString position = infoParts.at(1);
        QString playerName = infoParts.at(2);
        int transferFee = (ui -> transferFeeEdit -> text()).toInt();

        QSqlDatabase db = QSqlDatabase::database("DB1");
        QSqlQuery query(db);

        query.prepare("INSERT INTO TransferList (ShirtNumber, Position, Name, TransferFee) VALUES (:shirtNumber, :position, :playerName, :transferFee)");
        query.bindValue(":shirtNumber", playerShirtNumber);
        query.bindValue(":position", position);
        query.bindValue(":playerName", playerName);
        query.bindValue(":transferFee", transferFee);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "Player added to Transfer List successfully!");
            ui -> playerNameComboBox -> removeItem(ui -> playerNameComboBox -> currentIndex());
        }

        else {
            QMessageBox::critical(this, "Error", "Could not add Player to Transfer List!" + query.lastError().text());
            return;
        }
    }

    else {
        QMessageBox::critical(this, "Error", "Invalid selection");
        return;
    }
}

void AddTransferList::on_playerNameComboBox_activated()
{

}

