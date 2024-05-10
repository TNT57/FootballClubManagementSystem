#include "addstaff.h"
#include "ui_addstaff.h"

AddStaff::AddStaff(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddStaff)
{
    ui->setupUi(this);
}

AddStaff::~AddStaff()
{
    qDebug() << "~AddStaff";
    delete ui;
}

void AddStaff::on_confirmButton_clicked()
{
    if (validateInput() == false ) {
        return;
   }
    QString staffId = ui->staffIdLineEdit->text();
    QString name = ui-> nameLineEdit-> text();
    QString dob = ui-> dobLineEdit -> text();
    QString role = ui -> roleLineEdit -> text();
    QString salary = ui -> salaryLineEdit -> text();
    // initialize database and query method to take data from the database
    QSqlDatabase db = QSqlDatabase::database("DB1");
    QSqlQuery query (db);
    query.prepare("insert into Staff(StaffID, Name, DOB, Role, Salary)"
                  "values('"+staffId + "','" + name + "','" + dob + "','" + role + "','" + salary + "')");
    query.exec();
    query.finish();
    query.clear();
    QMessageBox::information(this, "Note", "Added succesfully!");
}

bool AddStaff::validateInput(){
    QString staffId = ui->staffIdLineEdit->text();
    QString name = ui-> nameLineEdit-> text();
    QString dob = ui-> dobLineEdit -> text();
    QString role = ui -> roleLineEdit -> text();
    QString salary = ui -> salaryLineEdit -> text();
    // input should not be blanked
    if (staffId == "" || name == "" || dob == "" || role == "" || salary == ""){
        QMessageBox::critical(this, "Alert", "not blanked");
        return false;
    }
    // check if staff id is the same with the already id
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);
    query.prepare("select StaffID from Staff");
    query.exec();
    while (query.next()){
        QString existedId = query.value(0).toString();
        if(staffId == existedId){
             QMessageBox::critical(this, "Error", "Staff ID already existed!");
            query.finish();
            query.clear();
            return false;
        }
    }
    // check the id and salary is positive integer or not
    bool ok;
    int value = staffId.toInt(&ok);
    if (ok && value > 0) {
        // The input is a positive integer. You can use the integer value here.
        qDebug() << "The input is a positive integer: " << value;
    } else {
        // The input is not a positive integer. You might want to show an error message here.
        QMessageBox::critical(this, "Invalid input", "Staff id must be a positive integer.");
        return false;
    }
    int value2 = salary.toInt(&ok);
    if (ok && value2 > 0) {
        // The input is a positive integer. You can use the integer value here.
        qDebug() << "The input is a positive integer: " << value2;
    } else {
        // The input is not a positive integer. You might want to show an error message here.
        QMessageBox::critical(this, "Invalid input", "Salary must be a positive integer.");
        return false;
    }
    // check dob is in right format or not
    static QRegularExpression regex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/((19\\d{2}|200\\d|201\\d|202[0-3]))$");
    if (!regex.match(dob).hasMatch()) {
        QMessageBox::critical(this, "Error", "DOB format must be dd//mm//year");
        return false;
    }
    query.finish();
    query.clear();
    return true;
}
