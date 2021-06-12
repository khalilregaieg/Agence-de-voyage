#ifndef STATISTIQUES_AGENCE
#define STATISTIQUES_AGENCE

#include "destination.h"
#include "destinations.h"
#include "date.h"
#include "client.h"
#include "clients.h"
#include "voyage.h"
#include "voyageSeul.h"
#include "voyagesSeul.h"
#include "voyageEnGroupe.h"
#include "voyagesEnGroupe.h"
using namespace std;

vector<int> vecteur_unique(vector<int> a,vector<int> b);
int maximale(vector<int> a);
int minimale(vector<int> a);
vector<int> nbre_occurence(int a,vector<int> b);
void mois_correspondant(int i);
void la_periode_la_plus_demandee_par_annee(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul);
void la_periode_la_moins_demandee_par_annee(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul);
void afficher_lesvoyages_chaque_saison(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul);
void afficher_lesvoyages_seuls_chaque_saison(voyagesSeul& voy_seul);//les voyages seules seulements
void afficher_lesvoyages_engroupes_chaque_saison(voyagesEnGroupe& voy_en_grps);
void afficher_lemoyen_annuel_des_voyages(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul);
void afficher_lemoyen_annuel_des_voyages_engroupes(voyagesEnGroupe& voy_en_grps);
void afficher_lemoyen_annuel_des_voyages_seuls(voyagesSeul& voy_seul);
int somme_tableau(vector<int> a);
void afficher_lemoyen_mensuel_des_voyages(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul);
void afficher_lemoyen_mensuel_des_voyages_engroupes(voyagesEnGroupe& voy_en_grps);
void afficher_lemoyen_mensuel_des_voyages_seuls(voyagesSeul& voy_seul);


int get_indice_max(int [], int);
void tranche_age_frequente(clients&);

void afficher_nombre_clients_distincts(clients&);

void afficher_nombre_voyages_total(voyagesEnGroupe& , voyagesSeul&);
#endif
