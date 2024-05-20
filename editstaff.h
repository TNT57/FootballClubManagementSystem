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

class EditStaff : public QWidget
{
    Q_OBJECT

public:
    explicit EditStaff( QWidget *parent = nullptr);
    void loadStaff();
    bool validateInput();
    int staffId;
    friend class TestEditStaff;
    ~EditStaff();

private slots:
    void on_confirmButton_clicked();

    void on_staffIdComboBox_currentTextChanged(const QString &staffId);


private:
    Ui::EditStaff *ui;
};

#endif // EDITSTAFF_H
