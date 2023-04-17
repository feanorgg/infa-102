#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::ostream;
using std::rand;
using std::endl;

namespace MySpace {
    template <typename T>
    class MyVector {
    private:
        vector<T> data;
        double Radius;
        int size;
        static int max;
        T random(T x0);
    public:
        MyVector() {
            size = 0;
            data = vector<T> (0);
        }

        MyVector(T elem, double rad) {
            size = 1;
            Radius = rad;
            data = vector<T> (1);
            data[0] = elem;
        }

        MyVector(double rad) {
            Radius = rad;
            size = 0;
            data = vector<T> (0);
        }

        void Start();

        int Size() {
            return size;
        }
        void Clear() {
            data.clear();
        }

        T operator[] (int& i) {
            return data[i];
        }

        template<class U>
        friend ostream & operator<< (ostream& os, const MyVector<U>& v);
    };

    template <class T>
    ostream& operator<< (ostream& os, const MyVector<T>& v)  {
        for(int i = 0; i < v.size; i++) {
            os << v.data[i] << " ";
        }
        os << endl;
        return os;
    }

    template<>
    int MyVector<double>::max = 50;

    template <>
    double MyVector<double>::random(double x0) {
        return x0 + (rand()%(int)1e5 - 5e4)/5e4;
    }

    template <class T>
    T MyVector<T>::random(T x0) {
        T x;
        return x0 + x.Random();
    }

    /*template <typename T>
    void MyVector<T>::Start() {
        int iteration_count = 0;
        T v;

        if(size > 0) {
            v = random(data[size-1]);
        } else {
            T x;
            v = x.Random();
            data = vector<T> (1);
            data[1] = v;
        }

        while(abs(v - data[0]) < Radius && iteration_count < max) {
            data.push_back(v);
            size += 1;
            iteration_count += 1;

            v = random(data[size-1]);
        }
    }*/

    template <>
    void MyVector<double>::Start() {
        int iteration_count = 0;
        double v;

        if(size > 0) {
            v = random(data[size-1]);
        } else {
            v = (rand()%(int)1e5 - 5e4)/5e4;
            data = vector<double> (1);
            data[1] = v;
        }

        while(abs((double)(v - data[0])) < Radius && iteration_count < max) {
            data.push_back(v);
            size += 1;
            iteration_count += 1;

            v = random(data[size-1]);
        }
    }

    class Vector {
    private:
        double x;
        double y;
    public:
        Vector() { x=0; y=0; }
        Vector(double xx, double yy) { x=xx; y=yy; };

        Vector Random();

        Vector operator+ (Vector& v) {
            Vector v2(x + v.x, y + v.y);
            return v2;
        }

        Vector operator- (Vector& v) {
            Vector v2(x - v.x, y - v.y);
            return v2;
        }

        friend ostream& operator<< (ostream &os, const Vector& v);

        operator double() {
            return sqrt(x*x + y*y);
        }
    };

    Vector Vector::Random() {
        double angle = 3.1415 * 2 * (rand()%(int)1e5)/1e5;
        double radius = (rand()%(int)1e5)/1e5;

        x = radius*cos(angle);
        y = radius*sin(angle);

        Vector v(x, y);

        return v;
    }

    ostream & operator<< (ostream& os, const Vector& v) {
        os << v.x << " " << v.y << endl;
        return os;
    }

    template<>
    int MyVector<Vector>::max = 1000;

    template <>
    void MyVector<Vector>::Start() {
        int iteration_count = 0;
        Vector v;

        if(size > 0) {
            v = random((Vector)data[size-1]);
        } else {
            v = Vector(0., 0.);
            data = vector<Vector> (1);
            data[1] = v;
        }

        while(abs((double)(v - data[0])) < Radius && iteration_count < max) {
            data.push_back(v);
            size += 1;
            iteration_count += 1;

            v = random((Vector)data[size-1]);
        }
    }

    /*template <>
    Vector MyVector<Vector>::random(Vector x0) {
        Vector v;
        return x0 + v.Random();
    }*/
}
