#include "staff.h"

Staff::Staff(QWidget* parent): TeamList(parent) {
    loadStaff();
}
void Staff::loadStaff(){
    QSqlDatabase db = QSqlDatabase::database("DB1");
    model = new QSqlQueryModel();
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
void Staff :: editPeople(){
    ptrEditStaff = new EditStaff();
    ptrEditStaff -> setWindowTitle("Edit Staff");
    ptrEditStaff -> show();
}
void Staff :: removePeople(){
    ptrRemoveStaff = new RemoveStaff();
    ptrRemoveStaff -> setWindowTitle("Remove staff");
    ptrRemoveStaff -> show();
}
void Staff :: reloadPeople(){
    loadStaff();
}
