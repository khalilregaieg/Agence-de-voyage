#ifndef CLIENTS_H
#define CLIENTS_H

#include <vector>
#include <string>
#include "date.h"
#include "client.h"
#include <fstream>
using namespace std;


class clients
{
    public:
        vector<client> tabClient;
    public:
        clients();
        ~clients();
        int existe(const string&); //basé sur numPasseport (retourne la position ou bien -1)
        bool ajouter_client( client );
        bool supprimer_client(const string&);//supprime un client à partir de son numPasseport
        void saisir_client(const string& numPass);//crée un client et l'ajoute à tabclient
        client& getClient(string numPass);
        client& get_ieme_client(int i);
        void annuler_voyage(const string& idVoy); // supprime un voyage de tous les clients si il s'agit d'un voy en groupe
        string numPass_client_gagnant();
        vector<int> agesClients();
        int nb_clients();
        void writeToFile(); // ecrire l'objet dans un fichier
        void readFile();    // lire l'objet du fichier
};



#endif