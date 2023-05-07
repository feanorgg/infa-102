#pragma once
#include <iostream>
#include <cmath>

using std::ostream;
using std::istream;
using std::cout;

class Array {
    private:
        double* data;
        int N;

    public:
        Array();
        Array(int);
        Array(double init);
        Array(const Array& a);
        Array(double* init, int size);
        ~Array();

        int Length() const;
        void changeSize(int);

        const double& operator[] (int i) const { return data[i]; }
        double& operator[] (int i) { return data[i]; }

        Array& operator=(const Array& a);
        Array operator+(const Array& a);
        Array operator += (const Array& A);

        Array operator* (const double& d);
        double operator* (const Array& A);
        operator double();

        friend Array operator/ (const Array& A, double);
        friend Array operator* (const double& d, const Array& a);
        friend ostream& operator<< (ostream& os, const Array& a);
};

Array::Array(double init) {
    N = 1;
    data = new double[N];

    for(int i = 0; i < N; i++) {
        data[i] = init;
    }
}

Array::Array() {
    N = 1;
    data = new double[N];
}

Array::Array(int size) {
    N = size;
    data = new double[N];

    for(int i = 0; i < N; i++) {
        data[i] = 0;
    }
}

Array::Array(double* init, int size) {
    Array::N = size;
    data = new double[N];

    for(int i = 0; i < N; i++) {
        data[i] = init[i];
    }
}

Array::Array(const Array& a) {
    N = a.Length();
    data = new double[N];

    for (int i = 0; i < N; i++) {
        data[i] = a.data[i];
    }
}

Array& Array::operator= (const Array& a) {
    N = a.Length();

    for(int i = 0; i < N; i++) {
        data[i] = a.data[i];
    }

    return *this;
}

Array Array::operator+ (const Array& a) {
    Array b(N);

    for(int i = 0; i < b.Length(); i++) {
        b.data[i] = a.data[i] + data[i];
    }

    return(b);
}

Array::operator double() {
    double summ = 0;

    for(int i = 0; i < N; i++) {
        summ += data[i] * data[i];
    }
        
    return(sqrt(summ));
}

Array Array::operator* (const double& d) {
    Array b;

    for(int i = 0; i < N; i++) {
        b.data[i] = data[i] * d;
    }
    return(b);
}

double Array::operator* (const Array& A) {
    double b = 0;

    for(int i = 0; i < N; i++) {
        b += data[i] * A[i];
    }
    return(b);
}

Array operator* (const double& d, const Array& a) {
    Array b(a.Length());

    for(int i = 0; i < b.Length(); i++) {
        b.data[i] = a.data[i] * d;
    }
        
    return(b);
}

Array Array::operator+= (const Array& A) {
    for(int i = 0; i < N; i++) {
        data[i] += A.data[i];
    }

    return(*this);
}

Array operator/ (const Array& A, double x) {
    Array A1;

    for(int i = 0; i < A1.Length(); i++) {
        A1.data[i] = A.data[i] / x;
    }
    
    return A1;
}

ostream& operator<< (ostream& os, const Array& a) {
    for(int i = 0; i < a.Length(); i++) {
        os << a.data[i] << " ";
    }

    cout << "\n";
    return(os);
}

Array::~Array() {
    delete[] data;
}

int Array::Length() const {
    return(N);
}

void Array::changeSize(int size) {
    N = size;
    delete[] data;
    data = new double[N];
}
