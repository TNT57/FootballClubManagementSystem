#ifndef TST_ADDPLAYER_H
#define TST_ADDPLAYER_H

#include <QObject>
#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QtTest>
#include "../addplayer.h"
#include "../ui_addplayer.h"

class TestAddPlayer : public QObject
{
    Q_OBJECT

public:
    TestAddPlayer();
    ~TestAddPlayer();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_validateInput();

private:
    AddPlayer *addPlayer;
};

#endif // TST_ADDPLAYER_H
