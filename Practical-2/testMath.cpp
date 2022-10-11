#include <iomanip>
#include <iostream>
#include "testMath.h"

using namespace std;

/** Converts Farenheit to Celcius
 *
 * @param Temperature in Farenheit
 * */
double convertF2C(double F) {
    double C = 5.0 / 9.0 * (F - 32.0);
    return C;
}

/** Converts Calcius to Farenheit
 *
 * @param Temperature in Celcius
 * */
double convertC2F(double C) {
    double F = 9.0 / 5.0 * C + 32.0;
    return F;
}

/** Shows Temperature in Farenheit and Celcius from 0 F to 100 F */
void F2C() {
    cout << setw(3) << "F";
    cout << setw(8) << "C" << endl;
    for (double F = 0.0; F <= 100.0; F+=20.00) {
        cout << setprecision(5);
        cout << setw(3) << F << setw(8) << convertF2C(F) << endl;
    }
}

/** Shows Temperature in Celius and Farenheit from 0 C to 100 C */
void C2F() {
    cout << setw(3);
    cout << "C" << setw(5) << "F" << endl;
    for (double C = 0.0; C <= 100.00; C+=20.0) {
        cout << setprecision(5);
        cout << setw(3) << C << setw(5) << convertC2F(C) << endl;
    }
}
