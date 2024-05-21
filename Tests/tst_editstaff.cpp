#include "tst_editstaff.h"

TestEditStaff::TestEditStaff()
{
    editStaff = new EditStaff();
}

TestEditStaff::~TestEditStaff()
{
    delete editStaff;
}

void TestEditStaff::initTestCase()
{
    // Initialization before running tests
}

void TestEditStaff::cleanupTestCase()
{
    // Cleanup after running tests
}

void TestEditStaff::test_loadStaff()
{
    // Test that the staffIdComboBox is populated with staff IDs from the database
    editStaff->loadStaff();
    QVERIFY(editStaff->ui->staffIdComboBox->count() > 0);
}

void TestEditStaff::test_on_confirmButton_clicked()
{
    // Add a new staff member
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query(db);
    query.prepare("INSERT INTO Staff (StaffID, Name, DOB, Role, Salary) VALUES (:staffId, :name, :dob, :role, :salary)");
    query.bindValue(":staffId", 9999);
    query.bindValue(":name", "Test Staff");
    query.bindValue(":dob", QDate::fromString("02-03-1995", "dd-MM-yyyy"));
    query.bindValue(":role", "Coach");
    query.bindValue(":salary", "1000");
    if (!query.exec()) {
        QFAIL("Failed to insert staff");
    }

    // Load the staff into the combo box
    editStaff->loadStaff();
    editStaff->ui->staffIdComboBox->setCurrentText("9999");

    // Edit the staff's information
    editStaff->ui->nameLineEdit->setText("New Name");
    editStaff->ui->dobLineEdit->setText("02-03-2005");
    editStaff->ui->salaryLineEdit->setText("5000");
    editStaff->on_confirmButton_clicked();

    // Check that the name, DOB, and salary were updated correctly
    query.prepare("SELECT * FROM Staff WHERE StaffID = :staffId");
    query.bindValue(":staffId", 9999);
    if (query.exec() && query.next()) {
        QCOMPARE(query.value("Name").toString(), QString("New Name"));
        QCOMPARE(query.value("DOB").toString(), QString("02-03-2005"));
        QCOMPARE(query.value("Salary").toString(), QString("5000"));
    } else {
        QFAIL("Failed to load staff data");
    }

    // Delete the staff member
    query.prepare("DELETE FROM Staff WHERE StaffID = :staffId");
    query.bindValue(":staffId", 9999);
    if (!query.exec()) {
        QFAIL("Failed to delete staff");
    }
}

void TestEditStaff::test_validateInput()
{
    // Test that the validateInput method correctly validates the input
    editStaff->ui->newStaffIdLineEdit->setText("invalid");
    editStaff->ui->salaryLineEdit->setText("invalid");
    QVERIFY(!editStaff->validateInput());
    editStaff->ui->newStaffIdLineEdit->setText("1");
    editStaff->ui->salaryLineEdit->setText("1");
    QVERIFY(editStaff->validateInput());
}

//QTEST_MAIN(TestEditStaff)
//#include "tst_editstaff.moc"
