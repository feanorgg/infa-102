#include <iostream>

using std::ostream;
using std::endl;

namespace MySpace {
    class Vector{
    private:
        double x,y;
    public:
        Vector(double xx=0, double yy=0){x=xx; y=yy;}
        ~Vector() {}

        void SetXY(double xx,double yy){x=xx;y=yy;}

        friend ostream& operator<<(ostream& os, const Vector& v);
    };

    ostream & operator<< (ostream& os, const Vector& v) {
        os << v.x << " " << v.y;
        return os;
    }

    class NVector: public Vector {
    private:
        char* name;
    public:
        NVector(double xx,double yy,char* str);
        NVector(char* str);
        NVector();
        ~NVector() { delete [] name; }

        void SetName(char* str);

        friend ostream& operator<< (ostream &os, const NVector& nv);
    };

    NVector::NVector(double xx, double yy, char* str) : Vector::Vector(xx, yy) {
        //SetXY(xx, yy);
        
        int len = strlen(str) + 1;
        name = new char[len];
        strncpy(name, str, len);
    }

    NVector::NVector(char* str) {
        SetXY(0., 0.);

        int len = strlen(str) + 1;
        name = new char[len];
        strncpy(name, str, len);
    }

    NVector::NVector() {
        SetXY(0., 0.);

        name = new char[7];
        strncpy(name, (char*)"default", 7);
    }

    void NVector::SetName(char* str) {
        delete [] name;

        int len = strlen(str) + 1;
        name = new char[len];
        strncpy(name, str, len);
    }

    ostream & operator<< (ostream& os, const NVector& nv) {
        Vector v = nv;
        os << nv.name << "\n" << v;

        return os;
    }

    class NVector3D: public NVector {
    private:
        double z;
    public:
        NVector3D(double xx, double yy, double zz, char* str);

        void SetXYZ(double xx, double yy, double zz);

        friend ostream& operator<< (ostream &os, const NVector3D& nv3d);
    };

    NVector3D::NVector3D(double xx, double yy, double zz, char* str) {
        SetXY(xx, yy);
        z = zz;
        SetName(str);
    }

    void NVector3D::SetXYZ(double xx, double yy, double zz) {
        SetXY(xx, yy);
        z = zz;
    }

    ostream & operator<< (ostream &os, const NVector3D& nv3d) {
        Vector v = nv3d;
        
        os << v << " " << nv3d.z << endl;

        return os;
    }
}

