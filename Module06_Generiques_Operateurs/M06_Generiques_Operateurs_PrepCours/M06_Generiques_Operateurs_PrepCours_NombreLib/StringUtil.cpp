#include "StringUtil.h"

#include <sstream>

std::string operator*(const std::string& p_chaineARepeter, const int& p_nbFois) {
	std::stringstream ss;
	for (size_t fois = 0; fois < p_nbFois; fois++)
	{
		ss << p_chaineARepeter;
	}

	return ss.str();
}
