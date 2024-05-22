#ifndef DATESELECTED_H
#define DATESELECTED_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include <QMessageBox>

#include "ourstartingxi.h"
#include "opponentstartingxi.h"
#include "simulatematch.h"

namespace Ui {
    class DateSelected;
}

class DateSelected: public QWidget {
    Q_OBJECT

    public:
        explicit DateSelected(QWidget *parent = nullptr); // constructor
        ~DateSelected(); // destructor
        void fetchMatchData(const QDate &date); // fetch data of the match day selected
        QString get_opponentName(); // getter the opponent name

    private slots:
        void on_viewOurStartingButton_clicked(); // view our XI
        void on_viewOpponentStartingButton_clicked(); // view opponent XI
        void on_simulateMatchButton_clicked(); // simulate match

    private:
        Ui::DateSelected *ui; // pointer to the UI
        OurStartingXI *ptrOurStartingXI; // pointer for Our XI
        OpponentStartingXI *ptrOpponentStartingXI; // pointer for opponent XI
        SimulateMatch *ptrSimulateMatch; // pointer for simulate match
        QString opponentName;
};

#endif // DATESELECTED_H
