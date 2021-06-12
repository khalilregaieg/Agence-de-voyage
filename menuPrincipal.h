#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <iostream>
#include <limits>
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
#include "gestionAgence.h"
#include "statistiquesAgence.h"
using namespace std;

void menu_principal(clients&, voyagesSeul&, voyagesEnGroupe&, Destinations&);
void gerer_agence(clients&, voyagesSeul&, voyagesEnGroupe&, Destinations&);
void afficher_statistiques(clients&, voyagesSeul&, voyagesEnGroupe&, Destinations&);
#endif