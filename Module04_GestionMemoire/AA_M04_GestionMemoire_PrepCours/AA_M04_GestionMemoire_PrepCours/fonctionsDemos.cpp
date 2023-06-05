#include <iostream>

#include "fonctionsDemos.h"
#include "Televiseur.h"
#include "ListeEntiers.h"

void demoPointeurObjet() {
	Televiseur t;
	Televiseur* pt = &t;

	// *pt.allumer(); // Erreur de compilation, le point est prioritaire ici
	(*pt).allumer();
	// Écriture simplifiée :
	pt->allumer();
}

void demoPointeurs() {
	int v1 = 42;
	int v2 = 23;
	int* p1v = &v1;
	int* p2v = &v2;

	std::cout << "int - v1 (0x" << std::hex << &v1 << ") = " << std::dec << v1 << std::endl;
	std::cout << "int - v2 (0x" << std::hex << &v2 << ") = " << std::dec << v2 << std::endl;
	std::cout << "int* - p1v (0x" << std::hex << &p1v << ") = 0x" << p1v << " -> " << std::dec << *p1v << std::endl;
	std::cout << "int* - p2v (0x" << std::hex << &p2v << ") = 0x" << p2v << " -> " << std::dec << *p2v << std::endl;

	std::cout << std::endl << "p1v = &v2; *p1v = 11; ppv = &p1v;" << std::endl;
	p1v = &v2;
	*p1v = 11;
	int** ppv = &p1v;

	std::cout << "int - v1 (0x" << std::hex << &v1 << ") = " << std::dec << v1 << std::endl;
	std::cout << "int - v2 (0x" << std::hex << &v2 << ") = " << std::dec << v2 << std::endl;
	std::cout << "int* - p1v (0x" << std::hex << &p1v << ") = 0x" << p1v << " -> " << std::dec << *p1v << std::endl;
	std::cout << "int* - p2v (0x" << std::hex << &p2v << ") = 0x" << p2v << " -> " << std::dec << *p2v << std::endl;

	//ppv = &(&v2); // Erreur & v2 n'est pas une lvalue
	ppv = &p2v;
	std::cout << "int** ppv (0x" << std::hex << &ppv << ") = 0x" << ppv << " -> 0x" << *ppv << " ->-> " << std::dec << **ppv << std::endl;
}

void demoConst() {
	int v1 = 42;
	int v2 = 23;
	int* const pc = &v1;
	int const* pvc = &v1;
	const int* pvcv2 = &v1;
	int const* const pcvc = &v1;
	*pc = 23;
	//pc = &v2; // Erreur compilation
	//*pvc = 23; // Erreur compilation
	pvc = &v2;
	//*pvcv2 = 23; // Erreur compilation
	pvcv2 = &v2;
	//*pcvc = 23; // Erreur compilation
	//pcvc = &v2; // Erreur compilation
}

void demoNewDelete() {
	Televiseur* pt = new Televiseur();

	pt->allumer();

	delete pt;
	pt = nullptr;
}

void demoNewDeleteTableau() {
	int* valeurs = new int[10];

	delete[] valeurs;
	valeurs = nullptr;
}

void saluerFrancais(const std::string& p_nom) {
	std::cout << "Bonjour " << p_nom << " !" << std::endl;
}

void saluerBasque(const std::string& p_nom) {
	std::cout << "Kaixo " << p_nom << " !" << std::endl;
}

void demoPointeurFonction(void (*p_saluer)(const std::string&)) {
	p_saluer("Pierre-Francois");
	// ou (*p_saluer)("Pierre-Francois");
}

void demoArithmetiquePointeurs() {
	constexpr int N = 5;
	int valeurs[N] = { 1, 2, 3, 4, 5};
	int* pvaleurActuelle = valeurs;
	int* pfin = valeurs + N;

	while (pvaleurActuelle < pfin)
	{
		std::cout 
			<< "0x" << std::hex << pvaleurActuelle
			<< std::dec << " : " << *pvaleurActuelle++ 
			<< std::endl;
	}
}

ListeEntiers creerListe() {
	ListeEntiers le;

	le.ajouterFin(23);
	le.ajouterFin(42);

	return le;
}

void testListeEntiers() {
	ListeEntiers le;
	std::cout << "ajouterFin(1);ajouterFin(2);ajouterFin(3);ajouterFin(42);ajouterFin(23);"
		<< std::endl;
	le.ajouterFin(1);
	le.ajouterFin(2);
	le.ajouterFin(3);
	le.ajouterFin(42);
	le.ajouterFin(23);
	le.parcourir([](const int& v) { std::cout << std::dec << v << std::endl; });
	std::cout << "Nombre elements : " << le.nombreElements() << " ; Capacite : " << le.capacite() << std::endl;

	std::cout << std::endl << "supprimerFin() * 2" << std::endl;
	le.supprimerFin();
	le.supprimerFin();
	le.parcourir([](const int& v) { std::cout << std::dec << v << std::endl; });
	std::cout << "Nombre elements : " << le.nombreElements() << " ; Capacite : " << le.capacite() << std::endl;

	std::cout << std::endl << "ctor par copie" << std::endl;
	ListeEntiers cple(le);

	std::cout << std::endl << "ctor par deplacement" << std::endl;
	ListeEntiers depcple = creerListe();

	std::cout << std::endl << "operateur= par deplacement" << std::endl;
	ListeEntiers affdepcple;
	affdepcple = creerListe();

	std::cout << std::endl;
}