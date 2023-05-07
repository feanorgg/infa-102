#pragma once
#include "Array.h"
#include "Functor.h"
#include <vector>

using std::vector;
using std::string;

typedef vector< vector <double> > RESULT;

class Resolver {
    private:
        Array K1, K2, K3, K4, Y;
        Functor functor;
        double t, h;
        int cnt = 0;
    public:
        Resolver(fun* fs);
        void stepRK();
        void stepEI();
        RESULT start(const Array& y0, double t0, double tend, double step, string method);
};

Resolver::Resolver(fun* fs) {
    functor = fs;
}

void Resolver::stepRK() {
    Array Z = Y;

    K1 = h * functor(Z, t);

    Z = Y + (0.5 * K1);
    double a = t + h * 0.5;
    K2 = h * functor(Z, a);

    Z = Y + (0.5 * K2);
    K3 = h * functor(Z, a);

    Z = Y + K3;
    a = t + h;
    K4 = h * functor(Z, a);

    Y += (K1 + (2. * K2) + (2. * K3) + K4) / 6.;
}

void Resolver::stepEI() {
    K1 = h * functor(Y, t);
    Y += K1;
}

RESULT Resolver::start(const Array& y0, double t0, double tend, double step, string method) {
    Y = y0;
    t = t0;
    cnt = 0;
    h = step;
    RESULT res(abs(tend - t0) / step + 1, vector<double>(4));

    if(method == "rk") {
        while(t <= tend) {
            stepRK();

            for(int i = 0; i < 4; i++) {
                res[cnt][i] = Y[i];
            }

            cnt++;
            t += step;
        }
    } else if(method == "ei") {
        while(t <= tend) {
            stepEI();

            for(int i = 0; i < 4; i++) {
                res[cnt][i] = Y[i];
            }

            cnt++;
            t += step;
        }
    } else {
        cout << "Provided method doesn't exist";
        exit(1);
    }

    return res;
}
