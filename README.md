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

Le crible d'Ératosthène est une méthode permettant de déterminer une liste de nombres premiers. Pour se faire, on prend une liste partant de 2 jusqu'à notre entier **n**. Ensuite, en partant de 2, il suffit de cocher tous les multiples du chiffre / nombre que l'on étudie (au premier tour ce sera 2, enlevant ainsi tous les chiffres / nombres pairs). 

On réitère l'opération en prenant le prochain entier non coché dans la liste. À noter que dans le crible d'Ératosthène

<img alt="GIF" src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8c/New_Animation_Sieve_of_Eratosthenes.gif/440px-New_Animation_Sieve_of_Eratosthenes.gif" /> 

_Working Progress ..._ ⛏️
