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
    cout << endl << "Finding first 100000 primes" << endl;
    clock_t startTime = clock();
    getNImprovedPrimes(100000);
    float timeElapsed = (float) (clock() - startTime) / CLOCKS_PER_SEC;
    cout << "Function took " << timeElapsed << " to run." << endl;

    // 500000 primes
    cout << endl << "Finding first 500000 primes" << endl;
    startTime = clock();
    getNPrimes(500000);
    timeElapsed = (float) (clock() - startTime) / CLOCKS_PER_SEC;
    cout << "Function took " << timeElapsed << " to run." << endl;

    return 0;
}
