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
    void addPeople();
    void removePeople();
    void editPeople();
    void loadTransferList();
    void reloadPeople();
    ~TransferList();

private:
    QSqlQueryModel *model;
    AddTransferList *ptrAddTransferList;
    RemoveTransferList *ptrRemoveTransferList;
    EditTransferList *ptrEditTransferList;
};

#endif // TRANSFERLIST_H
