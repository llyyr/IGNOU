// Q2: Write a program in C++ to find the sum of elements in an array using 
// Function Template. Make necessary assumptions.

#include <iostream>

using namespace std;

template <typename T>
T sumArray(const T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    int intSum = sumArray(intArray, 5);
    float floatSum = sumArray(floatArray, 5);
    double doubleSum = sumArray(doubleArray, 5);

    cout << "Sum of integers: " << intSum << endl;
    cout << "Sum of floats: " << floatSum << endl;
    cout << "Sum of doubles: " << doubleSum << endl;

    return 0;
}
