#include "Employee.h"
#include <iomanip>

Employee::Employee() {}

Employee::Employee(string n, string g, string bd, string wd, string e, string p, string a, string ph)
    : name(n), gender(g), birthDate(bd), workDate(wd), education(e), position(p), address(a), phone(ph) {}

void Employee::display() const {
    cout << left
        << setw(12) << name
        << setw(8) << gender
        << setw(12) << birthDate
        << setw(12) << workDate
        << setw(10) << education
        << setw(12) << position
        << setw(20) << address
        << setw(15) << phone << endl;
}