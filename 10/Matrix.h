#pragma once

using namespace std;

class Matrix {
    private:
        Array* mtx;
        int N;

    public:
        Matrix();
        Matrix(int);
        Matrix(const Matrix& m);
        Matrix(Array* init, int size);
        ~Matrix();

        const Array& operator[](int i) const { 
            return mtx[i];
        }
        
        Array& operator[](int i) {
            return mtx[i];
        }

        int Length() const;
        
        double det();
        double add(int i,int j);

        Matrix& operator=(const Matrix& a);
        Matrix operator+(const Matrix& a);

        Matrix operator*(const double& d);
        Matrix operator*(const Matrix& d);
        Array operator*(const Array& a);

        friend Matrix operator*(const double& d, const Matrix& a);
        friend ostream& operator<<(ostream& os, const Matrix& a);
};

Matrix::Matrix(int size) {
    N = size;
    mtx = new Array[N];

    for (int i = 0; i < N; i++) {
        mtx[i].changeSize(N);
        mtx[i] = Array(N);
    }
}

Matrix::Matrix() {
    N = 1;
    mtx = new Array[N];

    for (int i = 0; i < N; i++) {
        mtx[i].changeSize(N);
        mtx[i] = Array(N);
    }
}

Matrix::Matrix(Array* init, int size) {
    N = size;
    mtx = new Array[N];

    for (int i = 0; i < N; i++) {
        mtx[i].changeSize(N);
        mtx[i] = init[i];
    }
}

Matrix::Matrix(const Matrix& m) {
    N = m.Length();
    mtx = new Array [N];

    for (int i = 0; i < N; i++) {
        mtx[i].changeSize(N);
        mtx[i] = m.mtx[i];
    }
}

Matrix& Matrix::operator=(const Matrix& a) {
    N = a.Length();

    for (int i = 0; i < N; i++) {
        mtx[i] = a.mtx[i];
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix& a) {
    Matrix b(a.Length());

    for (int i = 0; i < N; i++) {
        b.mtx[i] = mtx[i] + a.mtx[i];
    }
    return(b);
}

Matrix Matrix::operator*(const double& d) {
    Matrix b(N);

    for (int i = 0; i < N; i++) {
        b.mtx[i] = mtx[i] * d;
    }

    return(b);
}

Matrix operator*(const double& d, const Matrix& a) {
    Matrix b(a.Length());

    for (int i = 0; i < a.Length(); i++) {
        b.mtx[i] = a.mtx[i] * d;
    }

    return(b);
}

Matrix transpose(const Matrix& d) {
    int N = d.Length();

    Matrix b(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[i][j] = d[j][i];
        }
    }

    return b;
}

Matrix Matrix::operator*(const Matrix& d) {
    Matrix b(N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
        b[i][j] = mtx[i] * transpose(d)[j];
        if(abs(b[i][j]) < 0.00001) b[i][j] = 0;
        }
    }

    return(b);
}

Array Matrix::operator*(const Array& a) {
    Array b(N);

    for (int i = 0; i < N; i++) {
        b[i] = mtx[i] * a;
        if (abs(b[i]) < 0.00001) b[i] = 0;
    }

    return(b);
}

ostream& operator<<(ostream& os, const Matrix& a) {
    for (int i = 0; i < a.Length(); i++) {
        os << a[i];
    }

    return(os);
}

Matrix::~Matrix() {
    delete[] mtx;
}

int Matrix::Length() const {
    return(N);
}

int sgn(int i) { 
    return 1 - 2 * (i % 2);
}

double Matrix::det() {
    if (N == 1) {
        return mtx[0][0];
    } else if (N == 2) {
        return(mtx[0][0] * mtx[1][1] - mtx[0][1] * mtx[1][0]);
    } else {
        double d = 0;
        for(int i = 0; i < N; i++) {
            d += add(0, i) * mtx[0][i];
        }
        return d;
    }
}

double Matrix::add(int p, int q) {
    Matrix c(N - 1);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i < p and j < q) {
                c[i][j] = mtx[i][j];
            }
            if(i > p and j < q) {
                c[i - 1][j] = mtx[i][j];
            }
            if(i < p and j > q) {
                c[i][j - 1] = mtx[i][j];
            }
            if(i>p and j > q) {
                c[i-1][j-1] = mtx[i][j];
            }
        }
    }

    return(c.det() * sgn(p + q));
}

Matrix inverse(Matrix& A) {
    int N = A.Length();
    double det = A.det();
    Matrix b(N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            b[i][j] = A.add(j, i) / det;
        }
    }

    return(b);
}
