#include "Array.h"

double f1(Array &Y, double t) {
    double ret = - Y[0] + Y[1] - Y[2] + Y[3];
    return ret;
}

double f2(Array Y, double t) {
    double ret = - Y[0] + Y[2] - Y[3];
    return ret;
}

double f3(Array Y, double t) {
    double ret = Y[0] - Y[1] + Y[3] + t/10;
    return ret;
}

double f4(Array Y, double t) {
    double ret = Y[0] - Y[3] - t/10;
    return ret;
}
