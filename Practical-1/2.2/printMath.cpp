#include "printMath.h"
#include <iostream>

using namespace std;

int printSum(int x, int y) {
  int z = x + y;

  cout << "The sum of " << x << " and " << y
    << " is " << z << endl;

  return z;
}
