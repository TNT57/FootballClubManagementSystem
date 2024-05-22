#ifndef ADDMATCHFIXTURE_H
#define ADDMATCHFIXTURE_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
    class AddMatchFixture;
}

class AddMatchFixture: public QWidget {
    Q_OBJECT

    public:
        explicit AddMatchFixture(QWidget *parent = nullptr); // Constructor
        ~AddMatchFixture(); // Destructor

    private slots:
        void on_confirmButton_clicked(); // Confirm add match fixture

    private:
        Ui::AddMatchFixture *ui; // pointer to the UI
};

#endif // ADDMATCHFIXTURE_H
