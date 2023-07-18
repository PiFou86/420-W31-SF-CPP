#include <stdexcept>

#include <iostream>
#include <iomanip>

#include <chrono>

#include <sstream>

#include "afficherNombres.h"

void afficherNombresDe1AN_v1_rec(int p_de, int p_a) { // Fonction privée
	std::cout << p_de << std::endl;
	if (p_de < p_a) {
		afficherNombresDe1AN_v1_rec(p_de + 1, p_a);
	}
}

void afficherNombresDe1AN_v1(int p_n) { // Fonction publique
	if (p_n < 1) {
		throw std::invalid_argument("La valeur doit être supérieure à 0");
	}
	afficherNombresDe1AN_v1_rec(1, p_n);
}

void afficherNombresDe1AN_v2_rec(int p_n) { // Fonction privée
	if (p_n > 1) {
		afficherNombresDe1AN_v2_rec(p_n - 1);
	}
	std::cout << p_n << std::endl;
}

void afficherNombresDe1AN_v2(int p_n) { // Fonction privée
	if (p_n < 1) {
		throw std::invalid_argument("La valeur doit être supérieure à 0");
	}
	afficherNombresDe1AN_v2_rec(p_n);
}

void afficherNombresDe1AN_v3_rec(int p_de, int p_a) { // Fonction privée
	std::cout << p_de << std::endl;
	if (p_de < p_a) {
		afficherNombresDe1AN_v3_rec(p_de + 1, p_a);
	}
}

void afficherNombresDe1AN_v3(int p_n) { // Fonction privée
	if (p_n < 1) {
		throw std::invalid_argument("La valeur doit être supérieure à 0");
	}
	afficherNombresDe1AN_v3_rec(1, p_n);
}

// Fonction publique
std::string dureeLisibleParHumain(long long p_ns,
	bool p_ignoreNs, bool p_ignoreUs, bool p_ignoreMs) {
	constexpr long long Ns = 1;
	constexpr long long UsNs = 1'000 * Ns;
	constexpr long long MsNs = 1'000 * UsNs;
	constexpr long long SNs = 1'000 * MsNs;
	constexpr long long MNs = 60 * SNs;
	constexpr long long HNs = 60 * MNs;
	constexpr long long jourNs = 24 * HNs;

	int jours = static_cast<int>(p_ns / jourNs);
	p_ns -= jours * jourNs;
	int heures = static_cast<int>(p_ns / HNs);
	p_ns -= heures * HNs;
	int minutes = static_cast<int>(p_ns / MNs);
	p_ns -= minutes * MNs;
	int secondes = static_cast<int>(p_ns / SNs);
	p_ns -= secondes * SNs;
	int millisecondes = static_cast<int>(p_ns / MsNs);
	p_ns -= millisecondes * MsNs;
	int microsecondes = static_cast<int>(p_ns / UsNs);
	p_ns -= microsecondes * UsNs;
	int nanosecondes = static_cast<int>(p_ns);

	std::stringstream ss;
	std::string prefixText = "";

	if (jours) {
		ss << std::setw(2) << jours << " jour(s), ";
	}
	if (heures) {
		ss << std::setw(2) << heures << " heure(s), ";
	}
	if (minutes) {
		ss << std::setw(2) << minutes << " minute(s), ";
	}
	if (secondes || (p_ignoreMs && p_ignoreUs && p_ignoreNs)) {
		ss << std::setw(2) << secondes << " seconde(s)";
		prefixText = ", ";
	}

	if (!p_ignoreMs) {
		ss << std::setw(3) << prefixText << millisecondes << " milliseconde(s)";
		prefixText = ", ";
		if (!p_ignoreUs) {
			ss << std::setw(3) << prefixText << microsecondes << " microsecond(s)";
			prefixText = ", ";
			if (!p_ignoreNs) {
				ss << std::setw(3) << prefixText << nanosecondes << " nanosecond(s)";
			}
		}
	}

	return ss.str();
}
