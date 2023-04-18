#include "myLib.h"
#include <iostream>

using namespace MySpace;
using std::cout;
using std::cin;
using std::endl;

int Array::length = 4;
int Functor::length = 4;

double _f1(Array& arr, double t) {
    double ret = - arr[0] + arr[1] - arr[2] + arr[3];
    return ret;
}

double _f2(Array& arr, double t) {
    double ret = - arr[0] + arr[2] - arr[3];
    return ret;
}

double _f3(Array& arr, double t) {
    double ret = arr[0] - arr[1] + arr[3] + t/10;
    return ret;
}

double _f4(Array& arr, double t) {
    double ret = arr[0] - arr[3] - t/10;
    return ret;
}

int main() {
    setlocale(LC_ALL, "rus");

    double t[] = {0, 1, 2};

    double xtest1[] = {0.1, -0.1, 0.1, -0.1};
    double xtest2[] = {1, 2, 3, 4};
    double xtest3[] = {4, 3, 2, 1};

    Array test1 = xtest1;
    Array test2 = xtest2;
    Array test3 = xtest3;

    fun f1 = _f1;
    fun f2 = _f2;
    fun f3 = _f3;
    fun f4 = _f4;

    fun ff[] = {f1, f2, f3, f4};

    Functor F(ff);

    cout << "F(" << test1 << ", " << t[0] << ") = " << F(test1, t[0]) << endl;
    cout << "F(" << test2 << ", " << t[1] << ") = " << F(test2, t[1]) << endl;
    cout << "F(" << test3 << ", " << t[2] << ") = " << F(test3, t[2]) << endl;

    cin.get();

    return 0;
}