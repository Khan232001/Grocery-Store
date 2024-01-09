#include "employee.h"

istream& operator>>(istream& input, Employee& E) {
    cout << "Enter name:" << endl;
   input >> E.name;//Please don't put space between the name because the string is taking only the first word not the words after the space
    cout << "Enter Gender:" << endl;
    input >> E.gender;
    cout << "Enter age:" << endl;
    input >> E.age;
    cout << "Enter Salary:" << endl;
    input >> E.salary;

    return input;
}
ostream& operator<<(ostream& out, const Employee& E) {

    out << "Name: " << E.name << endl;
    out << "Gender: " << E.gender << endl;
    out << "Age: " << E.age << endl;
    out << "Salary: " << E.salary << endl;

    return out;

}
