#include "printData.h"
#include <iostream>
#include <string>

using namespace std;


int printList(int N) {
  int i = 0;

  for (i = 0; i < N; i++) {
    cout << "Count i=" << i << endl;
  }

  return i;
}

void printBigTextSimple() {
  cout << "**** **** **** ****\t **   **    ** ****\t*  * *  *" << endl;
  cout << "*    *    *    *   \t*  * *  * *    *   \t*  * * * " << endl;
  cout << "***  ***  ***  *** \t  *  *  * ***  *** \t**** **  " << endl;
  cout << "*    *    *    *   \t *   *  * *  *    *\t*  * * * " << endl;
  cout << "**** **** **** ****\t****  **   **  *** \t*  * *  *" << endl;
}

BigText::BigText(string str) {
  this->text = str;

  // Setting up texts
  setupSymbols();
  setupLetters();
  setupNumbers();
}

void BigText::print() {
  // Looping over 5 lines
  for(int i = 0; i < 5; i ++) {
    // Looping over the all characters
    for(int j = 0; j < text.length(); j++) {
      char current_char = text[j];

      if (big_characters.count(current_char) == 0) {
        cout << "      ";
        continue;
      }
      // Printing Characters
      cout << big_characters[current_char][i] << " ";
    }

    // Printing New Line
    cout << endl;
  }
}

string BigText::getText() {
  return this->text;
}

BigText& BigText::setText(string str) {
  this->text = str;
  return *this;
}

void BigText::addCharacter(char c, array<string, 5> array) {
  this->big_characters[c] = array;
}

void BigText::setupLetters() {
  // White Space
  addCharacter(' ',
               {"     ",
                "     ",
                "     ",
                "     ",
                "     "});
  // A
  addCharacter('A',
               {" *** ",
                "*   *",
                "*****",
                "*   *",
                "*   *"});
  // B
  addCharacter('B',
               {"**** ",
                "*   *",
                "**** ",
                "*   *",
                "**** "});
  // C
  addCharacter('C',
               {"  ***",
                " *   ",
                "*    ",
                " *   ",
                "  ***"});
  // D
  addCharacter('D',
               {"***  ",
                "*  * ",
                "*   *",
                "*  * ",
                "***  "});
  // E
  addCharacter('E',
               {"*****",
                "*    ",
                "**** ",
                "*    ",
                "*****"});
  // F
  addCharacter('F',
               {"*****",
                "*    ",
                "**** ",
                "*    ",
                "*    "});
  // G
  addCharacter('G',
               {" ****",
                "*    ",
                "* ***",
                "*   *",
                " ****"});
  // H
  addCharacter('H',
               {"*   *",
                "*   *",
                "*****",
                "*   *",
                "*   *"});
  // I
  addCharacter('I',
               {"*****",
                "  *  ",
                "  *  ",
                "  *  ",
                "*****"});
  // J
  addCharacter('J',
               {"*****",
                "   * ",
                "   * ",
                "*  * ",
                " **  "});
  // K
  addCharacter('K',
               {"*  **",
                "* *  ",
                "**   ",
                "* *  ",
                "*  **"});
  // L
  addCharacter('L',
               {"*    ",
                "*    ",
                "*    ",
                "*    ",
                "*****"});
  // M
  addCharacter('M',
               {"*   *",
                "** **",
                "* * *",
                "*   *",
                "*   *"});
  // N
  addCharacter('N',
               {"*   *",
                "**  *",
                "* * *",
                "*  **",
                "*   *"});
  // O
  addCharacter('O',
               {" *** ",
                "*   *",
                "*   *",
                "*   *",
                " *** "});
  // P
  addCharacter('P',
               {"***  ",
                "*  * ",
                "***  ",
                "*    ",
                "*    "});
  // Q
  addCharacter('Q',
               {" *** ",
                "*   *",
                "*   *",
                " *** ",
                "    *"});
  // R
  addCharacter('R',
               {"**** ",
                "*   *",
                "**** ",
                "*  * ",
                "*   *"});
  // S
  addCharacter('S',
               {" ****",
                "*    ",
                " *** ",
                "    *",
                "**** "});
  // T
  addCharacter('T',
               {"*****",
                "  *  ",
                "  *  ",
                "  *  ",
                "  *  "});
  // U
  addCharacter('U',
               {"*   *",
                "*   *",
                "*   *",
                "*   *",
                " *** "});
  // V
  addCharacter('V',
               {"*   *",
                "*   *",
                "*   *",
                " * * ",
                "  *  "});
  // W
  addCharacter('W',
               {"*   *",
                "*   *",
                "* * *",
                "* * *",
                " * * "});
  // X
  addCharacter('X',
               {"*   *",
                " * * ",
                "  *  ",
                " * * ",
                "*   *"});
  // Y
  addCharacter('Y',
               {"*   *",
                " * * ",
                "  *  ",
                "  *  ",
                "  *  "});
  // Z
  addCharacter('Z',
               {"*****",
                "   * ",
                "  *  ",
                " *   ",
                "*****"});
}

void BigText::setupNumbers(void) {
  // 0
  addCharacter('0',
               {"*****",
                "*   *",
                "*   *",
                "*   *",
                "*****"});
  // 1
  addCharacter('1',
               {"    *",
                "    *",
                "    *",
                "    *",
                "    *"});
  // 2
  addCharacter('2',
               {"*****",
                "    *",
                "*****",
                "*    ",
                "*****"});
  // 3
  addCharacter('3',
               {"*****",
                "    *",
                "*****",
                "    *",
                "*****"});
  // 4
  addCharacter('4',
               {"*   *",
                "*   *",
                "*****",
                "    *",
                "    *"});
  // 5
  addCharacter('5',
               {"*****",
                "*    ",
                "*****",
                "    *",
                "*****"});
  // 6
  addCharacter('6',
               {"*****",
                "*    ",
                "*****",
                "*   *",
                "*****"});
  // 7
  addCharacter('7',
               {"*****",
                "    *",
                "    *",
                "    *",
                "    *"});
  // 8
  addCharacter('8',
               {"*****",
                "*   *",
                "*****",
                "*   *",
                "*****"});
  // 9
  addCharacter('9',
               {"*****",
                "*   *",
                "*****",
                "    *",
                "*****"});
}

void BigText::setupSymbols(void) {
  // !
  addCharacter('!',
               {"  *  ",
                "  *  ",
                "  *  ",
                "     ",
                "  *  "});
  // @
  addCharacter('@',
               {"*****",
                "* ***",
                "* ***",
                "*    ",
                "*****"});
  // #
  addCharacter('#',
               {" * * ",
                "*****",
                " * * ",
                "*****",
                " * * "});
  // $
  addCharacter('$',
               {" ****",
                "* *  ",
                " *** ",
                "  * *",
                "**** "});
  // %
  addCharacter('%',
               {"*   *",
                "   * ",
                "  *  ",
                " *   ",
                "*   *"});
  // ^
  addCharacter('^',
               {"  *  ",
                " * * ",
                "*   *",
                "     ",
                "     "});
  // &
  addCharacter('&',
               {" *** ",
                " *   ",
                "* * *",
                "*  * ",
                "*** *"});
  // *
  addCharacter('*',
               {"*   *",
                " * * ",
                "*****",
                " * * ",
                "*   *"});
  // (
  addCharacter('(',
               {"  *  ",
                " *   ",
                "*    ",
                " *   ",
                "  *  "});
  // )
  addCharacter(')',
               {"  *  ",
                "   * ",
                "    *",
                "   * ",
                "  *  "});
  // [
  addCharacter('[',
               {"***  ",
                "*    ",
                "*    ",
                "*    ",
                "***  "});
  // ]
  addCharacter(']',
               {"  ***",
                "    *",
                "    *",
                "    *",
                "  ***"});
  // ;
  addCharacter('\'',
               {" **  ",
                " **  ",
                "     ",
                " *   ",
                "*    "});
  // '
  addCharacter('\'',
               {"*    ",
                "*    ",
                "     ",
                "     ",
                "     "});
  // ,
  addCharacter(',',
               {"     ",
                "**   ",
                "**   ",
                " *   ",
                "*    "});
  // .
  addCharacter('.',
               {"     ",
                "     ",
                "     ",
                "**   ",
                "**   "});
  // ?
  addCharacter('?',
               {"**** ",
                "    *",
                "  ** ",
                "     ",
                "  *  "});
}
