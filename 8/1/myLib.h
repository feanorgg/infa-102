#include <iostream>

using std::ostream;

namespace MySpace {
    // simple Array class
    class Array {
    private:
        double* data;
        static int length;
    public:
        Array() {}
        Array(int s) {
            data = new double[s];
            for(int i = 0; i < length; i++) {
                data[i] = 0.;
            }
        }
        Array(double* initial) {
            data = new double[length];
            int __len = sizeof(initial)/sizeof(initial[0]);
            for(int i = 0; i < length; i++) {
                if(i >= __len) {
                    data[i] = 0.;
                }
            }
        }
        ~Array() {
            delete [] data;
        }

        static int Length() {
            return length;
        }

        double& operator[] (int i) {
            return data[i];
        }

        Array & operator= (const double* & arr) {
            for(int i = 0; i < length; i++) {
                data[i] = arr[i];
            }

            return *this;
        }

        Array operator+ (const Array &arr) const {
            Array arr2(0);
            for(int i = 0; i < length; i++) {
                arr2.data[i] = data[i] + arr.data[i];
            }

            return arr2;
        }

        Array operator* (const double &x) const {
            Array arr2(0.0);
            for(int i = 0; i < length; i++) {
                arr2.data[i] = data[i] * x;
            }

            return arr2;
        }

        friend Array operator* (const double &x, const Array &arr);
        friend ostream & operator<< (ostream &os, const Array &arr);
    };

    Array operator* (const double &x, const Array &arr) {
        Array arr2(arr);
        for(int i = 0; i < Array::Length(); i++) {
            arr2.data[i] *= x;
        }

        return arr2;
    }

    ostream & operator<< (ostream &os, const Array &arr) {
        for(int i = 0; i < Array::Length(); i++) {
            os << arr.data[i];
            if(i < Array::Length() - 1) os << " ";
        }
        return os;
    }

    // functor class
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

        Array operator() (const Array& arr, double t) {
            return arr;
        }
    };

    // functional type
    typedef double (*fun) (Array&, double);

    // functions
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
}