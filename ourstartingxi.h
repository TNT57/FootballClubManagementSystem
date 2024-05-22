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

class OurStartingXI: public StartingList {
    public:
        OurStartingXI(); // constructor
        void choosePlayer(); // pop up Choose Our XI UI
        void loadOurXI(); // load chosen Our XI to the UI
        void reloadPlayer(); // reload UI
        ~OurStartingXI(); // destructor

    private:
        QSqlQueryModel *model; // pointer for model
        ChooseOurXI *ptrChooseOurXI; // pointer for ChooseOutXI
};

#endif // OURSTARTINGXI_H
