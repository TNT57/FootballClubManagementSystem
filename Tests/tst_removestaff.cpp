#include "tst_removestaff.h"

TestRemoveStaff::TestRemoveStaff()
{
    removeStaff = new RemoveStaff();
}

TestRemoveStaff::~TestRemoveStaff()
{
    delete removeStaff;
}

void TestRemoveStaff::initTestCase()
{
    // Initialization before executing test cases
    // You might want to set up a mock database or use a real database with known data for these tests
}

void TestRemoveStaff::cleanupTestCase()
{
    // Clean-up after all test cases are executed
    // You might want to clean up the database here
}

void TestRemoveStaff::test_populateStaff()
{
    // Test case: Check if populateStaff function loads staff into the combo box
    // This test case involves database operations
    // You might need to set up a mock database or use a real database with known data for this test

    // 1. Set up the database and insert some known staff
    QSqlDatabase database = QSqlDatabase::database("DB1"); // Get the database.

    QSqlQuery query(database);
    query.exec("INSERT INTO Staff (StaffID, Name, DOB, Role, Salary) VALUES (1000, 'Test Staff', '02-03-2005', 'Coach', 25000)");

    // 2. Call removeStaff->populateStaff()
    removeStaff->populateStaff();

    // 3. Check if the combo box contains the staff you inserted into the database
    bool containsInsertedStaff = false;
    for(int i = 0; i < removeStaff->ui->staffNameComboBox->count(); i++)
    {
        if(removeStaff->ui->staffNameComboBox->itemText(i) == "1000 - Test Staff")
        {
            containsInsertedStaff = true;
            break;
        }
    }
    QCOMPARE(containsInsertedStaff, true);

    // 4. Clean up the database
    query.exec("DELETE FROM Staff WHERE StaffID = 1000");
}

void TestRemoveStaff::test_on_staffRemoveConfirmButton_clicked()
{
    // Test case: Check if on_staffRemoveConfirmButton_clicked function removes the selected staff
    // This test case involves database operations
    // You might need to set up a mock database or use a real database with known data for this test

    // 1. Set up the database and insert some known staff
    QSqlDatabase database = QSqlDatabase::database("DB1"); // Get the database.

    QSqlQuery query(database);
    query.exec("INSERT INTO Staff (StaffID, Name, DOB, Role, Salary) VALUES (1000, 'Test Staff', 02-03-2005, 'Coach', 25000)");

    // 2. Set the current text of the combo box to the staff you inserted
    removeStaff->ui->staffNameComboBox->setCurrentText("1000 - Test Staff");

    // 3. Call removeStaff->on_staffRemoveConfirmButton_clicked()
    removeStaff->on_staffRemoveConfirmButton_clicked();

    // 4. Check if the staff is removed from the database
    query.prepare("SELECT * FROM Staff WHERE StaffID = 1000");
    query.exec();
    bool staffRemoved = !query.next();
    QCOMPARE(staffRemoved, true);
}
