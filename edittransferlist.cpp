#include "edittransferlist.h"
#include "ui_edittransferlist.h"

EditTransferList::EditTransferList(QWidget *parent): QWidget(parent), ui(new Ui::EditTransferList) {
    ui -> setupUi(this);
    populateTransferList();

    // Set the size of the label to be a square
    ui -> infoLabel -> setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui -> infoLabel -> setStyleSheet("QLabel {"
                                     "border: 1px solid black;"
                                     "border-radius: 15px;" // Half of width/height
                                     "}");
}

EditTransferList::~EditTransferList() {
    delete ui;
}

void EditTransferList::populateTransferList() {
    // set database
    QSqlDatabase db = QSqlDatabase::database("DB1");

    // check if database is opened
    if (!db.isOpen()) {
        qDebug() << "Database connection failed!";
        return;
    }

    // set query
    QSqlQuery query(db);

    if (!query.exec("SELECT ShirtNumber, Position, Name FROM TransferList")) {
        qDebug() << "Query execution failed!" << query.lastError();
        return;
    }

    while (query.next()) {
        // load data to the combo box
        int playerShirtNumber = query.value(0).toInt();
        QString position = query.value(1).toString();
        QString playerName = query.value(2).toString();
        QString playerInfo = QString::number(playerShirtNumber) + " - " + position + " - " + playerName;
        ui -> playerNameComboBox -> addItem(playerInfo);
    }
}

bool EditTransferList::validateInput() {
    // validate if transfer fee is >= 0
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

void EditTransferList::on_confirmButton_clicked() {
    // validate before consider edit as successful
    if (!validateInput()) {
        QMessageBox::critical(this, "Error", "Invalid transfer fee. It must be greater or equal to $0");
        return;
    }

    QString playerInfo = ui -> playerNameComboBox -> currentText();
    QStringList infoParts = playerInfo.split(" - ");

    if (infoParts.size() > 1) {
        int playerShirtNumber = infoParts.at(0).toInt();
        int transferFee = (ui -> transferFeeEdit -> text()).toInt();

        // set database and query
        QSqlDatabase db = QSqlDatabase::database("DB1");
        QSqlQuery query(db);

        query.prepare("UPDATE TransferList SET TransferFee = :transferFee WHERE ShirtNumber = :shirtNumber");
        query.bindValue(":shirtNumber", playerShirtNumber);
        query.bindValue(":transferFee", transferFee);

        // check if query is executed
        if (query.exec()) {
            QMessageBox::information(this, "Success", "Player's transfer fee updated successfully!\n"
                                                      "Please reload the table");
            ui -> playerNameComboBox -> removeItem(ui -> playerNameComboBox -> currentIndex());
        }

        else {
            QMessageBox::critical(this, "Error", "Could not update player's transfer fee!" + query.lastError().text());
            return;
        }
    }

    else {
        QMessageBox::critical(this, "Error", "Invalid selection");
        return;
    }
}

void EditTransferList::on_playerNameComboBox_currentTextChanged(const QString &playerInfo)
{
    // display other features different according to playerInfo selected
    QStringList infoParts = playerInfo.split(" - ");

    if (infoParts.size() > 1) {
        int playerShirtNumber = infoParts.at(0).toInt();

        // set database and query
        QSqlDatabase db = QSqlDatabase::database("DB1");
        QSqlQuery query(db);

        query.prepare("SELECT TransferFee FROM TransferList WHERE ShirtNumber = :shirtNumber");
        query.bindValue(":shirtNumber", playerShirtNumber);

        if (query.exec() && query.next()) {
            int transferFee = query.value(0).toInt();
            ui -> transferFeeEdit -> setText(QString::number(transferFee));
        }

        else {
            qDebug() << "Query execution failed!" << query.lastError();
        }
    }
}
