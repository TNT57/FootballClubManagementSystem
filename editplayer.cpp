#include "editplayer.h"
#include "ui_editplayer.h"

EditPlayer::EditPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EditPlayer)
{
    ui->setupUi(this);
    loadPlayer();
    QStringList positions = {"CF", "RW", "LW", "CAM", "CM", "CDM", "LB", "CB", "RB", "GK"};
    ui->positionComboBox->addItems(positions);
    loadPlayerPosition();
}
void EditPlayer::loadPlayerPosition(){
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);
    query.prepare("SELECT Position FROM Player ORDER BY ShirtNumber LIMIT 1");
    if (query.exec() && query.next()) {
        // take the position that match the shirt number
        ui->positionComboBox->setCurrentText(query.value("Position").toString());
    } else {
        QMessageBox::critical(this, "Load error", "Failed to load initial player position");
    }
}
void EditPlayer::loadPlayer(){
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);
    query.prepare("SELECT ShirtNumber FROM Player ORDER BY ShirtNumber");
    if (query.exec()) {
        ui->shirtNumberComboBox->clear();
        while (query.next()) {
            // load the shirt number to the shirt number combo box
            ui->shirtNumberComboBox->addItem(query.value("ShirtNumber").toString());
        }
    } else {
        QMessageBox::critical(this, "Load error", "Failed to load shirt numbers");
    }
}

EditPlayer::~EditPlayer()
{
    delete ui;
}

void EditPlayer::on_shirtNumberComboBox_currentTextChanged(const QString &shirtNumber)
{
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Player WHERE ShirtNumber = :shirtNumber");
    query.bindValue(":shirtNumber", shirtNumber.toInt());
    // set the statistic of player to the line edits
    if (query.exec() && query.next()) {
        ui->nameLineEdit->setText(query.value("Name").toString());
        ui->positionComboBox->setCurrentText(query.value("Position").toString());
        ui->appLineEdit->setText(query.value("Apps").toString());
        ui->goalLineEdit->setText(query.value("Goals").toString());
        ui->assistLineEdit->setText(query.value("Assists").toString());
        ui->passLineEdit->setText(query.value("PassCmpPer90").toString());
        ui->tackleLineEdit->setText(query.value("TacklePer90").toString());
        ui->dribbleLineEdit->setText(query.value("DribblePer90").toString());
        ui->yellowLineEdit->setText(query.value("YellowCard").toString());
        ui->redLineEdit->setText(query.value("RedCard").toString());
        ui->savePer90LineEdit->setText(query.value("SavePer90").toString());
        ui->cleanSheetLineEdit->setText(query.value("CleanSheet").toString());
        ui->saveRateLineEdit->setText(query.value("SavePercentage").toString());
        // If the player is a goalkeeper, enable the goalkeeper stats line edits
        if (ui->positionComboBox->currentText() == "GK") {
            ui->savePer90LineEdit->show();
            ui->cleanSheetLineEdit->show();
            ui->saveRateLineEdit->show();
            ui->savePer90LineEdit->setText(query.value("SavePer90").toString());
            ui->cleanSheetLineEdit->setText(query.value("CleanSheet").toString());
            ui->saveRateLineEdit->setText(query.value("SavePercentage").toString());
        } else {
            ui->savePer90LineEdit->hide();
            ui->cleanSheetLineEdit->hide();
            ui->saveRateLineEdit->hide();
        }
    } else {
        QMessageBox::critical(this, "Load error", "Failed to load player data");
    }
}




void EditPlayer::on_confirmButton_clicked()
{
    if (validateInput()) {
        QSqlDatabase db = QSqlDatabase::database("DB1");
        QSqlQuery query(db);
        // update the database based on the input of user
        query.prepare("UPDATE Player SET ShirtNumber = :newShirtNumber, Position = :position, Name = :name, Apps = :app, Goals = :goal, Assists = :assist, PassCmpPer90 = :passPer90, TacklePer90 = :tacklePer90, DribblePer90 = :dribblePer90, YellowCard = :yellow, RedCard = :red, SavePer90 = :savePer90, CleanSheet = :cleanSheet, SavePercentage = :saveRate WHERE ShirtNumber = :oldShirtNumber");
        query.bindValue(":oldShirtNumber", ui->shirtNumberComboBox->currentText().toInt());
        query.bindValue(":newShirtNumber", ui->newShirtNumberLineEdit->text().isEmpty() ? ui->shirtNumberComboBox->currentText().toInt() : ui->newShirtNumberLineEdit->text().toInt());
        query.bindValue(":name", ui->nameLineEdit->text());
        query.bindValue(":position", ui->positionComboBox->currentText());
        query.bindValue(":app", ui->appLineEdit->text().toInt());
        query.bindValue(":goal", ui->goalLineEdit->text().toInt());
        query.bindValue(":assist", ui->assistLineEdit->text().toInt());
        query.bindValue(":passPer90", ui->passLineEdit->text().toDouble());
        query.bindValue(":tacklePer90", ui->tackleLineEdit->text().toDouble());
        query.bindValue(":dribblePer90", ui->dribbleLineEdit->text().toDouble());
        query.bindValue(":yellow", ui->yellowLineEdit->text().toInt());
        query.bindValue(":red", ui->redLineEdit->text().toInt());
        query.bindValue(":savePer90", ui->savePer90LineEdit->text().toDouble());
        query.bindValue(":cleanSheet", ui->cleanSheetLineEdit->text().toInt());
        query.bindValue(":saveRate", ui->saveRateLineEdit->text().toDouble());
        if (!query.exec()) {
            QMessageBox::critical(this, "Update error", "Failed to update player data");
            return;
        }

        if (ui->positionComboBox->currentText() != "GK") {
            QSqlQuery query(db);
            query.prepare("UPDATE Player SET SavePer90 = NULL, CleanSheet = NULL, SavePercentage = NULL WHERE ShirtNumber = :oldShirtNumber");
            query.bindValue(":oldShirtNumber", ui->shirtNumberComboBox->currentText().toInt());
            if (!query.exec()) {
                QMessageBox::critical(this, "Update error", "Failed to update player data");
                return;
            }
        }

        QMessageBox::information(this, "Update successful", "Player data updated successfully");
    }
}

bool EditPlayer::validateInput(){
    int oldShirtNumber = ui->shirtNumberComboBox->currentText().toInt();
    QString newShirtNumberText = ui->newShirtNumberLineEdit->text();
    // check the input of new shirt number
    if (!newShirtNumberText.isEmpty()) {
        bool ok;
        int newShirtNumber = newShirtNumberText.toInt(&ok);
        if (newShirtNumber <= 0 || newShirtNumber == oldShirtNumber||!ok) {
            QMessageBox::warning(this, "Input error", "New shirt number must be a positive integer and different from the old shirt number");
            return false;
        }
    }
    QString position = ui->positionComboBox->currentText();
    QString app = ui->appLineEdit->text();
    QString goal = ui->goalLineEdit->text();
    QString assist = ui->assistLineEdit->text();
    QString cleanSheet;
    QString passPer90 = ui->passLineEdit->text();
    QString tacklePer90 = ui->tackleLineEdit->text();
    QString dribblePer90 = ui->dribbleLineEdit->text();
    QString yellow = ui->yellowLineEdit->text();
    QString red = ui->redLineEdit->text();
    QString savePer90;
    QString saveRate;
    // all stats must be filled
    QStringList stats = {app, goal, assist, yellow, red, passPer90, tacklePer90, dribblePer90};
    if (ui->positionComboBox->currentText() == "GK"){
        cleanSheet = ui->cleanSheetLineEdit->text();
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
    // check the input of goal, assist, apps, clean sheet
    bool ok;
    QStringList positiveIntegers = {app, goal, assist, yellow, red};
    if (position == "GK"){
        cleanSheet = ui->cleanSheetLineEdit->text();
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

    // check the input for other stats
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

void EditPlayer::on_positionComboBox_currentTextChanged(const QString &position)
{
    // show specific stat of gk if position is gk
    if (position == "GK") {
        ui->savePer90LineEdit->show();
        ui->cleanSheetLineEdit->show();
        ui->saveRateLineEdit->show();
        ui->label_12->show();
        ui->label_13->show();
        ui->label_14->show();
    } else {
        ui->savePer90LineEdit->hide();
        ui->cleanSheetLineEdit->hide();
        ui->saveRateLineEdit->hide();
        ui->label_12->hide();
        ui->label_13->hide();
        ui->label_14->hide();
    }
}
