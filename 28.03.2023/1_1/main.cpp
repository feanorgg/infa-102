#include "myLib.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace MySpace;
using std::cout;
using std::endl;
using std::ofstream;

int main() {
	srand(time(NULL));
	MyVector<double> t(-5, 10);
	t.Start();

    cout << t << "\n=================\n\n";
    cout << t.Size() << endl;

	MyVector<Vector> t0(Vector(0., 0.), 10);
	t0.Start();

	ofstream out;
	out.open("/Users/ivangalkin/Documents/MSU/sem2/inf/28.03.2023/1_1/out.txt");

    cout << t0.Size() << endl;

	out << t0;
	out.close();
}
