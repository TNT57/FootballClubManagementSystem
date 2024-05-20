#ifndef TST_EDITPLAYER_H
#define TST_EDITPLAYER_H

#include <QObject>
#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QtTest>
#include "../editplayer.h"
#include "../ui_editplayer.h"

class TestEditPlayer : public QObject
{
    Q_OBJECT

public:
    TestEditPlayer();
    ~TestEditPlayer();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_on_confirmButton_clicked();


private:
    EditPlayer *editPlayer;
};

#endif // TST_EDITPLAYER_H
