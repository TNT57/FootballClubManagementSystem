#include "startingxilist.h"
#include "ui_startingxilist.h"

StartingXIList::StartingXIList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartingXIList)
{
    ui->setupUi(this);
}

StartingXIList::~StartingXIList()
{
    delete ui;
}
