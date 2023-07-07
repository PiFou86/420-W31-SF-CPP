#pragma once
#include <iostream>

template <class TypeNombre>
class Nombre {
	static_assert(std::is_integral_v<TypeNombre> || std::is_floating_point_v<TypeNombre>,
		"TypeNombre doit être un entier ou un flottant.");
public:
	Nombre(const TypeNombre& p_valeur)
		: m_valeur(p_valeur)
	{
		;
	}

	template<class TypeNombre>
	friend std::istream& operator>>(std::istream& p_istream, Nombre<TypeNombre>& p_valeur);
	template<class TypeNombre>
	friend std::ostream& operator<<(std::ostream& p_ostream, const Nombre<TypeNombre>& p_valeur);

	Nombre<TypeNombre> operator+(const Nombre<TypeNombre> p_valeur) { 
		return Nombre<TypeNombre>(this->m_valeur + p_valeur.m_valeur); 
	}

private:
	TypeNombre m_valeur;
};

template<class TypeNombre>
std::ostream& operator<<(std::ostream& p_ostream, const Nombre<TypeNombre>& p_valeur) {
	p_ostream << "Nombre(" << p_valeur.m_valeur << ")" << std::endl;

	return p_ostream;
}

template<class TypeNombre>
std::istream& operator>>(std::istream& p_istream, Nombre<TypeNombre>& p_valeur) {
	p_istream >> p_valeur.m_valeur;

	return p_istream;
}
