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

class Navigator : public QMainWindow
{
    Q_OBJECT

public:
    Navigator(QWidget *parent = nullptr);
    MatchFixture *get_ptrMatchFixture();
    ~Navigator();

private slots:
    void on_peopleButton_clicked();

    void on_matchButton_clicked();

    void on_teamButton_clicked();

private:
    Ui::Navigator *ui;
    QSqlDatabase database;
    People *ptrPeople;
    MatchFixture *ptrMatchFixture;
    TeamStatistics *ptrTeamStatistics;
};
#endif // NAVIGATOR_H
