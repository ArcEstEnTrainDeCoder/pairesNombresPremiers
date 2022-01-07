#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>

using namespace std;

typedef vector<unsigned> VU;
typedef vector<VU> VVU ;
typedef VU::iterator VUI ;

/* Consigne
 * Quelque soit un entier n pair, n est la somme de deux nombres premiers n1 et n2
 * Quelque que soit n, afficher (stocker) toutes les pairs de (n1, n2)
*/

bool estPremier(const unsigned & nbrDivise, const unsigned & maximum) {
    for (unsigned i = 2; i < sqrt(maximum); ++i) {
        //En partant de 2 car 2 est premier et jusqu à sqrt(maximu)
        if (nbrDivise%i == 0) {
            //Si i divise nbrDivise
            if (i != nbrDivise) {
                //Et que i et nbrDivise ne sont pas les memes chiffres/nombres
                return false;
                //Alors nbrDivise n est pas premier
            }
        }
    }
    return true;
    //nbrDivise est premier
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


VU creationNombrePremierN(const unsigned & n) {
    VU vuNombrePremier;
    for (unsigned i = 2; i < n; ++i) {
        if (estPremier(i, n)) {
            //Si i est premier, on l'ajoute au vecteur
            vuNombrePremier.push_back(i);
        }
    }
    return vuNombrePremier;
}



VVU vvuPair(const unsigned & n) {
    assert(n%2 == 0);   //On vérifie si n est bien pair
    VVU vvuPairesDeNombres;
    VU vuNombresPremiers = creationNombrePremierN(n);
    for (VUI n1 = vuNombresPremiers.begin(); *n1 < n/2 + 1; ++n1) {
        //On prend *n1 < n/2 + 1 pour éviter les répétitions de paires
        unsigned n2 = n - *n1;
        //On soustrait n car on sait qu'il est l'addition de deux nombres premiers
        if (estPremier(n2,n)) {
            //Si le résultat de la soustraction est premier, on ajoute la paire à notre VVU
            vvuPairesDeNombres.push_back({n2, *n1});
        }
    }
    return vvuPairesDeNombres;
}

/* Fonction permettant de vérifier si tous les éléments d'un VVU sont premiers

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
    unsigned n = 100000;
    vvuTest = vvuPair(n);
    afficherVV(vvuTest);
    //cout << "Le VVU contient uniquement des nombres premiers : "<< boolalpha << verification(vvuTest, n) << endl;
    return 0;
}
