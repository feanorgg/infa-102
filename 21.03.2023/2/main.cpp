#include "myLib.h"

using namespace MySpace;
using std::cout;
using std::endl;
using std::cin;

int main(){
    // Объект базового класса
    Vector v(1,2);
    cout << v <<endl;
    // Наследник базового класса. 1-е поколение
    cout << " NVector \n";
    NVector nv1((char*)"Named Vector #1");
    cout << nv1 << endl;
    NVector nv2(11,22,(char*)"Named Vector #2");
    cout << nv2 << endl;
    // Наследник базового класса. 2-е поколение
    cout << " 3D Vector demonstration \n";
    NVector3D nz1(11,22,33,(char*)"3D Vector");
    cout << nz1;
    // Меняем координаты
    nz1.SetXYZ(3.14,2.18,1.41);
    cout << nz1;
    // Вызов метода базового класса.Меняем две координаты
    nz1.SetXY(-3.14,-2.18);
    cout << nz1;
    // Преобразование к базовому типу. Получение 2D вектора
    Vector v2D = (Vector)nz1;
    cout << v2D << endl;
    cin.get();

    return 0;
}