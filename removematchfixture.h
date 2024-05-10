#ifndef REMOVEMATCHFIXTURE_H
#define REMOVEMATCHFIXTURE_H

#include <QWidget>

namespace Ui {
class RemoveMatchFixture;
}

class RemoveMatchFixture : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveMatchFixture(QWidget *parent = nullptr);
    ~RemoveMatchFixture();

private:
    Ui::RemoveMatchFixture *ui;
};

#endif // REMOVEMATCHFIXTURE_H
