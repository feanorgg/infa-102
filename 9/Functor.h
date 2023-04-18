#include "Array.h"
#pragma once

typedef double (*fun) (Array&, double);

class Functor {
private:
    fun* data;
    static int length;
public:
    Functor() {
        data = new fun[0];
    }
    Functor(fun* fs) {
        data = new fun[length];
        data = fs;
    }
    ~Functor() { delete [] data; }

    Array operator() (Array& arr, double t) {
        double r[length];
        for(int i = 0; i < length; i++) {
            r[i] = data[i](arr, t);
        }
        
        Array ret = r;

        return ret;
    }
};
