// Галкин Иван Андреевич, 102
// Задача к 1 семинару 2 семестра (Задания по теме 2_1.doc) - исполняемый файл для проверки реализации header-файла myLib

#include "myLib.h"
using namespace MySpace;

int main() {
    int a, b;

    Input(a, b, "Get the integers: a and b");

    Time t1 = SetTime(a);
    Time t2 = SetTime(a, b);
    Time t3 = SetTime();

    t3 = Add(t1, t2);
    Print(t3, "Let's summarize objects (a, 0) and (a, b) = 2a+b");
    Reset(t3);
    Print(t3);

    double x, y;
    Input(x, y, "Get me reals: x and y");

    xTime xt1 = SetxTime(x);
    xTime xt2 = SetxTime(x, y);
    xTime xt3 = SetxTime();

    xt3 = Add(xt1, xt2);
    Print(xt3,"Let's summarize objects (x,0) and (x,y) = 2x+y");

    Reset(xt3);
    Print(xt3);
    cin.get();
    cin.get();

    return 0;    
}
