// Q3: Write a program in C++ to compute the salaries of Employees of an
// organization who are having different designations. Use Virtual Base Class 
// or Classes. Make necessary assumptions.

#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int employeeID;

public:
    Employee(string empName, int empID) : name(empName), employeeID(empID) {}

    virtual double calculateSalary() = 0;

    void displayInfo() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Manager : public Employee {
private:
    double salary;

public:
    Manager(string empName, int empID, double empSalary)
        : Employee(empName, empID), salary(empSalary) {}

    double calculateSalary() override {
        return salary;
    }
};

class Developer : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    Developer(string empName, int empID, double rate, int hours)
        : Employee(empName, empID), hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    Manager manager("Manager 1", 101, 60000.0);
    Developer developer("Developer 1", 102, 25.0, 160);

    manager.displayInfo();
    cout << "Salary: $" << manager.calculateSalary() << endl;

    developer.displayInfo();
    cout << "Salary: $" << developer.calculateSalary() << endl;

    return 0;
}

