#pragma once

template<class TypeDonnee>
const TypeDonnee& calculerMinimum(const TypeDonnee& p_v1, const TypeDonnee& p_v2) {
	const TypeDonnee* res = &p_v1;
	if (p_v1 > p_v2) {
		res = &p_v2;
	}

	return *res;
}

template<class TypeDonnee>
const TypeDonnee& calculerMaximum(const TypeDonnee& p_v1, const TypeDonnee& p_v2) {
	const TypeDonnee* res = &p_v1;
	if (p_v1 < p_v2) {
		res = &p_v2;
	}

	return *res;
}
