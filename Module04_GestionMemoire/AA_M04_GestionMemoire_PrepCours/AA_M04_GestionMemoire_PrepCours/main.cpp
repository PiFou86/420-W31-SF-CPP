#include <iostream>
#include <string>

#include "fonctionsDemos.h"

int main()
{
    //demoConst();

    demoPointeurs();

    // Pointeurs de fonctions
    demoPointeurFonction(saluerFrancais);
    demoPointeurFonction(&saluerBasque);
    demoPointeurFonction(
        [](const std::string& p_nom)
        {
            std::cout << "Hello " << p_nom << " !" << std::endl;
        }
    );

    demoArithmetiquePointeurs();

    testListeEntiers();
}
