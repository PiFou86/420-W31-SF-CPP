#pragma once

#include <iostream>

#include "CalculatriceV1.h"

class NombreV1 {
public:
	NombreV1(const int& p_valeur) : m_valeur(p_valeur) { ;	}
	inline const int& valeur() { return this->m_valeur; }

	friend NombreV1 CalculatriceV1::additionner(const NombreV1& p_nombre1, const NombreV1& p_nombre2);
	friend NombreV1 additionner(const NombreV1& p_nombre1, const NombreV1& p_nombre2);

	friend class CalculatriceV2;

	friend std::istream& operator>>(std::istream& p_istream, NombreV1& p_valeur);
	friend std::ostream& operator<<(std::ostream& p_ostream, const NombreV1& p_valeur);

	friend NombreV1 operator+(const NombreV1& p_nombre1, const NombreV1& p_nombre2);
private:
	int m_valeur;
};


inline NombreV1 additionner(const NombreV1& p_nombre1, const NombreV1& p_nombre2) {
	return NombreV1(p_nombre1.m_valeur + p_nombre2.m_valeur);
}

inline NombreV1 operator+(const NombreV1& p_nombre1, const NombreV1& p_nombre2) {
	return NombreV1(p_nombre1.m_valeur + p_nombre2.m_valeur);
}

inline std::ostream& operator<<(std::ostream& p_ostream, const NombreV1& p_valeur) {
	p_ostream << "NombreV1(" << p_valeur.m_valeur << ")" << std::endl;

	return p_ostream;
}

inline std::istream& operator>>(std::istream& p_istream, NombreV1& p_valeur) {
	p_istream >> p_valeur.m_valeur;

	return p_istream;
}
