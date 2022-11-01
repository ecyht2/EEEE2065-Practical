#include <iostream>
#include "practical4.h"

using namespace std;

int main(int argc, char *argv[]) {
    adventureGame ag;
    cout << "Welcome to adventure game" << endl;
    while (ag.getCommand()) {
        if (ag.processCommand() == 0) {
            break;
        }
    }

    return 0;
}
