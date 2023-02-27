// Галкин Иван Андреевич, 102
// Задача к 3 семинару 2 семестра (Задания по теме 2_3.doc) - файл библиотеки к заданию 3

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

namespace MySpace {
    class Matrix {
        private:
            double** data;
            static int N;

        public:
            Matrix(double in = 0);
            ~Matrix();

            static int Length();

            Matrix(const Matrix & mtx2);

            Matrix & operator= (const Matrix & mtx) {
                if(this == &mtx) return *this;

                for(int i = 0; i < N; i++) {
                    for(int j = 0; j < N; j++) {
                        data[i][j] = mtx.data[i][j];
                    }
                }

                return *this;
            }

            friend ostream & operator<< (ostream &os, const Matrix &mtx);
    };

    Matrix::Matrix(double in) {
        data = new double* [N];
        for(int i = 0; i < N; i++) {
            data[i] = new double [N];
            for(int j = 0; j < N; j++) {
                data[i][j] = in;
            }
        }
    }

    Matrix::~Matrix() {
        for(int i = 0; i < N; i++) {
            delete [] data[i];
        }
        delete [] data;
    }

    int Matrix::Length() {
        return N;
    }

    Matrix::Matrix(const Matrix & mtx2) {
        data = new double* [N];
        for(int i = 0; i < N; i++) {
            data[i] = new double [N];
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                data[i][j] = mtx2.data[i][j];
            }
        }
    }

    ostream & operator<< (ostream &os, const Matrix &mtx) {
        os << "Matrix:" << endl;
        for(int i = 0; i < Matrix::Length(); i++) {
            for(int j = 0; j < Matrix::Length(); j++) {
                os << mtx.data[i][j] << " ";
            }

            os << endl;
        }

        return os;
    }
}
