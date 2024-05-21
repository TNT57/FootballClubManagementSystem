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
    explicit AddStaff(QWidget *parent = nullptr);

    bool validateInput();
    friend class TestAddStaff;
    ~AddStaff();

private slots:
    void on_confirmButton_clicked();

private:
   Ui::AddStaff *ui;
};

#endif // ADDSTAFF_H
