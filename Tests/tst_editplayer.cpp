#include "tst_editplayer.h"

TestEditPlayer::TestEditPlayer()
{
    editPlayer = new EditPlayer();
}

TestEditPlayer::~TestEditPlayer()
{
    delete editPlayer;
}

void TestEditPlayer::initTestCase()
{
    // Initialize the test case
}

void TestEditPlayer::cleanupTestCase()
{
    // Cleanup the test case
}

void TestEditPlayer::test_on_confirmButton_clicked()
{
    // Add a new player
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);
    query.prepare("INSERT INTO Player (ShirtNumber, Position, Name, Apps, Goals, Assists, PassCmpPer90, TacklePer90, DribblePer90, YellowCard, RedCard) VALUES (:shirtNumber, :position, :name, :apps, :goals, :assists, :passCmpPer90, :tacklePer90, :dribblePer90, :yellowCard, :redCard)");
    query.bindValue(":shirtNumber", 99);
     query.bindValue(":position", "CAM");
    query.bindValue(":name", "Test Player");
    query.bindValue(":apps", 0);
    query.bindValue(":goals", 0);
    query.bindValue(":assists", 0);
    query.bindValue(":passCmpPer90", 0);
    query.bindValue(":tacklePer90", 0);
    query.bindValue(":dribblePer90", 0);
    query.bindValue(":yellowCard", 0);
    query.bindValue(":redCard", 0);
    if (!query.exec()) {
        QFAIL("Failed to insert player");
    }

    // Load the player into the combo box
    editPlayer->loadPlayer();
    editPlayer->ui->shirtNumberComboBox->setCurrentText("99");

    // Edit the player's information
    editPlayer->ui->nameLineEdit->setText("Momo");
    editPlayer->ui->appLineEdit->setText("1000");
    editPlayer->ui->goalLineEdit->setText("1000");
    editPlayer->ui->assistLineEdit->setText("1000");
    editPlayer->ui->passLineEdit->setText("1000");
    editPlayer->ui->tackleLineEdit->setText("1000");
    editPlayer->ui->dribbleLineEdit->setText("1000");
    editPlayer->ui->yellowLineEdit->setText("1000");
    editPlayer->ui->redLineEdit->setText("1000");
    editPlayer->on_confirmButton_clicked();

    // Check that the name and statistics were updated correctly
    query.prepare("SELECT * FROM Player WHERE ShirtNumber = :shirtNumber");
    query.bindValue(":shirtNumber", 99);
    if (query.exec() && query.next()) {
        QCOMPARE(query.value("Name").toString(), QString("Momo"));
        QCOMPARE(query.value("Apps").toString(), QString("1000"));
        QCOMPARE(query.value("Goals").toString(), QString("1000"));
        QCOMPARE(query.value("Assists").toString(), QString("1000"));
        QCOMPARE(query.value("PassCmpPer90").toString(), QString("1000"));
        QCOMPARE(query.value("TacklePer90").toString(), QString("1000"));
        QCOMPARE(query.value("DribblePer90").toString(), QString("1000"));
        QCOMPARE(query.value("YellowCard").toString(), QString("1000"));
        QCOMPARE(query.value("RedCard").toString(), QString("1000"));
    } else {
        QFAIL("Failed to load player data");
    }

    // Delete the player
    query.prepare("DELETE FROM Player WHERE ShirtNumber = :shirtNumber");
    query.bindValue(":shirtNumber", 99);
    if (!query.exec()) {
        QFAIL("Failed to delete player");
    }
}
