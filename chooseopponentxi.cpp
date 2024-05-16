#include "chooseopponentxi.h"
#include "ui_chooseopponentxi.h"

ChooseOpponentXI::ChooseOpponentXI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChooseOpponentXI)
{
    ui->setupUi(this);
}

ChooseOpponentXI::~ChooseOpponentXI()
{
    delete ui;
}

void ChooseOpponentXI::on_confirmButton_clicked()
{

}

