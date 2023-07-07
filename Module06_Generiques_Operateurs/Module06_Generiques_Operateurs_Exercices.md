# Module 06 - Génériques et opérateurs

## Exercice 1 - Opérateurs

Reprenez le code de votre liste d'entiers et ajoutez-y les opérateurs suivants :

- `liste + élément => liste`, `liste += élément => liste` : ajoute un élément à la liste
- `liste + liste => liste`, `liste += liste => liste` : concatène deux listes
- `ostream << liste => ostream` : affiche la liste dans un flux de sortie

## Exercice 2 - Génériques

Reprenez le code de votre liste d'entiers et transformez-la en une liste générique. Vous devrez donc pouvoir créer une liste d'entiers, de chaînes de caractères, de booléens, etc.

## Exercice 3 - Pile et file

En utilisant votre liste générique, créez une pile et une file.

Une pile est une structure de données qui fonctionne sur le principe du LIFO (Last In First Out) : le dernier élément ajouté est le premier à être retiré.

Les opérations sur une pile sont les suivantes :

- `empiler(element)` : ajoute un élément au sommet de la pile
- `dépiler() => élément` : retire l'élément au sommet de la pile et le retourne
- `estVide() => booléen` : indique si la pile est vide ou non
- `taille() => entier` : retourne le nombre d'éléments dans la pile
- `sommet() => élément` : retourne l'élément au sommet de la pile sans le retirer

Une file fonctionne sur le principe du FIFO (First In First Out) : le premier élément ajouté est le premier à être retiré.

Les opérations sur une file sont les suivantes :

- `enfiler(element)` : ajoute un élément à la fin de la file
- `défiler() => élément` : retire l'élément au début de la file et le retourne
- `estVide() => booléen` : indique si la file est vide ou non
- `taille() => entier` : retourne le nombre d'éléments dans la file
- `premier() => élément` : retourne l'élément au début de la file sans le retirer

Ajoutez les opérateurs suivants à votre pile et votre file :

- `~pile` : retourne une pile inversée
- `~file` : retourne une file inversée
- `pile1 + pile2 => pile` : concatène deux piles
- `file1 + file2 => file` : concatène deux files
- `pile1 += pile2 => pile` : ajoute une pile à une autre
- `file1 += file2 => file` : ajoute une file à une autre
- `pile1 == pile2 => booléen` : indique si deux piles sont égales
- `file1 == file2 => booléen` : indique si deux files sont égales
- `pile1 != pile2 => booléen` : indique si deux piles sont différentes
- `file1 != file2 => booléen` : indique si deux files sont différentes
- `ostream << pile => ostream` : affiche la pile dans un flux de sortie
- `ostream << file => ostream` : affiche la file dans un flux de sortie
