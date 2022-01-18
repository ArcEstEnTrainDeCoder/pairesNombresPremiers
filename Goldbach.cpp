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

/*
void afficherVV(const VVU & vec) {
    for (auto & i : vec) {
        for (auto & j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}


int main() {
    /*
     * n = 1 000 000, temps = 0.008 secondes
     * n = 10 000 000, temps = 0.170 secondes
     * n = 100 000 000, temps = 1,9 secondes
     * n = 1 000 000 000, temps = 24 secondes
    */
    unsigned n = 100000000;
    VU vecQueDesUn(n, 1);
    VU vecTest;
    VVU vvuPaireNP;
    auto debut = chrono::system_clock::now();
    //On crée un vecteur avec uniquement des 1
    if (n == 4) {
        //Seul cas où 2 forme une paire pour un entier pair
        vvuPaireNP.push_back({2,2});
        //afficherVV(vvuPaireNP);
        return 0;
    }
    
    /* Début criblage */ 
    for (unsigned i = 3; i*i < n; i += 2) {
        //On démarre à 3 car 2 a été traité juste avant, on incrémente de deux pour venir chercher le plus petit impair car tout les autres nombres premiers sont impairs
        if (vecQueDesUn[i] == 1) {
            //Si il y a 1 à l'indice
            for (unsigned j = i*i; j < n ; j += i) {
                //j devient un multiple de i
                vecQueDesUn[j] = 0;
            }
        }
    }
    //On ressort donc avec un vecteur de taille n remplie de 0 sauf aux indices qui sont des nombres premiers

    //On va venir prendre ces indices pour les mettres dans un second vecteur qui a comme taille le nombre de nombres premiers de 3 à n/2 + 1
    for (unsigned i = 3; i < n/2 + 1; i += 2) {
        if (vecQueDesUn[i] == 1) {
            //Si l'indice est premier, on l'ajoute au vecteur
            vecTest.push_back(i);
        }
    }
    
    /* Fin criblage */ 
    
    //On ressort donc avec nos deux vecteurs, un de nombres premiers et un second d'indice de nombre premier

    for (const unsigned & n1 : vecTest){
        //On prend n1 dans le vecteur de nombres premiers
        unsigned n2 = n - n1;
        if (vecQueDesUn[n2] != 0) {
            //Si n2 est premier, c'est-à-dire que l'on retrouve 1 à l'indice n2 dans le vecteur
            vvuPaireNP.push_back({n2, n1});
        }
    }  
    auto fin = chrono::system_clock::now();
    //afficherVV(vvuTest);
    cout << "Temps : " << chrono::duration_cast<chrono::milliseconds>(fin - debut).count() << " millisecondes" << endl;
    return 0;
}

