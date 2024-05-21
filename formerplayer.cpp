#include "formerplayer.h"

FormerPlayer::FormerPlayer(): Player() {
    loadFormerPlayer();
    ptrAddFormerPlayer = new AddFormerPlayer();
    ptrRemoveFormerPlayer = new RemoveFormerPlayer();
    ptrEditFormerPlayer = new EditFormerPlayer();
}

void FormerPlayer::loadFormerPlayer() {
    QSqlDatabase db = QSqlDatabase::database("DB1");
    model = new QSqlQueryModel();

    model -> setQuery("SELECT * FROM FormerPlayer", db);
    ui -> tableView -> setModel(model);
}

void FormerPlayer::addPeople() {
    ptrAddFormerPlayer -> setWindowTitle("Add Former Player");
    ptrAddFormerPlayer -> show();
}

void FormerPlayer::removePeople() {
    ptrRemoveFormerPlayer -> setWindowTitle("Remove Former Player");
    ptrRemoveFormerPlayer -> show();
}

void FormerPlayer::editPeople() {
    ptrEditFormerPlayer -> setWindowTitle("Edit Former Player");
    ptrEditFormerPlayer -> show();
}

void FormerPlayer::reloadPeople() {
    loadFormerPlayer();
}

FormerPlayer::~FormerPlayer() {
    delete model;
    delete ptrAddFormerPlayer;
    delete ptrRemoveFormerPlayer;
    delete ptrEditFormerPlayer;
}
