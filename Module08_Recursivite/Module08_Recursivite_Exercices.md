# Module 08 - Récursivité

## Exercice 1 - Compter en négatif

- Écrivez une première fonction récursive qui affiche les nombres de -n à 0 sur la console.
- Écrivez une seconde fonction récursive qui affiche les nombres de 0 à -n.
- Si vous avez utilisé plus d'une paramètre pour la seconde méthode, écrivez une variante à un paramètre.

## Exercice 2 - Division entière

Écrivez une fonction récursive qui calcule le reste de la division entière de deux nombres entiers sans utiliser les opérateurs diviser, modulo et multiplier.

## Exercice 3 - Suite de Fibonacci

La suite est définie de la façon suivante :

```cpp
- Fibonacci(0) = 0 // Condition d'arrêt
- Fibonacci(1) = 1 // Condition d'arrêt
- Fibonacci(n) = Fibonacci(n - 1) + Fibonacci(n - 2) // Récursivité
```

1. Écrivez la fonction ```fibonacci``` en version récursive qui calcule une valeur de la suite de Fibonacci.
2. Avec cette fonction, calculez ```fibonacci(10)``` et validez que vous obtenez bien la valeur ```55```.
3. Dessinez l'arbre d'appel de la fonction ```fibonacci``` pour ```fibonacci(5)```.
4. Modifiez votre programme principal pour qu'il calcule les valeurs de ```fibonacci``` de 1 à 40. Affichez les temps en minutes, secondes, millisecondes, microsecondes, nanosecondes et tracez la courbe sur Excel. Validez que la complexité de l'algorithme est bien exponentielle.
5. Pourquoi la complexité est-elle aussi élevée ?
6. Comment pourriez-vous améliorer votre fonction ? Pourrait-on inverser l'ordre du calcul (c'est à dire partir de 0) ? Réécrivez une version optimisée.

<details>
    <summary>Mesure du temps</summary>

```cpp
std::string dureeLisibleParHumain(long long p_ns,
  bool p_ignoreNs = false, bool p_ignoreUs = false, bool p_ignoreMs = false) {
  constexpr long long Ns = 1;
  constexpr long long UsNs = 1'000 * Ns;
  constexpr long long MsNs = 1'000 * UsNs;
  constexpr long long SNs = 1'000 * MsNs;
  constexpr long long MNs = 60 * SNs;
  constexpr long long HNs = 60 * MNs;
  constexpr long long jourNs = 24 * HNs;

  int jours = static_cast<int>(p_ns / jourNs);
  p_ns -= jours * jourNs;
  int heures = static_cast<int>(p_ns / HNs);
  p_ns -= heures * HNs;
  int minutes = static_cast<int>(p_ns / MNs);
  p_ns -= minutes * MNs;
  int secondes = static_cast<int>(p_ns / SNs);
  p_ns -= secondes * SNs;
  int millisecondes = static_cast<int>(p_ns / MsNs);
  p_ns -= millisecondes * MsNs;
  int microsecondes = static_cast<int>(p_ns / UsNs);
  p_ns -= microsecondes * UsNs;
  int nanosecondes = static_cast<int>(p_ns);

  std::stringstream ss;
  std::string prefixText = "";

  if (jours) {
    ss << std::setw(2) << jours << " jour(s), ";
  }
  if (heures) {
    ss << std::setw(2) << heures << " heure(s), ";
  }
  if (minutes) {
    ss << std::setw(2) << minutes << " minute(s), ";
  }
  if (secondes || (p_ignoreMs && p_ignoreUs && p_ignoreNs)) {
    ss << std::setw(2) << secondes << " seconde(s)";
    prefixText = ", ";
  }

  if (!p_ignoreMs) {
    ss << std::setw(3) << prefixText << millisecondes << " milliseconde(s)";
    prefixText = ", ";
    if (!p_ignoreUs) {
      ss << std::setw(3) << prefixText << microsecondes << " microsecond(s)";
      prefixText = ", ";
      if (!p_ignoreNs) {
        ss << std::setw(3) << prefixText << nanosecondes << " nanosecond(s)";
      }
    }
  }

  return ss.str();
}

int main() {
  // ...
  {
    using namespace std::chrono;

    time_point<high_resolution_clock> debut = high_resolution_clock::now();
    std::cout << "factorielle_v1(120) = " << factorielle_v1(120) << std::endl << std::endl;
    time_point<high_resolution_clock> fin = high_resolution_clock::now();

    nanoseconds tempsPasseNs = fin - debut;
    std::cout << "Duree du calcul (ns) : " << tempsPasseNs.count() << std::endl;

    std::cout << "Duree du calcul : " << dureeLisibleParHumain(tempsPasseNs.count()) << std::endl;
  }
}

```

</details>

## Exercice 4 - Recherche

1. Écrivez la fonction ```Rechercher``` qui recherche un élément dans un tableau d'entiers de manière récursive (Équivalent de la [méthode find de C#](https://learn.microsoft.com/en-us/dotnet/api/system.collections.generic.list-1.find?view=net-7.0)) :
   - Elle prend un ```int*``` comme collection, l'entier à chercher et la taille du tableau en paramètres
   - Elle renvoie l'indice de l'élément s'il est trouvé, la valeur par défaut (-1) sinon

2. Écrivez la fonction récursive ```CompterNombreOccurences``` qui permet de compter le nombre d'éléments (Équivalent de la [méthode Count de C#](https://learn.microsoft.com/en-us/dotnet/api/system.linq.enumerable.count?view=net-7.0#system-linq-enumerable-count-1(system-collections-generic-ienumerable((-0))-system-func((-0-system-boolean))))) :
   - Elle prend un ```int*``` comme collection, la taille du tableau en paramètres et la fonction de recherche
   - La fonction de recherche prend une valeur en paramètres et renvoie vrai si c'est la valeur à trouver, faux sinon.
   - Elle renvoie le nombre d’occurrences de l'élément s'il est trouvé, la valeur par défaut (-1) sinon

3. Écrivez la fonction récursive ```Filtrer``` qui permet de filtrer une liste générique d'éléments (celle que vous avez codée précèdement) qui correspondent au critère d'une fonction lambda passée en paramètres (Équivalent de la [méthode ```Where``` de Linq](https://docs.microsoft.com/en-us/dotnet/api/system.linq.enumerable.where?view=net-6.0#System_Linq_Enumerable_Where__1_System_Collections_Generic_IEnumerable___0__System_Func___0_System_Boolean__)) :
   - La fonction prend une valeur en paramètres et renvoie vrai si c'est la valeur à trouver, faux sinon.
   - Votre fonction renvoie une liste d'éléments du même type que les éléments de l'énumération.

Pour écrire la fonction `CompterNombreOccurences` et `Filtrer`, vous pouvez vous inspirer du code suivant :

```cpp
template<class TypeValeur>
bool executePredicat(bool (*p_predicat)(TypeValeur), TypeValeur p_valeur) {
  return p_predicat(p_valeur);
}

int main()
{
  std::cout << "Appel executePredicat avec 42 et la lambda v => !(v & 1) = " << executePredicat<int>([](int v) { return !(v & 1); }, 42) << std::endl;
  std::cout << "Appel executePredicat avec 43 et la lambda v => !(v & 1) = " << executePredicat<int>([](int v) { return !(v & 1); }, 43) << std::endl;
}

```

## Exercice 6 - Recherche dichotomique

Écrivez la fonction de recherche dichotomique récursive ```RechercherDichotomique``` qui prend un tableau d'éléments, le nombre d'éléments, une fonction en paramètres et qui renvoie vrai s'il est trouvé, faux sinon :

- La fonction lambda prend une valeur en paramètres et renvoie un entier correspondant à sa position par rapport à la valeur cherchée.
- Votre fonction privée doit prendre un tableau, les indices de début et de fin du sous-tableau ainsi que la fonction.
