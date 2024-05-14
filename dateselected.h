#ifndef DATESELECTED_H
#define DATESELECTED_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include <QMessageBox>
namespace Ui {
class DateSelected;
}

class DateSelected : public QWidget
{
    Q_OBJECT

public:
    explicit DateSelected(QWidget *parent = nullptr);
    ~DateSelected();
    void fetchMatchData(const QDate &date);

private:
    Ui::DateSelected *ui;
};

#endif // DATESELECTED_H
