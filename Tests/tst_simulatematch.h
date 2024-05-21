#ifndef TESTSIMULATEMATCH_H
#define TESTSIMULATEMATCH_H

#include <QObject>
#include <QtTest>
#include "../simulatematch.h"
#include "../ui_simulatematch.h"

class TestSimulateMatch : public QObject
{
    Q_OBJECT

public:
    TestSimulateMatch();
   ~TestSimulateMatch();

private slots:
    void test_checkNumPlayers();
    void test_simulate();

private:
    SimulateMatch *simulateMatch;

};
#endif // TESTSIMULATEMATCH_H
