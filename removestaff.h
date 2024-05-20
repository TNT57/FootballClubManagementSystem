#ifndef REMOVESTAFF_H
#define REMOVESTAFF_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>


namespace Ui {
class RemoveStaff;
}

class RemoveStaff : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveStaff(QWidget *parent = nullptr);
    friend class TestRemoveStaff;
    ~RemoveStaff();

private slots:

    void on_staffNameComboBox_activated();

    void on_staffRemoveConfirmButton_clicked();

private:
    Ui::RemoveStaff *ui;
    void populateStaff();
};

#endif // REMOVESTAFF_H
