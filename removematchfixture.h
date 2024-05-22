#ifndef REMOVEMATCHFIXTURE_H
#define REMOVEMATCHFIXTURE_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
    class RemoveMatchFixture;
}

class RemoveMatchFixture: public QWidget {
    Q_OBJECT

    public:
        explicit RemoveMatchFixture(QWidget *parent = nullptr); // constructor
        void populateMatchDay(); // load data to the combo box
        ~RemoveMatchFixture(); // destructor

    private slots:
        void on_confirmButton_clicked(); // confirm removing match fixture

    private:
        Ui::RemoveMatchFixture *ui; // pointer for the UI
};

#endif // REMOVEMATCHFIXTURE_H
