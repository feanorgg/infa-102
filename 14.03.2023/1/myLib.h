// Галкин Иван Андреевич, 102
// Задача к 5 семинару 2 семестра (Задания по теме 2_5.doc) - файл библиотеки к заданию 1

#include <iostream>
#include <cmath>
#include <string>
#include <exception>
#include <fstream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::exception;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::string;
using std::to_string;
using std::getline;
using std::atof;

namespace MySpace {
    class Array {
        private:
            double* data;
            static int length;
            char* name;
            char* filename;

        public:
            Array(double in = 0);
            Array(double* arr);

            Array(double in, char* _name);
            Array(double* arr, char* _name);

            Array(double in, char* _name, char* _filename);
            Array(double* arr, char* _name, char* _filename);

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

            friend Array operator* (const double &x, const Array &arr);
            friend ostream & operator<< (ostream &os, const Array &arr);
            friend ofstream & operator<< (ofstream &ofs, const Array &arr);
            friend istream & operator>> (istream &is, const Array &arr);
            friend ifstream & operator>> (ifstream &ifs, const Array &arr);

            operator double() {
                double summ = 0;
                for(int i = 0; i < length; i++) {
                    summ += data[i]*data[i];
                }

                return sqrt(summ);
            }

            double& operator[] (int i) {
                if(i < 0) {
                    throw "Index is out of range.";
                } else if(i >= length) {
                    throw "Index is out of range.";
                }

                return data[i];
            }

            void UpdateName(char* str);

            Array operator+ (const Array &arr2) {
                Array arr3;
                for(int i = 0; i < Array::Length(); i++) {
                    arr3.data[i] = data[i] + arr2.data[i];
                }

                return arr3;
            }

            Array operator/ (const double &x) {
                if(x == 0) {
                    throw "Divide by zero is forbidden.";
                }

                Array arr2;
                for(int i = 0; i < length; i++) {
                    arr2.data[i] = data[i] / x;
                }

                return arr2;
            }

            Array operator* (const double &x) {
                Array arr2;
                for(int i = 0; i < Array::Length(); i++) {
                    arr2.data[i] = data[i] * x;
                }

                return arr2;
            }

            char* GetFileName();
            void SetFileName(char* _filename);
    };

    char* Array::GetFileName() {
        return filename;
    }

    void Array::SetFileName(char* _filename) {
        filename = _filename;
    }

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

    Array::Array(double in, char* _name, char* _filename) {
        int len = strlen(_name) + 1;
        name = new char[len];
        strncpy(name, _name, len);

        int len2 = strlen(_filename) + 1;
        filename = new char[len2];
        strncpy(filename, _filename, len2);

        data = new double[length];
        for(int i = 0; i < length; i++) {
            data[i] = in;
        }
    }

    Array::Array(double* arr, char* _name, char* _filename) {
        int len = strlen(_name) + 1;
        name = new char[len];
        strncpy(name, _name, len);

        int len2 = strlen(_filename) + 1;
        filename = new char[len2];
        strncpy(filename, _filename, len2);

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

    ofstream & operator<< (ofstream &ofs, const Array &arr) {
        for(int i = 0; i < Array::Length(); i++) {
            ofs << to_string(arr.data[i]) << endl;
        }

        return ofs;
    }

    istream & operator>> (istream &is, const Array &arr) {
        double input = 0.0;
        for(int i = 0; i < Array::Length(); i++) {
            try {
                is >> input;
            }
            catch (exception E) {
                throw "Input error.";
            }
            arr.data[i] = input;
        }

        return is;
    }

    ifstream & operator>> (ifstream &ifs, const Array &arr) {
        double input = 0.0;
        string line = "";

        for(int i = 0; i < Array::Length(); i++) {
            try {
                getline(ifs, line);
                input = atof(line.c_str());
            }
            catch (exception E) {
                throw "Input error: not enough data";
            }
            arr.data[i] = input;
        }

        return ifs;
    }

    void Array::UpdateName(char* str) {
        int len = strlen(str) + 1;
        name = new char[len];
        strncpy(name, str, len);
    }
}
