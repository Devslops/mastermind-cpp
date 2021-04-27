
#include <iostream>
#include <ctime> //pour la fonction time
#include <cstdlib> // pour la fonction rand

void affiche(int tab[], int nb_pions) {
    if(nb_pions <= nb_pions) { //Dans la portée du tableau
        for(int i = 0; i < nb_pions; i++) {
            std::cout << tab[i] << std::endl;
        }
    } else { //Hors portée
        std::cout << "Vous chercher à afficher plus de pions qu'il y en a" << std::endl;
    }
}

void lire(int joueur[], int nb_pions, int nb_couleurs) {
    int nbEntrees = 0;
    int entree = 0;
    while (nbEntrees < nb_pions)
    {
        std::cout << "Entrer une couleur (entier) " << nbEntrees << std::endl;
        std::cin >> entree;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Veuillez renseigner un entier" << std::endl;
        } else if (entree < 0 || entree > nb_couleurs - 1) {
            std::cout << "Veuillez renseigner une couleur entre " << 0 << " et " << nb_couleurs << std::endl;
        } else {
            joueur[nbEntrees] = entree;
            nbEntrees++;
        }
    }
}

int bienplace(int joueur[], int machine[], int nb_pions) {
    int nbBienPlace = 0;
    for(int j = 0; j < nb_pions; j++) {
       if(joueur[j] == machine[j]) {
            nbBienPlace++;
        } 
    }
    return nbBienPlace;
}

int malplace(int joueur[], int machine[], int nb_pions, int nb_couleurs) {
    int malplaces = 0;
    int cj = 0;//Nb fois couleur dans joueur
    int cm = 0;//Nb fois couleur dans machine

    for(int i = 0; i < nb_couleurs - 1; i++) { //Pour chaque couleur
        
        for(int j = 0; j < nb_pions; j++) { 
            if(joueur[j] == i) cj++;
        }

        for(int j = 0; j < nb_pions; j++) { 
            if(machine[j] == i) cm++;
        }

        //Malplace = min(cj/cm)
        if(cj < cm) {
            malplaces =  cj;
        } else malplaces = cm;
    }
     return malplaces;
}

void init(int machine[], int nb_pions, int nb_couleurs) {
    for(int i = 0; i < nb_pions; i++) {
        srand (time(NULL));
        int couleurAleat = rand() % nb_couleurs;
        machine[i] = couleurAleat;
    }
}