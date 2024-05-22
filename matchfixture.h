#ifndef MATCHFIXTURE_H
#define MATCHFIXTURE_H

#include <QWidget>
#include <QMessageBox>
#include <QTextCharFormat>

#include "dateselected.h"
#include "addmatchfixture.h"
#include "removematchfixture.h"
#include "editmatchfixture.h"

namespace Ui {
    class MatchFixture;
}

class MatchFixture: public QWidget {
    Q_OBJECT

    public:
        explicit MatchFixture(QWidget *parent = nullptr); // constructor
        ~MatchFixture(); // destructor

    private slots:
        void on_addMatchFixtureButton_clicked(); // button to pop up Add Match Fixture
        void on_removeMatchFixtureButton_clicked(); // button to pop up Remove Match Fixture
        void on_calendarMatchFixture_clicked(const QDate &date); // click on date selected
        void on_reloadMatchFixture_clicked(); // reload the Match Fixture
        void on_editMatchFixtureButton_clicked(); // button to pop up Edit Match Fixture

    private:
        Ui::MatchFixture *ui; // pointer to the UI
        DateSelected *ptrDateSelected; // pointer to date selected
        AddMatchFixture *ptrAddMatchFixture; // pointer to add match fixture
        RemoveMatchFixture *ptrRemoveMatchFixture; // pointer to remove match fixture
        EditMatchFixture *ptrEditMatchFixture; // pointer to edit match fixture
};

#endif // MATCHFIXTURE_H
