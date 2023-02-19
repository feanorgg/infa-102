// Галкин Иван Андреевич, 102
// Задача ко 2 семинару 2 семестра (Задания по теме 2_2.doc) - код для проверки выполнения задания (myLib.h)

#include <iostream>
#include "myLib.h"

using std::cin;
using std::cout;
using namespace MySpace;

int main() {
    Vector v[3] = {Vector(1., 1.), Vector(2.2)};

    for(int i = 0; i < 3; i++) {
        v[i].show();
    }

    return 0;
}
