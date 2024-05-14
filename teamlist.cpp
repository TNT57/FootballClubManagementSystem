#include "teamlist.h"
#include "ui_teamlist.h"

TeamList::TeamList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TeamList)
{
    ui->setupUi(this);
    database = QSqlDatabase::database("DB1");
}

TeamList::~TeamList()
{

    delete ui;
}

void TeamList::on_addButton_clicked()
{
    addPeople();
}


void TeamList::on_removeButton_clicked()
{
    removePeople();
}


void TeamList::on_editButton_clicked()
{
    editPeople();
}


void TeamList::on_reloadButton_clicked()
{
    reloadPeople();
}

