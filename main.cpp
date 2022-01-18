#include <iostream>
#include <vector>
#include <assert.h>
#include <chrono>


using namespace std;

typedef vector<unsigned> VU;
typedef vector<VU> VVU ;


/* Consigne
 * Quelque soit un entier n pair, n est la somme de deux nombres premiers n1 et n2 (conjecture de Goldbach)
 * Quelque que soit n, afficher (stocker) toutes les pairs de (n1, n2)
*/



bool estPremierV2(const unsigned & n2, const VU & vec) {
    //Si l'élément à l'indice n2 est autre que 0, alors n2 est premier
    return (vec[n2] != 0);
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

VU cribleEraV2(const unsigned & n, VU & vecTest) {
    assert(n%2 == 0);
    VU vecQueDesUn(n, 1);
    //On crée un vecteur avec uniquement des 1
    for (unsigned i = 3; i*i < n; i += 2) {
        if (vecQueDesUn[i] == 1) {
            //Si il y a 1
            for (unsigned j = i*i; j < n ; j += i) {
                //j devient un multiple de i
                vecQueDesUn[j] = 0;
            }
        }
    }
    for (unsigned i = 3; i < n/2 + 1; i += 2) {
        if (vecQueDesUn[i] == 1) {
            vecTest.push_back(i);
        }
    }
    return vecQueDesUn;
}



vector<vector<unsigned>> goldbachV2(const unsigned & n, VU & vecNP, const VU & vecNombreBien) {
    //Algo qui va donner les pairs en gros
    VVU vvuPaireNP;
    if (n == 4) {
        //Seul cas où 2 forme une paire pour un entier pair
        return {{2, 2}};
    }
    for (const unsigned & n1 : vecNombreBien){
        //On parcourt le vecteur avec un itérateur à la position 3 (car il y a 3) et on incrémente de deux pour chercher le plus petit impair
        unsigned n2 = n - n1;
        if (estPremierV2(n2, vecNP)) {
            //Si n2 est premier
            vvuPaireNP.push_back({n2, n1});
        }
    }
    return vvuPaireNP;
}

int main() {
    /*
     * n = 1 000 000, temps = 0.01 secondes
     * n = 10 000 000, temps = 0.253 secondes
     * n = 100 000 000, temps = 2,4 secondes
    */
    unsigned cmpt = 0;
    unsigned n = 1000000;
    auto debut = chrono::system_clock::now();
    VU vecTest;
    VU vecT = cribleEraV2(n, vecTest);
    VVU  vvuTest = goldbachV2(n, vecT, vecTest);
    auto fin = chrono::system_clock::now();
    //afficherVV(vvuTest);
    cout << "Temps : " << chrono::duration_cast<chrono::milliseconds>(fin - debut).count() << " millisecondes" << endl;
    return 0;
}

