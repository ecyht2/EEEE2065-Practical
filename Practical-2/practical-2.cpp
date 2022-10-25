#include <iostream>
#include <cstring>
#include <iomanip>
#include <functional>
#include <string>
#include "dataTypes.h"
#include "testMath.h"

using namespace std;

/** A wrapper class for a function that has a string name */
class NamedFunction {
    public:
        NamedFunction(function<void (void)> f, string name) {
            func = f;
            this->name = name;
        }
        void operator ()(void) {
            func();
        }
        void call() {
            func();
        }
        string getName() {
            return name;
        }
    private:
        function<void (void)> func = nullptr;
        string name = "";
};

int main(int argc, char *argv[]) {
    // Setting Up Named Function List
    NamedFunction functions[] = {
        NamedFunction(testString, "testString"),
        NamedFunction(testSignedUnsigned, "testSignedUnsigned"),
        NamedFunction(testFloatDouble, "testChar"),
        NamedFunction(C2F, "C2F"),
        NamedFunction(F2C, "F2C"),
        NamedFunction([]() {
            double F = 22.0;
            double C = convertF2C(F);
            cout << "Temp in F=" << F << endl << "Temp in C=" << C << endl;
        }, "convertF2C"),
        NamedFunction([]() {
            testInt(69, 420);
        }, "testInt"),
        NamedFunction([]() {
            double C = 22.0;
            double F = convertC2F(C);
            cout << "Temp in C=" << C << endl << "Temp in F=" << F << endl;
        }, "convertC2F")
    };

    // Looping Over all argc
    for (int i = 1; i < argc; i++) {
        char *current_string = argv[i];
        bool flag = true;

        // Looping all avaiable functions
        for (int j = 0; j < 8; j++) {
            NamedFunction current_function = functions[j];
            // Checking if the name matches
            if (current_function.getName() == current_string) {
                // Calling function
                cout << "Calling " << current_string << endl;
                flag = false;
                current_function();
                // Adding Padding
                cout << endl;
            }
        }

        // If not function found
        if (flag) {
            cout << "No Function " << current_string << " found skipping..." << endl;
        }
    }
    return 0;
}
