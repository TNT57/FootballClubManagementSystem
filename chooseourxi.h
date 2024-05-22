#ifndef CHOOSEOURXI_H
#define CHOOSEOURXI_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
    class ChooseOurXI;
}

class ChooseOurXI: public QWidget {
    Q_OBJECT

    public:
        explicit ChooseOurXI(QWidget *parent = nullptr); // constructor
        ~ChooseOurXI(); // destructor
        void loadPlayers(); // load our players to the UI

    private slots:
        void on_confirmButton_clicked(); // confirm choosing Our XI

    private:
        Ui::ChooseOurXI *ui; // pointer to the UI
};

#endif // CHOOSEOURXI_H
