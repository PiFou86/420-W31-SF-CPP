#pragma once

#include "NombreV1.h"

class CalculatriceV2 {
public:
	inline NombreV1 additionner(const NombreV1& p_nombre1, const NombreV1& p_nombre2) {
		return NombreV1(p_nombre1.m_valeur + p_nombre2.m_valeur);
	}
};
