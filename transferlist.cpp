#include "transferlist.h"

TransferList::TransferList(): Player() {
    loadTransferList();
}

void TransferList::loadTransferList() {
    QSqlDatabase db = QSqlDatabase::database("DB1");
    model = new QSqlQueryModel();

    model -> setQuery("SELECT * FROM TransferList", db);
    ui -> tableView -> setModel(model);
}

void TransferList::addPeople() {
    ptrAddTransferList = new AddTransferList();
    ptrAddTransferList -> setWindowTitle("Add to Transfer List");
    ptrAddTransferList -> show();
}

void TransferList::removePeople() {
    ptrRemoveTransferList = new RemoveTransferList();
    ptrRemoveTransferList -> setWindowTitle("Remove from Transfer List");
    ptrRemoveTransferList -> show();
}

void TransferList::editPeople() {
    ptrEditTransferList = new EditTransferList();
    ptrEditTransferList -> setWindowTitle("Edit Transfer List");
    ptrEditTransferList -> show();
}

void TransferList::reloadPeople() {
    loadTransferList();
}

TransferList::~TransferList() {
    delete model;
    delete ptrAddTransferList;
    delete ptrRemoveTransferList;
    delete ptrEditTransferList;
}
