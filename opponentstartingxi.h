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

class OpponentStartingXI: public StartingList {
    public:
        OpponentStartingXI(QString opponentName); // constructor with given opponentName
        void choosePlayer(); // pop up Choose Opponent XI
        void loadOpponentXI(); // load chosen Opponent XI to the UI
        void reloadPlayer(); // reload UI
        ~OpponentStartingXI(); // destructor

        QString get_opponentName(); // getter for opponentName
        void set_opponentName(QString opponentName); // setter for opponentName

    private:
        QSqlQueryModel *model; // pointer for model
        ChooseOpponentXI *ptrChooseOpponentXI; // pointer for ChooseOpponentXI
        QString opponentName;
};

#endif // OPPONENTSTARTINGXI_H
