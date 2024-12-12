# Révision : Algorithmique avancée et C++

## 1. Donnez les valeurs des variables après chaque ligne

```cpp
int i = 40;  // i =
int j = ++i;  // i = ; j =
i = 40;
int k = i++; // i = ; k =
i = 40;
int l = (++i)++; // i = ; l =
i = 40;
int m = (++++++i)++; // i = ; m =
i = 40;
int n = (++++++i)--; // i = ; n =
```

<details>
<summary>Indices et rappels</summary>
- Rappelez-vous que `++i` incrémente avant d'utiliser la valeur, tandis que `i++` utilise la valeur avant d'incrémenter.
- Les expressions complexes telles que `(++++++i)` doivent être analysées pas à pas.
</details>

<details>
<summary>Réponse détaillée</summary>
1. `i = 40;` Initialisation simple.
2. `j = ++i;` `i` est incrémenté avant d'être assigné à `j`, donc `i = 41` et `j = 41`.
3. `k = i++;` `k` prend la valeur actuelle de `i`, puis `i` est incrémenté, donc `i = 41` et `k = 40`.
4. `l = (++i)++;` `++i` incrémente `i` avant l'assignation, la référence renvoyée par `++i` est une `lvalue`, donc i = 42 et l = 41.
5. `m = (++++++i)++;` `++++++i` incrémente `i` 3 fois avant l'assignation et i est incrémentée après, donc i = 44 et m = 43.
6. `n = (++++++i)--;` `++++++i` incrémente `i` 3 fois avant l'assignation et i est décrémentée après, donc i = 42 et n = 43.
</details>

## 2. Qu’est-ce que sont les lvalues et les rvalues ? En quoi les distinguer est-il important ?

<details>
<summary>Indices et rappels</summary>
- Les `lvalues` sont des expressions qui ont une adresse mémoire.
- Les `rvalues` sont des valeurs temporaires ou des littéraux.
- Différencier les deux est crucial pour écrire des programmes robustes et optimisés.
</details>

<details>
<summary>Réponse détaillée</summary>
- `lvalue`: Toute expression qui peut apparaître à gauche d'une assignation, comme une variable. Les `lvalues` ont une adresse mémoire.
- `rvalue`: Tout ce qui n'est pas une `lvalue`, comme les littéraux ou les résultats de calculs temporaires. 
Exemple :
```cpp
int x = 10; // x est une lvalue, 10 est une rvalue
x = x + 5; // x + 5 est une rvalue
```
</details>

## 3. Peut-on avoir des méthodes et/ou opérateurs qui reçoivent des rvalues en paramètres ? Est-ce utile ?

<details>
<summary>Indices et rappels</summary>
- Explorez l'idée des références rvalue (`T&&`).
- Recherchez les usages pour l'optimisation, comme dans le déplacement.
</details>

<details>
<summary>Réponse détaillée</summary>
- Oui, en utilisant des références rvalue (`T&&`), on peut recevoir des `rvalues` en paramètres.
- C'est utile pour éviter des copies inutiles, notamment dans les constructeurs ou opérateurs par déplacement.
- On évite ainsi des copies coûteuses en réutilisant les ressources de l'objet temporaire.
Exemple :
```cpp
class MaClasse {
public:
   MaClasse(MaClasse&& other) noexcept { /* déplacement */ }
};
```
</details>

## 4. Calcul des adresses dans un tableau

### Hypothèses :
- `int` codé sur 8 octets.
- Tableau `t` de capacité 10, alloué à l'adresse `0x100`.

### Questions :
- `t[0] :`
- `t[1] :`
- `t + 3 :`
- `t + 9 :`
- `t + 10 :`
- Formule générale pour calculer l’adresse :
- Pourquoi les tableaux débutent à 0 ?
- De plus, est-ce que toutes les adresses peuvent être utilisées ?

<details>
<summary>Indices et rappels</summary>
- La taille d'un `int` est importante.
- Les indices de tableaux commencent à 0.
- Pour une adresse `t[i]`, utilisez la formule : `adresse_base + i * sizeof(type)`.
</details>

<details>
<summary>Réponse détaillée</summary>
- `t[0]` : `0x100`
- `t[1]` : `0x100 + 8 = 0x108`
- `t + 3` : `0x100 + 3 * 8 = 0x118`
- `t + 9` : `0x100 + 9 * 8 = 0x148`
- `t + 10` : `0x100 + 10 * 8 = 0x150`
- Formule : `adresse_base + i * sizeof(type_element)`
- L'index correspond à un décalage par rapport à l'adresse de base.
- On ne peut pas accéder à des adresses en dehors des limites du tableau. Donc ici, il n'y a pas de `t[10]` ou de *(t + 10) (possibilité d'écraser des données).
</details>

## 5. Expliquez la différence entre un pointeur et une référence

<details>
<summary>Indices et rappels</summary>
- Une référence est un alias/synonyme constant.
- Un pointeur est une variable qui stocke une adresse.
- Un pointeur peut être null, mais pas une référence.
</details>

<details>
<summary>Réponse détaillée</summary>
- Références : alias constant, non null et doit être initialisé lors de sa déclaration.
- Pointeurs : variables pouvant changer d'adresse ou être nulles.
Exemple :
```cpp
int x = 10;
int& ref = x; // Référence
int* ptr = &x; // Pointeur
```
</details>

## 6. Si Radio est une classe et que le constructeur par défaut contient le code `std::cerr << "ctor()" << std::endl;` et que l’on déclare un tableau de 10 Radio, que se passe-t-il sur la sortie standard ? Y a-t-il autre chose à noter à l’écran ?

<details>
<summary>Indices et rappels</summary>
- Rappelez-vous que pour un tableau d'objets, le constructeur par défaut est appelé pour chaque élément.
- Vérifiez sur quel flux de sortie est affiché le message.
</details>

<details>
<summary>Réponse détaillée</summary>
- La sortie d'erreurs affichera "ctor()" 10 fois, une fois pour chaque objet construit.
- Pour chaque case du tableau, le constructeur par défaut est appelé.
</details>

## 7. Quand doit-on déclarer un destructeur virtuel pur ?

<details>
<summary>Indices et rappels</summary>
- Un destructeur virtuel pur est utile pour les classes abstraites.
</details>

<details>
<summary>Réponse détaillée</summary>
- Il permet de rendre une classe abstraite sans déclarer des méthodes virtuelles pures.
```
</details>

## 8. Faut-il définir un destructeur virtuel pur ?

<details>
<summary>Indices et rappels</summary>
- Même si un destructeur virtuel pur est "= 0", il doit toujours avoir une implémentation.
</details>

<details>
<summary>Réponse détaillée</summary>
- Oui, car la destruction complète de la hiérarchie d'héritage en dépend.
Exemple :
```cpp
Base::~Base() {}
```
</details>

## 9. Expliquez la différence entre déclaration et définition

<details>
<summary>Indices et rappels</summary>
- La déclaration indique l'existence d'un élément.
- La définition alloue ou initialise cet élément.
</details>

<details>
<summary>Réponse détaillée</summary>
- Déclaration : donne les informations nécessaires pour utiliser un élément sans en réserver l'espace ou exécuter du code.
- Définition : alloue ou initialise réellement l'élément.
Exemple :
```cpp
void f(); // Déclaration
void f() {} // Définition
```
</details>

## 10. Donnez un exemple d’appel d’un opérateur d’affectation par déplacement

<details>
<summary>Indices et rappels</summary>
- Rappelez-vous que l'opérateur d'affectation par déplacement utilise des rvalues et est défini avec un paramètre `T&&`.
</details>

<details>
<summary>Réponse détaillée</summary>
- Exemple d'implémentation :
```cpp
class MaClasse {
public:
    MaClasse& operator=(MaClasse&& other) noexcept {
        if (this != &other) {
            // Déplacement des ressources
        }
        return *this;
    }
};
```
- Exemple d'appel :
```cpp
MaClasse a;
a = MaClasse(); // Appel de l'opérateur de déplacement
```
</details>

## 11. Que se passe-t-il si vous avez une classe Fenetre et la variable `f` de ce type, et que vous appelez `f` qui est définie par `void f(Fenetre f)` ?

<details>
<summary>Indices et rappels</summary>
- Analysez la signature de la fonction pour comprendre l'effet sur la variable passée par copie.
</details>

<details>
<summary>Réponse détaillée</summary>
- L'appel à `f` va créer une copie locale de l'objet passé en paramètre. Cela peut être coûteux en ressources si l'objet est complexe.
- Utiliser une référence ou une référence rvalue peut optimiser ce processus.
Exemple :
```cpp
void f(Fenetre& f); // Passage par référence
```
</details>

## 12. Quel est l’intérêt de définir un constructeur par déplacement ? À quoi faut-il faire attention ?

<details>
<summary>Indices et rappels</summary>
- Les constructeurs par déplacement optimisent les performances en réutilisant les ressources d'un objet temporaire.
- Attention aux états invalides après un déplacement.
</details>

<details>
<summary>Réponse détaillée</summary>
- Intérêt : évite la copie coûteuse en allouant les ressources de l'objet temporaire à l'objet en construction.
- Précautions : assurer que l'objet déplacé est laissé dans un état valide (par exemple, valeurs par défaut).
Exemple :
```cpp
class MaClasse {
public:
    MaClasse(MaClasse&& objetADeplacer) noexcept : m_donnees(objetADeplacer.m_donnees) {
        objetADeplacer.m_donnees = nullptr; // Laisser l'objet déplacé dans un état valide.
    }
};
```
</details>

## 13. Quelle est la particularité des références ? Cela a-t-il un/des impacts si vous en avez en données membres ?

<details>
<summary>Indices et rappels</summary>
- Les références doivent être initialisées à la déclaration et ne peuvent pas être modifiées.
</details>

<details>
<summary>Réponse détaillée</summary>
- Particularité : elles doivent être initialisées dans la liste d'initialisation du constructeur et doit être une lvalue. Elles ne peuvent être réassignées.
- Impact : les membres référencés doivent être initialisés dans les listes d'initialisation des constructeurs.
Exemple :
```cpp
class MaClasse {
    int& m_ref;
public:
    MaClasse(int& ref) : m_ref(ref) {}
};
```
</details>

## 14. Où est allouée la mémoire des parties suivantes ?

### Code :
```cpp
int i = 42;
int& j = i; 
int* k = new int;
Robot r1();
Robot* r2 = new Robot();
Robot& r3 = *r2;
```

<details>
<summary>Indices et rappels</summary>
- Différenciez la pile (stack) et le tas (heap).
- Les pointeurs suivent les allocations de leurs objets associés.
- Les références ne sont pas allouées, elles sont des alias, donc pas de mémoire supplémentaire.
</details>

<details>
<summary>Réponse détaillée</summary>
- `i`: pile (stack)
- `j`: nul part, référence à `i`
- `k`: pile, `new int` tas (heap)
- `r1`: pile, appel du constructeur par défaut
- `r2`: pile, pointeur vers un objet alloué sur le tas, `new Robot` tas
- `r3`: nul part, référence à l'objet alloué sur le tas.
</details>

## 15. Y a-t-il des erreurs (mémoire, logique, etc.) dans les codes suivants ? Si oui, lesquelles ?

### Code :
```cpp
int& f() { int i = 42; return i; }
int g() { int i = 42; return i; }
int* h() { int i = 42; return &i; }
int* i() { return new int; }
```

<details>
<summary>Indices et rappels</summary>
- Analysez la durée de vie des variables.
- Identifiez les zones mémoire invalides ou fuites.
</details>

<details>
<summary>Réponse détaillée</summary>
- `f`: erreur, la référence retourne une variable locale qui sera détruite après la sortie de la fonction.
- `g`: correct, retourne une copie.
- `h`: erreur, retourne un pointeur sur une variable locale détruite après la sortie de la fonction.
- `i`: correct, mais entraîne une fuite mémoire si le pointeur n'est pas supprimé avec `delete`. Donc pratique à éviter.
</details>

## 16. Pourquoi faut-il savoir qui est le propriétaire d’une zone de la mémoire ?

<details>
<summary>Indices et rappels</summary>
- Le propriétaire est responsable de libérer la mémoire pour éviter les fuites.
</details>

<details>
<summary>Réponse détaillée</summary>
- Identifier le propriétaire évite des erreurs comme des doubles suppressions ou des fuites mémoire.
- On essaie d'avoir un seul propriétaire pour chaque zone mémoire allouée. Si la mémoire est partagée, il faut définir qui est responsable de la libération et il ne faut pas oublier d'oublier les adresses de la mémoire désallouée.
</details>

## 17. Qui est responsable de désallouer la mémoire allouée sur la pile ? Qui pour le tas ?

<details>
<summary>Indices et rappels</summary>
- Différenciez la gestion automatique de la mémoire de la pile par rapport à la gestion manuelle de la mémoire du tas.
</details>

<details>
<summary>Réponse détaillée</summary>
- Pile : le compilateur gère automatiquement la désallocation à la fin de la portée.
- Tas : le programmeur est responsable de désallouer la mémoire allouée dynamiquement avec `delete` ou `delete[]`.
</details>

## 18. Pourquoi veut-on se retrouver dans la position d’avoir seulement un seul propriétaire d’une zone mémoire ?

<details>
<summary>Indices et rappels</summary>
- Considérez les problèmes liés aux doubles suppressions ou aux fuites mémoire.
</details>

<details>
<summary>Réponse détaillée</summary>
- Un seul propriétaire garantit une gestion claire et sûre de la mémoire.
- Les pointeurs intelligents comme `std::unique_ptr` facilitent cette gestion en assurant un seul propriétaire par conception. (Voir référence dans le livre demandé en cours)
</details>

## 19. Pourquoi faut-il initialiser vos pointeurs à `nullptr` ou à l’adresse renvoyée par un `new` ? Pourquoi faut-il passer la valeur d’un pointeur à `nullptr` après avoir appelé `delete` ou `delete[]` sur l’adresse qu’il pointait ? Faut-il assigner une valeur particulière à une donnée membre dont on a volé (ou transféré) l’adresse dans un autre objet ? Pourquoi ?

<details>
<summary>Indices et rappels</summary>
- Comprenez les dangers des pointeurs non initialisés ou pendants.
- Étudiez les bonnes pratiques pour éviter les erreurs de segmentation.
</details>

<details>
<summary>Réponse détaillée</summary>
- Initialisation à `nullptr` : évite les comportements indéterminés des pointeurs non initialisés.
- Assignation à `nullptr` après suppression : signale que le pointeur ne pointe plus vers une zone valide.
- Données transférées : assignez des valeurs par défaut pour éviter des états invalides.
- Cela évite aussi d'essayer de libérer la mémoire alors qu'il ne faut pas (ex. déplacement d'un pointeur ou déjà désalloué).
</details>

## 20. Est-ce qu’il y a des problèmes/risques dans les codes suivants ? Si oui, lesquels ?

### Code 1 :
```cpp
int a = 42;
int* p = new int;
p = &a;
delete p;
p = nullptr;
```

<details>
<summary>Indices et rappels</summary>
- Analysez l’ordre des opérations pour vérifier si la mémoire est correctement libérée.
</details>

<details>
<summary>Réponse détaillée</summary>
- Problème : le pointeur `p` est réassigné à l’adresse de `a` avant d’appeler `delete`, ce qui entraîne une tentative de libération d’une zone de mémoire non allouée dynamiquement.
</details>

### Code 2 :
```cpp
class Bol {
   ListeLiquides* m_listeLiquides;
public:
   Bol();
   Bol(Bol &&);
   ~Bol();
};
[…]
Bol::Bol(Bol &&objetADeplacer) : m_listeLiquides(objetADeplacer.m_listeLiquides)
Bol ::~Bol() { if (m_listeLiquides) { delete m_listeLiquides; } }
````

<details>
<summary>Indices et rappels</summary>
- Vérifiez si la mémoire allouée est correctement libérée.
- Considérez les implications de l’absence de copie ou de déplacement.
- Vérifiez le code du constructeur par déplacement et ce qui se passe pour l'objet à déplacer dans le destructeur.
</details>

<details>
<summary>Réponse détaillée</summary>

Le destructeur supprime `m_listeLiquides` même s'il est déplacé d'un autre objet, ce qui entraîne une double suppression.

</details>

### Code 3 :

```cpp
class PileEntiers {
   int* m_valeurs;
   int m_capacite;
public:
   PileEntiers();
   ~PileEntiers();
};
[…]
PileEntiers::PileEntiers() : m_capacite(10), m_valeurs(new int[m_capacite]) { }
PileEntiers::~PileEntiers() { delete[] m_valeurs; }
```

<details>
<summary>Indices et rappels</summary>
- Est-ce que la liste d'initialisation du constructeur par défaut est correcte ?
</details>

<details>
<summary>Réponse détaillée</summary>

Le constructeur par défaut doit initialiser les données membres dans le bon ordre. Ici, `m_valeurs` est initialisé avant `m_capacite`, ce qui peut entraîner des comportements indéterminés.

</details>

## 21. Dans la déclaration `int* v`, est-ce que `v` est un pointeur sur un entier ou un tableau d’entiers ? Quel `delete` utiliser ?

<details>
<summary>Indices et rappels</summary>
- La distinction dépend de la façon dont `v` est initialisé.
</details>

<details>
<summary>Réponse détaillée</summary>
- `v` est un pointeur sur un entier ou un tableau d'entiers selon l'initialisation :
  - `v = new int;` -> pointeur sur un entier, utilisez `delete v`.
  - `v = new int[10];` -> tableau d'entiers, utilisez `delete[] v`.
</details>

## 22. À quoi sert le destructeur ? Quel code trouve-t-on dedans ? Donnez un exemple de classe.

<details>
<summary>Indices et rappels</summary>
- Le destructeur libère les ressources allouées dynamiquement par l’objet.
</details>

<details>
<summary>Réponse détaillée</summary>
- Le destructeur garantit que les ressources (mémoire, fichiers, etc.) sont correctement libérées lorsque l’objet est détruit.
Exemple :
```cpp
class MaClasse {
   int* m_donnees;
public:
   MaClasse() : m_donnees(new int[10]) {}
   ~MaClasse() { delete[] m_donnees; }
};
```
</details>

## 23. En admettant que nous ayons

### Déclarations

```cpp
MaClasse();
MaClasse(const MaClasse&);
MaClasse(MaClasse&&);
~MaClasse();
MaClasse SuperMethode(const MaClasse&);
MaClasse& operator=(const MaClasse&);
MaClasse& operator=(MaClasse&&);
```

Dans la définition, chaque méthode affiche son nom et son type.

### Code

```cpp
MaClasse m;
MaClasse n();
MaClasse o = m;
MaClasse p = std::move(m.SuperMethode(o));
p = o;
p = m.SuperMethode(o);
```

- Pourquoi le constructeur par copie est déclaré const & ?
- Pourquoi le constructeur par déplacement est déclaré non const et && ?
- Qu'affiche le code qui utilise la classe `MaClasse` ?

<details>
<summary>Indices et rappels</summary>
- Étudiez les appels des constructeurs et opérateurs d’affectation.
- Considérez l’optimisation RVO (Return Value Optimization).
</details>

<details>
<summary>Réponse détaillée</summary>
- Les appels suivants se produiront :
  1. Constructeur par défaut pour `m`.
  2. MaClasse n(); est une déclaration de fonction, pas un objet.
  3. Constructeur par copie pour `o`.
  4. Constructeur par déplacement pour `p` (à cause de `std::move`).
  5. Opérateur d’affectation par copie pour `p = o`.
  6. Opérateur d’affectation par déplacement pour `p = m.SuperMethode(o);

Exemple de trace :

```
MaClasse()

MaClasse(const MaClasse&)

MaClasse SuperMethode(const MaClasse&)
MaClasse(const MaClasse&)
MaClasse Copie()
MaClasse(const MaClasse&)
~MaClasse()
MaClasse(MaClasse&&)
~MaClasse()

MaClasse& operator=(const MaClasse&)
MaClasse SuperMethode(const MaClasse&)
MaClasse(const MaClasse&)
MaClasse Copie()
MaClasse(const MaClasse&)
~MaClasse()

MaClasse& operator=(MaClasse&&)
~MaClasse()

~MaClasse()
~MaClasse()
~MaClasse()
```

</details>

## 24. Pourquoi faire une liste de pointeurs plutôt qu’une liste d’objets ?

<details>
<summary>Indices et rappels</summary>
- Étudiez les avantages des listes de pointeurs dans la gestion de la mémoire et la polymorphie.
</details>

<details>
<summary>Réponse détaillée</summary>
- Une liste de pointeurs permet :
  - La gestion de polymorphisme avec des objets de classes dérivées.
  - Une meilleure gestion de la mémoire pour éviter les copies coûteuses.
  - Cependant, elle nécessite une gestion explicite de la mémoire (suppression des pointeurs).
</details>
