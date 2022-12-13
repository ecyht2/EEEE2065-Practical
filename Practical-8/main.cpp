#include <iostream>

#include "practical8.h"

using namespace std;

int main(int argc, char *argv[]) {
    Polymorphism obj(1, 2 ,3);

    obj.print();
    cout << "1D dist:" << obj.dist(5) << endl;
    cout << "2D dist:" << obj.dist(5, 5) << endl;
    cout << "3D dist:" << obj.dist(5, 5, 5) << endl;

    Polymorphism obj1(1, 1, 1);
    Polymorphism obj2(2, 3, 4);
    obj1.print("obj1");
    obj2.print("obj2");
    Polymorphism obj3 = obj1 + obj2;
    obj3.print("obj3");
    (obj2 - obj1).print("obj2 - obj1");
    cout << "obj1 * obj2 = " << obj1 * obj2 << endl;

    Complex obj4(1, 2, 3);
    obj4.print();

    return 0;
}
