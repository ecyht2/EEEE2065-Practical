#include "practical3.h"
#include <string.h>
#include <iostream>
#include <functional>
#include <fstream>

using namespace std;

/** Code Related to Practical 3.1. */
void practical3_1() {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char *str;
    // Q1: What does str contain at this point (prior to any assignment?) Should you print
    // out the string pointed to by str at this time? Why or why not?
    // Answer: str containts a random location in memory. It is a bad idea to print out the
    // string at this point as we shouldn't have access to this memory and it will most likely
    // be some random characters.

    cout << "strlen(alphabet) = " << strlen(alphabet) << endl;

    str = alphabet;
    cout << "str=" << str << endl;
    cout << "strlen(str)=" << strlen(str) << endl;
    // Q2: What is the length of s? Do you understand why?
    // Answer: s doesn't exist but the length of str = 26 as both str and alphabet
    // are pointing to the same string in mememory.

    str++;
    cout << "str=" << str << endl;
    cout << "strlen(str)=" << strlen(str) << endl;
    // Q3: Explain your observed result.
    // Answer: After adding 1 to str, str is pointing to a memory location of 1 byte
    // after the original str. The byte after str is b hence the string now starts
    // with b and ends at z

    str = &alphabet[10];
    cout << "str=" << str << endl;
    cout << "strlen(str)=" << strlen(str) << endl;
    // Q4:  Explain again why you are getting what you observe.
    // Answer: Now str is pointing at the 10th character in the alphabet array (k).
    // Hence, it starts printing from k-z.
}

/** Prints x op y = .
 *
 * This function is mainly used by printAND, printOR and printXOR so less code needs to be
 * repeated.
 *
 * @param x First integer to use.
 * @param y Second integer to use.
 * @param op The operator.
 * */
void printOperator(int x, int y, string op) {
    cout << x << " " << op << " " << y << " = ";
}

/** Prints the logical AND output of x and y.
 *
 * @param x The first integer to compare.
 * @param y The second integer to compare.
 * */
void printAND(int x, int y) {
    printOperator(x, y, "&&");
    cout << (x && y) << endl;
}

/** Prints the logical OR output of x and y.
 *
 * @param x The first integer to compare.
 * @param y The second integer to compare.
 * */
void printOR(int x, int y) {
    printOperator(x, y, "||");
    cout << (x || y) << endl;
}

/** Prints the logical XOR output of x and y.
 *
 * @param x The first integer to compare.
 * @param y The second integer to compare.
 * */
void printXOR(int x, int y) {
    printOperator(x, y, "^");
    cout << (x ^ y) << endl;
}

/** Code Related to Practical 3.2 */
void practical3_2(){
    void (*functions[3])(int, int) = {&printAND, &printOR, &printXOR};

    // Looping over all functions
    for (int i = 0; i < 3; i++) {
        functions[i](0, 0);
        functions[i](0, 1);
        functions[i](1, 0);
        functions[i](1, 1);
    }

    printAND(5, -3);
    // Q5: What do you get for printAND(5,-3); and why?
    // Answer: 5 && -3 outputs 1 beccause the value of 5 and -3 is considered
    // a logical HIGH (1) hence, 5 && -3 = 1 && 1 which outputs 1.
    printXOR(5, -3);
    // Q6: What can you say about the XOR operator when non-binary inputs are given?
    // Answer: The XOR operator does the XOR logic on every bit of the number (bitwise operator).
}

/** Prints an 8-bit number in binary.
 *
 * @param x The 8-bin number to convert.
 * */
void printBinary(unsigned char x) {
    char bin[9];
    bin[8] = '\0';

    int y = x;

    for (int i = 7; i >= 0; i--) {
        bin[i] = ((x & 1) == 1 ? '1' : '0');
        x = x >> 1;
    }

    cout << y << ": " << bin << endl;
}

/** Code Related to Practical 3.3. */
void practical3_3() {
    printBinary(2);
    printBinary(4);
    printBinary(5);
    printBinary(69);
    printBinary(255);
}

/** Code Related to Practical 3.4.1. */
void practical3_4_1(int argc, char *argv[]) {
    ofstream f("myOutput.txt");

    if (argc < 4) {
        cout << "Not Enough Inputs" << endl;
        return;
    }

    if (f.is_open()) {
        f << argv[1] << endl << argv[2] << endl << argv[3] << endl;

        for (int i = 4; i < argc; i++) {
            f << argv[i] << " ";
        }

        f.close();
    } else {
        cout << "Unable to open file for writing.";
    }

    // Q7: Check the contents of myOutput.txt file. You can do this with a command such
    // as cat myOutput.txt in Linux/UNIX or type myOutput.txt in DOS/Windows.
    // Answer: With argv = (one two three) cat myOutput.txt shows:
    // one
    // two
    // three
}

/** Code Related to Practical 3.4.2. */
void practical3_4_2() {
    ifstream f("myOutput.txt");
    char line[1000];

    if (f.is_open()) {
        while (true) {
            f >> line;

            if (f.eof()) {
                break;
            }
            cout << line << endl;
        }

        f.close();
    } else {
        cout << "Unable to open file for reading.";
    }
    // Q8: Try modifying the contents of the file "myOutput.txt" manually
    // for example, using the Code::Blocks IDE. Does the output of the
    // program change accordingly?
    // Answer: Yes the out put changes accordingly.
}
