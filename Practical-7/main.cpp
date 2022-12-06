#include <iostream>

#include "practical7.h"

using namespace std;

int main(int argc, char *argv[]) {
    Calendar cal1;
    cal1.printDate();

    Calendar cal2(2022, 12, 06, 2);
    cal2.printDate();

    Calendar cal3(cal2);
    cal3.printDate();

    Calendar cal4 = cal3;
    cal4.printDate();

    Calendar cal5(4);
    cal5.printMeeting();

    return 0;
}
