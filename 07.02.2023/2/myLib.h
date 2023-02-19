// Галкин Иван Андреевич, 102
// Задача к 1 семинару 2 семестра (Задания по теме 2_1.doc) - реализация именного пространства MySpace

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

namespace MySpace {
    class Time {
        public:
            int h;
            int m;
    };

    class xTime {
        public:
            double h;
            double m;
    };

    template <typename T>
    void Input(T &a, T &b, string c = "Input 2 values !") {
        cout << c << endl;
        cin >> a >> b;

        return;
    }

    Time SetTime(int h = 0, int m = 0) {
        Time t;
        t.h = h;
        t.m = m;

        return t;
    }

    xTime SetxTime(double h = 0, double m = 0) {
        xTime t;
        t.h = h;
        t.m = m;

        return t;
    }

    template <typename T>
    T Add(T &t1, T &t2) {
       T t3;
       t3.h = t1.h + t2.h;
       t3.m = t1.m + t2.m;

        return t3;
    }

    template <typename T>
    void Print(T t, string str = " ") {
        cout << str << endl;
        cout << t.h << " : " << t.m << endl;

        return;
    }

    template <typename T>
    void Reset(T &t) {
        t.h = 0;
        t.m = 0;

        return;
    }
}
