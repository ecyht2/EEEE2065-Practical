#ifndef PRINTDATA_H_
#define PRINTDATA_H_

#include <string>
#include <map>
#include <array>
using namespace std;

int printList(int);
void printBigTextSimple();

class BigText {
    public:
        BigText(string);
        void print();
        string getText();
        BigText& setText(string);
    private:
        string text;
        map<char, array<string, 5>> big_characters;
        void setupLetters(void);
        void setupNumbers(void);
        void setupSymbols(void);
    protected:
        void addCharacter(char, array<string, 5>);
};

#endif // PRINTDATA_H_
