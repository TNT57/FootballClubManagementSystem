#ifndef CHOOSEOURXI_H
#define CHOOSEOURXI_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class ChooseOurXI;
}

class ChooseOurXI : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseOurXI(QWidget *parent = nullptr);
    ~ChooseOurXI();

    void loadPlayers();

private slots:
    void on_confirmButton_clicked();

private:
    Ui::ChooseOurXI *ui;
};

#endif // CHOOSEOURXI_H
