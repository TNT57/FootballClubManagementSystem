#include "player.h"
#include "ui_player.h"

Player::Player(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Player)
{
    ui->setupUi(this);
    loadAllPlayer();
}

Player::~Player()
{
    delete ui;
}
// load and show the table of player data
void Player :: loadAllPlayer(){
     QSqlDatabase database = QSqlDatabase::database("DB1");
    if (model == nullptr)
        model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM Player", database);
    ui->tableView->setModel(model); // Show the database table in the table view
}
