// Галкин Иван Андреевич, 102
// Задача к 3 семинару 2 семестра (Задания по теме 2_3.doc) - код для проверки выполнения задания 1 (myLib.h)

#include <iostream>
#include "myLib.h"

using std::cin;
using std::cout;
using namespace MySpace;

int main() {
    Vector v1;
    Vector v2(2);
    Vector v3(3, 4);

    v1.show();
    v2.show();
    v3.show();

    v2.set(v3.getX(), v3.getY());
    v2.show();

    double inp;
    cin >> inp;

    v2.scale(inp);
    v2.show();

    cout << "Length: " << v2.length() << endl;

    Vector v4 = v2.sum(v3);
    v4.show();

    return 0;

    /*
    Вывод: теперь баланс сообщений о создании и об удалении элементов соблюдается.
    */
}
