
#include <iostream>
#include <vector>
#include "tests.h"

int main (int argc, char* argv[]) {
    if (argc == 2)
        Tests tests(argv[1]);
    else
        std::printf("Resources directory argument expected");

    return 0;
}

