#include "tst_removeplayer.h"

TestRemovePlayer::TestRemovePlayer()
{
    removePlayer = new RemovePlayer();
}

TestRemovePlayer::~TestRemovePlayer()
{
    delete removePlayer;
}

void TestRemovePlayer::initTestCase()
{
    // Initialization before executing test cases
}

void TestRemovePlayer::cleanupTestCase()
{
    // Clean-up after all test cases are executed
}

void TestRemovePlayer::test_populatePlayers()
{
    // Test case: Check if populatePlayers function loads players into the combo box
    // This test case involves database operations

    // 1. Set up the database and insert a known player with all his statistics
    QSqlDatabase database = QSqlDatabase::database("DB1"); // Get the database.

    QSqlQuery query(database);
    query.exec("INSERT INTO Player (ShirtNumber, Position, Name, Goals, Apps, Assists, PassCmpPer90, TacklePer90, DribblePer90, YellowCard, RedCard) VALUES (1000, 'CAM', 'Test Player', 10, 20, 10, 10, 10, 10, 2, 1)");

    // 2. Call removePlayer->populatePlayers()
    removePlayer->populatePlayers();

    // 3. Check if the combo box contains the player you inserted into the database
    bool containsInsertedPlayer = false;
    for(int i = 0; i < removePlayer->ui->playerNameComboBox->count(); i++)
    {
        if(removePlayer->ui->playerNameComboBox->itemText(i) == "1000 - Test Player")
        {
            containsInsertedPlayer = true;
            break;
        }
    }
    QCOMPARE(containsInsertedPlayer, true);

    // 4. Clean up the database
    query.exec("DELETE FROM Player WHERE ShirtNumber = 1000");
}

void TestRemovePlayer::test_on_confirmButton_clicked()
{
    // Test case: Check if on_confirmButton_clicked function removes the selected player
    // This test case involves database operations

    // 1. Set up the database and insert a known player with all his statistics
    QSqlDatabase database = QSqlDatabase::database("DB1"); // Get the database.

    QSqlQuery query(database);
    query.exec("INSERT INTO Player (ShirtNumber, Position, Name, Goals, Apps, Assists, PassCmpPer90, TacklePer90, DribblePer90, YellowCard, RedCard) VALUES (1000, 'CAM', 'Test Player', 10, 20, 10, 10, 10, 10, 2, 1)");

    // 2. Set the current text of the combo box to the player you inserted
    removePlayer->ui->playerNameComboBox->setCurrentText("1000 - Test Player");

    // 3. Call removePlayer->on_confirmButton_clicked()
    removePlayer->on_confirmButton_clicked();

    // 4. Check if the player is removed from the database
    query.prepare("SELECT * FROM Player WHERE ShirtNumber = 1000");
    query.exec();
    bool playerRemoved = !query.next();
    QCOMPARE(playerRemoved, true);
}
