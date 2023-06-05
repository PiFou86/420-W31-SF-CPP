#pragma once

class ListeEntiers {
public:
	ListeEntiers();
	ListeEntiers(const ListeEntiers& p_listeACopier);
	ListeEntiers(ListeEntiers&& p_listeADeplacer);
	~ListeEntiers();
	void ajouterFin(const int& p_valeur);
	void supprimerFin();
	int obtenir(const int& p_indice);
	int nombreElements() const;
	int capacite() const;
	ListeEntiers& operator=(const ListeEntiers& p_listeACopier);
	ListeEntiers& operator=(ListeEntiers&& p_listeADeplacer);
	void parcourir(void (*p_fonction)(const int&));

private:
	int* m_valeurs;
	int m_capacite;
	int m_nbElements;
};
