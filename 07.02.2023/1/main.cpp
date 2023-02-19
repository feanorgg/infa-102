// Галкин Иван Андреевич, 102
// Задача 1

#include <iostream>
#include <cmath>
#include <string>
#include "header.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using MySpace::MyClass;

int main() {
    double x;

    cout << "Hello" << endl;
    cout << "Please, specify X argument: " << endl;
    cin >> x;
    cout << "std::sin: " << std::sin(x) << endl;
    cout << "myspace::sin from header file: " << MySpace::sin(x) << endl;

    string y;

    cout << "New class: set payload: " << endl;
    cin >> y;

    MyClass<string> myClass;
    myClass.set_payload(y);
    
    cout << "Now payload is: " << endl;
    cout << myClass.get_payload();

    cout << "Class output: " << endl;
    myClass.show();

    return 0;
}
