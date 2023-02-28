// Галкин Иван Андреевич, 102
// Задача к 4 семинару 2 семестра (Задания по теме 2_4.doc) - код для проверки выполнения задания 1 (myLib.h)

#include <iostream>
#include "myLib.h"

using std::cin;
using std::cout;
using namespace MySpace;

int Array::length = 5;

int main() {
    double initial_data[5] = {0, 1, 2, 3, 4};
    Array arr(initial_data, "Object 1");

    cout << arr << endl;

    Array arr2(0.0, "Object 2");
    cout << "Type in " << Array::Length() << " values for a new array:" << endl;
    cin >> arr2;

    cout << arr2 << endl;

    return 0;
}