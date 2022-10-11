#include <iostream>
#include <cstring>
#include <iomanip>
#include "dataTypes.h"
#include "testMath.h"

using namespace std;

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        char *current_string = argv[i];
        if (strcmp(current_string, "testInt") == 0) {
            testInt(69, 420);
        } else if (strcmp(current_string, "testSignedUnsigned") == 0) {
            testSignedUnsigned();
        } else if (strcmp(current_string, "testFloatDouble") == 0) {
            testFloatDouble();
        } else if (strcmp(current_string, "testChar") == 0) {
            testChar();
        } else if (strcmp(current_string, "testString") == 0) {
            testString();
        } else if (strcmp(current_string, "convertF2C") == 0) {
            double F = 22.0;
            double C = convertF2C(F);
            cout << "Temp in F=" << F << endl << "Temp in C=" << C << endl;
        } else if (strcmp(current_string, "convertC2F") == 0) {
            double C = 22.0;
            double F = convertC2F(C);
            cout << "Temp in C=" << C << endl << "Temp in F=" << F << endl;
        } else if (strcmp(current_string, "F2C") == 0) {
            F2C();
        } else if (strcmp(current_string, "C2F") == 0) {
            C2F();
        } else {
            cout << "No Function " << current_string << " found skipping..." << endl;
        }
    }
    return 0;
}
