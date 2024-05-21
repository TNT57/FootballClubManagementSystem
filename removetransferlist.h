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

class RemoveTransferList : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveTransferList(QWidget *parent = nullptr);
    void populateTransferList();
    ~RemoveTransferList();

private slots:
    void on_confirmButton_clicked();
    void on_playerNameComboBox_activated();

private:
    Ui::RemoveTransferList *ui;
};

#endif // REMOVETRANSFERLIST_H
