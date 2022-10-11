#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "dataTypes.h"

using namespace std;

/** Testing function for int types
 *
 * @param First Integer
 * @pram Second Integer
 * */
void testInt(int x, int y) {
    int z = x + y;
    cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
}

/** Testing function for signed and unsigned types */
void testSignedUnsigned() {
    // char
    cout << "Char:" << endl;
    unsigned char i;
    i = 255;
    printf("signed: %d, unsinged: %u\n", i, i);
    i = 127;
    printf("signed: %d, unsinged: %u\n", i, i);
    i = 128;
    printf("signed: %d, unsinged: %u\n", i, i);

    // short int
    cout << "Short:" << endl;
    unsigned short j = -0;
    cout << "unsigned: " << j << ", signed: " << (signed short) j << endl;
    j = 65535;
    cout << "unsigned: " << j << ", signed: " << (signed short) j << endl;
    j = 32768;
    cout << "unsigned: " << j << ", signed: " << (signed short) j << endl;
    j = 32767;
    cout << "unsigned: " << j << ", signed: " << (signed short) j << endl;
}

/** Testing function for floats and doubles */
void testFloatDouble() {
    // Testing Float and Double percisions
    float f = 1.12345678901234567890;
    double d = 1.12345678901234567890123456789;
    cout << "double: " << setprecision(20) << d << ", float: " << f << endl;
    // Q1 & Q2: double: 16, float: 6

    // Adding int and float
    int i = 1;
    cout << "Sum of int and float:" << endl;
    cout << "%d=" << (int) (i + f) << ", %f=" << (float) (i + f) << endl;
    // Q3: int is rounded to the nearest integer while float show decimal places

    // Printing doubles as other types
    cout << "Printing Doubles" << endl;
    double print_double = 6.9420694206942069;
    printf("%%d=%d, %%f=%f, %%lf=%lf\n", (int) print_double, (float) print_double, print_double);
    /// Q4: The decimal places gets chop off accordingly
}

/** Testing function for char */
void testChar() {
    int c = 'A';

    cout << "Print As char: c=" << (char) c << ", print as decimal: c=" << c << endl;
    c++;
    cout << "Print As char: c=" << (char) c << ", print as decimal: c=" << c << endl;
    // Q5: The character is different after adding 1, hence we can conclude that characters are
    //     stored as an integers.
    cout << "Looping over 255" << endl;
    for (c = 0; c < 256; c++) {
        cout << "Print As char: c=" << (char) c << ", print as decimal: c=" << c << endl;
    }
}

/** Testing function for strings */
void testString() {
    char s[] = "Nottingham";
    cout << "s=" << s << endl;

    for(int i = 0; i < sizeof(s) + 3; i++) {
        cout << "s[" << i << "]=" << s[i] << " = " << setw(3) << (int) s[i] << endl;
    }
    // Q6: An empty character with ascii number 0 (null) is at the end of the string
    //     Once beyond that it is just some random numbers and characters.
}
