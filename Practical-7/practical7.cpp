#include "practical7.h"

#include <iostream>
#include <ctime>
#include <exception>
#include <string>
#include <algorithm>

// Calendar
Calendar::Calendar(void) {
    // https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    this->thisyear = now->tm_year + 1900;
    this->thismonth = now->tm_mon + 1;
    this->thisdate = now->tm_mday;
    this->thisday = now->tm_wday;

    std::cout << "In default constructor" << std::endl;
}

Calendar::Calendar(int y, uint8_t m, uint8_t d, uint8_t D): thisyear(y) {
    if (m >= 1 && m <= 12) {
        this->thismonth = m;
    } else {
        throw std::invalid_argument("Month must be between 1-12");
    }

    if (d >= 1 && d <= DAYS_IN_MONTH[m - 1]) {
        this->thisdate = d;
    } else {
        std::string error_msg = "Date must be between 1-";
        error_msg += std::to_string(DAYS_IN_MONTH[m - 1]);
        throw std::invalid_argument(error_msg);
    }

    if (D >= 0 && D <= 6) {
        this->thisday = D;
    } else {
        throw std::invalid_argument("Day of Week must be between 0-6");
    }
}

Calendar::Calendar(Calendar &cal): thisyear(cal.thisyear), thismonth(cal.thismonth) {
    if (cal.thisdate == DAYS_IN_MONTH[cal.thismonth - 1]) {
        if (cal.thismonth != 12) {
            (this->thismonth)++;
        } else {
            this->thismonth = 1;
            (this->thisyear)++;
        }
        this->thisdate = 1;
    } else {
        this->thisdate = cal.thisdate + 1;
    }
    this->thisday = (cal.thisday + 1) % 7;
}

Calendar::Calendar(int M): Nmeeting(M) {
    std::cout << "In dynamic constructo M=" << M << std::endl;

    meeting = new int[this->Nmeeting];

    this->thisyear = 0;
    this->thismonth = 1;
    this->thisdate = 1;
    this->thisday = 0;
}

Calendar::~Calendar(void) {
    std::cout << "In destructor" << std::endl;
    if (meeting != nullptr) {
        delete [] meeting;
    }
}

void Calendar::printDate(void) {
    std::cout << DAYS_OF_WEEK[this->thisday] << " "
              << (unsigned int) this->thisdate << "/"
              << (unsigned int) this->thismonth << "/"
              << thisyear << std::endl;
}

void Calendar::printMeeting(void) {
    for (int i = 0; i < (int) this->Nmeeting; i++) {
        std::cout << i << " " << meeting[i] << std::endl;
    }
}

// Adventure Game
void convertToLower(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void convertToCap(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

int adventureGame::getCommand(void) { // getCommand function is written inline
    std::cout << "Enter Command: ";
    std::getline(std::cin, command); // For now we only take single-word commands using cin.
    return(1);
}

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
    // Process get
    if (command.substr(0, 4) == "get ") {
        validCommand += processGet(command.substr(4, command.size()));
    }
    // Process inventory
    validCommand += processInventory();
    // Process drop
    if (command.substr(0, 5) == "drop ") {
        validCommand += processDrop(command.substr(5, command.size()));
    }
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
        for (int i = 0; i < this->N_artifact; i++) {
            if (artifactLoc[i] == room) {
                std::cout << "You see a " << artifact[i] << " here" << std::endl;
            }
        }
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

int adventureGame::processGet(std::string object) {
    convertToLower(object);

    for (int i = 0; i < N_artifact; i++) {
        convertToLower(artifact[i]);
        if (object == artifact[i]) {
            convertToCap(object);
            if (artifactLoc[i] == room) {
                if (noArtPlayerCarrying() < 3) {
                    std::cout << "You pick up the " << object << std::endl;
                    artifactLoc[i] = -1;
                    return 1;
                } else {
                    std::cout << "You are overloaded, drop another object first" << std::endl;
                    return 1;
                }
            } else {
                std::cout << "There is no " << object << " here." << std::endl;
                return 1;
            }
        }
    }
    std::cout << "There is no " << object << " here." << std::endl;
    return 1;
};

int adventureGame::noArtPlayerCarrying(void) {
    int N = std::count_if(std::begin(artifactLoc), std::end(artifactLoc),
                          [](int x) {return x == -1;});
    return N;
}

int adventureGame::processInventory(void) {
    if (command == "inventory") {
        std::cout << "You are carrying:" << std::endl;
        for (int i = 0, j = 0; i < N_artifact; i++) {
            if (artifactLoc[i] == -1) {
                std::cout << ++j << ": " << artifact[i] << std::endl;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

int adventureGame::processDrop(std::string object) {
    convertToLower(object);

    for (int i = 0; i < N_artifact; i++) {
        convertToLower(artifact[i]);
        if (artifactLoc[i] == -1 && object == artifact[i]) {
            convertToCap(object);
            artifactLoc[i] = -2;
            std::cout << "You dropped " << object << "." << std::endl;
            return 1;
        }
    }
    convertToCap(object);
    std::cout << object << " not in inventory." << std::endl;
    return 1;
}
