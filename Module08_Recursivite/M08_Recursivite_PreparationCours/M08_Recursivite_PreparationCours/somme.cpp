#include <stdexcept>

#include "somme.h"

int calculerSomme1AN_v1_rec(int p_n) { // Fonction privée
	if (p_n == 1) {
		return 1;
	}
	return p_n + calculerSomme1AN_v1_rec(p_n - 1);
}

int calculerSomme1AN_v1(int p_n) { // Fonction publique
	if (p_n < 1) {
		throw std::invalid_argument("La valeur doit être supérieure à 0");
	}
	return calculerSomme1AN_v1_rec(p_n);
}
