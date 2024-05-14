#ifndef REMOVEMATCHFIXTURE_H
#define REMOVEMATCHFIXTURE_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class RemoveMatchFixture;
}

class RemoveMatchFixture : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveMatchFixture(QWidget *parent = nullptr);
    ~RemoveMatchFixture();

private slots:
    void on_confirmButton_clicked();

private:
    Ui::RemoveMatchFixture *ui;
};

#endif // REMOVEMATCHFIXTURE_H
