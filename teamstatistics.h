#ifndef TEAMSTATISTICS_H
#define TEAMSTATISTICS_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>

namespace Ui {
class TeamStatistics;
}

class TeamStatistics : public QWidget
{
    Q_OBJECT

public:
    explicit TeamStatistics(QWidget *parent = nullptr);
    ~TeamStatistics();
    void loadPlayerStats();

private slots:
    void on_btnReload_clicked();

private:
    Ui::TeamStatistics *ui;
    QSqlQueryModel *model;
};

#endif // TEAMSTATISTICS_H
