// Галкин Иван Андреевич, 102
// Задача ко 2 семинару 2 семестра (Задания по теме 2_2.doc) - файл библиотеки

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

namespace MySpace {
    class Vector {
        private:
            double x;
            double y;

        public:
            Vector();
            Vector(double xx);
            Vector(double xx, double yy);
            ~Vector();

            double getX();
            double getY();

            void set(double xx, double yy);
            void show();

            void scale(double scl);
            Vector sum(Vector v1);
            double length();

            Vector(const Vector & v2);

            Vector & operator=(const Vector & v) {
                if(this == &v) return *this;
                x = v.x;
                y = v.y;
                cout << "Создан объект посредством оператора присваивания";

                return *this;
            }
    };

    Vector::Vector() {
        x = 1;
        y = 0;
        cout << "Создан объект" << endl;
    }

    Vector::Vector(double xx) {
        x = xx;
        y = 0;
        cout << "Создан объект" << endl;
    }

    Vector::Vector(double xx, double yy) {
        x = xx;
        y = yy;
        cout << "Создан объект" << endl;
    }

    Vector::~Vector() {
        cout << "Удален объект" << endl;
    }

    double Vector::getX() {
        return x;
    }

    double Vector::getY() {
        return y;
    }

    void Vector::set(double xx, double yy) {
        x = xx;
        y = yy;

        return;
    }

    void Vector::show() {
        cout << x << " : " << y << endl;

        return;
    }

    void Vector::scale(double scl) {
        x *= scl;
        y *= scl;

        return;
    }

    Vector Vector::sum(Vector v1) {
        return Vector(v1.getX() + x, v1.getY() + y);
    }

    double Vector::length() {
        return sqrt(x*x + y*y);
    }

    Vector::Vector(const Vector & v2) {
        x = v2.x;
        y = v2.y;

        cout << "Создан объект с использованием конструктора копирования" << endl;
    }
}
