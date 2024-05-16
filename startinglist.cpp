#include "startinglist.h"
#include "ui_startinglist.h"

StartingList::StartingList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartingList)
{
    ui->setupUi(this);
      database = QSqlDatabase::database("DB1");
}

StartingList::~StartingList()
{
    delete ui;
}

void StartingList::on_chooseStartingButton_clicked()
{
    choosePlayer();
}

