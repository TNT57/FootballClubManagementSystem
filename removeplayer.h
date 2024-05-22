#ifndef REMOVEPLAYER_H
#define REMOVEPLAYER_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QSqlError> // Include this header for QSqlError


namespace Ui {
    class RemovePlayer;
}

class RemovePlayer: public QWidget {
    Q_OBJECT

    public:
        explicit RemovePlayer(QWidget *parent = nullptr); // constructor
        void populatePlayers(); // load data to the combo box
        friend class TestRemovePlayer; // for testing
        ~RemovePlayer(); // destructor

    private slots:
        void on_confirmButton_clicked(); // confirm removing player

    private:
        Ui::RemovePlayer *ui; // pointer for the UI
};

#endif // REMOVEPLAYER_H
