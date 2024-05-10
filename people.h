#ifndef PEOPLE_H
#define PEOPLE_H

#include <QWidget>
#include "player.h"
#include "staff.h"

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
    void on_playerButton_clicked();

    void on_staffButton_clicked();

private:
    Ui::People *ui;
    Player *ptrPlayer;
    Staff *ptrStaff;

};

#endif // PEOPLE_H
