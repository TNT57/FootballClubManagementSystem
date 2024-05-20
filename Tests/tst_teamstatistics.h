#ifndef TST_TEAMSTATISTICS_H
#define TST_TEAMSTATISTICS_H

#include <QtTest>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "../teamstatistics.h"
#include "../ui_teamstatistics.h"

class TestTeamStatistics : public QObject
{
    Q_OBJECT

public:
    TestTeamStatistics();
    ~TestTeamStatistics();


private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_loadPlayerStats();

private:
    TeamStatistics *teamStatistics;
};

#endif // TST_TEAMSTATISTICS_H
