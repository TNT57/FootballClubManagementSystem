#include "opponentstartingxi.h"

OpponentStartingXI::OpponentStartingXI(QString opponentName): opponentName(opponentName) {
    loadOpponentXI();
    ptrChooseOpponentXI = new ChooseOpponentXI();
}

OpponentStartingXI::~OpponentStartingXI() {
    delete ui;
    delete model;
    delete ptrChooseOpponentXI;
}

QString OpponentStartingXI::get_opponentName() {
    return opponentName;
}

void OpponentStartingXI::set_opponentName(QString opponentName) {
    this -> opponentName = opponentName;
    loadOpponentXI();
}

void OpponentStartingXI::loadOpponentXI() {
    // set database
    QSqlDatabase db = QSqlDatabase::database("DB1");
    model = new QSqlQueryModel();

    QString query = QString("SELECT ShirtNumber, Position, Name FROM %1 WHERE Selected = 1").arg(opponentName);
    model -> setQuery(query, db);
    ui -> tableView -> setModel(model);
}

// reload
void OpponentStartingXI::reloadPlayer() {
    loadOpponentXI();
}

// open Choose Opponent XI UI
void OpponentStartingXI::choosePlayer() {
    ptrChooseOpponentXI -> set_opponentName(get_opponentName());
    ptrChooseOpponentXI -> setWindowTitle("Choose Opponent Starting XI");
    ptrChooseOpponentXI -> show();
}
