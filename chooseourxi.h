#ifndef CHOOSEOURXI_H
#define CHOOSEOURXI_H

#include <QWidget>

namespace Ui {
class ChooseOurXI;
}

class ChooseOurXI : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseOurXI(QWidget *parent = nullptr);
    ~ChooseOurXI();

private slots:
    void on_confirmButton_clicked();

private:
    Ui::ChooseOurXI *ui;
};

#endif // CHOOSEOURXI_H
