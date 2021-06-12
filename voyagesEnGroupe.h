#ifndef VOYAGESENGROUPE_H
#define VOYAGESENGROUPE_H

#include "voyage.h"
#include <vector>
#include "voyageEnGroupe.h"
#include "destination.h"
#include "date.h"
using namespace std;

class voyagesEnGroupe
{
    private:
        vector<voyageEnGroupe> tabVoyageEnGroupe;
    public:
        voyagesEnGroupe();
        ~voyagesEnGroupe();
        int existe(string idVoy);
        bool ajouter_voyageEnGroupe(voyageEnGroupe);
        void afficher_groupes();
        void afficher_groupes(Destination);
        int nb_voyagesEnGroupe();
        vector<string> groupes_disponibles(); //affiche tous les groupes disponibles et retourne les id dans un vecteur
        vector<string> groupes_disponibles(Destination);// affiche les groupes disponible pour une destination et retourne les id dans un vecteur
        vector<string> tous_les_groupes();
        bool existe_groupes_disponibles();
        bool existe_groupes_disponibles(Destination);
        voyageEnGroupe& getVoyage(const string& idVoy);
        void annuler_voyage(const string&); //supprime le voyage de tab!voyageEngroupe à partir de l'id
        vector<string> afficher_voyages_client(const string&);
        vector<string> afficher_futur_voyages_client(const string&);
        bool est_vide();
        int retarder_voyages_en_groupe(Date dep);
        void writeToFile();
        void readFile();

        vector<int> liste_des_annees();
        vector<int> nbre_desvoyages_engroupes_chaquemois(int annee);
        vector<int> nbre_desvoyages_engroupes_chaquesaison(int annee);
};


#endif