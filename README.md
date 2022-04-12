# ConjectureGoldbach

Dans le cadre d'une proposition de stage, un petit problème mathématique s'est dressé en face de moi :

 _Quelque soit un entier n pair, n est la somme de deux nombres premiers n1 et n2.
 Quelque que soit n, afficher (stocker) toutes les paires de (n1, n2)._

Le but était donc de réaliser un programme permetttant de calculer toutes les paires de nombres premiers qui, en les additionnant, forment notre nombre **n**, un entier pair fixé. Il faut également faire en sorte que le programme soit suffisament optimisé pour atteindre des **n** de plus en plus grand.

Ce document markdown a donc comme but d'expliquer les différentes étapes de l'algorithme ainsi que les réflexions qui ont permis d'aboutir à ce résultat.

Le document est divisé en trois parties distinctes :

* _Trouver les nombres premiers_
* _Stocker les nombres premiers_
* _Trouver les paires_

### Temps moyen pour un n donné :

* n = 1 000 000 :
  * __6__ millisecondes.
* n = 10 000 000 :
  * __95__ millisecondes
* n = 100 000 000 :
  * __1,2__ secondes.
* n = 1 000 000 000 :
  * __17,1__ secondes.

## 1 - Trouver les nombres premiers

Faire un test de primalité semble être l'option la plus logique, mais bien trop couteuse en temps. Pour trouver les nombres premiers, utiliser le **crible d'Érathostène** sera bien moins coûteux. 

### Le crible d'Ératosthène - 

Le crible d'Ératosthène est une méthode permettant de déterminer une liste de nombres premiers. Pour se faire, on prend une liste partant de 2 jusqu'à notre entier **n**. Ensuite, en partant de 2, il suffit de cocher tous les multiples du chiffre / nombre que l'on étudie (au premier tour ce sera 2, enlevant ainsi tous les chiffres / nombres pairs). Un indice non barré correspond donc à un nombre premier. 


<img alt="GIF" src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8c/New_Animation_Sieve_of_Eratosthenes.gif/440px-New_Animation_Sieve_of_Eratosthenes.gif" /> 

On réitère l'opération en prenant le prochain entier non coché dans la liste. À noter qu'avec ce crible, il est possible de parcourir notre liste jusqu'à sqrt(n). On obtient une boucle :

```c++
for (size_t i = 0; i < sqrt(n): i += 1) { for (size_t j = i; j < sqrt(n); j += i) { ... } }
```

On peut dans un premier temps penser à une petite optimisation. On sait que **presque** tous les nombres premiers sont impairs, tous sauf 2. On peut également déduire 
qu'il n'y a une seule possibilité où 2 est nécessaire ( *n = 4, n1 = 2, n2 = 2* ). Il nous suffit donc de créer une solution à part dans notre programme pour n = 4. Ainsi, on peut uniquement parcourir l'ensemble des nombres impairs :

```c++
for (size_t i = 3; i < sqrt(n): i += 2) { for (size_t j = i; j < sqrt(n); j += i) { ... } }
```

On ajoute également une dernière optimisation concernant la boucle en elle-même, on applique la fonction carré de chaque côté de l'égalité ( *j'avoue avoir du mal à comprendre, mais mon programme va bien plus vite sans la racine carré* ). On obtient finalement :

```c++
for (size_t i = 3; i*i < n: i += 2) { for (size_t j = i*i; j < n; j += i) { ... } }
```

## 2 - Stocker les nombres premiers

Le vecteur dans lequel sont nos nombres premiers (et non premier également) à la fin du crible peut se faire sous plusieurs formes. La manière la plus intuisitve serait de faire un vecteur d'entiers naturels en le remplissant de ``` 0 ``` et mettre par exemple ``` 1 ``` aux indices non premiers. Cette méthode a quelques défauts. Tout d'abord, un entier naturel peut prendre entre 2 et 4 octets de mémoire. De plus, lorsque l'on crée un vecteur d'entier naturel de taille n, ce dernier se remplie forcément de 0. 

On peut donc refaire le même procédés mais en remplaçant la liste d'entier par une chaine de caractère. Un charactère ne prend que 1 octet, ce qui est bien moins gourmand qu'un entier naturel. C'est donc un gain de mémoire et de temps. Il nous suffit donc de prendre la boucle plus haut est de remplacer un caractère qui n'est pas premier par un caractère quelconque (ici ``` 1 ```).

Une fois notre chaine de caractère obtenu, il faut maintenant 

_Working Progress ..._ ⛏️
