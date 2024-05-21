#ifndef FORMERPLAYER_H
#define FORMERPLAYER_H

#include "player.h"
#include "addformerplayer.h"
#include "removeformerplayer.h"
#include "editformerplayer.h"

class FormerPlayer: public Player
{
public:
    FormerPlayer();
    void addPeople();
    void removePeople();
    void editPeople();
    void loadFormerPlayer();
    void reloadPeople();
    ~FormerPlayer();

private:
    QSqlQueryModel *model;
    AddFormerPlayer *ptrAddFormerPlayer;
    RemoveFormerPlayer *ptrRemoveFormerPlayer;
    EditFormerPlayer *ptrEditFormerPlayer;
};

#endif // FORMERPLAYER_H
