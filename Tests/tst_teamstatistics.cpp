#include "tst_teamstatistics.h"

TestTeamStatistics::TestTeamStatistics()
{
    teamStatistics = new TeamStatistics();
}

TestTeamStatistics::~TestTeamStatistics()
{
    delete teamStatistics;
}

void TestTeamStatistics::initTestCase()
{
    // Initialize the test case
}

void TestTeamStatistics::cleanupTestCase()
{
    // Cleanup the test case
}

void TestTeamStatistics::test_loadPlayerStats()
{
    // Load the player stats
    teamStatistics->loadPlayerStats();

    // Calculate the statistics directly from the database
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);
    query.prepare("SELECT SUM(Goals), SUM(Assists), SUM(YellowCard), SUM(RedCard), AVG(PassCmpPer90), AVG(TacklePer90), AVG(DribblePer90) FROM Player");
    if (!query.exec() || !query.next()) {
        QFAIL("Failed to calculate statistics");
    }
    QString expectedGoals = QString::number(query.value(0).toInt());
    QString expectedAssists = QString::number(query.value(1).toInt());
    QString expectedYellowCards = QString::number(query.value(2).toInt());
    QString expectedRedCards = QString::number(query.value(3).toInt());
    QString expectedPassCmpPer90 = QString::number(query.value(4).toDouble(), 'f', 2);
    QString expectedTacklePer90 = QString::number(query.value(5).toDouble(), 'f', 2);

    // Check that the stats were updated correctly
    QCOMPARE(teamStatistics->ui->goalLabel->text(), expectedGoals);
    QCOMPARE(teamStatistics->ui->assistLabel->text(), expectedAssists);
    QCOMPARE(teamStatistics->ui->yellowLabel->text(), expectedYellowCards);
    QCOMPARE(teamStatistics->ui->redLabel->text(), expectedRedCards);
    QCOMPARE(teamStatistics->ui->passLabel->text(), expectedPassCmpPer90);
    QCOMPARE(teamStatistics->ui->tackleLabel->text(), expectedTacklePer90);
}
