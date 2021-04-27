#include <iostream>
#include "fonctions.hpp"

const int NB_PIONS = 5;
const int NB_COULEURS = 7;
int joueur[NB_PIONS] = {1, 2, 4, 7, 6};
int machine[NB_PIONS] = {1, 2, 3, 5, 6};
int nbCoups = 12, coupCompteur = 0, bp = 0, mp = 0;
bool gagne = false;

int main ()
{

    init(machine, NB_PIONS, NB_COULEURS);
    //affiche(machine, NB_PIONS); //reponse attendue
    while (coupCompteur < nbCoups && gagne == false)
    {
        std::cout << "Tour n°" << coupCompteur << " / " << nbCoups << std::endl;
        lire(machine, NB_PIONS, NB_COULEURS);
        int bienPlaceResultat = bienplace(joueur, machine, NB_PIONS);
        std::cout << "Nb bien placés: " << bienPlaceResultat << std::endl;
        if(bienPlaceResultat == 5) {
            gagne = true;
            std::cout << "Vous avez gagné !: " << std::endl;
        } else {
            std::cout << "Nb mal placés: " << malplace(joueur, machine, NB_PIONS, NB_COULEURS) << std::endl;
        }
        coupCompteur++;
    }
    
    coupCompteur = 0;
    
    
    
    return 0;
}

