#include "startinglist.h"
#include "ui_startinglist.h"

StartingList::StartingList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartingList)
{
    ui->setupUi(this);
}

StartingList::~StartingList()
{
    delete ui;
}

void StartingList::on_modifyOurStartingButton_clicked()
{

}


void StartingList::on_modifyOpponentStartingButton_clicked()
{

}


void StartingList::on_simulateMatchButton_clicked()
{

}

