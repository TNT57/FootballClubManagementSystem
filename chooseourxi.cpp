#include "chooseourxi.h"
#include "ui_chooseourxi.h"

ChooseOurXI::ChooseOurXI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChooseOurXI)
{
    ui->setupUi(this);
}

ChooseOurXI::~ChooseOurXI()
{
    delete ui;
}

void ChooseOurXI::on_confirmButton_clicked()
{

}
