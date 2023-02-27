// Галкин Иван Андреевич, 102
// Задача к 3 семинару 2 семестра (Задания по теме 2_3.doc) - файл библиотеки к заданию 2

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

namespace MySpace {
    class Array {
        private:
            double* data;
            static int length;

        public:
            Array(double in = 0);
            ~Array();

            static int Length();

            Array(const Array & arr2);

            Array & operator= (const Array & arr) {
                if(this == &arr) return *this;
                for(int i = 0; i < length; i++) {
                    data[i] = arr.data[i];
                }

                return *this;
            }

            friend Array operator+ (const Array &arr1, const Array &arr2);
            friend Array operator* (const Array &arr, const double &x);
            friend Array operator* (const double &x, const Array &arr);
            friend ostream & operator<< (ostream &os, const Array &arr);
    };

    Array::Array(double in) {
        data = new double[length];
        for(int i = 0; i < length; i++) {
            data[i] = in;
        }
    }

    Array::~Array() {
        delete [] data;
    }

    int Array::Length() {
        return length;
    }

    Array::Array(const Array & arr2) {
        data = new double[length];
        for(int i = 0; i < length; i++) {
            data[i] = arr2.data[i];
        }
    }

    Array operator+ (const Array &arr1, const Array &arr2) {
        Array arr3;
        for(int i = 0; i < Array::Length(); i++) {
            arr3.data[i] = arr1.data[i] + arr2.data[i];
        }

        return arr3;
    }

    Array operator* (const Array &arr, const double &x) {
        Array arr2(arr);
        for(int i = 0; i < Array::Length(); i++) {
            arr2.data[i] *= x;
        }

        return arr2;
    }

    Array operator* (const double &x, const Array &arr) {
        Array arr2(arr);
        for(int i = 0; i < Array::Length(); i++) {
            arr2.data[i] *= x;
        }

        return arr2;
    }

    ostream & operator<< (ostream &os, const Array &arr) {
        os << "Array: [";
        for(int i = 0; i < Array::Length(); i++) {
            os << arr.data[i];
            if(i < Array::Length() - 1) os << ", ";
        }

        os << "]";

        return os;
    }
}

/*

Array & operator+ (const Array & arr) {
                for(int i = 0; i < length; i++) {
                    data[i] += arr.data[i];
                }

                return *this;
            }

            Array & operator* (const double & x) {
                for(int i = 0; i < length; i++) {
                    data[i] *= x;
                }

                return *this;
            }

*/