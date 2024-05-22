#ifndef STAFF_H
#define STAFF_H
#include "teamlist.h"
#include "ui_teamlist.h"
#include "addstaff.h"
#include "editstaff.h"
#include "removestaff.h"

class Staff : public TeamList
{
public:
    // constructor for the ui inherited from the TeamList
    Staff(QWidget *parent = nullptr);
    void addPeople(); // add staff to the Staff database (virtual)
    void removePeople(); // remove staff from the Staff database (virtual)
    void editPeople(); // edit the information of each staff (virtual)
    void loadStaff(); // load the staff from the database
    void reloadPeople(); // reload the staff table (virtual)
    ~Staff();
private:
     QSqlQueryModel *model;
    // pointers to the ui of each features
    AddStaff* ptrAddStaff;
    EditStaff *ptrEditStaff;
    RemoveStaff* ptrRemoveStaff;
};

#endif // STAFF_H
