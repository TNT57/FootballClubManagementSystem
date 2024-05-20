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
    void addPeople(); // can be used in Former Player
    void removePeople(); // can be used in Former Player
    void editPeople();
    void loadPlayer(); // can be used in Former Player
    void reloadPeople(); // can be used in Former Player
    ~Player();

private:
    QSqlQueryModel *model;
    AddPlayer* ptrAddPlayer;
    EditPlayer* ptrEditPlayer;
    RemovePlayer* ptrRemovePlayer;
};

#endif // PLAYER_H


