#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>
#include <chrono>


using namespace std;

typedef vector<bool> VB ;
typedef vector<unsigned> VU;
typedef VU::iterator VUI ;
typedef vector<VU> VVU ;


/* Consigne
 * Quelque soit un entier n pair, n est la somme de deux nombres premiers n1 et n2 (conjecture de Goldbach)
 * Quelque que soit n, afficher (stocker) toutes les pairs de (n1, n2)
*/


bool estPremier(const unsigned & nbr, const unsigned & maximum) {
    for (unsigned i = 2; i*i < maximum; i += 1) {
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

VU cribleEraV2(const unsigned & n) {
    assert(n%2 == 0);
    VU vecBool(n, 1);
    VU vecTest;
    for (unsigned i = 3; i*i < n; i += 2) {
        if (vecBool[i] == 1) {
            for (unsigned j = i*i; j < n ; j += i) {
                vecBool[j] = 0;
            }
        }
    }
    for (unsigned i = 3; i < n/2 + 1; i += 2) {
        if (vecBool[i] == 1) {
            vecTest.push_back(i);
        }
    }
    return vecTest;
}



VVU goldbachV2(const unsigned & n, VU & vecNP) {
    VVU vvuPaireNP;
    if (n == 4) {
        //Seul cas où 2 forme une paire pour un entier pair
        return {{2, 2}};
    }
    for (const unsigned & n1 : vecNP) {
        unsigned n2 = n - n1;
        if (estPremier(n2, n)) {
            vvuPaireNP.push_back({n2, n1});
        }
    }
    return vvuPaireNP;
}


//Fonction permettant de vérifier si tous les éléments d'un VVU sont premiers

template <typename T>
bool verification(const vector<T> & vecTest, const unsigned & n) {
    for (const auto & i : vecTest) {
        for (const auto & j : i) {
            if (!estPremier(j, n)) {
                return false;
            }
        }
    }
    return true;
}



int main() {
    /*
     * n = 1 000 000, temps = 0.037 secondes
     * n = 10 000 000, temps = 0.7 secondes
     * n = 100 000 000, temps = 14 secondes
    */
    unsigned n = 100000000;
    auto debut = chrono::system_clock::now();
    VU vecT = cribleEraV2(n);
    VVU  vvuTest = goldbachV2(n, vecT);
    auto fin = chrono::system_clock::now();
    afficherVV(vvuTest);
    cout << "Temps : " << chrono::duration_cast<chrono::milliseconds>(fin - debut).count() << " millisecondes" << endl;
    //cout << "VVU nombre premiers : " << boolalpha << verification(vvuTest, n) << endl;
    return 0;
}
