#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int employee_id;
    string employee_name;
    string designation;
    string department;
    int years_of_experience;

public:
    void read_info() {
        cout << "Enter Employee ID: ";
        cin >> employee_id;
        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, employee_name);

        cout << "Enter Designation: ";
        getline(cin, designation);

        cout << "Enter Employee Department: ";
        getline(cin, department);

        cout << "Enter Years of Experience: ";
        cin >> years_of_experience;
    }

    void display_info() {
        cout << "\nEmployee Information:\n"
               << "Employee ID: " << employee_id << "\n"
               << "Employee Name: " << employee_name << "\n"
               << "Designation: " << designation << "\n"
               << "Employee Department: " << department << "\n"
               << "Years of Experience: " << years_of_experience << "\n";
    }
};

int main() {
    Employee employee;

    employee.read_info();
    employee.display_info();

    return 0;
}
