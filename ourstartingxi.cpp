#include "ourstartingxi.h"

OurStartingXI::OurStartingXI() {
    loadOurXI();
    ptrChooseOurXI = new ChooseOurXI();
}

OurStartingXI::~OurStartingXI() {
    delete ui;
    delete model;
    delete ptrChooseOurXI;
}

void OurStartingXI::loadOurXI(){
    QSqlDatabase db = QSqlDatabase::database("DB1");
    model = new QSqlQueryModel();
    model->setQuery("SELECT ShirtNumber, Position, Name FROM Player WHERE Selected = 1", db);
    ui->tableView->setModel(model);
}

void OurStartingXI::reloadPlayer() {
    loadOurXI();
}

void OurStartingXI::choosePlayer() {
    ptrChooseOurXI -> setWindowTitle("Choose Our Starting XI");
    ptrChooseOurXI -> show();
}
