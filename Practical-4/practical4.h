#ifndef PRACTICAL4_H_
#define PRACTICAL4_H_

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void practical4_1();
void practical4_2();

class adventureGame { // Declare the adventureGame class.
private:// All variables/functions from here down are private to the class
    string command; // command taken from the user stored in this string.
    int monster = 1; // a flag indicating the status of a monster. 1=Monster is alive

public:// All variables/functions from here down are declared public
    int getCommand() { // getCommand function defined inline
        cout << "Enter Command: ";
        cin >> command; // Take single-word commands using cin
        return(1);
    }
    int processCommand();
};

void pascalsTriangle(unsigned int);
void getNPrimes(unsigned int);
void getNImprovedPrimes(unsigned int);

template<typename T>
auto timer(T func) {
    return [func] (auto &&...args) {
        clock_t startTime = clock();
        func(args...);
        float timeElapsed = (float) (clock() - startTime) / CLOCKS_PER_SEC;
        cout << "Function took " << timeElapsed << " to run." << endl;
    };
}

#endif // PRACTICAL4_H_
