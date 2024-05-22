#include "startinglist.h"
#include "ui_startinglist.h"

StartingList::StartingList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartingList)
{
    ui->setupUi(this);
      database = QSqlDatabase::database("DB1");

    // Set the tooltip for the label
    ui->infoLabel->setToolTip("Click reload to see the most updated statistic of the team!");

    // Set the size of the label to be a square
    ui->infoLabel->setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui->infoLabel->setStyleSheet("QLabel {"
                                 "border: 1px solid black;"
                                 "border-radius: 15px;" // Half of width/height
                                 "}");

}

StartingList::~StartingList()
{
    delete ui;
}

void StartingList::on_chooseStartingButton_clicked()
{
    choosePlayer();
}


void StartingList::on_reloadButton_clicked()
{
    reloadPlayer();
}

