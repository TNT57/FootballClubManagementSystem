#include "removeaddfixture.h"
#include "ui_removeaddfixture.h"

RemoveAddFixture::RemoveAddFixture(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RemoveAddFixture)
{
    ui->setupUi(this);
}

RemoveAddFixture::~RemoveAddFixture()
{
    delete ui;
}
