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
    Staff(QWidget *parent = nullptr);
    void addPeople();
    void removePeople();
    void editPeople();
    void loadStaff();
    void reloadPeople();
    ~Staff();
private:
    AddStaff* ptrAddStaff;
    EditStaff *ptrEditStaff;
    QSqlQueryModel *model;
    RemoveStaff* ptrRemoveStaff;
};

#endif // STAFF_H
