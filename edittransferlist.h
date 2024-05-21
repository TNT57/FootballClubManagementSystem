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

class EditTransferList : public QWidget
{
    Q_OBJECT

public:
    explicit EditTransferList(QWidget *parent = nullptr);
    void populateTransferList();
    bool validateInput();
    ~EditTransferList();

private slots:
    void on_confirmButton_clicked();
    void on_playerNameComboBox_activated();

    void on_playerNameComboBox_currentTextChanged(const QString &shirtNumber);

private:
    Ui::EditTransferList *ui;
};

#endif // EDITTRANSFERLIST_H
