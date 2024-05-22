#ifndef ADDTRANSFERLIST_H
#define ADDTRANSFERLIST_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
    class AddTransferList;
}

class AddTransferList: public QWidget {
    Q_OBJECT

    public:
        explicit AddTransferList(QWidget *parent = nullptr); // constructor
        void populateTransferList(); // load data to the combo box
        bool validateInput(); // validate input
        ~AddTransferList(); // destructor

    private slots:
        void on_confirmButton_clicked(); // confirm add to transfer list

    private:
        Ui::AddTransferList *ui; // pointer to the ui
};

#endif // ADDTRANSFERLIST_H
