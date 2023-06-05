#include <iostream>

#include "ListeEntiers.h"

ListeEntiers::ListeEntiers()
	: m_valeurs(new int[1]), m_capacite(1), m_nbElements(0)
{
	std::cout << "ListeEntiers() (0x" << std::hex << this << ")" << std::endl;
}

ListeEntiers::ListeEntiers(const ListeEntiers& p_listeACopier)
	: m_valeurs(nullptr), m_capacite(p_listeACopier.m_capacite), m_nbElements(p_listeACopier.m_nbElements)
{
	std::cout << "ListeEntiers(const ListeEntiers& p_listeACopier) (0x" << std::hex << this << ")" << std::endl;

	this->m_valeurs = new int[this->m_capacite];
	for (size_t indexValeur = 0; indexValeur < this->m_nbElements; indexValeur++)
	{
		this->m_valeurs[indexValeur] = p_listeACopier.m_valeurs[indexValeur];
	}
}

ListeEntiers::ListeEntiers(ListeEntiers&& p_listeADeplacer)
	: m_valeurs(p_listeADeplacer.m_valeurs),
	m_capacite(p_listeADeplacer.m_capacite),
	m_nbElements(p_listeADeplacer.m_nbElements)
{
	std::cout << "ListeEntiers(ListeEntiers&& p_listeADeplacer) (0x" << std::hex << this << ")" << std::endl;

	p_listeADeplacer.m_valeurs = nullptr;
	p_listeADeplacer.m_capacite = 0;
	p_listeADeplacer.m_nbElements = 0;
}

ListeEntiers::~ListeEntiers()
{
	std::cout << "~ListeEntiers() (0x" << std::hex << this << ")" << std::endl;

	if (this->m_valeurs) {
		delete[] this->m_valeurs;
	}
}

void ListeEntiers::ajouterFin(const int& p_valeur)
{
	if (this->m_nbElements == this->m_capacite) {
		int futureCapacite = this->m_capacite * 2;
		int* futurTableauDonnees = new int[futureCapacite];
		for (size_t indexValeur = 0; indexValeur < this->m_nbElements; indexValeur++)
		{
			futurTableauDonnees[indexValeur] = this->m_valeurs[indexValeur];
		}

		delete[] this->m_valeurs;
		this->m_valeurs = futurTableauDonnees;
		this->m_capacite = futureCapacite;
	}

	this->m_valeurs[this->m_nbElements++] = p_valeur;
}

void ListeEntiers::supprimerFin()
{
	if (this->m_nbElements == 0) {
		throw std::invalid_argument("Impossible de supprimer le dernier element");
	}

	--this->m_nbElements;
}

int ListeEntiers::obtenir(const int& p_indice)
{
	if (p_indice >= this->m_nbElements || p_indice < 0) {
		throw std::invalid_argument("L'indice n'est pas valide");
	}

	return this->m_valeurs[p_indice];
}

int ListeEntiers::nombreElements() const
{
	return this->m_nbElements;
}

int ListeEntiers::capacite() const
{
	return this->m_capacite;
}

ListeEntiers& ListeEntiers::operator=(const ListeEntiers& p_listeACopier)
{
	std::cout << "ListeEntiers::operator=(const ListeEntiers& p_listeACopier) (0x" << std::hex << this << ")" << std::endl;

	if (this != &p_listeACopier) {
		if (this->m_capacite < p_listeACopier.m_capacite) {
			int* futurTableauDonnees = new int[p_listeACopier.m_capacite];
			delete[] this->m_valeurs;
			this->m_valeurs = futurTableauDonnees;
			this->m_capacite = p_listeACopier.m_capacite;
		}

		for (size_t indexValeur = 0; indexValeur < p_listeACopier.m_nbElements; indexValeur++)
		{
			this->m_valeurs[indexValeur] = this->m_valeurs[indexValeur];
		}

		this->m_nbElements = p_listeACopier.m_nbElements;
	}

	return *this;
}

ListeEntiers& ListeEntiers::operator=(ListeEntiers&& p_listeADeplacer)
{
	std::cout << "ListeEntiers::operator=(ListeEntiers&& p_listeACopier) (0x" << std::hex << this << ")" << std::endl;

	this->m_nbElements = p_listeADeplacer.m_nbElements;
	if (this->m_valeurs)
	{
		delete[] this->m_valeurs;
	}

	this->m_valeurs = p_listeADeplacer.m_valeurs;
	p_listeADeplacer.m_valeurs = nullptr;
	p_listeADeplacer.m_capacite = 0;
	p_listeADeplacer.m_nbElements = 0;

	return *this;
}

void ListeEntiers::parcourir(void (*p_fonction)(const int&))
{
	for (size_t indexValeur = 0; indexValeur < this->m_nbElements; indexValeur++)
	{
		p_fonction(this->m_valeurs[indexValeur]);
	}
}
