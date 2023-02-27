// Галкин Иван Андреевич, 102
// Задача к 3 семинару 2 семестра (Задания по теме 2_3.doc) - код для проверки выполнения задания 3 (myLib.h)

#include <iostream>
#include "myLib.h"

using std::cin;
using std::cout;
using namespace MySpace;

int Matrix::N = 5;

int main() {
    Matrix mtx(1);

    cout << mtx;

    cout << "mtx2(mtx):" << endl;
    Matrix mtx2(mtx);

    cout << mtx2;

    cout << "mtx3 = mtx2:" << endl;
    Matrix mtx3 = mtx2;

    cout << mtx3;

    return 0;
}