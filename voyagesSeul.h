#ifndef voyageSeulS_H
#define voyageSeulS_H

#include "voyageSeul.h"
#include <vector>
using namespace std;

class voyagesSeul
{
    private:
        vector<voyageSeul> tabVoyageSeul;
    public:
        voyagesSeul();
        ~voyagesSeul();
        int existe(string);
        bool ajouter_voyageSeul(voyageSeul);
        void afficher_voyagesSeul(clients&);
        voyageSeul& getVoyage(const string& idVoy);
        vector<string> afficher_voyages_client(const string& numPass);
        vector<string> afficher_futur_voyages_client(const string&);
        bool annuler_voyage(const string& idVoy);
        int retarder_voyages_seul(Date dep);
        void liste_voyages_pays(Destination dest);
        bool est_vide();
        void writeToFile();
        void readFile();
        vector<int> liste_des_annees();
        vector<int> nbre_desvoyages_seules_chaquemois(int);
        vector<int> nbre_desvoyages_seules_chaquesaison(int);
        int nb_voyagesSeul();
};

#endif 