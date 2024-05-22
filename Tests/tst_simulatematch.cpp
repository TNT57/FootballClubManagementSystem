#include <QtTest>
#include "tst_simulatematch.h"

TestSimulateMatch :: TestSimulateMatch()
{
    simulateMatch = new SimulateMatch();

}

TestSimulateMatch ::~TestSimulateMatch()
{
    delete simulateMatch;
}

void TestSimulateMatch::test_simulate()
{
    SimulateMatch match;
    // choose the opponent team
    match.set_opponentName("Arsenal");

    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);
    // select the first 11 players from our team
    query.prepare("UPDATE Player SET Selected = 1 LIMIT 11");
    if (!query.exec()) {
        qDebug() << "Failed to select players: ";
    }

    // Select the first 11 players in the opponent team (Arsenal)
    query.prepare("UPDATE Arsenal SET Selected = 1 LIMIT 11");
    if (!query.exec()) {
        qDebug() << "Failed to select players: " ;
    }
    // simulate the match
    match.simulate();

    // Check that the goals are positive integers
    bool ok;
    int ourGoals = match.ui->ourGoals->text().toInt(&ok);
    QVERIFY(ok && ourGoals >= 0);

    int opponentGoals = match.ui->opponentGoals->text().toInt(&ok);
    QVERIFY(ok && opponentGoals >= 0);;
    query.prepare("UPDATE Player SET Selected = 0");
    if (!query.exec()) {
        qDebug() << "Failed to unselect players: " ;
    }

    // Unselect the players in the opponent team (Arsenal)
    query.prepare("UPDATE Arsenal SET Selected = 0");
    if (!query.exec()) {
        qDebug() << "Failed to unselect players: ";
    }
}

//QTEST_MAIN(TestSimulateMatch)
//#include "testsimulatematch.moc"
