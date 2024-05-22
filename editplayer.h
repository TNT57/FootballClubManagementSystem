#ifndef EDITPLAYER_H
#define EDITPLAYER_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class EditPlayer;
}

class EditPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit EditPlayer(QWidget *parent = nullptr); //constructor to initialize the ui for EditPlayer class
    void loadPlayer(); // method to load the player from the database
    void loadPlayerPosition(); // method to load and take the position of the player from the database
    bool validateInput(); // method to validate the user input
    friend class TestEditPlayer;
    ~EditPlayer();

private slots:
    void on_shirtNumberComboBox_currentTextChanged(const QString &shirtNumber); // slot to handle the signal of combo box of player's shirt number

    void on_confirmButton_clicked(); // slot to handle the signal of confirm button

    void on_positionComboBox_currentTextChanged(const QString &position); // slot to handle the signal of the position combo box

private:
    Ui::EditPlayer *ui;
};

#endif // EDITPLAYER_H
