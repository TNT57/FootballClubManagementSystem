#include "teamstatistics.h"
#include "ui_teamstatistics.h"

TeamStatistics::TeamStatistics(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeamStatistics)
{
    ui->setupUi(this);
}

TeamStatistics::~TeamStatistics()
{
    delete ui;
}
