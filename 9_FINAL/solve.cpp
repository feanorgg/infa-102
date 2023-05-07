#include "Resolver.h"
#include "functions.h"
#include <fstream>

using namespace std;

int Array::length = 4;
int Functor::length = 4;

int main(int argc, char *argv[]) {
    double t0 = 0.;
    double tend = 40.;
    double step = 0.05;
    string fname = "default";
    string method = "rk";

    // ./solve.cpp [step] [filename] [method]
    for(int i = 0; i < argc; i++) {
        if(i == 1) {
            step = atof(argv[1]);
            cout << step << endl;
        } else if(i == 2) {
            fname = argv[2];
            cout << fname << endl;
        } else if(i == 3) {
            method = argv[3];
            cout << method << endl;
        }
    }

    double y0[] = {0.1, -0.1, 0.1, -0.1};
    fun functions[] = {(fun)f1, (fun)f2, (fun)f3, (fun)f4};

    Resolver ode(functions);

    RESULT res = ode.start(Array(y0), t0, tend, step, method);

    ofstream file("/Users/ivangalkin/Documents/PycharmProjects/Task11/"+fname+".txt");

    for(int i = 0; i < abs(tend - t0)/step + 1; i++) {
        file << t0+i*step << " ";
        for(int j = 0; j < 4; j++) {
            file << res[i][j] << " ";
        }
        file << endl;
    }

    file.close();

    return 0;
}
