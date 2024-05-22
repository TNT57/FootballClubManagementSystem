#ifndef PLAYER_H
#define PLAYER_H

#include "teamlist.h"
#include "ui_teamlist.h"
#include "addplayer.h"
#include "editplayer.h"
#include "removeplayer.h"

class Player: public TeamList {
    public:
        // constructor to inherit the ui from the teamlist class
        Player(QWidget *parent = nullptr);
        void addPeople(); // add the player to the Player database (virtual)
        void removePeople(); // remove the player from the Player database (virtual)
        void editPeople(); // edit the statistics of each player in the database (virtual)
        void loadPlayer(); // load the player from the Player database
        void reloadPeople(); // reload the player table (virtual)
        ~Player(); // destructor

    private:
        // pointer for the model
        QSqlQueryModel *model;
        // pointers to ui for each feature
        AddPlayer* ptrAddPlayer;
        EditPlayer* ptrEditPlayer;
        RemovePlayer* ptrRemovePlayer;
};

#endif // PLAYER_H


