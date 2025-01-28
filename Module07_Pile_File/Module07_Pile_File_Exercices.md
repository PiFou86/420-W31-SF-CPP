# Module 07 - Pile et file

## Exercice 1 - Pile et file

En utilisant votre liste générique, créez une pile et une file.

Une pile est une structure de données qui fonctionne sur le principe du LIFO (Last In First Out) : le dernier élément ajouté est le premier à être retiré.

Les opérations sur une pile sont les suivantes :

- `empiler(element)` : ajoute un élément au sommet de la pile
- `dépiler() => élément` : retire l'élément au sommet de la pile et le retourne
- `sommet() => élément` : retourne l'élément au sommet de la pile sans le retirer
- `estPileVide() => booléen` : indique si la pile est vide ou non
- `taille() => entier` : retourne le nombre d'éléments dans la pile

Une file fonctionne sur le principe du FIFO (First In First Out) : le premier élément ajouté est le premier à être retiré.

Les opérations sur une file sont les suivantes :

- `enfiler(element)` : ajoute un élément à la fin de la file
- `défiler() => élément` : retire l'élément au début de la file et le retourne
- `tete() => élément` : retourne l'élément au début de la file sans le retirer
- `estFileVide() => booléen` : indique si la file est vide ou non
- `taille() => entier` : retourne le nombre d'éléments dans la file

Ajoutez les opérateurs suivants à votre pile et votre file :

- `~pile` : retourne une pile inversée
- `~file` : retourne une file inversée
- `pile1 + pile2 => pile` : concatène deux piles (Par exemple, si la pile 1 contient les éléments `1`, `2` et `3` et la pile 2 contient `4` et `5`, la pile retournée sera `1`, `2`, `3`, `4` et `5` après la concaténation.)
- `file1 + file2 => file` : concatène deux files (Par exemple, si la file 1 contient les éléments `1`, `2` et `3` et la file 2 contient `4` et `5`, la file retournée sera `1`, `2`, `3`, `4` et `5` après la concaténation.)
- `pile1 += pile2 => pile` : ajoute une pile à une autre
- `file1 += file2 => file` : ajoute une file à une autre
- `pile1 == pile2 => booléen` : indique si deux piles sont égales
- `file1 == file2 => booléen` : indique si deux files sont égales
- `pile1 != pile2 => booléen` : indique si deux piles sont différentes
- `file1 != file2 => booléen` : indique si deux files sont différentes
- `ostream << pile => ostream` : affiche la pile dans un flux de sortie
- `ostream << file => ostream` : affiche la file dans un flux de sortie

## Exercice 2 - Compteur de parenthèses

En utilisant une des deux structures de données vues en cours, écrivez un programme qui lit une chaîne de caractères et qui indique si les parenthèses sont correctement imbriquées. Par exemple, les chaînes suivantes sont correctes : `()`, `(()())`, `(()(()()))`, `((()())(()()))`. Les chaînes suivantes sont incorrectes : `(`, `)`, `(()`, `())`, `(()(()())`, `((()())(()())`.

Modifiez le programme pour qu'il accepte aussi les caractères `[]` et `{}`. Par exemple, les chaînes suivantes sont correctes : `()`, `[]`, `{}`, `(()())`, `(()[]())`, `((){()})`, `(()(()()))`, `((()())(()()))`. Les chaînes suivantes sont incorrectes : `(`, `)`, `[`, `]`, `{`, `}`, `(()`, `())`, `(()[]`, `((){()}`, `(()(()())`, `((()())(()())`.

## Exercice 3 - Transformation d'une expression infixe en expression postfixe

En utilisant un des deux structures de données vues en cours, écrivez une méthode qui permet de transformer une expression infixe en expression postfixe. Par exemple, l'expression infixe `1 + 2 * 3` devient `1 2 3 * +` après transformation. L'expression infixe `1 + 2 * 3 + 4 * 5` devient `1 2 3 * + 4 5 * +` après transformation. L'expression infixe `(1 + 2) * 3` devient `1 2 + 3 *` après transformation. L'expression infixe `1 + 2 * (3 + 4) * 5` devient `1 2 3 4 + * 5 * +` après transformation.

Pour vous aidez, voici les règles de transformation :

- Si l'élément est un nombre, il est ajouté à la sortie.
- Si l'élément est un opérateur :

  - Si la pile est vide, l'opérateur est ajouté à la pile.
  - Si la pile n'est pas vide, l'opérateur est ajouté à la pile si sa priorité est strictement supérieure à celle de l'opérateur au sommet de la pile. Sinon, l'opérateur au sommet de la pile est retiré et ajouté à la sortie. Cette dernière action est répétée tant que l'opérateur n'est pas strictement supérieur à l'opérateur sur le sommet de la pile. L'opérateur est ensuite ajouté à la pile.

- Si l'élément est une parenthèse ouvrante, elle est ajoutée à la pile.
- Si l'élément est une parenthèse fermante, tous les éléments de la pile sont retirés et ajoutés à la sortie jusqu'à ce que la parenthèse ouvrante correspondante soit atteinte. La parenthèse ouvrante est ensuite retirée de la pile.
- Lorsque tous les éléments ont été traités, tous les éléments de la pile sont retirés et ajoutés à la sortie.

Pour les priorités des opérateurs, voici les règles :

- Les opérateurs sont prioritaires dans l'ordre suivant : `*`, `/`, `+`, `-`.
- Les parenthèses ouvrantes et fermantes ont la même priorité.

Quelques exemples :

- `1 + 2 * 3` :

  - `1` : ajouté à la sortie
  - `+` : empilé
  - `2` : ajouté à la sortie
  - `*` : empilé
  - `3` : ajouté à la sortie
  - `*` : dépilé et ajouté à la sortie
  - `+` : dépilé et ajouté à la sortie
  - Fin de l'expression : `1 2 3 * +`

- `1 + 2 * 3 + 4 * 5` :

  - `1` : ajouté à la sortie
  - `+` : empilé
  - `2` : ajouté à la sortie
  - `*` : empilé
  - `3` : ajouté à la sortie
  - `*` : dépilé et ajouté à la sortie
  - `+` : dépilé et ajouté à la sortie
  - `+` : empilé
  - `4` : ajouté à la sortie
  - `*` : empilé
  - `5` : ajouté à la sortie
  - `*` : dépilé et ajouté à la sortie
  - `+` : dépilé et ajouté à la sortie
  - Fin de l'expression : `1 2 3 * + 4 5 * +`

- `(1 + 2) * 3` :

  - `(` : empilé
  - `1` : ajouté à la sortie
  - `+` : empilé
  - `2` : ajouté à la sortie
  - `+` : dépilé et ajouté à la sortie
  - `(` : dépilé
  - `*` : empilé
  - `3` : ajouté à la sortie
  - `*` : dépilé et ajouté à la sortie
  - Fin de l'expression : `1 2 + 3 *`

Vous pouvez trouver une version dynamique sur le site suivante : https://www.free-online-calculator-use.com/infix-to-postfix-converter.html

## Exercice 4 - Évaluation d'une expression postfixe

En utilisant un des deux structures de données vues en cours, écrivez une méthode qui permet d'évaluer une expression postfixe. Par exemple, l'expression postfixe `1 2 3 * +` donne le résultat `7`. L'expression postfixe `1 2 3 * + 4 5 * +` donne le résultat `27`. L'expression postfixe `1 2 + 3 *` donne le résultat `9`. L'expression postfixe `1 2 3 4 + * 5 * +` donne le résultat `71`.

Vous pouvez trouver une version dynamique sur le site suivante :
https://www.free-online-calculator-use.com/postfix-evaluator.html
