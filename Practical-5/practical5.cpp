#include "practical5.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/** Prints the given float x and changes it's value to 3.1415 via call by value.
 *
 * @param x the float to print and change
 * */
void printFloat(float x) {
    cout << "In printFloat:" << endl;
    cout << setprecision(6) << fixed << x << endl;
    x = 3.1415;
}

/** Function to test out call by value. */
void practical_5_1_1(void) {
    float x = 6.942069;
    cout << "Before printFloat:" << endl;
    cout << setprecision(6) << x << endl;
    printFloat(x);
    cout << "After printFloat:" << endl;
    cout << setprecision(6) << x << endl;
    // Q1: Does the value of x change in the calling environment? Why or why not?
    // A: No because the x passed into printFloat is the copy of the x being passed in.
}

/** Prints the given float x and changes it's value to 3.1415 via call by refrence.
 *
 * @param *x the float to print and change
 * */
void printFloat2(float *x) {
    cout << "In printFloat2:" << endl;
    cout << setprecision(6) << *x << endl;
    *x = 3.1415;
}

/** Function to test out call by refrence. */
void practical_5_1_2(void) {
    float x = 6.942069;
    cout << "Before printFloat2:" << endl;
    cout << setprecision(6) << x << endl;
    printFloat2(&x);
    cout << "After printFloat2:" << endl;
    cout << setprecision(6) << x << endl;
    // Q2: Now does the value of x change after calling the function? Why or why not?
    // A: The value changes because the value passed in is the memory address of where x is stored.
    // By changing the value of where the memory the value changes in the calling enviornment.
}

/** Function to test string class. */
void practical_5_2(void) {
    string str = "abcdefg";
    cout << str[0] << str[1] << str[2]<<endl; // access elements of str char by char
    cout << &str[1] <<endl; // print out the string from the first element.

    str[0] = 'z';
    cout << str <<endl; // print out the entire string
    // Q3: What output do you get and why?
    // A: str but it starts with 'z' instead of 'a' because we changed the first
    // character of the string into 'z'.

    // Try to assign to a string offset by the indexing operator
    // &str[1] = "hi";
    // Q4: Are you able to assign to a subpart of the string?
    // A: No.
}

/** Function to test cin. */
void practical_5_2_1_1(void) {
    string str;

    for (int i = 0; i < 5; i++) {
        cout << "Enter a string: ";
        cin >> str;
        cout << "You entered " << str << endl;
    }
    // Q5: How does cin behave when you enter a string that has spaces in it?
    // A: cin treats the string after the ' ' as a seperate string.
}

/** Function to test getline(). */
void practical_5_2_1_2(void) {
    string str;

    for (int i = 0; i < 5; i++) {
        cout << "Enter a string: ";
        getline(cin, str);
        cout << "You entered " << str << endl;
    }
    // Q6: How does the getline() function behaviour differ from cin<< behaviour?
    // A: getline() treats the inputs after the space as the same string.
}

/** Function to test the combination with cin and getline(). */
void practical_5_2_1_3(void) {
    string name;
    int age;
    string gender;
    cout << "Enter your full name: ";
    getline(cin,name);
    cout << "Enter your age: ";
    cin >> age;
    cout << "Are you male or female? ";
    getline(cin,gender);
    cout << name << " is a " << age << " year old " << gender << endl;
    // Q7: What is the behaviour of this program and why?
    // A: The program skipped asking for gender.
}

/**  The fixed version of the combination with cin and getline(). */
void practical_5_2_1_4(void) {
    string name;
    int age;
    string gender;
    cout << "Enter your full name: ";
    getline(cin,name);
    cout << "Enter your age: ";
    cin >> age;
    cin.ignore();
    cout << "Are you male or female? ";
    getline(cin,gender);
    cout << name << " is a " << age << " year old " << gender << endl;
    // Q8: How does the program behave now?
    // A: The program behaved just as expected.
    // Still has a problem when age is not an int.
}

/** Function to test out string manipulation and comparison. */
void practical_5_2_2(void) {
    // Operators
    cout << "1==1: " << (1==1) << endl;
    cout << "cat==cat:" << ((string) "cat" == "cat") << endl;
    cout << "cat==dog:" << ((string) "cat" == "dog") << endl;
    cout << "cat>dog:" << ("cat" > (string) "dog") << endl;
    cout << "cat<dog:" << ("cat" < (string) "dog") << endl;
    // Q9: How do the ==, < and > operators behave with regards to strings?
    // A: Simillar to comparisons between int and other numeric values.

    // Copying
    string str1 = "The cat sat on the mat";
    string str2 = "dog";
    string str3 = "cat";
    cout << "Before Change: " << str1 << endl;
    // str1.copy(str2, 3); // copy length chars from str1 to str2.
    str2.copy(&str1[4], 3, 0); // copy length chars from pos in str1 to str2.
    cout << "After Change 1: " << str1 << endl;
    str3.copy(&str1[19], 3, 0); // copy length chars from pos in str1 to str2.
    cout << "After Change 2: " << str1 << endl;
    cout << "Length of str1 after change: " << str1.length() << endl;

    // substr()
    str1 = "The cat sat on the mat";
    cout << "cat: " << str1.substr(4, 3) << endl;
    cout << "mat: " << str1.substr(19, 3) << endl;
    str1.substr(4, 3) = "dog";
    cout << "After setting substr: " << str1 << endl;
    // Q10: Are you able to use substr() to write to (change) part of the given string?
    // A: No.

    // insert() and erase()
    str1 = "The cat sat on the mat";
    // Code to modify str1 to "The fat cat sat on the mat".
    str1.insert(4, "fat ", 0, 4);
    cout << "str1=" << str1 << endl;
    // Code to modify str1 to "The fat cat on the mat".
    str1.erase(12, 4);
    cout << "str1=" << str1 << endl;
}

/** Prints a 1D array as a 2D array.
 *
 * @param x The array to print.
 * @param M The number of rows the 2D array has.
 * @pram N The number of columns the 2D array has.
 */
void printOneDAsTwoD(int *x, int M, int N) {
    int i,j;
    for (i=0;i<M;i++) {
        for (j=0;j<N;j++) {
            cout << x[i*N+j] << " ";
        }
        cout << endl;
    }
}

/** Function to test out the processing of 1D and 2D arrays. */
void practical_5_2_3(void) {
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << "4x3" << endl;
    printOneDAsTwoD(x, 4, 3);
    cout << "3x4" << endl;
    printOneDAsTwoD(x, 3, 4);
    cout << "2x6" << endl;
    printOneDAsTwoD(x, 2, 6);
}

int adventureGame::processCommand() {
    if (command == "exit") {
        cout << "You exit the game.";
        return(0);
    }

    switch (room) {
        case 1:
            return processRoom1();
        case 2:
            return processRoom2();
        case 3:
            return processRoom3();
        case 4:
            return processRoom4();
    }
    cout << "Command: " << command << " not recognized" << endl;    // Process the look command
    return 1;
}

int adventureGame::processRoom1() {
    if (command == "look") {
        cout << "You are in a big hall. ";
        if (monster == 1) cout << "There is a monster here. ";
        if (monster == 0) cout << "There is a dead monster here. ";
        cout << "There is an exit to the east and the south.";
        cout << endl;
        return(1);
    }
    // Process the "killMonster" command
    if (command == "killMonster") {
        if (monster == 1) {
            cout << "You slay the vile monster!" << endl;
            monster = 0;
        } else {
            cout << "The monster is already dead!" << endl;
        }
        return(1);
    }
    // Process "east" command
    if ((command=="east") || (command=="e")) {
        cout << "You go east to the courtyard." << endl;
        room=2; //Change the player’s location to be in the courtyard.
        return(1);
    }
    // Process "south" command
    if ((command=="south") || (command=="s")) {
        cout << "You go south to the bedroom." << endl;
        room=3; //Change the player’s location to be in the bedroom.
        return(1);
    }
    // Process "north" command
    if ((command=="north") || (command=="n")) {
        cout << "You cannot go north from here." << endl;
        return(1);
    }
    // Process "west" command
    if ((command=="west") || (command=="w")) {
        cout << "You cannot go west from here." << endl;
        return(1);
    }
    cout << "Command: " << command << " not recognized" << endl;
    return(1);
}

int adventureGame::processRoom2() {
    if (command == "look") {
        cout << "You are in a courtyard. ";
        cout << "There is an exit to the west and the south.";
        cout << endl;
        return(1);
    }
    // Process "east" command
    if ((command=="east") || (command=="e")) {
        cout << "You cannot go east from here." << endl;
        return(1);
    }
    // Process "south" command
    if ((command=="south") || (command=="s")) {
        cout << "You go south to the dining room." << endl;
        room=4; //Change the player’s location to be in the bedroom.
        return(1);
    }
    // Process "north" command
    if ((command=="north") || (command=="n")) {
        cout << "You cannot go north from here." << endl;
        return(1);
    }
    // Process "west" command
    if ((command=="west") || (command=="w")) {
        cout << "You go west to the main hall." << endl;
        room=1; //Change the player’s location to be in the bedroom.
        return(1);
    }

    cout << "Command: " << command << " not recognized" << endl;
    return(1);
}

int adventureGame::processRoom3() {
    if (command == "look") {
        cout << "You are in a bedroom. ";
        cout << "There is an exit to the east and the north.";
        cout << endl;
        return(1);
    }
    // Process "east" command
    if ((command=="east") || (command=="e")) {
        cout << "You go east to the dining room." << endl;
        room=4;
        return(1);
    }
    // Process "south" command
    if ((command=="south") || (command=="s")) {
        cout << "You cannot go south from here." << endl;
        return(1);
    }
    // Process "north" command
    if ((command=="north") || (command=="n")) {
        cout << "You go north to the main hall." << endl;
        room=1;
        return(1);
    }
    // Process "west" command
    if ((command=="west") || (command=="w")) {
        cout << "You cannot go west from here." << endl;
        return(1);
    }

    cout << "Command: " << command << " not recognized" << endl;
    return(1);
}

int adventureGame::processRoom4() {
    if (command == "look") {
        cout << "You are in a dining room. ";
        cout << "There is an exit to the west and the north.";
        cout << endl;
        return(1);
    }
    // Process "east" command
    if ((command=="east") || (command=="e")) {
        cout << "You cannot go east from here." << endl;
        return(1);
    }
    // Process "south" command
    if ((command=="south") || (command=="s")) {
        cout << "You cannot go south from here." << endl;
        return(1);
    }
    // Process "north" command
    if ((command=="north") || (command=="n")) {
        cout << "You go north to the courtyard." << endl;
        room=2;
        return(1);
    }
    // Process "west" command
    if ((command=="west") || (command=="w")) {
        cout << "You go west to the bedroom." << endl;
        room=3; //Change the player’s location to be in the bedroom.
        return(1);
    }

    cout << "Command: " << command << " not recognized" << endl;
    return(1);
}
