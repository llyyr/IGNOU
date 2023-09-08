// Q1: Write a program in C++ for multiplication of two sparse matrices using 
// pointers.

#include <iostream>
#include <vector>

using namespace std;

struct SparseMatrix {
    int rows, cols;
    vector<vector<int>> data;
};

SparseMatrix mult(const SparseMatrix &A, const SparseMatrix &B) {
    if (A.cols != B.rows) {
        cout << "Matrix dimensions are not compatible for multiplication" << endl;
        exit(1);
    }

    SparseMatrix result;
    result.rows = A.rows;
    result.cols = B.cols;
    result.data.resize(A.rows, vector<int>(B.cols, 0));

    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            int dot_product = 0;
            for (int k = 0; k < A.cols; k++)
                dot_product += A.data[i][k] * B.data[k][j];
            result.data[i][j] = dot_product;
        }
    }

    return result;
}

int main() {
    SparseMatrix A, B, result;

    A.rows = 3;
    A.cols = 2;
    A.data = {{1, 2}, {3, 4}, {5, 6}};

    B.rows = 2;
    B.cols = 4;
    B.data = {{1, 2, 3, 4}, {5, 6, 7, 8}};

    result = mult(A, B);

    cout << "Result matrix:" << endl;
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++)
            cout << result.data[i][j] << " ";
        cout << endl;
    }

    return 0;
}
