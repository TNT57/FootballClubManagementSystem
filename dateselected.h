#ifndef DATESELECTED_H
#define DATESELECTED_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include <QMessageBox>
//#include "startinglist.h"
#include "ourstartingxi.h"
#include "opponentstartingxi.h"
namespace Ui {
class DateSelected;
}

class DateSelected : public QWidget
{
    Q_OBJECT

public:
    explicit DateSelected(QWidget *parent = nullptr);
    ~DateSelected();
    void fetchMatchData(const QDate &date);

    QString get_opponentName();

private slots:
    void on_viewOurStartingButton_clicked();

    void on_viewOpponentStartingButton_clicked();

    //void on_simulateMatchButton_clicked();

private:
    Ui::DateSelected *ui;
    //StartingList *ptrStartingList;
    OurStartingXI *ptrOurStartingXI;
    OpponentStartingXI *ptrOpponentStartingXI;

    QString opponentName = "";
};

#endif // DATESELECTED_H
