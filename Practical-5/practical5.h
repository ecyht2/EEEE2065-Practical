#ifndef PRACTICAL5_H_
#define PRACTICAL5_H_

#include <iostream>
#include <string>

using namespace std;

void practical_5_1_1(void);
void practical_5_1_2(void);
void practical_5_2(void);
void practical_5_2_1_1(void);
void practical_5_2_1_2(void);
void practical_5_2_1_3(void);
void practical_5_2_1_4(void);
void practical_5_2_2(void);
void practical_5_2_3(void);

class adventureGame {
    private:
        string command; // command taken from the user stored in this string.
        int monster = 1; // a flag indicating the status of a monster. Monster is alive at the start.
        int room = 1;
    public:
        int getCommand() { // getCommand function is written inline
            cout << "Enter Command:";
            cin >> command; // For now we only take single-word commands using cin.
            return(1);
        }
        int processCommand(); // function to processCommand
        int processRoom1();
        int processRoom2();
        int processRoom3();
        int processRoom4();
};

#endif // PRACTICAL5_H_
