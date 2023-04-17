#include "myLib.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace MySpace;
using std::cout;
using std::fixed;
using std::setprecision;
using std::ofstream;
using std::endl;

int main() {
    MyVector<double> vect(0., 10.);
    vect.Start();

    cout << fixed << setprecision(2) << vect;

    /*Vector v0(0., 0.);
    MyVector<Vector> vect2(v0, 50.);
    vect2.Start();

    ofstream ofs;
    ofs.open("/Users/ivangalkin/Documents/MSU/sem2/inf/28.03.2023/1/out.txt");

    for(int i = 0; i < vect2.Size(); i++) {
        ofs << vect2[i] << endl;
    }*/
    
    return 0;
}