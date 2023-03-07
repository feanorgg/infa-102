#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector< vector<double> > mat;

public:
    Matrix(int r, int c) : rows(r), cols(c), mat(vector< vector<double> >(r, vector<double>(c, 0))) {}

    int get_rows() const { return rows; }
    int get_cols() const { return cols; }

    double& operator() (int r, int c) { return mat[r][c]; }
    const double& operator() (int r, int c) const { return mat[r][c]; }

    void swap_rows(int i, int j) {
        for (int k = 0; k < cols; ++k) {
            double temp = mat[i][k];
            mat[i][k] = mat[j][k];
            mat[j][k] = temp;
        }
    }

    Matrix operator+ (const Matrix& A) {
        if (A.get_rows() != rows || A.get_cols() != cols) {
            throw invalid_argument("Matrix dimensions do not match.");
        }
        Matrix res(A.get_rows(), A.get_cols());
        for (int i = 0; i < A.get_rows(); ++i) {
            for (int j = 0; j < A.get_cols(); ++j) {
                res(i, j) = A(i, j) + mat[i][j];
            }
        }
        return res;
    };

    Matrix operator- (const Matrix& A) {
        if (A.get_rows() != rows || A.get_cols() != cols) {
            throw invalid_argument("Matrix dimensions do not match.");
        }
        Matrix res(A.get_rows(), A.get_cols());
        for (int i = 0; i < A.get_rows(); ++i) {
            for (int j = 0; j < A.get_cols(); ++j) {
                res(i, j) = A(i, j) - mat[i][j];
            }
        }
        return res;
    };

    Matrix operator* (const Matrix& A) {
        if (A.get_cols() != rows) {
            throw invalid_argument("Matrix dimensions do not match.");
        }
        Matrix res(A.get_rows(), cols);
        for (int i = 0; i < A.get_rows(); ++i) {
            for (int j = 0; j < cols; ++j) {
                double sum = 0;
                for (int k = 0; k < A.get_cols(); ++k) {
                    sum += A(i, k) * mat[k][j];
                }
                res(i, j) = sum;
            }
        }
        return res;
    };

    friend Matrix operator* (const double& k, const Matrix& a);

    friend double det(const Matrix& m);
    friend Matrix inverse(const Matrix& m);
    friend Matrix adjoint(const Matrix& m);
    friend Matrix transpose(const Matrix& m);

    static Matrix gauss_jordan(const Matrix& A, const Matrix& B) {
        if (A.get_rows() != A.get_cols()) {
            throw invalid_argument("Matrix is not square.");
        }

        if (B.get_rows() != A.get_rows()) {
            throw invalid_argument("Inconsistent dimensions.");
        }

        if (B.get_cols() != 1) {
            throw invalid_argument("Inconsistent dimensions of solution matrix");
        }

        Matrix aug(A.get_rows(), A.get_cols() + B.get_cols());
        for (int i = 0; i < A.get_rows(); ++i) {
            for (int j = 0; j < A.get_cols(); ++j) {
                aug(i, j) = A(i, j);
            }

            for (int j = 0; j < B.get_cols(); ++j) {
                aug(i, A.get_cols() + j) = B(i, j);
            }

        }
            
        for (int i = 0; i < A.get_rows(); ++i) {
            int pivot = i;
            for (int j = i + 1; j < A.get_rows(); ++j) {
                if (abs(aug(j, i)) > abs(aug(pivot, i))) {
                    pivot = j;
                }
            }

            if (pivot != i) {
                aug.swap_rows(pivot, i);
            }

            double div = aug(i, i);
            for (int j = i; j < aug.get_cols(); ++j) {
                aug(i, j) /= div;
            }

            for (int j = 0; j < A.get_rows(); ++j) {
                if (j != i) {
                    double mult = aug(j, i);
                    for (int k = i; k < aug.get_cols(); ++k) {
                        aug(j, k) -= mult * aug(i, k);
                    }
                }
            }
        }

        Matrix res(A.get_rows(), B.get_cols());
        for (int i = 0; i < A.get_rows(); ++i) {
            for (int j = 0; j < B.get_cols(); ++j) {
                res(i, j) = aug(i, A.get_cols() + j);
            }
        }

        return res;
    }
};

ostream & operator<< (ostream &os, const Matrix &mtx) {
    os << "Matrix:" << endl;
    for(int i = 0; i < mtx.get_cols(); i++) {
        for(int j = 0; j < mtx.get_rows(); j++) {
            os << mtx(i, j) << " ";
        }

        os << endl;
    }

    return os;
}

Matrix operator* (const double& k, const Matrix& A) {
    Matrix res(A.get_rows(), A.get_cols());
    for (int i = 0; i < A.get_rows(); ++i) {
        for (int j = 0; j < A.get_cols(); ++j) {
            res(i, j) = k * A(i, j);
        }
    }
    return res;
}

double det(const Matrix& m) {
    if (m.rows != m.cols) {
        throw invalid_argument("Matrix is not square.");
    }

    if (m.rows == 1) {
        return m(0, 0);
    }

    if (m.rows == 2) {
        return m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0);
    }

    double res = 0;
    for (int j = 0; j < m.cols; ++j) {
        Matrix sub(m.rows - 1, m.cols - 1);
        for (int r = 1; r < m.rows; ++r) {
            for (int c = 0; c < m.cols; ++c) {
                if (c < j) {
                    sub(r - 1, c) = m(r, c);
                } else if (c > j) {
                    sub(r - 1, c - 1) = m(r, c);
                }
            }
        }
        res += m(0, j) * pow(-1, j) * det(sub);
    }

    return res;
}

Matrix inverse(const Matrix& m) {
    if (m.rows != m.cols) {
        throw invalid_argument("Matrix is not square.");
    }

    double d = det(m);
    if (d == 0) {
        throw invalid_argument("Matrix is not invertible.");
    }

    Matrix res(m.rows, m.cols);
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            Matrix sub(m.rows - 1, m.cols - 1);
            for (int r = 0; r < m.rows; ++r) {
                for (int c = 0; c < m.cols; ++c) {
                    if (r < i && c < j) {
                        sub(r, c) = m(r, c);
                    } else if (r < i && c > j) {
                        sub(r, c - 1) = m(r, c);
                    } else if (r > i && c < j) {
                        sub(r - 1, c) = m(r, c);
                    } else if (r > i && c > j) {
                        sub(r - 1, c - 1) = m(r, c);
                    }
                }
            }
            
            res(j, i) = pow(-1, i + j) * det(sub) / d;
        }
    }

    return res;
}

Matrix adjoint(const Matrix& m) {
    if (m.rows != m.cols) {
        throw invalid_argument("Matrix is not square.");
    }

    Matrix res(m.rows, m.cols);
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            Matrix sub(m.rows - 1, m.cols - 1);
            for (int r = 0; r < m.rows; ++r) {
                for (int c = 0; c < m.cols; ++c) {
                    if (r < i && c < j) {
                        sub(r, c) = m(r, c);
                    } else if (r < i && c > j) {
                        sub(r, c - 1) = m(r, c);
                    } else if (r > i && c < j) {
                        sub(r - 1, c) = m(r, c);
                    } else if (r > i && c > j) {
                        sub(r - 1, c - 1) = m(r, c);
                    }
                }
            }

            res(j, i) = pow(-1, i + j) * det(sub);
        }
    }

    return res;
}

Matrix transpose(const Matrix& m) {
    Matrix res(m.cols, m.rows);
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            res(j, i) = m(i, j);
        }
    }
        
    return res;
}
