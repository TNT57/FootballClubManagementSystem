#include "teamlist.h"
#include "ui_teamlist.h"

TeamList::TeamList(QWidget *parent): QWidget(parent), ui(new Ui::TeamList) {
    ui -> setupUi(this);

    // set database
    database = QSqlDatabase::database("DB1");

    // Set the size of the label to be a square
    ui -> infoLabel -> setFixedSize(30, 30);

    // Set the stylesheet to add a circular border around the label
    ui -> infoLabel -> setStyleSheet("QLabel {"
                                     "border: 1px solid black;"
                                     "border-radius: 15px;" // Half of width/height
                                     "}");
}

TeamList::~TeamList() {
    delete ui;
}

void TeamList::on_addButton_clicked() {
    addPeople();
}

void TeamList::on_removeButton_clicked() {
    removePeople();
}

void TeamList::on_editButton_clicked() {
    editPeople();
}

void TeamList::on_reloadButton_clicked() {
    reloadPeople();
}

