#ifndef STARTINGXILIST_H
#define STARTINGXILIST_H

#include <QWidget>

namespace Ui {
class StartingXIList;
}

class StartingXIList : public QWidget
{
    Q_OBJECT

public:
    explicit StartingXIList(QWidget *parent = nullptr);
    ~StartingXIList();

private:
    Ui::StartingXIList *ui;
};

#endif // STARTINGXILIST_H
