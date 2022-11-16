#include <iostream>
#include "practical5.h"

using namespace std;

int main(int argc, char *argv[]) {
    adventureGame ag; // define the object for our adventure game
    cout << "Welcome to adventure game\n";
    while (ag.getCommand()>0) {//Read a command from the user
        if (ag.processCommand()==0) break;
    }

    return 0;
}
