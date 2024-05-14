#include "addplayer.h"
#include "ui_addplayer.h"

AddPlayer::AddPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddPlayer)
{
    // Hide the GK stat line edits initially
    ui->setupUi(this);
    ui->savePer90LineEdit -> hide();
    ui->cleanSheet->hide();
    ui->saveRateLineEdit->hide();
    ui->label_12->hide();
    ui->label_13->hide();
    ui->label_14->hide();
}

AddPlayer::~AddPlayer()
{
    qDebug() << "~AddPlayer";
    delete ui;
}


void AddPlayer::on_confirmButton_clicked()
{
    if (validateInput() == false ) {
        return;
    }
    QString shirtNumber = ui->shirtLineEdit->text();
    QString position = ui->positionComboBox->currentText();
    QString name = ui->nameLineEdit->text();
    QString app = ui->appLineEdit->text();
    QString goal = ui->goalLineEdit->text();
    QString assist = ui->assistLineEdit->text();
    QString passPer90 = ui->passLineEdit->text();
    QString tacklePer90 = ui->tackleLineEdit->text();
    QString dribblePer90 = ui->dribbleLineEdit->text();
    QString yellow = ui->yellowLineEdit->text();
    QString red = ui->redLineEdit->text();
    QString savePer90, cleanSheet, saveRate;

    if (position == "GK"){
        savePer90 = ui->savePer90LineEdit->text();
        cleanSheet = ui->cleanSheet->text();
        saveRate = ui->savePer90LineEdit->text();
    }
    // initialize database and query method to take data from the database
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);
    query.prepare("insert into Player(ShirtNumber, Position, Name, Apps, Goals, Assists, PassCmpPer90, TacklePer90, DribblePer90, YellowCard, RedCard, SavePer90, CleanSheet, SavePercentage) "
                  "values('"+shirtNumber+"', '"+position+"', '"+name+"', '"+app+"', '"+goal+"', '"+assist+"', '"+passPer90+"', '"+tacklePer90+"', '"+dribblePer90+"', '"+yellow+"', '"+red+"', '"+savePer90+"', '"+cleanSheet+"', '"+saveRate+"')");
    query.exec();
    query.finish();
    query.clear();
    QMessageBox::information(this, "Note", "Added succesfully!");
}
bool AddPlayer::validateInput() {
    QString shirtNumber = ui->shirtLineEdit->text();
    QString position = ui->positionComboBox->currentText();
    QString app = ui->appLineEdit->text();
    QString goal = ui->goalLineEdit->text();
    QString assist = ui->assistLineEdit->text();
    QString yellow = ui->yellowLineEdit->text();
    QString red = ui->redLineEdit->text();
    QString cleanSheet;
    QString passPer90 = ui->passLineEdit->text();
    QString tacklePer90 = ui->tackleLineEdit->text();
    QString dribblePer90 = ui->dribbleLineEdit->text();
    QString savePer90;
    QString saveRate;

    // all lines must be filled
    QStringList stats = {app, goal, assist, yellow, red, passPer90, tacklePer90, dribblePer90};
     if (ui->positionComboBox->currentText() == "GK"){
        cleanSheet = ui->cleanSheet->text();
        savePer90 = ui->savePer90LineEdit->text();
        saveRate = ui->saveRateLineEdit->text();
        stats << cleanSheet<< savePer90 << saveRate;
    }
    for (const QString &stat : stats){
        if (stat.trimmed().isEmpty()){
            QMessageBox::warning(this, "Input error", "All stats fields must be filled");
            return false;
        }
    }
    // ShirtNumber should be unique and integer only
    bool ok;
    int shirtNumberValue = shirtNumber.toInt(&ok);
    if (ok && shirtNumberValue > 0) {
        qDebug() << "The input is a positive integer: " << shirtNumberValue;
    } else {
         QMessageBox::critical(this, "Invalid input", "Shirt number must be a positive integer.");
        return false;
    }

    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);
    query.prepare("select ShirtNumber from Player");
    query.exec();
    while (query.next()){
        QString existedShirtNumber = query.value(0).toString();
        if(shirtNumber == existedShirtNumber){
            QMessageBox::critical(this, "Error", "This shirt number is already existed!");
            query.finish();
            query.clear();
            return false;
        }
    }

    // App, Goal, Assist, CleanSheet must be positive integer numbers
    QStringList positiveIntegers = {app, goal, assist, red, yellow};
    if (position == "GK"){
        cleanSheet = ui->cleanSheet->text();
        positiveIntegers << cleanSheet;
    }
    for (const QString &str : positiveIntegers) {
        int num = str.toInt(&ok);
       if (ok && num >= 0){
             qDebug() << "The input is a positive integer: " << num;
       } else {
            QMessageBox::critical(this, "Invalid Input", "App, Goal, Assist, and CleanSheet must be positive integers");
            return false;
        }
    }

    // Other stats just need to be positive numbers
    QStringList positiveNumbers = {passPer90, tacklePer90, dribblePer90};
    if (position == "GK") {
        savePer90 = ui->savePer90LineEdit->text();
        saveRate = ui->saveRateLineEdit->text();
        positiveNumbers << savePer90 << saveRate;
    }
    for (const QString &str : positiveNumbers) {
        double num = str.toDouble(&ok);
        if (ok && num >= 0){
            qDebug() << "The input is a positive number: " << num;
        } else {
            QMessageBox::critical(this, "Invalid Input", "PassPer90, TacklePer90, DribblePer90, SavePer90, and SaveRate must be positive numbers");
            return false;
        }
    }


    return true;
}


void AddPlayer::on_positionComboBox_currentTextChanged(const QString &position)
{
    // show the specific stat of gk if user choose gk
    if (position == "GK"){
        ui->savePer90LineEdit->show();
        ui->cleanSheet->show();
        ui->saveRateLineEdit->show();
        ui->label_12->show();
        ui->label_13->show();
        ui->label_14->show();
    } else {
        ui->savePer90LineEdit -> hide();
        ui->cleanSheet->hide();
        ui->saveRateLineEdit->hide();
        ui->label_12->hide();
        ui->label_13->hide();
        ui->label_14->hide();
    }
}

