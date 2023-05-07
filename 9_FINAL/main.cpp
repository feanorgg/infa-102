#include "Resolver.h"
#include "functions.h"
#include <fstream>

using namespace std;

int Array::length = 4;
int Functor::length = 4;

int main() {
    double y0[] = {0.1, -0.1, 0.1, -0.1};
    fun functions[] = {(fun)f1, (fun)f2, (fun)f3, (fun)f4};

    Resolver ode(functions);

    RESULT res = ode.start(Array(y0), 0.0, 40.0, 0.05, "rk");
    RESULT res0 = ode.start(Array(y0), 0.0, 40.0, 0.05, "ei");

    ofstream rk("/Users/ivangalkin/Documents/MSU/sem2/inf/9_FINAL/rk.txt");

    for(int i = 0; i < 801; i++) {
        for(int j = 0; j < 4; j++) {
            rk << res[i][j] << " ";
        }
        rk << endl;
    }

    rk.close();

    ofstream ei("/Users/ivangalkin/Documents/MSU/sem2/inf/9_FINAL/ei.txt");

    for(int i = 0; i < 801; i++) {
        for(int j = 0; j < 4; j++) {
            ei << res0[i][j] << " ";
        }
        ei << endl;
    }

    ei.close();

    return 0;
}
