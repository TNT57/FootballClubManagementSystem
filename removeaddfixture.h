#ifndef REMOVEADDFIXTURE_H
#define REMOVEADDFIXTURE_H

#include <QWidget>

namespace Ui {
class RemoveAddFixture;
}

class RemoveAddFixture : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveAddFixture(QWidget *parent = nullptr);
    ~RemoveAddFixture();

private:
    Ui::RemoveAddFixture *ui;
};

#endif // REMOVEADDFIXTURE_H
