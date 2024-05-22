#include "staff.h"

Staff::Staff(QWidget* parent): TeamList(parent) {
    loadStaff();
}

void Staff::loadStaff() {
    // set database
    QSqlDatabase db = QSqlDatabase::database("DB1");
    model = new QSqlQueryModel();

    // query the staff table from the database
    model -> setQuery("SELECT * FROM Staff", db);

    // show the staff table
    ui -> tableView -> setModel(model);
}

Staff::~Staff() {
    delete ui;
    delete ptrAddStaff;
}

// open the add staff feature
void Staff::addPeople() {
    ptrAddStaff = new AddStaff();
    ptrAddStaff -> setWindowTitle("Add staff");
    ptrAddStaff -> show();
}

// open the edit staff feature
void Staff::editPeople() {
    ptrEditStaff = new EditStaff();
    ptrEditStaff -> setWindowTitle("Edit Staff");
    ptrEditStaff -> show();
}

// open the remove staff feature
void Staff::removePeople() {
    ptrRemoveStaff = new RemoveStaff();
    ptrRemoveStaff -> setWindowTitle("Remove staff");
    ptrRemoveStaff -> show();
}

// reload the table
void Staff :: reloadPeople() {
    loadStaff();
}
