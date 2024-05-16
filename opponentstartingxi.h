#ifndef OPPONENTSTARTINGXI_H
#define OPPONENTSTARTINGXI_H
#include "startinglist.h"
#include "chooseopponentxi.h"
#include "ui_startinglist.h"
#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

class OpponentStartingXI : public StartingList
{
public:
    OpponentStartingXI(QString opponentName);
    void choosePlayer();
    void loadStartingXI();
    ~OpponentStartingXI();

    void set_opponentName(QString opponentName);

private:
    QSqlQueryModel *model;
    ChooseOpponentXI *ptrChooseOpponentXI;
    QString opponentName;
};

#endif // OPPONENTSTARTINGXI_H
