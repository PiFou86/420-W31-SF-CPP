#include <iostream>

#include "../M05_TestsUnitaires_PrepCoursLib/mesmath.h"

int main()
{
    std::cout << "Hello World!\n";
    int donnees[] = { 2, 3, 17, -42 };

    std::cout << "Minimum : " << calculerMinimum(donnees, 4) << std::endl;
}
