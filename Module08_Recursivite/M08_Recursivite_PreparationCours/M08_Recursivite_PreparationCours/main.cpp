#include <iostream>

// high_resolution_clock
#include <chrono>

#include "factorielle.h"

#include "afficherNombres.h"

#include "somme.h"

template<class TypeValeur>
bool executePredicat(bool (*p_predicat)(TypeValeur), TypeValeur p_valeur) {
	return p_predicat(p_valeur);
}


int main()
{
	std::cout << "factorielle_v1(5) = " << factorielle_v1(5) << std::endl << std::endl;
	std::cout << "factorielle_v2(5) = " << factorielle_v2(5) << std::endl << std::endl;
	std::cout << "factorielle_v3(5) = " << factorielle_v3(5) << std::endl << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "afficherNombresDe1AN_v1(5):" << std::endl;
	afficherNombresDe1AN_v1(5);
	std::cout << "afficherNombresDe1AN_v2(5):" << std::endl;
	afficherNombresDe1AN_v2(5);
	std::cout << "afficherNombresDe1AN_v3(5):" << std::endl;
	afficherNombresDe1AN_v3(5);

	std::cout << std::endl << std::endl;

	std::cout << "calculerSomme1AN_v1(5) = " << calculerSomme1AN_v1(5) << std::endl << std::endl;

	{
		using namespace std::chrono;

		time_point<high_resolution_clock> debut = high_resolution_clock::now();
		std::cout << "factorielle_v1(120) = " << factorielle_v1(120) << std::endl << std::endl;
		time_point<high_resolution_clock> fin = high_resolution_clock::now();

		nanoseconds tempsPasseNs = fin - debut;
		std::cout << "Duree du calcul (ns) : " << tempsPasseNs.count() << std::endl;

		std::cout << "Duree du calcul : " << dureeLisibleParHumain(tempsPasseNs.count()) << std::endl;
	}

	std::cout << "Appel executePredicat avec 42 et la lambda v => !(v & 1) = " << executePredicat<int>([](int v) { return !(v & 1); }, 42) << std::endl;
	std::cout << "Appel executePredicat avec 43 et la lambda v => !(v & 1) = " << executePredicat<int>([](int v) { return !(v & 1); }, 43) << std::endl;
}
