#ifndef OURSTARTINGXI_H
#define OURSTARTINGXI_H
#include "startinglist.h"
#include "chooseourxi.h"
#include "ui_startinglist.h"

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

class OurStartingXI : public StartingList
{
public:
    OurStartingXI();
    void choosePlayer();
    void loadStartingXI();
    ~OurStartingXI();
private:
    QSqlQueryModel *model;
    ChooseOurXI *ptrChooseOurXI;
};

#endif // OURSTARTINGXI_H
