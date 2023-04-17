#include <iostream>

using std::cout;
using std::endl;

namespace MySpace {
    class Ac {
        private:
            int a;
        public:
            Ac();
            Ac(int v);
            //virtual void show() = 0;
            void show();
    };

    Ac::Ac() {
        a = 1;
    }

    Ac::Ac(int v) {
        a = v;
    }

    void Ac::show() {
        cout << a << endl;
    }

    class Bc: public Ac {
        private:
            int b;
        public:
            Bc();
            Bc(int v);
            Bc(int aa, int bb);
            void show();
    };

    Bc::Bc() : Ac::Ac() {
        b = 2;
    }

    Bc::Bc(int v) : Ac::Ac() {
        b = v;
    }

    Bc::Bc(int aa, int bb) : Ac::Ac(aa) {
        b = bb;
    }

    void Bc::show() {
        Ac::show();
        cout << b << endl;
    }

    class Cc: public Bc {
        private:
            int c;
        public:
            Cc();
            Cc(int v);
            Cc(int aa, int bb, int cc);
            void show();
    };

    Cc::Cc() {
        
        c = 3;
    }

    Cc::Cc(int v) {
        c = v;
    } 

    Cc::Cc(int aa, int bb, int cc) : Bc::Bc(aa, bb) {
        c = cc;
    }

    void Cc::show() {
        Bc::show();
        cout << c << endl;
    }
}
