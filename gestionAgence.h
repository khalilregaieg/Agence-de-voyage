#ifndef GESTIONAGENCE_H
#define GESTIONAGENCE_H

#include "destination.h"
#include "destinations.h"
#include "date.h"
#include "client.h"
#include "clients.h"
#include "voyage.h"
#include <limits>
#include "voyageSeul.h"
#include "voyagesSeul.h"
#include "voyageEnGroupe.h"
#include "voyagesEnGroupe.h"
using namespace std;


// gestion destinations
//méthodes permettant à l'utilisateur de gérer les destinations possibles
void menu_gestion_destinations();
void gerer_destinations(Destinations&);
Destination choisir_destination( Destinations&); // saisir une parmis les destinations disponibles




//Gestion des groupes : créations de nouveaux voyages en groupe
void menu_gestion_groupe();
void gerer_groupes(voyagesEnGroupe&, Destinations&, clients&);
void saisir_voyage_en_groupe(voyagesSeul&, voyagesEnGroupe&, Destinations&);
void annuler_voyage_groupe(voyagesEnGroupe&, clients&);


/* Gestion des clients :
    * si ancien client : afficher un menu (afficher ou ajouter les voyages)
    * si nouveau client : saisir ses infos puis ajouter un voyage puis afficher un menu
*/
string generer_id_voyage_groupe(voyagesEnGroupe&);
string generer_id_voyage_seul(voyagesSeul&);
void gerer_clients(clients&, voyagesSeul&, voyagesEnGroupe&, Destinations&);
void menu_ancien_client();

// crée un nouveau voyage et l'ajoute
void nouveau_voyage(const string& numpPass, clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDestinations);
void voyager_en_groupe(const string& numPass, clients&, voyagesSeul&, voyagesEnGroupe&, Destinations&);
string saisir_idVoyage_groupe(vector<string>&);
int existe(vector<string>&, const string&);
void afficher_voyages_client(const string& numPass,clients&, voyagesSeul&, voyagesEnGroupe&);
vector<string> afficher_futur_voyages_client(const string& numPass,clients&, voyagesSeul&, voyagesEnGroupe&);
bool en_groupe(string);
void annuler_voyage_client(const string&, clients&, voyagesSeul&, voyagesEnGroupe&);
string saisir_id_voyage_client(vector<string>&);
void gerer_ancien_client(const string& numPass, clients&, voyagesSeul&, voyagesEnGroupe&, Destinations&);


/********** reste des fonctions ******/
void afficher_tous_les_voyages(voyagesSeul&, voyagesEnGroupe&, clients&); // affiche tous les voyages de l'agence
void retarder_tous_les_voyages(voyagesSeul&,voyagesEnGroupe&);            // retarde tous les voyages pour une date donnée d'une période donnée
void liste_voyages_pays(voyagesSeul&, voyagesEnGroupe&, Destinations&);// 

void client_gagnant(voyagesSeul&,voyagesEnGroupe&, clients&, Destinations&);

#endif

