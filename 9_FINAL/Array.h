#include <iostream>
#pragma once

using namespace std;

class Array {
    private:
        double* data;
        static int length;
    public:
        Array() {
            data = new double[length];
            for(int i = 0; i < length; i++) {
                data[i] = 0.;
            }
        }
        
        Array(double fillwith) {
            data = new double[length];
            for(int i = 0; i < length; i++) {
                data[i] = fillwith;
            }
        }

        Array(double* initial) {
            data = new double[length];
            for(int i = 0; i < length; i++) {
                data[i] = initial[i];
            }
        }

        ~Array() {
            //delete [] data;
        }

        static int Length() {
            return length;
        }

        double& operator[] (int i) {
            return data[i];
        }

        Array & operator= (const double* &arr) {
            for(int i = 0; i < length; i++) {
                data[i] = arr[i];
            }

            return *this;
        }

        Array & operator= (const Array &arr) {
            if(this == &arr) {
                return *this;
            }

            for(int i = 0; i < length; i++) {
                data[i] = arr.data[i];
            }

            return *this;
        }

        Array operator+ (const Array &arr) const {
            Array arr2(0.);
            for(int i = 0; i < length; i++) {
                arr2.data[i] = data[i] + arr.data[i];
            }

            return arr2;
        }

        Array operator+= (const Array &arr) const {
            for(int i = 0; i < length; i++) {
               data[i] += arr.data[i];
            }

            return *this;
        }

        Array operator* (const double &x) const {
            Array arr2(0.);
            for(int i = 0; i < length; i++) {
                arr2.data[i] = data[i] * x;
            }

            return arr2;
        }

        Array operator/ (const double &x) const {
            Array arr2(0.);
            for(int i = 0; i < length; i++) {
                arr2.data[i] = data[i] / x;
            }

            return arr2;
        }

        friend Array operator* (const double &x, const Array &arr);
        friend ostream & operator<< (ostream &os, const Array &arr);
};

Array operator* (const double &x, const Array &arr) {
    Array arr2(arr);
    for(int i = 0; i < Array::Length(); i++) {
        arr2.data[i] = x * arr2.data[i];
    }

    return arr2;
}

ostream & operator<< (ostream &os, const Array &arr) {
    for(int i = 0; i < Array::Length(); i++) {
        os << arr.data[i] << " ";
    }

    return os;
}
