#ifndef SIMULATEMATCH_H
#define SIMULATEMATCH_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
    class SimulateMatch;
}

class SimulateMatch: public QWidget {
    Q_OBJECT

    public:
        explicit SimulateMatch(QWidget *parent = nullptr); // constructor
        ~SimulateMatch(); // destructor

        QString get_opponentName(); // getter for opponent name
        void set_opponentName(QString opponentName); // setter for opponent name
        bool checkNumPlayers(); // check if there are EXACTLY 11 players for each team (EXACTLY 1 GK for each team)
        void simulate(); // simulate the result
        friend class TestSimulateMatch; // for testing

    private:
        Ui::SimulateMatch *ui; // pointer for the UI
        QString opponentName = "RealMadrid"; // init to avoid error
};

#endif // SIMULATEMATCH_H
