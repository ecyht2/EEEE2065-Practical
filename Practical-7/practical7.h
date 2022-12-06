#ifndef PRACTICAL7_H_
#define PRACTICAL7_H_

#include <cinttypes>
#include <string>

const uint8_t DAYS_IN_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::string DAYS_OF_WEEK[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

class Calendar {
  public:
	Calendar(void);
	Calendar(int y, uint8_t m, uint8_t d, uint8_t D);
	Calendar(Calendar &cal);
	Calendar(int M);
	~Calendar();
	void printDate(void);
	void printMeeting(void);
  private:
	uint64_t thisyear;
	uint8_t thismonth, thisday, thisdate;
	int *meeting = nullptr;
	unsigned int Nmeeting = 0;
};

// Adveture Game
void convertToLower(std::string &str);
void convertToCap(std::string &str);

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
		int N_artifact = 4;
		std::string artifact[4] = {"Sword", "Golden chalice", "First Aid kit", "Food"};
		int artifactLoc[4] = {0, 1, 2, 3};
    public:
        /** Gets user input for command to execute.
         *
         * @return 0 if failure and 1 if success.
         * */
        int getCommand(void);
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
        /** Process "get object" commands.
         *
         * @return 1 if success, 0 if not a valid "get object"  command.
         * */
        virtual int processGet(std::string object);
		/** Gets the number of artifact the player is carrying.
		 *
		 * @return The number of artifact the player is carrying.
		 * */
		virtual int noArtPlayerCarrying(void);
        /** Process inventory commands.
         *
         * @return 1 if success, 0 if not a valid inventory  command.
         * */
         virtual int processInventory(void);
        /** Process "drop object" commands.
         *
         * @return 1 if success, 0 if not a valid "drop object"  command.
         * */
        virtual int processDrop(std::string object);
};

#endif // PRACTICAL7_H_
