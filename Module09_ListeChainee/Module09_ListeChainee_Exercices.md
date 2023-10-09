# Module 09 - Liste chainée

Pour chacune des fonctionnalités, vous devez écrire les tests unitaires avant d'écrire le code.

## Exercice 1 - Liste chainée d'entiers

### Exercice 1.1 - Opérations de base

Écrivez une classe ```ListeChaineeEntiers``` qui implémente une liste chaînée d'entiers avec les fonctionnalités suivantes :

- `ListeChaineeEntiers()` : Constructeur par défaut, initialise la liste à vide
- `ListeChaineeEntiers(const ListeChaineeEntiers &p_listeACopier)` : Constructeur par copie, copie les éléments de la liste passée en paramètre.
- `ListeChaineeEntiers(ListeChaineeEntiers &&p_listeADeplacer)` : Constructeur par déplacement, déplace les éléments de la liste passée en paramètre.
- `~ListeChaineeEntiers()` : Destructeur, libère la mémoire allouée
- `void ajouterDebut(const int& p_valeur)` : Ajoute un élément au début de la liste.
- `void ajouterFin(const int& p_valeur)` : Ajoute un élément à la fin de la liste.
- `void inserer(const int& p_valeur, const int& p_indice)` : Insère un élément à l'indice donné en paramètre.
- `void supprimerDebut()` : Supprime le premier élément de la liste.
- `void supprimerFin()` : Supprime le dernier élément de la liste.
- `void supprimerA(const int& p_indice)` : Supprime l'élément à l'indice donné en paramètre.
- `void vider()` : Vide la liste.
- `int obtenir(const int& p_indice)` : Retourne la valeur à l'indice donné en paramètre.
- `int nombreElements() const` : Retourne le nombre d'éléments dans la liste.
- `ListeChaineeEntiers & operator=(const ListeChaineeEntiers &p_listeACopier)` : Opérateur d'affectation par copie, copie les éléments de la liste passée en paramètre.
- `ListeChaineeEntiers & operator=(ListeChaineeEntiers &&p_listeADeplacer)` : Opérateur d'affectation par déplacement, déplace les éléments de la liste passée en paramètre.
- `void parcourir(void (*p_fonction)(const int&))` : Parcourt la liste et applique la fonction passée en paramètre à chaque élément de la liste.
- `void trier(bool (*p_fonctionTri)(const int&, const int&))` : Trie la liste selon la fonction de classement passée en paramètre.

### Exercice 1.2 - Redéfinition d'opérateurs

Ajoutez des fonctions amies pour l'opérateur `+` afin d'effectuer la concaténation de deux listes. N'oubliez pas que les paramètres peuvent être passés par référence ou par référence de rvalue. Vous aurez donc à redéfinir les opérateurs :

- `friend ListeChaineeEntiers operator+(const ListeChaineeEntiers&, const ListeChaineeEntiers&)`
- `friend ListeChaineeEntiers operator+(ListeChaineeEntiers&&, const ListeChaineeEntiers&)`
- `friend ListeChaineeEntiers operator+(const ListeChaineeEntiers&, ListeChaineeEntiers&&)`
- `friend ListeChaineeEntiers operator+(ListeChaineeEntiers&&, ListeChaineeEntiers&&)`

Dans tous les cas, on a choisi une fonction amie, donc on crée une nouvelle liste comme résultat.

## Exercice 2 - Liste chainée générique

Écrivez une classe ```ListeChaineeGenerique``` qui implémente une liste chaînée générique avec les mêmes fonctionnalités que l'exercice précédent.
