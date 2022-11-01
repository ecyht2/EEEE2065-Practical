#include <iostream>
#include <time.h>
#include "practical4.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "Practical 4.1" << endl;
    practical4_1();

    cout << endl << "Practical 4.2" << endl;
    practical4_2();

    cout << endl << "Pascal's Triangle" << endl;
    pascalsTriangle(10);

    cout << endl << "Prime Numbers" << endl;
    getNPrimes(10);

    // 100000 primes
    auto timedNPrimes = timer(getNImprovedPrimes);
    timedNPrimes(100000);

    // 500000 primes
    cout << endl << "Finding first 500000 primes" << endl;
    timedNPrimes(500000);

    return 0;
}
