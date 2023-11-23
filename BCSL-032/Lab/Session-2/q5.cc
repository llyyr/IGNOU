#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string student_name;

public:
    // Constructor
    Student(const string& name) : student_name(name) {
        cout << "Constructor called. Student name: " << student_name << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called. Student name: " << student_name << endl;
    }

    // Function to access the private data member
    void display_student_name() {
        cout << "Student name: " << student_name << endl;
    }
};

int main() {
    Student student1("Test Student");

    // Attempt to access the private data member from outside the class
    // cout << student1.student_name;

    student1.display_student_name();
    return 0;
}
