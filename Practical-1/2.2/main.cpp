#include <iostream>
#include "printData.h"
#include "printMath.h"

using namespace std;

int main(int argc, char *argv[]) {
  cout << "Hello World" << endl;
  printList(6);
  printSum(6, 9);
  printSum(42, 0);
  printSum(69, 69);
  printBigTextSimple();

  cout << "-------------------------------------------------" << endl;
  BigText("abcdefghijklmnopqrstuvwxyz").print();
  BigText(" 0123456789").print();
  return 0;
}
