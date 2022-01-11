#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>


using namespace std;

typedef vector<vector<unsigned>> VVU ;


/* Consigne
 * Quelque soit un entier n pair, n est la somme de deux nombres premiers n1 et n2 (conjecture de Goldbach)
 * Quelque que soit n, afficher (stocker) toutes les pairs de (n1, n2)
*/


bool estPremier(const unsigned & nbr, const unsigned & maximum) {
    for (unsigned i = 2; i < sqrt(maximum); i += 1) {
        //En partant de 2 car 2 est premier et jusqu à sqrt(maximum)
        if (nbr%i == 0) {
            //Si i divise nbr
            if (i != nbr) {
                //Et que i et nbr ne sont pas les memes chiffres/nombres
                return false;
                //Alors nbr est pas premier
            }
        }
    }
    return true;
    //nbr est premier
}


template <typename T>
void afficherVV(const vector<T> & vec) {
    for (const auto & i : vec) {
        for (const auto & j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}


VVU Goldbach(const unsigned & n) {
    assert(n%2 == 0);   //On vérifie d'abord si n est pair
    VVU vvuPairesDeNombres;
    //On teste pour n = 4 ici car, notre boucle va faire un saut de 2 en partant de trois pour aller chercher le plus petit impair à chaque fois
    //Et le seul cas où 2 est nécessaire c'est si n = 4 car 4 = 2 + 2
    if (n == 4) {
        vvuPairesDeNombres.push_back({2, 2});
        return vvuPairesDeNombres;
    }
    for (unsigned n1 = 3; n1 < n/2 + 1; n1 += 2) {
        //On fait n1 < n/2 +1 car on vaut éviter les répétitions
        if(estPremier(n1, n)) {
            //Si n1 est un nombre premier
            unsigned n2 = n - n1;
            if (estPremier(n2, n)) {
                //Si n2 est un nombre premier
                vvuPairesDeNombres.push_back({n2, n1});
            }
        }
    }
    return vvuPairesDeNombres;
}




/*Fonction permettant de vérifier si tous les éléments d'un VVU sont premiers

bool verification(const VVU & vecTest, const unsigned & n) {
    for (unsigned i = 0; i < vecTest.size(); ++i) {
        for (unsigned j = 0; j < vecTest[i].size(); ++j) {
            if (!estPremier(vecTest[i][j], n)) {
                return false;
            }
        }
    }
    return true;
}
*/

int main() {
    VVU vvuTest;
    unsigned n = 1000000;
    vvuTest = Goldbach(n);
    afficherVV(vvuTest);
    //cout << "VVU que nombres premiers : " << boolalpha << verification(vvuTest, n) << endl;
    return 0;
}