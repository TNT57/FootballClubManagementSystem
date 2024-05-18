#ifndef SIMULATEMATCH_H
#define SIMULATEMATCH_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class SimulateMatch;
}

class SimulateMatch : public QWidget
{
    Q_OBJECT

public:
    explicit SimulateMatch(QWidget *parent = nullptr);
    ~SimulateMatch();

    QString get_opponentName();
    void set_opponentName(QString opponentName);
    bool checkNumPlayers();
    void simulate();

private:
    Ui::SimulateMatch *ui;
    QString opponentName = "RealMadrid";
};

#endif // SIMULATEMATCH_H
