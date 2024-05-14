#include "player.h"

Player::Player(QWidget *parent) : TeamList(parent){
    loadPlayer();
}
void Player:: loadPlayer(){
    QSqlDatabase db = QSqlDatabase::database("DB1");
        model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM Player", db);
    ui->tableView->setModel(model);

}
Player :: ~Player(){
    delete ui;
    delete ptrAddPlayer;
}
void Player::addPeople(){
    ptrAddPlayer = new AddPlayer();
    ptrAddPlayer -> setWindowTitle("Add player");
    ptrAddPlayer -> show();
}
void Player::editPeople(){
    ptrEditPlayer = new EditPlayer();
    ptrEditPlayer -> setWindowTitle("Edit player");
    ptrEditPlayer -> show();
}
void Player::reloadPeople(){
    loadPlayer();
}
void Player::removePeople(){
    ptrRemovePlayer = new RemovePlayer();
    ptrRemovePlayer -> setWindowTitle("Remove Player");
    ptrRemovePlayer -> show();
}
