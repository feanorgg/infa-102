// Галкин Иван Андреевич, 102
// Задача к 3 семинару 2 семестра (Задания по теме 2_3.doc) - код для проверки выполнения задания 2 (myLib.h)

#include <iostream>
#include "myLib.h"

using std::cin;
using std::cout;
using namespace MySpace;

int Array::length = 5;

int main() {
    Array arr1(1);
    Array arr2(2);

    cout << "Created arr1:" << endl;
    cout << arr1 << endl;

    cout << "Created arr2:" << endl;
    cout << arr2 << endl;

    cout << "arr3 = arr1 + arr2:" << endl;
    Array arr3 = arr1 + arr2;
    cout << arr3 << endl;

    cout << "arr4 = arr1 * 0.5:" << endl;
    Array arr4 = arr1 * 0.5;
    cout << arr4 << endl;

    cout << "arr5 = 2 * arr1:" << endl;
    Array arr5 = 2 * arr1;
    cout << arr5 << endl;

    return 0;
}