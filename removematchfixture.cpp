#include "removematchfixture.h"
#include "ui_removematchfixture.h"

RemoveMatchFixture::RemoveMatchFixture(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RemoveMatchFixture)
{
    ui->setupUi(this);
}

RemoveMatchFixture::~RemoveMatchFixture()
{
    delete ui;
}
