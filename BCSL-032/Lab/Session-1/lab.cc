#include <cstdint>
#include <iostream>
#include <algorithm>

using namespace std;

// Problem 1:
// Write a program in C++ to find and print the all basic data types of C++.
static inline int q1() {
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Size of bool: " << sizeof(bool) << " byte" << endl;
    return 0;
}

// Problem 2:
// Write a program in C++ to explain the use of for loop, while loop,
// switch-case, break and continue statements.
static inline int q2() {
    cout << "for-loop example:" << endl;
    for (int i = 1; i <= 5; i++)
        cout << i << " ";
    cout << endl;

    cout << "while-loop example:" << endl;
    int j = 1;
    while (j <= 5) {
        cout << j << " ";
        ++j;
    }
    cout << endl;

    cout << "switch-case example:" << endl;
    char grade = 'B';
    switch (grade) {
        case 'A':
            cout << "Grade = A" << endl;
            break;
        case 'B':
            cout << "Grade = B" << endl;
            break;
        case 'C':
            cout << "Grade = C" << endl;
            break;
        default:
            cout << "Invalid grade." << endl;
    }

    cout << "break and continue example:";
    for (int k = 1; k <= 10; k++) {
        cout << endl;
        if (k == 5) {
            cout << "Breaking the loop at k = 5." << endl;
            break;
        }
        if (k % 2 == 0) {
            cout << k << " (even) ";
            continue;
        }
        cout << k;
    }

    return 0;
}

// Problem 3:
// Write a program in C++ to find the maximum marks, average marks and minimum 
// marks obtained by a student in five papers as given below:
// Paper 1: 50; Paper 2: 70; Paper 3: 65; Paper 4: 80; Paper 5: 56;
static inline int q3() {
    int marks_paper1 = 50;
    int marks_paper2 = 70;
    int marks_paper3 = 65;
    int marks_paper4 = 80;
    int marks_paper5 = 56;
    int maximum_marks = max({marks_paper1, marks_paper2, marks_paper3, marks_paper4, marks_paper5});
    int minimum_marks = min({marks_paper1, marks_paper2, marks_paper3, marks_paper4, marks_paper5});
    float average_marks = static_cast<float>(marks_paper1 + marks_paper2 + marks_paper3 + marks_paper4 + marks_paper5) / 5;
    cout << "Maximum Marks: " << maximum_marks << endl;
    cout << "Minimum Marks: " << minimum_marks << endl;
    cout << "Average Marks: " << average_marks << endl;
    return 0;
}

static int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

static bool is_prime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return false;
    return true;
}

static inline void fibonacci(int n) {
    uint64_t n1 = 0, n2 = 1, tmp;
    cout << "Fibonacci series of " << n << " numbers: " << endl;
    for (int i = 0; i < n; i++) {
        cout << n1 << " ";
        tmp = n1 + n2;
        n1 = n2;
        n2 = tmp;
    }
    cout << endl;
}

// Problem 4:
// Write a program in C++ that:
// (i) prints the factorial of a given number,
// (ii) prints whether the given number is prime or not,
// (iii) generate a Fibonacci series of 50 numbers.
static inline int q4() {
    int num_factorial = 11;
    cout << "Factorial of " << num_factorial << " is: " << factorial(num_factorial) << endl;

    int num_prime = 17;
    if (is_prime(num_prime))
        cout << num_prime << " is a prime" << endl;
    else
        cout << num_prime << " is not a prime" << endl;

    fibonacci(50);
    return 0;
}

int main() {
    q1();
    cout << endl;
    q2();
    cout << endl;
    q3();
    cout << endl;
    q4();
}
