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

class MatchFixture: public QWidget
{
    Q_OBJECT
public:
    explicit MatchFixture(QWidget *parent = nullptr);
    ~MatchFixture();

private slots:

    void on_addMatchFixtureButton_clicked();

    void on_removeMatchFixtureButton_clicked();

    void on_calendarMatchFixture_clicked(const QDate &date);

    void on_reloadMatchFixture_clicked();

    void on_editMatchFixtureButton_clicked();

private:
    Ui::MatchFixture *ui;
    DateSelected *ptrDateSelected;
    AddMatchFixture *ptrAddMatchFixture;
    RemoveMatchFixture *ptrRemoveMatchFixture;
    EditMatchFixture *ptrEditMatchFixture;
};

#endif // MATCHFIXTURE_H
