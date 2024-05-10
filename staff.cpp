#include "staff.h"

Staff::Staff(QWidget* parent): TeamList(parent) {
    loadStaff();
}
void Staff::loadStaff(){
    QSqlDatabase db = QSqlDatabase::database("DB1");
    if (model == nullptr) {
         model = new QSqlQueryModel();
    }
    model->setQuery("SELECT * FROM Staff", db);
    ui->tableView->setModel(model);
}
Staff :: ~Staff(){
    delete ui;
    delete ptrAddStaff;
}
void Staff :: addPeople(){
    ptrAddStaff = new AddStaff();
    ptrAddStaff -> setWindowTitle("Add staff");
    ptrAddStaff -> show();
}
void Staff :: reloadPeople(){
    loadStaff();
}
