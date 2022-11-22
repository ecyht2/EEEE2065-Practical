#include <iostream>

#include "practical6.h"

using namespace std;

int main(int argc, char *argv[]) {
    adventureGame ag;
    cout << "Welcome to Adventure Game!\n";
    while (ag.getCommand()>0) { // get a command from the user
        if (ag.processCommand()==0) break; // process the command given by the user.
    }
    cout << "Thanks for playing adventure-game!" << endl;
    return 0;
}
