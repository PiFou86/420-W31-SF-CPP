#include <iostream>
#include "util.h"

int main()
{
    int min = 0;
    int max = 100;

    std::cout << contraintValeur(110, min, max) << std::endl;
    std::cout << contraintValeur(-3, min, max) << std::endl;
}
