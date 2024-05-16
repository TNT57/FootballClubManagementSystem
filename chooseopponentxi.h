#ifndef CHOOSEOPPONENTXI_H
#define CHOOSEOPPONENTXI_H

#include <QWidget>

namespace Ui {
class ChooseOpponentXI;
}

class ChooseOpponentXI : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseOpponentXI(QWidget *parent = nullptr);
    ~ChooseOpponentXI();

private slots:
    void on_confirmButton_clicked();

private:
    Ui::ChooseOpponentXI *ui;
};

#endif // CHOOSEOPPONENTXI_H
