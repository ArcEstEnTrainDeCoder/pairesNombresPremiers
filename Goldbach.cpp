#include <iostream>
#include <vector>
#include <assert.h>
#include <chrono>


using namespace std;

typedef vector<string> VS;
typedef vector<unsigned> VU;
typedef vector<VU> VVU ;


/* Consigne
 * Quelque soit un entier n pair, n est la somme de deux nombres premiers n1 et n2 (conjecture de Goldbach)
 * Quelque que soit n, afficher (stocker) toutes les pairs de (n1, n2)
*/

int main() {
    /* Temps records :
     * n = 1 000 000, temps = 0.008 secondes
     * n = 10 000 000, temps = 0.103 secondes
     * n = 100 000 000, temps = 1,5 secondes
     * n = 1 000 000 000, temps = 18,1 secondes
    */
    const unsigned n = 1000000000;
    string vecQueDesUn;
    vecQueDesUn.resize(n);
    //On crée une chaine de caractère de taille n 
    VU vecTest;
    VVU vvuPaireNP;
    auto debut = chrono::system_clock::now();
    if (n == 4) {
        //Seul cas où 2 forme une paire pour un entier pair
        vvuPaireNP.push_back({2,2});
        return 0;
    }
    /*  Début criblage */
    for (size_t i = 3; i*i < n; i += 2) {
        //On démarre à 3 car 2 a été traité juste avant, on incrémente de deux pour venir chercher le plus petit impair car tout les autres nombres premiers sont impairs
        if (vecQueDesUn[i] == vecQueDesUn[n+ 1]) {
            //Si il n'y a rien à l'indice i
            for (size_t j = i*i; j < n ; j += i) {
                //j devient un multiple de i
                vecQueDesUn[j] = '1';
            }
        }
    }
    //On ressort donc avec une chaine de caractère avec des '1' à l'indice de nombres non premiers

    //On va venir prendre ces indices pour les mettres dans un second vecteur qui a comme taille le nombre de nombres premiers de 3 à n/2 + 1
    for (size_t i = 3; i < n/2 + 1; i += 2) {
        if (vecQueDesUn[i] == vecQueDesUn[n+ 1]) {
            //Si l'indice est premier, on l'ajoute au vecteur
            vecTest.push_back(i);
        }
    }
    //On ressort donc avec un vecteur d'indice premiers et une chaine de carctère qui est un gruyère de 1

    /* Fin criblage */

    for (const unsigned & n1 : vecTest){
        //On prend n1 dans le vecteur de nombres premiers
        unsigned n2 = n - n1;
        if (vecQueDesUn[n2] == vecQueDesUn[n+ 1]) {
            //Si n2 est premier, c'est-à-dire que l'on trouve rien à l'indice n2 dans la chaine de caractères
            vvuPaireNP.push_back({n2, n1});
        }
    }  
    auto fin = chrono::system_clock::now();
    for (auto & i : vvuPaireNP) {
        for (auto & j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << "Temps : " << chrono::duration_cast<chrono::milliseconds>(fin - debut).count() << " millisecondes" << endl;
    return 0;
}

