#include <iostream>

#include "NewEtDep.h"

NewEtDep::NewEtDep()
	: m_donnee(new int)
{
	std::cout << "ctor(0x" << std::hex << this << ")" << std::endl;
}

NewEtDep::NewEtDep(const NewEtDep& p_aDeplacer) {
	std::cout << "ctor cp(0x" << std::hex << this << ")" << std::endl;
}


NewEtDep::NewEtDep(NewEtDep&& p_aDeplacer)
{
	std::cout << "ctor dep (0x" << std::hex << this << ")" << std::endl;

	this->m_donnee = p_aDeplacer.m_donnee;
	p_aDeplacer.m_donnee = nullptr;
}

NewEtDep& NewEtDep::operator=(NewEtDep&& p_aDeplacer)
{
	std::cout << "operateur= dep (0x" << std::hex << this << ")" << std::endl;

	if (this->m_donnee) {
		delete[] this->m_donnee;
	}

	this->m_donnee = p_aDeplacer.m_donnee;
	p_aDeplacer.m_donnee = nullptr;

	return *this;
}

NewEtDep::~NewEtDep() {
	std::cout << "destructeur (0x" << std::hex << this << ")" << std::endl;

	if (this->m_donnee) {
		delete[] this->m_donnee;
		this->m_donnee = nullptr;
	}
}