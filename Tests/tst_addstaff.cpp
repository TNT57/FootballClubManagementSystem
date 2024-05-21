#include "tst_addstaff.h"

TestAddStaff::TestAddStaff()
{
    addstaff = new AddStaff();
}

TestAddStaff::~TestAddStaff()
{
    delete addstaff;
}

void TestAddStaff::initTestCase()
{
    // Initialization before running tests
}

void TestAddStaff::cleanupTestCase()
{
    // Cleanup after running tests
}

void TestAddStaff::test_validateInput()
{
    // Test normal case
    addstaff->ui->staffIdLineEdit->setText("123");
    addstaff->ui->nameLineEdit->setText("John Doe");
    addstaff->ui->dobLineEdit->setText("01/01/2000");
    addstaff->ui->roleLineEdit->setText("Manager");
    addstaff->ui->salaryLineEdit->setText("5000");
    QVERIFY(!addstaff->validateInput());

    // Test case where salary is not an integer
    addstaff->ui->salaryLineEdit->setText("not an integer");
    QVERIFY(!addstaff->validateInput());

    // Test case where a line is left blan
    addstaff->ui->nameLineEdit->setText("");
    QVERIFY(!addstaff->validateInput());
}

// QTEST_MAIN(TestAddStaff)
// #include "tst_addstaff.moc"

