#include <iostream>

#include "Televiseur.h"

void Televiseur::allumer() {
	std::cout << "allumer (0x" << std::hex << this << ")" << std::endl;
}
