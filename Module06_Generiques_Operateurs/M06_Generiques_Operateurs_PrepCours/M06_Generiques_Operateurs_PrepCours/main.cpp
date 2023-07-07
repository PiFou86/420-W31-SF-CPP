#include <iostream>

#include "NombreV1.h"
#include "CalculatriceV1.h"
#include "CalculatriceV2.h"

#include "StringUtil.h"

#include "Nombre.h"
#include "MesMaths.h"

int main()
{
    NombreV1 n1(23), n2(19);
    NombreV1 na1 = additionner(n1, n2);
    std::cout << "fonction amie - n1 + n2 = " << na1.valeur() << std::endl;

    CalculatriceV1 calculatriceV1;
    NombreV1 na2 = calculatriceV1.additionner(n1, n2);
    std::cout << "méthode amie - n1 + n2 = " << na2.valeur() << std::endl;

    CalculatriceV2 calculatriceV2;
    NombreV1 na3 = calculatriceV2.additionner(n1, n2);
    std::cout << "classe amie - n1 + n2 = " << na3.valeur() << std::endl;

    std::string s = "chocolatine ";
    //s *= 3; // erreur : non surchargé / défini
    std::cout << "s = \"" << s << "\"" << std::endl;
    s = s * 3;
    std::cout << "s = s * 3 : \"" <<  s << "\"" << std::endl;
    std::cout << "s * 3 : \"" << s * 3 << "\"" << std::endl;

    std::cout << calculerMaximum(13, 42) << std::endl;
    
    std::cout.precision(10);

    NombreV1 nombreV1(42);
    std::cout << "nombreV1 : " << nombreV1 << std::endl;
    std::cout << "Saisir un entier : ";
    std::cin >> nombreV1;
    std::cout << "L'entier saisi est : " << nombreV1 << std::endl;

    Nombre<int> entier1(42);
    std::cout << "entier1 : " << entier1 << std::endl;

    Nombre<float> float1(0.1f + 0.2f);
    std::cout << "float1 : " << float1 << std::endl;

    Nombre<float> float2(1.618f);
    std::cout << "float2 : " << float2 << std::endl;

    std::cout << "float1 + float2 : " << float1 + float2 << std::endl;

    Nombre<int> entier2(0);
    std::cout << "Saisir un entier : ";
    std::cin >> entier2;
    std::cout << "L'entier saisi est : " << entier2 << std::endl;
}
