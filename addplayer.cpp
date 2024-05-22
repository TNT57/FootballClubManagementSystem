#include "addplayer.h"
#include "ui_addplayer.h"

AddPlayer::AddPlayer(QWidget *parent): QWidget(parent), ui(new Ui::AddPlayer) {
    // Hide the GK stat line edits initially
    ui -> setupUi(this);
    ui -> savePer90LineEdit -> hide();
    ui -> cleanSheet -> hide();
    ui -> saveRateLineEdit -> hide();
    ui -> label_12 -> hide();
    ui -> label_13 -> hide();
    ui -> label_14 -> hide();

    //Set up stylesheet for info label
    // Set the size of the label to be a square
    ui -> infoLabel -> setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui -> infoLabel -> setStyleSheet("QLabel {"
                                     "border: 1px solid black;"
                                     "border-radius: 15px;" // Half of width/height
                                     "}");

}

AddPlayer::~AddPlayer() {
    qDebug() << "~AddPlayer";
    delete ui;
}

void AddPlayer::on_confirmButton_clicked() {
    // validate before consider add as successful
    if (validateInput() == false) {
        return;
    }

    //initialise variable to store the text typed by user
    QString shirtNumber = ui -> shirtLineEdit -> text();
    QString position = ui -> positionComboBox -> currentText();
    QString name = ui -> nameLineEdit -> text();
    QString app = ui -> appLineEdit -> text();
    QString goal = ui -> goalLineEdit -> text();
    QString assist = ui -> assistLineEdit -> text();
    QString passPer90 = ui -> passLineEdit -> text();
    QString tacklePer90 = ui -> tackleLineEdit -> text();
    QString dribblePer90 = ui -> dribbleLineEdit -> text();
    QString yellow = ui -> yellowLineEdit -> text();
    QString red = ui -> redLineEdit -> text();
    QString savePer90, cleanSheet, saveRate;

    // store the specific stats of the goalkeeper
    if (position == "GK") {
        savePer90 = ui -> savePer90LineEdit -> text();
        cleanSheet = ui -> cleanSheet -> text();
        saveRate = ui -> saveRateLineEdit -> text();
    }

    // initialize database and query method to take data from the database
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);

    // player statistic add to the Player database
    query.prepare("INSERT INTO Player(ShirtNumber, Position, Name, Apps, Goals, Assists, PassCmpPer90, TacklePer90, DribblePer90, YellowCard, RedCard, SavePer90, CleanSheet, SavePercentage) "
                  "VALUES('"+shirtNumber+"', '"+position+"', '"+name+"', '"+app+"', '"+goal+"', '"+assist+"', '"+passPer90+"', '"+tacklePer90+"', '"+dribblePer90+"', '"+yellow+"', '"+red+"', '"+savePer90+"', '"+cleanSheet+"', '"+saveRate+"')");
    query.exec();
    query.finish();
    query.clear();

    // confirm that user has add player succesfully to the database
    QMessageBox::information(this, "Note", "Added succesfully!\n"
                                           "Please reload the player table");

    // clear the text in the line after user add player successfully
    ui -> shirtLineEdit -> clear();
    ui -> appLineEdit -> clear();
    ui -> nameLineEdit -> clear();
    ui -> assistLineEdit -> clear();
    ui -> dribbleLineEdit -> clear();
    ui -> passLineEdit -> clear();
    ui -> tackleLineEdit -> clear();
    ui -> yellowLineEdit -> clear();
    ui -> redLineEdit -> clear();
    ui -> savePer90LineEdit -> clear();
    ui -> cleanSheet -> clear();
    ui -> saveRateLineEdit -> clear();
    ui -> goalLineEdit -> clear();
}

bool AddPlayer::validateInput() {
    QString shirtNumber = ui -> shirtLineEdit -> text();
    QString position = ui -> positionComboBox -> currentText();
    QString app = ui -> appLineEdit -> text();
    QString goal = ui -> goalLineEdit -> text();
    QString assist = ui -> assistLineEdit -> text();
    QString yellow = ui -> yellowLineEdit -> text();
    QString red = ui -> redLineEdit -> text();
    QString cleanSheet;
    QString passPer90 = ui -> passLineEdit -> text();
    QString tacklePer90 = ui -> tackleLineEdit -> text();
    QString dribblePer90 = ui -> dribbleLineEdit -> text();
    QString savePer90;
    QString saveRate;

    // check if all lines has be filled or not
    QStringList stats = {app, goal, assist, yellow, red, passPer90, tacklePer90, dribblePer90};

    if (ui -> positionComboBox -> currentText() == "GK") {
        cleanSheet = ui -> cleanSheet -> text();
        savePer90 = ui -> savePer90LineEdit -> text();
        saveRate = ui -> saveRateLineEdit -> text();
        stats << cleanSheet << savePer90 << saveRate;
    }

    // print the warning if user missing a stat
    for (const QString &stat: stats) {
        if (stat.trimmed().isEmpty()) {
            QMessageBox::warning(this, "Input error", "All stats fields must be filled");
            return false;
        }
    }

    // check if shirt number is a positive integer
    bool ok;
    int shirtNumberValue = shirtNumber.toInt(&ok);

    if (ok && shirtNumberValue > 0) {
        qDebug() << "The input is a positive integer: " << shirtNumberValue;
    }

    else {
        QMessageBox::critical(this, "Invalid input", "Shirt number must be a positive integer.");
        return false;
    }

    // check if shirt number is already taken or not
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);

    query.prepare("SELECT ShirtNumber FROM Player");
    query.exec();

    while (query.next()) {
        QString existedShirtNumber = query.value(0).toString();

        if (shirtNumber == existedShirtNumber) {
            QMessageBox::critical(this, "Error", "This shirt number is already existed!");
            query.finish();
            query.clear();
            return false;
        }

        if (shirtNumberValue > 99) {
            QMessageBox::critical(this, "Invalid input", "Shirt number must be less than 100.");
            return false;
        }
    }

    // Check if App, Goal, Assist, CleanSheet is all positive integer numbers
    QStringList positiveIntegers = {app, goal, assist, red, yellow};

    if (position == "GK") {
        cleanSheet = ui -> cleanSheet -> text();
        positiveIntegers << cleanSheet;
    }

    for (const QString &str : positiveIntegers) {
        int num = str.toInt(&ok);

        if (ok && num >= 0) {
            qDebug() << "The input is >= 0: " << num;
        }

        else {
            QMessageBox::critical(this, "Invalid Input", "App, Goal, Assist, and CleanSheet must be >= 0");
            return false;
        }
    }

    // check if other stats is positive numbers
    QStringList positiveNumbers = {passPer90, tacklePer90, dribblePer90};

    if (position == "GK") {
        savePer90 = ui -> savePer90LineEdit -> text();
        saveRate = ui -> saveRateLineEdit -> text();
        positiveNumbers << savePer90 << saveRate;
    }

    for (const QString &str : positiveNumbers) {
        double num = str.toDouble(&ok);

        if (ok && num >= 0) {
            qDebug() << "The input is >= 0: " << num;
        }

        else {
            QMessageBox::critical(this, "Invalid Input", "PassPer90, TacklePer90, DribblePer90, SavePer90, and SaveRate must be >= 0");
            return false;
        }
    }

    return true;
}


void AddPlayer::on_positionComboBox_currentTextChanged(const QString &position) {
    // show the specific stats of gk on the ui if user choose gk
    if (position == "GK") {
        ui -> savePer90LineEdit -> show();
        ui -> cleanSheet -> show();
        ui -> saveRateLineEdit -> show();
        ui -> label_12 -> show();
        ui -> label_13 -> show();
        ui -> label_14 -> show();
    }

    else {
        ui -> savePer90LineEdit -> hide();
        ui -> cleanSheet -> hide();
        ui -> saveRateLineEdit -> hide();
        ui -> label_12 -> hide();
        ui -> label_13 -> hide();
        ui -> label_14 -> hide();
    }
}

