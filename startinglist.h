#ifndef STARTINGLIST_H
#define STARTINGLIST_H

#include <QWidget>

namespace Ui {
class StartingList;
}

class StartingList : public QWidget
{
    Q_OBJECT

public:
    explicit StartingList(QWidget *parent = nullptr);
    ~StartingList();

private slots:
    void on_modifyOurStartingButton_clicked();

    void on_modifyOpponentStartingButton_clicked();

    void on_simulateMatchButton_clicked();

private:
    Ui::StartingList *ui;
};

#endif // STARTINGLIST_H
