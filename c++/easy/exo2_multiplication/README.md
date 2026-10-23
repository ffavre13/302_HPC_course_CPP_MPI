# Exercice 2

Dans cet exercice, vous allez écrire un programme en C++ qui demande à l’utilisateur d’entrer un nombre à l’aide de **cin**. Une fois le nombre saisi, le programme devra calculer et écrire les 100 000 premiers multiples de ce nombre dans un fichier texte. Pour cela, vous utiliserez **ofstream** pour écrire dans le fichier, et vous testerez deux façons de terminer chaque ligne : avec **"\n"** et avec **endl**.

Comme dans l’exercice 1, vous mesurerez le temps d’exécution avec la bibliothèque **chrono**. Chronométrez uniquement l’écriture du fichier (de son ouverture à sa fermeture), sans inclure la saisie de l’utilisateur, et affichez le résultat en millisecondes à l’aide de **duration_cast\<milliseconds\>**.

Une fois le fichier généré, vous devrez observer et comparer les performances du programme selon la méthode utilisée pour terminer les lignes. Est-ce que le temps d’exécution change ? Le contenu du fichier est-il différent ? Que fait **endl** de plus que **"\n"** ? À vous de tester et d’analyser les résultats.

- endl en plus d'ajouter un \n flush le contenu. CPP n'écrit pas directement dans le fichier il stocke dans un buffer mais le flush du endl force le buffer a écrire dans le fichier il y a donc 100000 écriture la ou juste le \n écrit moin.