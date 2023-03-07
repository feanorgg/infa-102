#include "Matrix.h"

using namespace std;

int main() {
    Matrix A(3, 3);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(0, 2) = 3;
    A(1, 0) = 4;
    A(1, 1) = 5;
    A(1, 2) = 6;
    A(2, 0) = 7;
    A(2, 1) = 8;
    A(2, 2) = 10;

    // 1 2 3
    // 4 5 6
    // 7 8 10

    Matrix B(3, 1);
    B(0, 0) = 1;
    B(1, 0) = 2;
    B(2, 0) = 3;

    // 1
    // 2
    // 3

    Matrix X = Matrix::gauss_jordan(A, B);

    cout << X << endl;
    return 0;
}