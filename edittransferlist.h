#ifndef EDITTRANSFERLIST_H
#define EDITTRANSFERLIST_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
    class EditTransferList;
}

class EditTransferList: public QWidget {
    Q_OBJECT

    public:
        explicit EditTransferList(QWidget *parent = nullptr); // constructor
        void populateTransferList(); // load data of transfer list to the combox box
        bool validateInput(); // validate input
        ~EditTransferList(); // destructor

    private slots:
        void on_confirmButton_clicked(); // confirm editting transfer list
        void on_playerNameComboBox_currentTextChanged(const QString &shirtNumber); // display other features different according to shirt number selected

    private:
        Ui::EditTransferList *ui; // pointer to the UI
};

#endif // EDITTRANSFERLIST_H
