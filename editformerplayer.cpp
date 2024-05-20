#include "editformerplayer.h"
#include "ui_editformerplayer.h"

EditFormerPlayer::EditFormerPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EditFormerPlayer)
{
    ui->setupUi(this);
}

EditFormerPlayer::~EditFormerPlayer()
{
    delete ui;
}
