#ifndef REMOVETRANSFERLIST_H
#define REMOVETRANSFERLIST_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
    class RemoveTransferList;
}

class RemoveTransferList: public QWidget {
    Q_OBJECT

    public:
        explicit RemoveTransferList(QWidget *parent = nullptr); // constructor
        void populateTransferList(); // load data to the combo box
        ~RemoveTransferList(); // destructor

    private slots:
        void on_confirmButton_clicked(); // confirm removing transfer list

    private:
        Ui::RemoveTransferList *ui; // pointer to the UI
};

#endif // REMOVETRANSFERLIST_H
