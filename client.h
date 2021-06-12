#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>
#include "date.h"
using namespace std;

class client
{
    private:
        string numPasseport;
        string Nom;
        string Prenom;
        Date DateNaissance;
        vector<string> VoyagesClient; // vecteur contenant les idVoyage du client
    public:
        client();
        client(const string&, const string&, const string&, Date);
        ~client();
        string getNumPasseport();
        string getNom();
        string getPrenom();
        Date getDateNaissance();
        vector<string> getVoyagesClient();
        bool ajouter_voyage(string idVoy);
        int participe_au_voyage(string idVoy); // retourne la pos du voyage dans VoyagesClient si le voy existe sinon -1
        friend ostream& operator<<(ostream&, const client&);//affiche le client (sans afficher les voyages)
        int getAge();
        void annuler_voyage(const string& idVoy); // annule le voyage pour le client si il y participe
        ostream& write(ostream&);
        istream& read(istream&);
};



/**** autres fonctions ****/
bool est_majus(const string&);
bool est_numPasseport(const string&); //verifie si une chaine est un numPass valide
string saisir_numPasseport();  //saisir un num Pass a partir du clavier


ostream& writeVect(vector<string>&, ostream&);
istream& readVect(vector<string>&, istream&);

#endif