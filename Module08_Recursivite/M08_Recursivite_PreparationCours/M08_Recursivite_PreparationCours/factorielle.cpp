#include <stdexcept>

#include "factorielle.h"

long long factorielle_v1(long long p_n) {
	if (p_n < 0) {
		throw std::invalid_argument("La valeur ne doit pas être négative");
	}
	// f(0) = 1
	if (p_n == 0) {
		return 1;
	}
	// f(n) = n * f(n – 1)
	return p_n * factorielle_v1(p_n - 1);
}

long long factorielle_v2_rec(long long p_n) { // Fonction privée
	if (p_n == 0) {
		return 1;
	}
	return p_n * factorielle_v2_rec(p_n - 1);
}

long long factorielle_v2(long long p_n) { // Fonction publique
	if (p_n < 0) {
		throw std::invalid_argument("La valeur ne doit pas être négative");
	}
	return factorielle_v2_rec(p_n);
}

long long factorielle_v3_rec(long long p_n, long long p_res) {
	if (p_n == 0) {
		return p_res;
	}
	return factorielle_v3_rec(p_n - 1, p_res * p_n);
}

long long factorielle_v3(long long p_n) {
	if (p_n < 0) {
		throw std::invalid_argument("La valeur ne doit pas être négative");
	}
	return factorielle_v3_rec(p_n, 1);
}
