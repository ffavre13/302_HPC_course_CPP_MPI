# Exercice 1

Dans cet exercice, vous allez reprendre le tout premier programme du laboratoire (_Hello World_) et le modifier pour qu’il fonctionne avec MPI. L’objectif est que chaque processus affiche `Processor X - Hello World` dans le terminal, où `X` est son rang. Le processus de rang 0 affiche en plus le nombre total de processus.

Votre programme devra obligatoirement contenir au minimum les appels à **MPI_Init** et **MPI_Finalize**. Vous utiliserez également **MPI_Comm_size** pour connaître le nombre total de processus, et **MPI_Comm_rank** pour identifier le rang de chaque processus. Pour compiler un programme MPI, utilisez **mpic++** à la place de g++ dans votre Makefile.

Le programme sera lancé avec **mpirun**, ce qui permettra d’exécuter plusieurs instances en parallèle. Par exemple, pour lancer 6 processus :

```
mpirun -np 6 ./run
```

Exemple de résultat avec 6 processus :

```
Number of processors: 6
Processor 0 - Hello World
Processor 5 - Hello World
Processor 1 - Hello World
Processor 2 - Hello World
Processor 3 - Hello World
Processor 4 - Hello World
```

Lancez votre programme plusieurs fois. Que remarquez-vous sur l’ordre d’affichage des messages ? Comment l’expliquez-vous ?
L'ordre change 