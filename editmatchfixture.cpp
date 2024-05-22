#include "editmatchfixture.h"
#include "ui_editmatchfixture.h"

EditMatchFixture::EditMatchFixture(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EditMatchFixture)
{
    ui->setupUi(this);
    populateDate();
    populateOpponentName();
}

EditMatchFixture::~EditMatchFixture()
{
    delete ui;
}

void EditMatchFixture::populateDate() {
    QSqlDatabase db = QSqlDatabase::database("DB1"); // set database

    //Check if database is open
    if (!db.isOpen()) {
        qDebug() << "Database connection failed: ";
        return;
    }

    QSqlQuery query(db);

    if (!query.exec("SELECT Date FROM MatchRecord")) {
        qDebug() << "Query execution failed: " << query.lastError();
        return;
    }

    while (query.next()) {
        QString date = query.value(0).toString();
        ui -> matchDayComboBox -> addItem(date);
    }
}

void EditMatchFixture::populateOpponentName() {
    QSqlDatabase db = QSqlDatabase::database("DB1"); // set database

    //Check if database is open
    if (!db.isOpen()) {
        qDebug() << "Database connection failed: ";
        return;
    }

    QSqlQuery query(db);

    if (!query.exec("SELECT DISTINCT OpponentName FROM MatchRecord")) {
        qDebug() << "Query execution failed: " << query.lastError();
        return;
    }

    while (query.next()) {
        QString opponentName = query.value(0).toString();
        ui -> opponentNameComboBox -> addItem(opponentName);
    }
}

void EditMatchFixture::on_confirmButton_clicked()
{
    QString date = ui -> matchDayComboBox -> currentText();
    QString time = ui -> timeEdit -> text();
    QString opponentName = ui -> opponentNameComboBox -> currentText();
    QString location = ui -> locationEdit -> text();

    QSqlDatabase db = QSqlDatabase::database("DB1"); // set database

    //Check if database is open
    if (!db.isOpen()) {
        qDebug() << "Database connection failed: ";
        return;
    }

    QSqlQuery query(db);

    // Prepare the query to update the match details for the selected date
    query.prepare("UPDATE MatchRecord SET Time = :time, OpponentName = :opponentName, Location = :location WHERE Date = :date");
    query.bindValue(":time", time);
    query.bindValue(":opponentName", opponentName);
    query.bindValue(":location", location);
    query.bindValue(":date", date);

    if (!query.exec()) {
        qDebug() << "Query execution failed: " << query.lastError();
        return;
    }

    QMessageBox::information(this, "Update successful", "The match details have been updated successfully.");

}


void EditMatchFixture::on_matchDayComboBox_currentTextChanged(const QString &date)
{
    QSqlDatabase db = QSqlDatabase::database("DB1"); // set database

    //Check if database is open
    if (!db.isOpen()) {
        qDebug() << "Database connection failed: ";
        return;
    }

    QSqlQuery query(db);

    // Prepare the query to fetch the match details for the selected date
    query.prepare("SELECT Time, OpponentName, Location FROM MatchRecord WHERE Date = :date");
    query.bindValue(":date", date);

    if (!query.exec()) {
        qDebug() << "Query execution failed: " << query.lastError();
        return;
    }

    while (query.next()) {
        // Update the displayed time, opponentName, and location with the fetched data
        QTime time = QTime::fromString(query.value(0).toString(), "h:mm AP");
        QString opponentName = query.value(1).toString();
        QString location = query.value(2).toString();

        ui->timeEdit->setTime(time);
        ui->opponentNameComboBox->setCurrentText(opponentName);
        ui->locationEdit->setText(location);
    }
}

