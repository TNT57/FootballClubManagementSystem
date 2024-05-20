#include "people.h"
#include "ui_people.h"


People::People(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::People)
{
    ui->setupUi(this);
    ptrPlayer = new Player();
    ptrStaff = new Staff();
    ptrFormerPlayer = new FormerPlayer();
}

People::~People()
{
    delete ui;
    delete ptrPlayer;
    delete ptrStaff;
    delete ptrFormerPlayer;
}

void People::on_playerButton_clicked()
{
    ptrPlayer -> setWindowTitle("Player");
    ptrPlayer -> show();
}

void People::on_staffButton_clicked()
{
    ptrStaff -> setWindowTitle("Staff");
    ptrStaff -> show();
}


void People::on_formerPlayerButton_clicked()
{
    ptrFormerPlayer -> setWindowTitle("Former Player");
    ptrFormerPlayer -> show();
}

