#ifndef STAFF_H
#define STAFF_H
#include "teamlist.h"
#include "ui_teamlist.h"
#include "addstaff.h"

class Staff : public TeamList
{
public:
    Staff(QWidget *parent = nullptr);
    void addPeople();
    // void removePeople();
    // void editPeople();
    void loadStaff();
    void reloadPeople();
    ~Staff();
private:
    AddStaff* ptrAddStaff;
    QSqlQueryModel *model;
};

#endif // STAFF_H
