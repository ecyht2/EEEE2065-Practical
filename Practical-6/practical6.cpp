#include "practical6.h"

#include <iostream>

void practical6_1(void) {
    Student x;
    x.setID(69);
    x.setName("Johnny");
    x.setMathScore(70);
    x.setPhysicsScore(69);
    x.setProgrammingScore(100);
    x.calcAverage();
    x.print();

    Student y;
    y.takeInputFromUser();
    y.print();
}

Student::Student(void) {

}

void Student::print(void) {
    std::cout << "Student ID: " << this->ID << std::endl
              << "Name: " << this->name << std::endl
              << "Math Score: " << this->sMath << std::endl
              << "Physics Score: " << this->sPhysics << std::endl
              << "Programming Score: " << this->sProg << std::endl
              << "Average: " << this->sAvg << std::endl;
}

void Student::calcAverage(void) {
    float sum = this->sMath + this->sPhysics + this->sProg;
    this->sAvg = sum / 3;
}

void Student::takeInputFromUser(void) {
    std::cout << "Enter student name:";
    getline(std::cin,name);
    std::cout << "Enter student ID#:";
    std::cin >> ID;
    std::cout << "Enter student math score:";
    std::cin >> sMath;
    std::cout << "Enter student physics score:";
    std::cin >> sPhysics;
    std::cout << "Enter student programming score:";
    std::cin >> sProg;

    this->calcAverage();
}

// Adventure Game
int adventureGame::processCommand(void) {
    // Process quitting commands
    if (command == "quit" || command == "exit") {
        return 0;
    }
    int validCommand=0;// To determine if user has issued a valid command.
    // Process the look command
    validCommand+=processLook();
    // Process the "killMonster" command
    validCommand+=processKillMonster();
    // Process the movement command
    validCommand+=processMovement2();
    if (validCommand==0) std::cout << "Unknown command: " << command << "\n";
    return(1);
}

int adventureGame::processRoom0(void) {
    int validCommand=0;// To determine if user has issued a valid command.
    // Process the look command
    if (command=="look") {
        std::cout << "You are in a big hall. There is a courtyard to the east, and a bed room lies to the south.";
        if (monster==1) std::cout << "There is a monster here.";
        if (monster==0) std::cout << "There is a dead monster here.";
        std::cout << "\n";
        return(1);
    }
    // Process the "killMonster" command
    if (command=="killMonster") {
        if (monster==1) {
            std::cout << "You slay the vile monster!\n";
            monster=0;
        } else std::cout << "The monster is already dead!";
        return(1);
    }
    validCommand+=processMovement("east","e","You go east to the courtyard", 1);
    validCommand+=processMovement("south","s","You go south to the bedroom", 2);
    validCommand+=processMovement("north","n","You cannot go north", -1);
    validCommand+=processMovement("west","w","You cannot go west", -1);
    if (validCommand==0) std::cout << "Unknown command: " << command << "\n";
    return(1);
}

int adventureGame::processRoom1(void) {
    int validCommand=0;// To determine if user has issued a valid command.
    // Process the look command
    if (command=="look") {
        std::cout << "You are in a courtyard. There is a big hall to the west, and a dining room lies to the south.";
        std::cout << "\n";
        return(1);
    }
    validCommand+=processMovement("east","e","You cannot go east.", -1);
    validCommand+=processMovement("south","s","You go south to the dining room.", 3);
    validCommand+=processMovement("north","n","You cannot go north.", -1);
    validCommand+=processMovement("west","w","You go west to the big hall.", 0);
    if (validCommand==0) std::cout << "Unknown command: " << command << "\n";
    return(1);
}

int adventureGame::processRoom2(void) {
    int validCommand=0;// To determine if user has issued a valid command.
    // Process the look command
    if (command=="look") {
        std::cout << "You are in a bed room. There is a dining room to the east, and a big hall lies to the north.";
        std::cout << "\n";
        return(1);
    }
    validCommand+=processMovement("east","e","You go east to the dining room.", 3);
    validCommand+=processMovement("south","s","You cannot go south.", -1);
    validCommand+=processMovement("north","n","You go north to the big hall.", 0);
    validCommand+=processMovement("west","w","You cannot go west.", -1);
    if (validCommand==0) std::cout << "Unknown command: " << command << "\n";
    return(1);
}

int adventureGame::processRoom3(void) {
    int validCommand=0;// To determine if user has issued a valid command.
    // Process the look command
    if (command=="look") {
        std::cout << "You are in a dining room. There is a bed room to the west, and a courtyard lies to the north.";
        std::cout << "\n";
        return(1);
    }
    validCommand+=processMovement("east","e","You cannot go east.", -1);
    validCommand+=processMovement("south","s","You cannot go south", -1);
    validCommand+=processMovement("north","n","You go north to the courtyard.", 1);
    validCommand+=processMovement("west","w","You go west to the bed room.", 2);
    if (validCommand==0) std::cout << "Unknown command: " << command << "\n";
    return(1);
}

int adventureGame::processMovement(std::string direction, std::string dir,
                                   std::string mesg, int roomVal) {
    if(command==direction || command==dir) {
        std::cout << mesg << std::endl;
        if (roomVal!=-1) room=roomVal;
        return(1);
    } else return(0);
}

int adventureGame::processMovement2 (void) {
    if(command=="north" || command=="n") {
        std::cout << moveArray[room][0] << std::endl;
        if (moveToArray[room][0]!=-1) room=moveToArray[room][0];
        return(1);
    } else if(command=="south" || command=="s") {
        std::cout << moveArray[room][1] << std::endl;
        if (moveToArray[room][1]!=-1) room=moveToArray[room][1];
        return(1);
    } else if(command=="east" || command=="e") {
        std::cout << moveArray[room][2] << std::endl;
        if (moveToArray[room][2]!=-1) room=moveToArray[room][2];
        return(1);
    } else if(command=="west" || command=="w") {
        std::cout << moveArray[room][3] << std::endl;
        if (moveToArray[room][3]!=-1) room=moveToArray[room][3];
        return(1);
    } else return(0);
}

int adventureGame::processLook(void) {
    if (command == "look") {
        std::cout << lookArray[room] << " ";
        if (monsterStatusArray[room] == -1) {
            std::cout << "There is a " << monsterArray[room] << " here.";
        } else {
            std::cout << "There is a dead " << monsterArray[room] << " here.";
        }
        std::cout << std::endl;
        return 1;
    } else {
        return 0;
    }
}

int adventureGame::processKillMonster(void) {
    if (command == "killMonster") {
        if (monsterStatusArray[room] == -1) {
            std::cout << "You slay the vile " << monsterArray[room] << "!";
            monsterStatusArray[room] = 0;
        } else {
            std::cout << "The " << monsterArray[room] << " is alread dead.";
        }
        std::cout << std::endl;
        return 1;
    } else {
        return 0;
    }
}
