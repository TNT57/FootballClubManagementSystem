#include "removeformerplayer.h"
#include "ui_removeformerplayer.h"

RemoveFormerPlayer::RemoveFormerPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RemoveFormerPlayer)
{
    ui->setupUi(this);
    populateFormerPlayers();
}

RemoveFormerPlayer::~RemoveFormerPlayer()
{
    delete ui;
}

void RemoveFormerPlayer::populateFormerPlayers() {

}

void RemoveFormerPlayer::on_confirmButton_clicked()
{

}

void RemoveFormerPlayer::on_playerNameComboBox_activated()
{

}

