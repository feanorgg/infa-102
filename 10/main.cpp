#include "Array.h"
#include "Matrix.h"

int main() {
  int size1 = 3;
  int size2 = 4;

  double x1[] = { 2, -2,  1 };
  double x2[] = { 1,  3, -2 };
  double x3[] = { 3, -1, -1 };
  double R1[] = {-3,  1,  2 };

  Array X1(x1, size1);
  Array X2(x2, size1);
  Array X3(x3, size1);
  Array C1(R1, size1);

  Array* Z;
  Z = new Array[3];
  for (int i = 0; i < size1; i++) {
    Z[i].changeSize(size1);
  }

  Z[0] = X1;
  Z[1] = X2;
  Z[2] = X3;

  Matrix A(Z, size1);

  Matrix C(size1);
  C = A * inverse(A);
  cout << "A: " << inverse(A) * C1;

  double x21[] = { 0,  1,  3, -1 };
  double x22[] = { 2, -3,  2,  0 };
  double x23[] = { 2, -4,  0,  1 };
  double x24[] = {-2,  5, -3,  3 };
  double R2[] =  { 2, -2,  3,  1 };

  Array X21(x21, size2);
  Array X22(x22, size2);
  Array X23(x23, size2);
  Array X24(x24, size2);
  Array C2(R2, size2);

  Array* Z2;
  Z2 = new Array[size2];
  for (int i = 0; i < size2; i++) {
    Z2[i].changeSize(size2);
  }

  Z2[0] = X21;
  Z2[1] = X22;
  Z2[2] = X23;
  Z2[3] = X24;

  Matrix B(Z2, size2);

  Array YB(size2); 
  YB = inverse(B) * C2;
  cout << "B: " << inverse(B) * C2;

  cout << "RESULT:\n" << B * YB;
  cout << "CORRECT ANSWER:\n" << C2;

  cout << "Self * inverse:\n";
  cout << B*inverse(B);

  return 0;
}
