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

class AddTransferList : public QWidget
{
    Q_OBJECT

public:
    explicit AddTransferList(QWidget *parent = nullptr);
    void populateTransferList();
    bool validateInput();
    ~AddTransferList();

private slots:
    void on_confirmButton_clicked();
    void on_playerNameComboBox_activated();

private:
    Ui::AddTransferList *ui;
};

#endif // ADDTRANSFERLIST_H
