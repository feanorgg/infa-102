// Галкин Иван Андреевич, 102
// Задача к 4 семинару 2 семестра (Задания по теме 2_4.doc) - код для проверки выполнения задания 2 (myLib.h)

#include <iostream>
#include "myLib.h"

using std::cin;
using std::cout;
using namespace MySpace2;

template <typename T>
int TArray<T>::length = 5;

int MySpace::Array::length = 5;

int main() {
    double initial_data[5] = {0, 1, 2, 3, 4};
    TArray<double> arr1(initial_data, "Object 1");

    cout << arr1 << endl;

    MySpace::Array single(7.7, "Single");

    MySpace::Array initial_arr_data[5] = {single, single, single, single, single};

    TArray<MySpace::Array> arr2(initial_arr_data, "Object 2");
    cout << arr2 << endl;

    return 0;
}