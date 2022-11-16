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
}

void BigText::print() {
  // Looping over 5 lines
  for(int i = 0; i < 5; i ++) {
    // Looping over the all characters
    for(int j = 0; j < text.length(); j++) {
      char current_char = text[j];
      int index = getCharIndex(current_char);

      // Printing Characters
      cout << big_characters[index][i] << " ";
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
