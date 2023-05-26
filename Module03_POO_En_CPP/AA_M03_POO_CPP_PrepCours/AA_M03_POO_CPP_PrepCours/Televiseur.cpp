#include <iostream>
#include <stdexcept>

#include "Televiseur.h"

// Ctor par défaut
// Utilisation d'un constructeur délégué
Televiseur::Televiseur()
	: Televiseur(1, 20, false) {
	//:
	//m_canalActuel(1),
	//m_volume(20),
	//m_estAllume(false)
    //{
	std::cout << "Ctor par défaut (0x" << std::hex << this << ")" << std::endl;
}

// Ctor par copie
Televiseur::Televiseur(const Televiseur& p_objetACopier) :
	m_canalActuel(p_objetACopier.m_canalActuel),
	m_volume(p_objetACopier.m_volume),
	m_estAllume(p_objetACopier.m_estAllume)
{
	std::cout << "Ctor par copie (0x" << std::hex << this << ")" << std::endl;
}

// Ctor par déplacement
// Peu d'intérêt ici car nous n'avons pas de pointeur
Televiseur::Televiseur(Televiseur&& p_rvalue) :
	m_canalActuel(p_rvalue.m_canalActuel),
	m_volume(p_rvalue.m_volume),
	m_estAllume(p_rvalue.m_estAllume)
{
	std::cout << "Ctor par copie (0x" << std::hex << this << ")" << std::endl;
}

// Ctor d'initialisation avec un paramètre qui a une valeur par défaut
Televiseur::Televiseur(int p_canalActuel, int p_volume, bool p_estAllume)
	: m_canalActuel(p_canalActuel), m_volume(p_volume), m_estAllume(p_estAllume)
{
	if (p_canalActuel < 0 || p_canalActuel > 100) {
		throw std::invalid_argument("Le canal doit être compris entre 0 et 100");
	}

	if (p_volume < 0 || p_volume > 100) {
		throw std::invalid_argument("Le volume doit être compris entre 0 et 100");
	}

	std::cout << "Ctor d'initialisation (0x" << std::hex << this << ")" << std::endl;
}

// Destructeur. Il n'y a jamais de paramètres
Televiseur::~Televiseur() {
	std::cout << "Destructeur (0x" << std::hex << this << ")" << std::endl;
}

// Opérateur d'affectation
Televiseur& Televiseur::operator=(const Televiseur& p_objetAAffecter) {
	std::cout << "operateur= & (0x" << std::hex << this << ")" << std::endl;

	if (this != &p_objetAAffecter) {
		this->m_canalActuel = p_objetAAffecter.m_canalActuel;
		this->m_volume = p_objetAAffecter.m_volume;
		this->m_estAllume = p_objetAAffecter.m_estAllume;
	}

	return *this;
}

// Opérateur d'affectation
Televiseur& Televiseur::operator=(Televiseur&& p_objetAAffecter) {
	std::cout << "operateur= && (0x" << std::hex << this << ")" << std::endl;

	if (this != &p_objetAAffecter) {
		this->m_canalActuel = p_objetAAffecter.m_canalActuel;
		this->m_volume = p_objetAAffecter.m_volume;
		this->m_estAllume = p_objetAAffecter.m_estAllume;
	}

	return *this;
}

void Televiseur::volume(const int& p_volume) {
	if (p_volume < 0 || p_volume > 100) {
		throw std::invalid_argument("Le volume doit être compris entre 0 et 100");
	}
	this->m_volume = p_volume;
}
int Televiseur::volume() const {
	return this->m_volume;
}

bool Televiseur::estAllume() const {
	return this->m_estAllume;
}
void Televiseur::allumer() {
	this->m_estAllume = true;
}

void Televiseur::eteindre() {
	this->m_estAllume = false;
}

void Televiseur::changerCanal(const int& p_canal) {
	if (p_canal < 0 || p_canal > 100) {
		throw std::invalid_argument("Le canal doit être compris entre 0 et 100");
	}

	this->m_canalActuel = p_canal;
}

int Televiseur::canal() const {
	return this->m_canalActuel;
}