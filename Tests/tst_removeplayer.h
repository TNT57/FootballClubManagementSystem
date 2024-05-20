#ifndef TST_REMOVEPLAYER_H
#define TST_REMOVEPLAYER_H

#include <QtTest>
#include "../removeplayer.h"
#include "../ui_removeplayer.h"

class TestRemovePlayer : public QObject
{
    Q_OBJECT

public:
    TestRemovePlayer();
    ~TestRemovePlayer();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_populatePlayers();
    void test_on_confirmButton_clicked();

private:
    RemovePlayer *removePlayer;
};

#endif // TST_REMOVEPLAYER_H
