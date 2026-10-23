# Exercice 4

Dans cet exercice, vous allez écrire un programme en C++ qui calcule le produit scalaire de deux vecteurs de grande taille. Chaque vecteur doit être rempli avec des valeurs aléatoires. Le produit scalaire se calcule en multipliant les éléments correspondants des deux vecteurs, puis en additionnant tous les résultats obtenus. Le programme doit afficher le résultat du produit scalaire.

L’objectif est de tester les performances du programme en fonction de la taille des vecteurs. Vous devrez mesurer le temps d’exécution pour différentes tailles : 1 million, 10 millions, 50 millions et 100 millions d’éléments. Chronométrez uniquement le calcul du produit scalaire, sans inclure le remplissage des vecteurs, et affichez le résultat en millisecondes.

La taille des vecteurs ne doit pas être écrite en dur dans le code. Vous pouvez soit la passer en argument lors du lancement du programme à l’aide de **argc** et **argv**, comme dans l’exercice 3, soit faire une boucle sur les quatre tailles dans votre programme. Si vous passez la taille en argument, pensez à convertir la chaîne de caractères en nombre (par exemple avec **stoi**).

Exemple de lancement avec un argument :

```
./run 10000000
```

Quelle est la complexité de votre algorithme ? Les temps mesurés sont-ils cohérents avec cette complexité ?
C'est complexité O(n), oui ils sont cohérents : 1m - 4814, 10m - 48164, 100m - 478111

Attention au type de la variable qui contient le résultat : quelle est la valeur maximale qu’elle peut atteindre ?
il s'agit d'un int, c'est donc max 2,147,483,647 (2^31 -1)