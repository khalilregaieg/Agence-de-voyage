#include "client.h"
#include "clients.h"
#include "voyage.h"
#include "voyageSeul.h"
#include "voyagesSeul.h"
#include "voyageEnGroupe.h"
#include "voyagesEnGroupe.h"
#include "destination.h"
#include "destinations.h"
#include "date.h"
#include "gestionAgence.h"

#include "menuPrincipal.h"

#include "fstream"

#include <iostream>
using namespace std;

int main()
{   
    //les 4 conteneurs sur lesquelles les modifications auront lieu
    Destinations tabDestinations;
    clients tabClient;
    voyagesSeul tabVoyageSeul;
    voyagesEnGroupe tabVoyageEngroupe;


    //charger les conteneurs à partir des fichiers s'ils existent
    //sinon on crée les fichiers
    tabDestinations.readFile();
    tabClient.readFile();
    tabVoyageSeul.readFile();
    tabVoyageEngroupe.readFile();


    //exécution du programme
    menu_principal(tabClient, tabVoyageSeul, tabVoyageEngroupe, tabDestinations);


    //enregistrer les 4 conteneurs dans les fichiers
    tabDestinations.writeToFile();
    tabClient.writeToFile();
    tabVoyageSeul.writeToFile();
    tabVoyageEngroupe.writeToFile();
}