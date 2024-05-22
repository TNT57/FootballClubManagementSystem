#ifndef EDITSTAFF_H
#define EDITSTAFF_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
    class EditStaff;
}

class EditStaff: public QWidget {
    Q_OBJECT

    public:
        explicit EditStaff( QWidget *parent = nullptr); // constructor to initialize the ui of the EditStaff class
        void loadStaff(); // method to load staff info from the database
        bool validateInput(); // method to validate the user input
        int staffId;
        friend class TestEditStaff; // for testing
        ~EditStaff(); // destructor

    private slots:
        void on_confirmButton_clicked(); // slot to handle the signal of the confirm button
        void on_staffIdComboBox_currentTextChanged(const QString &staffId); // slot to handle the combo box of the staff id

    private:
        Ui::EditStaff *ui; // pointer to the UI
};

#endif // EDITSTAFF_H
