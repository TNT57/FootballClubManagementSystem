#ifndef SELECTDATE_H
#define SELECTDATE_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class SelectDate;
}

class SelectDate : public QWidget
{
    Q_OBJECT

public:
    explicit SelectDate(QWidget *parent = nullptr);
    ~SelectDate();

private:
    Ui::SelectDate *ui;
};

#endif // SELECTDATE_H
