// Галкин Иван Андреевич, 102
// Задача к 4 семинару 2 семестра (Задания по теме 2_4.doc) - файл библиотеки к заданию 2

#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

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

            Array operator+ (const Array &arr) const {
                Array arr2(0.0);
                for(int i = 0; i < length; i++) {
                    arr2.data[i] = data[i] + arr.data[i];
                }

                return arr2;
            }

            Array operator* (const double &x) const {
                Array arr2(0.0);
                for(int i = 0; i < Array::Length(); i++) {
                    arr2.data[i] = data[i] * x;
                }

                return arr2;
            }

            friend Array operator* (const double &x, const Array &arr);
            friend ostream & operator<< (ostream &os, const Array &arr);
            friend istream & operator>> (istream &is, const Array &arr);

            operator double() {
                double summ = 0;
                for(int i = 0; i < length; i++) {
                    summ += data[i]*data[i];
                }

                return sqrt(summ);
            }

            double& operator[] (int i) {
                return data[i];
            }

            void UpdateName(char* str);
    };

    Array::Array(double in) {
        char* def = "Default";
        int len = strlen(def) + 1;
        name = new char[len];
        strncpy(name, def, len);

        data = new double[length];
        for(int i = 0; i < length; i++) {
            data[i] = in;
        }
    }

    Array::Array(double* arr) {
        char* def = "Default";
        int len = strlen(def) + 1;
        name = new char[len];
        strncpy(name, def, len);

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

    Array operator* (const double &x, const Array &arr) {
        Array arr2(arr);
        for(int i = 0; i < Array::Length(); i++) {
            arr2.data[i] *= x;
        }

        return arr2;
    }

    ostream & operator<< (ostream &os, const Array &arr) {
        os << arr.name << ": [";
        for(int i = 0; i < Array::Length(); i++) {
            os << arr.data[i];
            if(i < Array::Length() - 1) os << ", ";
        }

        os << "]";

        return os;
    }

    istream & operator>> (istream &is, const Array &arr) {
        double input = 0.0;
        for(int i = 0; i < Array::Length(); i++) {
            is >> input;
            arr.data[i] = input;
        }

        return is;
    }

    void Array::UpdateName(char* str) {
        int len = strlen(str) + 1;
        name = new char[len];
        strncpy(name, str, len);
    }
}

namespace MySpace2 {
    template <typename T>
    class TArray {
        private:
            T* data;
            char* name;
            static int length;

        public:
            TArray() {
                data = new T[length];

                char* def = "Default";
                int len = strlen(def) + 1;
                name = new char[len];
                strncpy(name, def, len);
            }

            TArray(T* initial) {
                data = new T[length];
                for(int i = 0; i < length; i++) {
                    data[i] = initial[i];
                }

                char* def = "Default";
                int len = strlen(def) + 1;
                name = new char[len];
                strncpy(name, def, len);
            }

            TArray(T in) {
                data = new T[length];
                for(int i = 0; i < length; i++) {
                    data[i] = in;
                }
                
                char* def = "Default";
                int len = strlen(def) + 1;
                name = new char[len];
                strncpy(name, def, len);
            }

            TArray(T* initial, char* str) {
                data = new T[length];
                for(int i = 0; i < length; i++) {
                    data[i] = initial[i];
                }

                int len = strlen(str) + 1;
                name = new char[len];
                strncpy(name, str, len);
            }

            TArray(T in, char* str) {
                data = new T[length];
                for(int i = 0; i < length; i++) {
                    data[i] = in;
                }

                int len = strlen(str) + 1;
                name = new char[len];
                strncpy(name, str, len);
            }

            ~TArray() {
                delete [] data;
                delete [] name;
            }

            static int Length() {
                return length;
            }

            TArray(const TArray & arr2) {
                int len = strlen(arr2.name) + 1;
                name = new char[len];
                strncpy(name, arr2.name, len);

                data = new T[length];
                for(int i = 0; i < length; i++) {
                    data[i] = arr2.data[i];
                }
            }

            TArray & operator= (const TArray & arr) {
                if(this == &arr) return *this;
                for(int i = 0; i < length; i++) {
                    data[i] = arr.data[i];
                }

                return *this;
            }

            friend TArray operator+ (const TArray &arr1, const TArray &arr2) {
                TArray arr3;
                for(int i = 0; i < TArray::Length(); i++) {
                    arr3.data[i] = arr1.data[i] + arr2.data[i];
                }

                return arr3;
            }

            // Убрал перегрузку *, т. к. нет строгих инструкций для каждого типа
            // friend TArray operator* (const TArray &arr, const double &x);
            // friend TArray operator* (const double &x, const Array &arr);
            friend ostream & operator<< (ostream &os, const TArray &arr) {
                os << arr.name << ": [";
                for(int i = 0; i < TArray::Length(); i++) {
                    os << arr.data[i];
                    if(i < TArray::Length() - 1) os << ", ";
                }

                os << "]";

                return os;
            }

            friend istream & operator>> (istream &is, const TArray &arr) {
                T input = 0.0;
                for(int i = 0; i < TArray::Length(); i++) {
                    is >> input;
                    arr.data[i] = input;
                }

                return is;
            }

            T& operator[] (int i) {
                return data[i];
            }

            void UpdateName(char* str) {
                int len = strlen(str) + 1;
                name = new char[len];
                strncpy(name, str, len);
            }
    };
}