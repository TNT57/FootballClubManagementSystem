#ifndef TEAMLIST_H
#define TEAMLIST_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QTableView>
namespace Ui {
class TeamList;
}

class TeamList : public QWidget
{
    Q_OBJECT

public:
    explicit TeamList(QWidget *parent = nullptr); // constructor to initialize the ui for TeamList class
    virtual void addPeople() = 0;  // declare virtual function to implement funtionality for add button
    virtual void removePeople() = 0;  // declare virtual funciton to implement functionality for remove button
    virtual void editPeople() = 0;  // declare virtual function to implement functionality for edit button
    virtual void reloadPeople() = 0; // declare virtual function to implement functionality for reload button
    ~TeamList();

private slots:
    void on_addButton_clicked(); // slot to handle the signal for the add button

    void on_removeButton_clicked(); // slot to handle the signal for the remove button

    void on_editButton_clicked(); // slot to handle the signal for the edit button

    void on_reloadButton_clicked(); // slot to handle the signal for the reload button

protected:
    Ui::TeamList *ui;
    QSqlDatabase database;
};

#endif // TEAMLIST_H
