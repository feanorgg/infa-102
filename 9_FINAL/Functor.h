#pragma once
#include "Array.h"

typedef double (*fun)(const Array &Y, double t);

class Functor {
    private:
        fun* fs;
        static int length;

    public:
        Functor() { fs = new fun[length]; };
        Functor(fun* _fs) {
            fs = new fun[length];
            for(int i = 0; i < length; i++) {
                fs[i] = _fs[i];
            }

            Array test(1.);
            cout << fs[0](test, 1.) << endl;
            cout << fs[1](test, 1.) << endl;
            cout << fs[2](test, 1.) << endl;
            cout << fs[3](test, 1.) << endl;
        }
        ~Functor();

        Array operator() (Array A, double v);
};

Functor::~Functor() {
    //delete[] func;
}

Array Functor::operator() (Array A, double v) {
    Array arr(0.);

    for(int i = 0; i < length; i++) {
        arr[i] = fs[i](A, v);
    }

    return arr;
}
