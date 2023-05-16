# Module 01 - Complexité

## Préalables pour la suite

Installez le support de C++ pour Visual Studio :

1. Ouvrez Visual Studio
2. Allez dans le menu `Tools` > `Get Tools and Features`
3. Sélectionnez `Desktop development with C++`
4. Cliquez sur `Modify`
5. Pendant les opérations d'installation, vous pouvez faire les exercices

## Exercice 1 - Recherche

1. Calculer la complexité de la recherche d'une valeur dans une liste
2. Essayer de recalculer la complexité de la recherche dichotomique

## Exercice 2 - Une idée sur l'impact de la complexité sur le temps d'exécution

Créez un projet **C#** (Vous n'avez pas encore vu C++) dans Visual Studio et implémentez un programme qui permet d'afficher le temps d'exécution d'une fonction en fonction de la taille de l'entrée et de sa complexité.

Les complexités à tester sont :

- O(1)
- O(n)
- O(n²)
- O(n³)
- O(2^n)
- O(n!)
- O(n log n)

Les hypothèses sont :

- 1 000 000 d'opérations par seconde
- Tests avec des entrées de dimensions 10, 100, 1000, 10 000, 100 000, 1 000 000

## Exercice 3 - Tris

1. Calculez la complexité du tri à bulles
2. Calculez la complexité du tri rapide dans le meilleur des cas : division en deux du tableau à chaque itération
3. Calculez la complexité du tri rapide dans le pire : tableau trié en ordre croissant ou décroissant et donc partitionnement qui ne partitionne pas vraiment
