#ifndef PLAYER_H
#define PLAYER_H
#include <QSqlDatabase>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class Player;
}

class Player : public QWidget
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = nullptr);
    ~Player();
    void loadAllPlayer(); // load all the player in the database

private:
    Ui::Player *ui;
    QSqlQueryModel *model;
};

#endif // PLAYER_H
