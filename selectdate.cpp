#include "selectdate.h"
#include "ui_selectdate.h"

SelectDate::SelectDate(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelectDate)
{
    ui->setupUi(this);
}

SelectDate::~SelectDate()
{
    delete ui;
}
