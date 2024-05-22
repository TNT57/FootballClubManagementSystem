#include "player.h"

Player::Player(QWidget *parent) : TeamList(parent){
    loadPlayer();
}
void Player:: loadPlayer(){
    QSqlDatabase db = QSqlDatabase::database("DB1");
    //query all players from the database
    model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM Player", db);
    //show the player table
    ui->tableView->setModel(model);

}
Player :: ~Player(){
    delete ui;
    delete ptrAddPlayer;
}
//open the add player feature
void Player::addPeople(){
    ptrAddPlayer = new AddPlayer();
    ptrAddPlayer -> setWindowTitle("Add player");
    ptrAddPlayer -> show();
}
//open the edit player feature
void Player::editPeople(){
    ptrEditPlayer = new EditPlayer();
    ptrEditPlayer -> setWindowTitle("Edit player");
    ptrEditPlayer -> show();
}
//reload the table
void Player::reloadPeople(){
    loadPlayer();
}
//open the remove player feature
void Player::removePeople(){
    ptrRemovePlayer = new RemovePlayer();
    ptrRemovePlayer -> setWindowTitle("Remove Player");
    ptrRemovePlayer -> show();
}
