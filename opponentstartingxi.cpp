#include "opponentstartingxi.h"

OpponentStartingXI::OpponentStartingXI() {
    loadStartingXI();
    ptrChooseOpponentXI = new ChooseOpponentXI();
}

OpponentStartingXI::~OpponentStartingXI() {
    delete ui;
    delete model;
    delete ptrChooseOpponentXI;
}

void OpponentStartingXI::loadStartingXI(){
    QSqlDatabase db = QSqlDatabase::database("DB1");
    model = new QSqlQueryModel();
    QString query = QString("SELECT ShirtNumber, Position, Name FROM %1 WHERE Selected = 1").arg(opponentName);
    model->setQuery(query, db);
    ui->tableView->setModel(model);
}

void OpponentStartingXI::choosePlayer() {
    ptrChooseOpponentXI -> setWindowTitle("Choose Opponent Starting XI");
    ptrChooseOpponentXI -> show();
}
