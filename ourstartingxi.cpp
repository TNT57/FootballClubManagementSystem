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

void OurStartingXI::loadOurXI() {
    QSqlDatabase db = QSqlDatabase::database("DB1");
    model = new QSqlQueryModel();

    model -> setQuery("SELECT ShirtNumber, Position, Name FROM Player WHERE Selected = 1", db);
    ui -> tableView -> setModel(model);
}

// reload
void OurStartingXI::reloadPlayer() {
    loadOurXI();
}

// open Choose Our XI UI
void OurStartingXI::choosePlayer() {
    ptrChooseOurXI -> setWindowTitle("Choose Our Starting XI");
    ptrChooseOurXI -> show();
}
