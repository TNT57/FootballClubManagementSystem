#ifndef TRANSFERLIST_H
#define TRANSFERLIST_H

#include "player.h"
#include "addtransferlist.h"
#include "removetransferlist.h"
#include "edittransferlist.h"

class TransferList: public Player
{
public:
    TransferList();
    void addPeople();// function for add button
    void removePeople(); // function for remove button
    void editPeople(); // function for edit button
    void loadTransferList(); // load the player to the transfer list
    void reloadPeople(); // reload the transfer list
    ~TransferList();

private:
    QSqlQueryModel *model;
    // pointers to other features
    AddTransferList *ptrAddTransferList;
    RemoveTransferList *ptrRemoveTransferList;
    EditTransferList *ptrEditTransferList;
};

#endif // TRANSFERLIST_H
