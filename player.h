#ifndef PLAYER_H
#define PLAYER_H
#include "teamlist.h"
#include "ui_teamlist.h"
#include "addplayer.h"
#include "editplayer.h"
#include "removeplayer.h"
class Player : public TeamList
{
public:
    // constructor to inherit the ui from the teamlist class
    Player(QWidget *parent = nullptr);
    void addPeople();
    void removePeople();
    void editPeople();
    void loadPlayer();
    void reloadPeople();
    ~Player();

private:
    QSqlQueryModel *model;
    AddPlayer* ptrAddPlayer;
    EditPlayer* ptrEditPlayer;
    RemovePlayer* ptrRemovePlayer;
};

#endif // PLAYER_H


