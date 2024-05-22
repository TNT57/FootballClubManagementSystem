#ifndef TEAMSTATISTICS_H
#define TEAMSTATISTICS_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError> // Include this header for QSqlError
#include <QMessageBox>
#include <QDebug>

namespace Ui {
    class TeamStatistics;
}

class TeamStatistics: public QWidget {
    Q_OBJECT

    public:
        explicit TeamStatistics(QWidget *parent = nullptr); // constructor
        ~TeamStatistics(); // destructor
        void loadPlayerStats(); // load player stats
        friend class TestTeamStatistics; // for testing

    private slots:
        void on_btnReload_clicked(); // reload stats

    private:
        Ui::TeamStatistics *ui; // pointer for the UI
        QSqlQueryModel *model; // pointer for the model
};

#endif // TEAMSTATISTICS_H
