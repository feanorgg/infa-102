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
            virtual void show() = 0;
            //void show();
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
            void show() override;
    };

    Bc::Bc() {
        b = 2;
    }

    Bc::Bc(int v) {
        b = v;
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
            void show() override;
    };

    Cc::Cc() {
        c = 3;
    }

    Cc::Cc(int v) {
        c = v;
    } 

    void Cc::show() {
        Bc::show();
        cout << c << endl;
    }
}
