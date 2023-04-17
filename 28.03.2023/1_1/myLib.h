#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

using std::vector;
using std::ostream;
using std::endl;

namespace MySpace {
    template <typename T>
    class MyVector {
    private:
        vector<T> data;
        double Radius;
        int size;
        const int max = 500;

        T random(const T& x0) {
            double x = x0 + (double)rand()*2/RAND_MAX - 1.0;
            return x;
        }

    public:
        MyVector() : size(0) {}
        MyVector(const T& x0, double radius) {
            data.push_back(x0);
            Radius = radius;
            size = 1;
        }

        void Start() {
            int cnt = 0;
            T v0 = data[0];
            T v = v0;
            while (cnt < max && (abs(v0 - v) < Radius))
            {
                v = random(v);
                data.push_back(v);
                size += 1;
                cnt += 1;
            }
        }

        int Size() {
            return size;
        }

        int Clear() {
            data.clear();
            size = 0;
        }

        T& operator[](int index) {
            return data[index];
        }

        friend ostream& operator<<(ostream& out, const MyVector<T>& v) {
            for (int i = 0; i < v.size; i++) {
                out << v.data[i] << endl;
            }

            return out;
        }
    };

    class Vector {
    public:
        double x;
        double y;

        Vector() { x=0; y=0; }
        Vector(double xx, double yy) { x=xx; y=yy; }
        ~Vector() {}

        Vector operator-(const Vector& v) const {
            Vector r;
            r.x = x - v.x;
            r.y = y - v.y;
            return r;
        }

        Vector operator+(const Vector& v) const {
            Vector r;
            r.x = x + v.x;
            r.y = y + v.y;
            return r;
        }

        friend ostream& operator<<(ostream& out, const Vector& v) {
            out << v.x << " " << v.y;
            return out;
        }

        operator double() {
            return sqrt(x*x + y*y);
        }

    };

    template <>
    Vector MyVector <Vector>::random(const Vector& v0) {
        double angle = (double)rand()/RAND_MAX*3.1415*2;
        double length = (double)rand()/RAND_MAX;

        Vector r;
        r.x = length * cos(angle);
        r.y = length * sin(angle);
        return v0 + r;
    }
}