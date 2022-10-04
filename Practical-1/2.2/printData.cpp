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

void BigText::setText(string str) {
  this->text = str;
}

int BigText::getCharIndex(char c) {
  int ascii_index = (int) c;
  int index = 0;

  if(ascii_index > 64 && ascii_index < 91) {
    // Upper Case Letters
    index = ascii_index - 64;
  } else if (ascii_index > 96 && ascii_index < 123) {
    // Lower Case Letters
    index = ascii_index - 96;
  } else if (ascii_index > 47 && ascii_index < 58) {
    // Numbers
    index = ascii_index - 47;
    // Shifting by the number of alphabets
    index += 26;
  } else {
    // Other characters
    index = 0;
  }

  return index;
}
