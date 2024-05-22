#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDateTime>
#include <QMessageBox>

#include "people.h"
#include "matchfixture.h"
#include "teamstatistics.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Navigator;
}
QT_END_NAMESPACE

class Navigator: public QMainWindow {
    Q_OBJECT

    public:
        Navigator(QWidget *parent = nullptr); // constructor
        ~Navigator(); // destructor

    private slots:
        // open ui of features when click on each button
        void on_peopleButton_clicked();
        void on_matchButton_clicked();
        void on_teamButton_clicked();

    private:
        Ui::Navigator *ui; // pointer to initialize the ui of the main window
        // pointer to other features
        QSqlDatabase database;
        People *ptrPeople;
        MatchFixture *ptrMatchFixture;
        TeamStatistics *ptrTeamStatistics;
};

#endif // NAVIGATOR_H
