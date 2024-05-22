#ifndef STARTINGLIST_H
#define STARTINGLIST_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QTableView>

namespace Ui {
    class StartingList;
}

class StartingList: public QWidget {
    Q_OBJECT

    public:
        explicit StartingList(QWidget *parent = nullptr); // constructor
        virtual void choosePlayer() = 0; // virtual function for choose XI (our and opponent team)
        virtual void reloadPlayer() = 0; // virtual function for reload XI (our and opponent team)
        ~StartingList(); // destructor

    private slots:
        void on_chooseStartingButton_clicked(); // pop up choose starting XI
        void on_reloadButton_clicked(); // reload starting XI

    protected:
        Ui::StartingList *ui; // pointer for the UI
        QSqlDatabase database; // database
};

#endif // STARTINGLIST_H
