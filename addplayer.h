#ifndef ADDPLAYER_H
#define ADDPLAYER_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
    class AddPlayer;
}

class AddPlayer: public QWidget {
    Q_OBJECT

    public:
        explicit AddPlayer(QWidget *parent = nullptr); // constructor to initialize the ui for AddPlayer class
        bool validateInput(); // method to validate user input
        friend class TestAddPlayer; // for testing
        ~AddPlayer(); // destructor

    private slots:
        void on_confirmButton_clicked(); // slot to handle the confirm button event
        void on_positionComboBox_currentTextChanged(const QString &arg1); // slot to handle the position combo box

    private:
        Ui::AddPlayer *ui; // pointer to the ui
};

#endif // ADDPLAYER_H
