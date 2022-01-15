#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>
#include <chrono>


using namespace std;

typedef vector<bool> VB ;
typedef vector<unsigned> VU;
typedef vector<VU> VVU ;


/* Consigne
 * Quelque soit un entier n pair, n est la somme de deux nombres premiers n1 et n2 (conjecture de Goldbach)
 * Quelque que soit n, afficher (stocker) toutes les pairs de (n1, n2)
*/


bool estPremier(const unsigned & nbr, const unsigned & maximum) {
    for (unsigned i = 2; i*i < maximum; i += 1) {
        //En partant de 2 car 2 est premier et jusqu à maximum 
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

VU cribleEra(const unsigned & n) {
    assert(n%2 == 0);
    VB vecBool(n, true);
    VU vecTest;
    for (unsigned i = 3; i*i < n; i += 2) {
        //On démarre de 3 et incrémente de deux pour aller chercher le plus petit impair, 2 est le seul nombre premier pair il sera donc traité à part
        if (vecBool[i]) {
            for (unsigned j = i*i; j < n; j += i) {
                //j devient un multiple de i car incrémenté de i
                vecBool[j] = false;
            }
        }
    }
    for (unsigned i = 3; i < n/2 + 1; i += 2) {
        //Jusqu'à n/2 + 1 pour éviter les doublons
        if (vecBool[i]) {
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


/*Fonction permettant de vérifier si tous les éléments d'un VVU sont premiers

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
*/


int main() {
    /*
     * n = 1 000 000, temps = 0.061 secondes
     * n = 10 000 000, temps = 0.9 secondes
     * n = 100 000 000, temps = 16 secondes
    */
    unsigned n = 1000000;
    //J'ai mis auto parce que j'avais aucune idée de quoi mettre
    auto debut = chrono::system_clock::now();
    VU vecT = cribleEra(n);
    VVU  vvuTest = goldbachV2(n, vecT);
    auto fin = chrono::system_clock::now();
    afficherVV(vvuTest);
    cout << "Temps : " << chrono::duration_cast<chrono::milliseconds>(fin - debut).count() << " millisecondes" << endl;
    //cout << "VVU nombre premiers : " << boolalpha << verification(vvuTest, n) << endl;
    return 0;
}
