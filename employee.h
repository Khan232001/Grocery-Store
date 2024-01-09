#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include<iostream>
using namespace std;

class Employee {

public:
    friend istream& operator>>(istream& input, Employee& E);
    friend ostream& operator<<(ostream& out, const Employee& E);
    string name;
    string salary;
    int age;
    string gender;


};
#endif

