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
#include <QSqlError>

namespace Ui {
    class RemoveStaff;
}

class RemoveStaff: public QWidget {
    Q_OBJECT

    public:
        explicit RemoveStaff(QWidget *parent = nullptr); // constructor
        void populateStaff(); // load data to the combo box
        friend class TestRemoveStaff; // for testing
        ~RemoveStaff(); // destructor

    private slots:
        void on_staffRemoveConfirmButton_clicked(); // confirm removing staff

    private:
        Ui::RemoveStaff *ui; // pointer for the UI
};

#endif // REMOVESTAFF_H
