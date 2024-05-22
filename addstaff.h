#ifndef ADDSTAFF_H
#define ADDSTAFF_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>


namespace Ui {
class AddStaff;
}

class AddStaff : public QWidget
{
    Q_OBJECT

public:
    explicit AddStaff(QWidget *parent = nullptr); // contructor to initialize the ui for AddStaff class

    bool validateInput(); //method to validate user input
    friend class TestAddStaff;
    ~AddStaff();

private slots:
    void on_confirmButton_clicked(); //slot to handle the confirm button event

private:
   Ui::AddStaff *ui; // pointer to the ui
};

#endif // ADDSTAFF_H
