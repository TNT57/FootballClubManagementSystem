#include "tst_addplayer.h"

TestAddPlayer::TestAddPlayer()
{
    addPlayer = new AddPlayer();
}

TestAddPlayer::~TestAddPlayer()
{
    delete addPlayer;
}

void TestAddPlayer::initTestCase()
{
    // Initialization before running tests
}

void TestAddPlayer::cleanupTestCase()
{
    // Cleanup after running tests
}

void TestAddPlayer::test_validateInput()
{
    // Test normal case
    addPlayer->ui->shirtLineEdit->setText("122");
    addPlayer->ui->positionComboBox->setCurrentText("GK");
    addPlayer->ui->nameLineEdit->setText("John Doe");
    addPlayer->ui->appLineEdit->setText("10");
    addPlayer->ui->goalLineEdit->setText("5");
    addPlayer->ui->assistLineEdit->setText("3");
    addPlayer->ui->passLineEdit->setText("50");
    addPlayer->ui->tackleLineEdit->setText("20");
    addPlayer->ui->dribbleLineEdit->setText("30");
    addPlayer->ui->yellowLineEdit->setText("2");
    addPlayer->ui->redLineEdit->setText("1");
    addPlayer->ui->savePer90LineEdit->setText("2");
    addPlayer->ui->cleanSheet->setText("3");
    addPlayer->ui->saveRateLineEdit->setText("70");
    QVERIFY(!addPlayer->validateInput());

    // Test case where goals, assists and apps are not integers
    addPlayer->ui->shirtLineEdit->setText("124");
    addPlayer->ui->positionComboBox->setCurrentText("GK");
    addPlayer->ui->nameLineEdit->setText("John Doe");
    addPlayer->ui->goalLineEdit->setText("not an integer");
    addPlayer->ui->assistLineEdit->setText("not an integer");
    addPlayer->ui->appLineEdit->setText("not an integer");
    addPlayer->ui->passLineEdit->setText("50");
    addPlayer->ui->tackleLineEdit->setText("20");
    addPlayer->ui->dribbleLineEdit->setText("30");
    addPlayer->ui->yellowLineEdit->setText("2");
    addPlayer->ui->redLineEdit->setText("1");
    addPlayer->ui->savePer90LineEdit->setText("2");
    addPlayer->ui->cleanSheet->setText("3");
    addPlayer->ui->saveRateLineEdit->setText("70");
    QVERIFY(!addPlayer->validateInput());

    // Test case where a line is left blank
    addPlayer->ui->shirtLineEdit->setText("125");
    addPlayer->ui->positionComboBox->setCurrentText("GK");
    addPlayer->ui->nameLineEdit->setText("");
    addPlayer->ui->appLineEdit->setText("10");
    addPlayer->ui->goalLineEdit->setText("5");
    addPlayer->ui->assistLineEdit->setText("3");
    addPlayer->ui->passLineEdit->setText("50");
    addPlayer->ui->tackleLineEdit->setText("20");
    addPlayer->ui->dribbleLineEdit->setText("30");
    addPlayer->ui->yellowLineEdit->setText("2");
    addPlayer->ui->redLineEdit->setText("1");
    addPlayer->ui->savePer90LineEdit->setText("2");
    addPlayer->ui->cleanSheet->setText("3");
    addPlayer->ui->saveRateLineEdit->setText("70");
    QVERIFY(!addPlayer->validateInput());

    // Test case where user types a negative number in one of the statistics
    addPlayer->ui->shirtLineEdit->setText("126");
    addPlayer->ui->positionComboBox->setCurrentText("GK");
    addPlayer->ui->nameLineEdit->setText("John Doe");
    addPlayer->ui->goalLineEdit->setText("-5");
    addPlayer->ui->assistLineEdit->setText("3");
    addPlayer->ui->passLineEdit->setText("50");
    addPlayer->ui->tackleLineEdit->setText("20");
    addPlayer->ui->dribbleLineEdit->setText("30");
    addPlayer->ui->yellowLineEdit->setText("2");
    addPlayer->ui->redLineEdit->setText("1");
    addPlayer->ui->savePer90LineEdit->setText("2");
    addPlayer->ui->cleanSheet->setText("3");
    addPlayer->ui->saveRateLineEdit->setText("70");
    QVERIFY(!addPlayer->validateInput());

    // Test case where user chooses a shirt number that's the same as an old one
    addPlayer->ui->positionComboBox->setCurrentText("GK");
    addPlayer->ui->nameLineEdit->setText("John Doe");
    addPlayer->ui->goalLineEdit->setText("-5");
    addPlayer->ui->assistLineEdit->setText("3");
    addPlayer->ui->passLineEdit->setText("50");
    addPlayer->ui->tackleLineEdit->setText("20");
    addPlayer->ui->dribbleLineEdit->setText("30");
    addPlayer->ui->yellowLineEdit->setText("2");
    addPlayer->ui->redLineEdit->setText("1");
    addPlayer->ui->savePer90LineEdit->setText("2");
    addPlayer->ui->cleanSheet->setText("3");
    addPlayer->ui->saveRateLineEdit->setText("70");
    addPlayer->ui->shirtLineEdit->setText("123");
    QVERIFY(!addPlayer->validateInput());
}
//QTEST_MAIN(TestAddPlayer)
//#include "tst_addplayer.moc"
