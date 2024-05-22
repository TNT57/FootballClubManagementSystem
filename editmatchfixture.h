#ifndef EDITMATCHFIXTURE_H
#define EDITMATCHFIXTURE_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
    class EditMatchFixture;
}

class EditMatchFixture: public QWidget {
    Q_OBJECT

    public:
        explicit EditMatchFixture(QWidget *parent = nullptr); // constructor
        void populateDate(); // load data of date to combo box
        void populateOpponentName(); // load data of opponent name to combo box
        ~EditMatchFixture(); // destructor

    private slots:
        void on_confirmButton_clicked(); // confirm editting match fixture
        void on_matchDayComboBox_currentTextChanged(const QString &date); // display other features different according to date selected

    private:
        Ui::EditMatchFixture *ui; // pointer to the UI
};

#endif // EDITMATCHFIXTURE_H
