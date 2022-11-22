#ifndef PRACTICAL6_H_
#define PRACTICAL6_H_

#include <iostream>
#include <string>

// Student Class
/** Test function to test out the student class. */
void practical6_1(void);

/** A class representing a Student.
 *
 * The student has an ID, name, math score
 * physics score and a programming score.
 * */
class Student{
    public: //Public variables and functions go here
        /** Deafult constructor class for Student. */
        Student(void);
        /** Prints out information about the student. */
        void print(void);
        /** Calculates the average score of the student. */
        void calcAverage(void);
        /** Populates the student data via standard input. */
        void takeInputFromUser(void);
        // Setters
        /** Sets the student's name.
         *
         * @param name The name to set to.
         * */
        void setName(std::string name) {
            this->name = name;
        }
        /** Sets the student's ID.
         *
         * @param ID The ID to set to.
         * */
        void setID(int ID) {
            this->ID = ID;
        }
        /** Sets the student's math score.
         *
         * @param sMath The score to set to.
         * */
        void setMathScore(int sMath) {
            this->sMath = sMath;
        }
        /** Sets the student's physics score.
         *
         * @param sPhysics The score to set to.
         * */
        void setPhysicsScore(int sPhysics) {
            this->sPhysics = sPhysics;
        }
        /** Sets the student's programming score.
         *
         * @param sProg The score to set to.
         * */
        void setProgrammingScore(int sProg) {
            this->sProg = sProg;
        }
        // Getters
        /** Gets the student's name
         *
         * @return The student's name
         * */
        std::string getName(void) {
            return this->name;
        }
        /** Gets the student's ID
         *
         * @return The student's ID
         * */
        int getID(void) {
            return this->ID;
        }
        /** Gets the student's math score
         *
         * @return The student's math score
         * */
        int getMathScore(void) {
            return this->sMath;
        }
        /** Gets the student's physics score
         *
         * @return The student's physics score
         * */
        int getPhysicsScore(void) {
            return this->sPhysics;
        }
        /** Gets the student's programming score
         *
         * @return The student's programming score
         * */
        int getProgrammingScore(void) {
            return this->sProg;
        }
        /** Gets the student's average score
         *
         * @return The student's average score
         * */
        float getAverageScore(void) {
            return this->sAvg;
        }
    private: //Private variables and functions go here
        /** Member Variable that stores the student's name. */
        std::string name = "";
        int ID = 0; /**< Member variable that stores the student's ID. */
        int sMath = 0; /**< Member variable that stores the student's math score. */
        int sPhysics = 0; /**< Member variable that stores the student's physics score. */
        int sProg = 0; /**< Member variable that stores the student's programming score. */
        float sAvg = 0; /**< Member variable that stores the student's average score. */
};

// Adveture Game
class adventureGame {
    private:
        std::string command; // command taken from the user stored in this string.
        int monster=1; // a flag indicating the status of a monster. Monster is alive at the start.
        int room=0; // The room the player is currently in

        std::string lookArray[4]={
        // Main Hall
        "You are in a big hall. There is a courtyard to the east, and a bed room lies to the south.",
        // Courtyard
        "You are in a courtyard. There is a big hall to the west, and a dining room lies to the south.",
        // Bed room
        "You are in a bed room. There is a dining room to the east, and a big hall lies to the north.",
        // Dining room
        "You are in a dining room. There is a bed room to the west, and a courtyard lies to the north."
    };

        std::string moveArray[4][4]={
        // Main Hall
        {"You cannot go north.", "You go south to the bed room.",
         "You go east to the courtyard.","You cannot go west."},
        // Courtyard
        {"You cannot go north.", "You go south to the dining room.",
         "You cannot go east.", "You go west to the big hall."},
        // Bed room
        {"You go north to the big hall.", "You cannot go south.",
         "You go east to the dining room.", "You cannot go west."},
        // Dining room
        {"You go north to the courtyard.", "You cannot go south.",
         "You cannot go east.", "You go west to the bed room."}
    };

        int moveToArray[4][4]={
        // Main Hall
        {-1, 2, 1, -1},
        // Courtyard
        {-1, 3, -1, 0},
        // Bed room
        {0, -1, 3, -1},
        // Dining room
        {1, -1, -1, 2}
    };
        std::string monsterArray[4] = {"monster", "vampire", "zombie", "werewolf"};
        int monsterStatusArray[4] = {-1, -1, -1, -1};
    public:
        /** Gets user input for command to execute.
         *
         * @return 0 if failure and 1 if success.
         * */
        int getCommand(void) { // getCommand function is written inline
            std::cout << "Enter Command: ";
            std::cin >> command; // For now we only take single-word commands using cin.
            return(1);
        }
        /** Main function to process command inserted by the user.
         *
         * @return 1 indicating continue the game, 0 indicating exitting.
         */
        int processCommand(void); // function to processCommand
    protected:
        /** Process commands in room zero. (Deprecated).
         *
         * @return 1 if success, 0 if not a valid command.
         * */
        virtual int processRoom0(void);
        /** Process commands in room one. (Deprecated).
         *
         * @return 1 if success, 0 if not a valid command.
         * */
        virtual int processRoom1(void);
        /** Process commands in room two. (Deprecated).
         *
         * @return 1 if success, 0 if not a valid command.
         * */
        virtual int processRoom2(void);
        /** Process commands in room three. (Deprecated).
         *
         * @return 1 if success, 0 if not a valid command.
         * */
        virtual int processRoom3(void);
        /** Process movment commands. (Deprecated in favor of processMovement2).
         *
         * @param direction The direction of the movement command.
         * @param dir The short version of the direction command.
         * @param mesg The message to print.
         * @param roomVal The room number to move to on success. -1 if invalid direction.
         *
         * @return 1 if success, 0 if not a valid movement.
         */
        virtual int processMovement(std::string direction, std::string dir,
                                    std::string mesg, int roomVal);
        /** Process movment commands.
         *
         * @return 1 if success, 0 if not a valid movement command.
         * */
        virtual int processMovement2(void);
        /** Process look commands.
         *
         * @return 1 if success, 0 if not a valid look command.
         * */
        virtual int processLook(void);
        /** Process killMonster commands.
         *
         * @return 1 if success, 0 if not a valid killMonster command.
         * */
        virtual int processKillMonster(void);
};

#endif // PRACTICAL6_H_
