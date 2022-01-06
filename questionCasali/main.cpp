#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

typedef vector<unsigned> VU;
typedef vector<VU> VVU ;
typedef VU::iterator VUI ;

/* Consigne
 * Quelque soit un entier n pair, n est la somme de deux nombres premiers n1 et n2
 * Quelque que soit n, afficher (stocker) toutes les pairs de (n1, n2)
*/

bool estPremier(const unsigned & nbrDivise, const unsigned & maximum) {
    for (unsigned i = 2; i < maximum; i += 1) {
        //En partant de 2 car 2 est premier et jusqu à maximum
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
void afficherVVT(const vector<T> & vec) {
    for (const auto & i : vec) {
        for (const auto & j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}


VU creationNombrePremierN(const unsigned & n) {
    VU vuNombrePremier;
    for (unsigned i = 2; i < n; i += 1) {
        if (estPremier(i, n)) {
            //Si i est premier
            vuNombrePremier.push_back(i);
        }
    }
    return vuNombrePremier;
}

VVU vvuPair(const unsigned & n) {
    assert(n%2 == 0);   //On vérifie que n soit bien pair
    VUI n1;
    VUI n2;
    VVU vvuPairesDeNombres;
    VU vuNombrePremier = creationNombrePremierN(n);
    for (n1 = vuNombrePremier.begin(); n1 != vuNombrePremier.end(); ++n1) {
        for (n2 = vuNombrePremier.begin(); *n2 < n/2 + 1; ++n2) {
            //*itDeux < n/2 + 1 pour éviter les répétitions
            if(*n1 + *n2 == n) {
                VU vuNombreBon = {*n1, *n2};
                vvuPairesDeNombres.push_back(vuNombreBon);
            }
        }
    }
    return vvuPairesDeNombres;
}


int main()
{
    VVU vvuTest;
    unsigned n = 15000;
    vvuTest = vvuPair(n);
    afficherVVT(vvuTest);
    return 0;
}
