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
    explicit TeamList(QWidget *parent = nullptr);
    virtual void addPeople() = 0;
   // virtual void removePeople() = 0;
   // virtual void editPeople() = 0;
    virtual void reloadPeople() = 0;
    ~TeamList();

private slots:
    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_editButton_clicked();

    void on_reloadButton_clicked();

protected:
    Ui::TeamList *ui;
    QSqlDatabase database;
};

#endif // TEAMLIST_H
