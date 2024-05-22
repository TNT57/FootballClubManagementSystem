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
}

void TestRemoveStaff::cleanupTestCase()
{
    // Clean-up after all test cases are executed
}

void TestRemoveStaff::test_populateStaff()
{

    // insert a new staff to the database
    QSqlDatabase database = QSqlDatabase::database("DB1"); // Get the database.

    QSqlQuery query(database);
    query.exec("INSERT INTO Staff (StaffID, Name, DOB, Role, Salary) VALUES (1000, 'Test Staff', '02-03-2005', 'Coach', 25000)");

    // call the function to see the staff in the combo box
    removeStaff->populateStaff();

    // Check if the combo box contains the staff you inserted into the database
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

    // Clean up the database
    query.exec("DELETE FROM Staff WHERE StaffID = 1000");
}

void TestRemoveStaff::test_on_staffRemoveConfirmButton_clicked()
{

    // insert the new staff to the database
    QSqlDatabase database = QSqlDatabase::database("DB1"); // Get the database.

    QSqlQuery query(database);
    query.exec("INSERT INTO Staff (StaffID, Name, DOB, Role, Salary) VALUES (1000, 'Test Staff', 02-03-2005, 'Coach', 25000)");

    // Set the current text of the combo box to the new staff
    removeStaff->ui->staffNameComboBox->setCurrentText("1000 - Test Staff");

    // Call the function to remove staff
    removeStaff->on_staffRemoveConfirmButton_clicked();

    // Check if the staff is removed from the database
    query.prepare("SELECT * FROM Staff WHERE StaffID = 1000");
    query.exec();
    bool staffRemoved = !query.next();
    QCOMPARE(staffRemoved, true);
}
