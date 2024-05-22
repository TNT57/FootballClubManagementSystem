#ifndef PEOPLE_H
#define PEOPLE_H

#include <QWidget>
#include "player.h"
#include "staff.h"
#include "transferlist.h"

namespace Ui {
class People;
}

class People : public QWidget
{
    Q_OBJECT

public:
    explicit People(QWidget *parent = nullptr);

    ~People();

private slots:
    // open the ui of the features when click on each button
    void on_playerButton_clicked();

    void on_staffButton_clicked();

    void on_transferListButton_clicked();

private:
    Ui::People *ui; // initialize the ui of the People class
    // pointer to other features
    Player *ptrPlayer;
    Staff *ptrStaff;
    TransferList *ptrTransferList;
};

#endif // PEOPLE_H
