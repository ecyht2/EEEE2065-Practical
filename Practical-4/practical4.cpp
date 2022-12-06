#include "practical4.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

void practical4_1() {
    // Increasing
    cout << "Increasing:" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << i << " ";
    }

    // Decreasing
    cout << endl;
    cout << "Decreasing:" << endl;
    for (int i = 10; i >= 0; i--) {
        cout << i << " ";
    }

    // Floats
    cout << endl;
    cout << "Floats:" << endl;
    cout << setw(3) << "x" << setw(8) << "x * x" << endl;
    for (float x = 0.5; x <= 4.5; x++) {
        cout << setw(3) << x << setw(8) << x * x << endl;
    }
}

void practical4_2() {
    int i;

    // Increasing
    cout << "Increasing:" << endl;
    i = 0;
    while (i <= 10) {
        cout << i << " ";
        i++;
    }

    // Decreasing
    cout << endl;
    cout << "Decreasing:" << endl;
    i = 10;
    while (i >= 0) {
        cout << i << " ";
        i--;
    }

    // Floats
    cout << endl;
    cout << "Floats:" << endl;
    cout << setw(3) << "x" << setw(8) << "x * x" << endl;
    float x = 0.5;
    while ( x <= 4.5) {
        cout << setw(3) << x << setw(8) << x * x << endl;
        x++;
    }
}

// Adventure Game
/** Processes the commands passed by the user by adventureGame::getCommand
 *
 * @return 0 if exit is entered 1 for others
 * */
int adventureGame::processCommand() {
    if (command == "look") { // Look Command
        cout << "You are in a big hall. ";

        // Checking for monsters
        if (monster == 1) {
            cout << "There is a monster here.";
        } else {
            cout << "There is a dead monster here.";
        }
        cout << endl;
        return 1;
    } else if (command == "killMonster") { // killMonster Command
        if (monster == 1) {
            cout << "You slay the vile monster." << endl;
            monster = 0;
        } else {
            cout << "The monster is already dead!" << endl;
        }
        return 1;
    } else if (command == "exit") { // exit Command
        cout << "You exited the game" << endl;
        return 0;
    } else { // Unknown Commands
        cout << "Unknown Command: " << command << endl;
        return 1;
    }
}

// Pascal's Triangle
/** Prints all elements in a vector.
 * @param vector The vector to print
 * @param sep The character used to seperate each element
 */
void printVector(vector<unsigned int> vector, char sep = ' ') {
    for (auto it = vector.cbegin(); it != vector.cend(); ++it) {
        cout << *it << sep;
    }
    cout << endl;
}
/** Prints a Pascal's Triangle of a given height.
 * @param height The height of the Pascal's Triangle
 * */
void pascalsTriangle(unsigned int height) {
    vector<unsigned int> previous = { 1 };
    vector<unsigned int> current = { 1, 1 };

    // Printing First two rows
    printVector(previous);
    printVector(current);
    // Swapping current wiht previous
    previous.swap(current);
    current.clear();

    // Looping over all the rows
    for (int i = 3; i < (int) height + 1; i++) {
        // Adding intial 1
        current.push_back(1);
        // Adding middle elements
        for (int j = 1; j < i - 1; j++) {
            current.push_back(previous[j] + previous[j-1]);
        }
        // Adding Ending 1
        current.push_back(1);
        // Printing Result
        printVector(current);

        // Making current row the previous
        previous.swap(current);
        current.clear();
    }
}

// Prime Numbers
/** Gets the first x number of prime numbers.
 *
 * @param x How many prime numbers to find
 * */
void getNPrimes(unsigned int x) {
    vector <unsigned int> primes = { 2 };

    // Getting all primes
    unsigned int testNumber = 3;
    while (primes.size() < x) {
        bool isPrime = true;
        // Checking Primality
        // Looping over all current primes
        for (auto it = primes.cbegin(); it != primes.cend(); ++it) {
            // Checking divisibility of the testNumber
            if (testNumber % *it == 0) {
                isPrime = false;
                break;
            }
        }
        // If it is a prime number add it to list
        if (isPrime) {
            primes.push_back(testNumber);
        }
        // Testing next number
        testNumber++;
    }
    // Printing all primes
    for (unsigned int i = 0; i < x; i++) {
        cout << i << " " << primes[i] << endl;
    }
}

/** Gets the first x number of prime numbers.
 *
 * @param x How many prime numbers to find
 * */
void getNImprovedPrimes(unsigned int x) {
    vector <unsigned int> primes = { 2 };

    // Getting all primes
    unsigned int testNumber = 3;
    while (primes.size() < x) {
        bool isPrime = true;
        // Checking Primality
        // Looping over all current primes
        for (auto it = primes.cbegin(); it != primes.cend(); ++it) {
            if (*it > sqrt(testNumber)) {
                break;
            }
            // Checking divisibility of the testNumber
            if (testNumber % *it == 0) {
                isPrime = false;
                break;
            }
        }
        // If it is a prime number add it to list
        if (isPrime) {
            primes.push_back(testNumber);
        }
        // Testing next number
        testNumber++;
    }
    // Printing all primes
    for (unsigned int i = 0; i < x; i++) {
        cout << i << " " << primes[i] << endl;
    }
}
