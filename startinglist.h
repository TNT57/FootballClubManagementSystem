#ifndef STARTINGLIST_H
#define STARTINGLIST_H

#include <QWidget>
#include <QListWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QTableView>

namespace Ui {
class StartingList;
}

class StartingList : public QWidget
{
    Q_OBJECT

public:
    explicit StartingList(QWidget *parent = nullptr);
    virtual void choosePlayer() = 0;
    virtual void reloadPlayer() = 0;
    ~StartingList();

private slots:
    void on_chooseStartingButton_clicked();

    void on_reloadButton_clicked();

protected:
    Ui::StartingList *ui;
    QSqlDatabase database;
};

#endif // STARTINGLIST_H
