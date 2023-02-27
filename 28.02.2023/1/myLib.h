// Галкин Иван Андреевич, 102
// Задача к 4 семинару 2 семестра (Задания по теме 2_4.doc) - файл библиотеки к заданию 1

#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

namespace MySpace {
    class Array {
        private:
            double* data;
            static int length;
            char* name;

        public:
            Array(double in = 0);
            Array(double* arr);

            Array(double in, char* _name);
            Array(double* arr, char* _name);

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
            friend ostream & operator>> (ostream &os, const Array &arr);

            operator double() {
                double summ = 0;
                for(int i = 0; i < length; i++) {
                    summ += data[i]*data[i];
                }

                return sqrt(summ);
            }

            double& Array::operator[] (int i) {
                return data[i];
            }

            void UpdateName(char* str);
    };

    Array::Array(double in) {
        name = "Default";
        data = new double[length];
        for(int i = 0; i < length; i++) {
            data[i] = in;
        }
    }

    Array::Array(double* arr) {
        name = "Default";
        data = new double[length];
        for(int i = 0; i < length; i++) {
            data[i] = arr[i];
        }
    }

    Array::Array(double in, char* _name) {
        int len = strlen(_name) + 1;
        name = new char[len];
        strncpy(name, _name, len);

        data = new double[length];
        for(int i = 0; i < length; i++) {
            data[i] = in;
        }
    }

    Array::Array(double* arr, char* _name) {
        int len = strlen(_name) + 1;
        name = new char[len];
        strncpy(name, _name, len);

        data = new double[length];
        for(int i = 0; i < length; i++) {
            data[i] = arr[i];
        }
    }

    Array::~Array() {
        delete [] data;
        delete [] name;
    }

    int Array::Length() {
        return length;
    }

    Array::Array(const Array & arr2) {
        int len = strlen(arr2.name) + 1;
        name = new char[len];
        strncpy(name, arr2.name, len);

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

    ostream & operator>> (ostream &os, const Array &arr) {
        for(int i = 0; i < Array::Length(); i++) {
            os >> arr.data[i];
        }
    }

    void Array::UpdateName(char* str) {
        int len = strlen(str) + 1;
        name = new char[len];
        strncpy(name, str, len);
    }
}
