#include "transferlist.h"

TransferList::TransferList(): Player() {
    loadTransferList();
}

void TransferList::loadTransferList() {
    // set database
    QSqlDatabase db = QSqlDatabase::database("DB1");
    model = new QSqlQueryModel();

    //query players trom the database
    model -> setQuery("SELECT * FROM TransferList", db);
    ui -> tableView -> setModel(model);
}

// open the add player feature
void TransferList::addPeople() {
    ptrAddTransferList = new AddTransferList();
    ptrAddTransferList -> setWindowTitle("Add to Transfer List");
    ptrAddTransferList -> show();
}

// open the remove player feature
void TransferList::removePeople() {
    ptrRemoveTransferList = new RemoveTransferList();
    ptrRemoveTransferList -> setWindowTitle("Remove from Transfer List");
    ptrRemoveTransferList -> show();
}

// open the edit player feature
void TransferList::editPeople() {
    ptrEditTransferList = new EditTransferList();
    ptrEditTransferList -> setWindowTitle("Edit Transfer List");
    ptrEditTransferList -> show();
}

// reload the list
void TransferList::reloadPeople() {
    loadTransferList();
}

TransferList::~TransferList() {
    // delete pointers
    delete model;
    delete ptrAddTransferList;
    delete ptrRemoveTransferList;
    delete ptrEditTransferList;
}
