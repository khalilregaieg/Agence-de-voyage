#include "voyage.h"
using namespace std;

voyage::voyage(){};
voyage::voyage(const string& id, Destination d, Date dep, Date ret)
{
    idVoyage = id;
    Dest = d;
    dateDepart = dep;
    dateRetour = ret;
}

string voyage::getIdVoyage()
{
    return idVoyage;
}


Destination voyage::getDestination()
{
    return Dest;
}

Date voyage::getDateDepart()
{
    return dateDepart;
}


Date voyage::getDateRetour()
{
    return dateRetour;
}

void voyage::afficher_voyage()
{
    cout << "   *IdVoyage       : " << idVoyage << endl;
    cout << "   -Destination    : " << Dest << endl;
    cout << "   -Date de depart : " << dateDepart;
    cout << "   -Date de retour : " << dateRetour;
}


void voyage::retarder_voyage()
{
    Date dep;
    do
    {
        cout << " Donner la nouvelle date de départ " << endl;
        cout << " ---> ";
        dep = saisir_date();
    }
    while ((dep < dateDepart) || (dep == dateDepart));
    int diff = difference_date(dateDepart, dep);
    dateDepart = dep;
    dateRetour = ajouter_nbJours(dateRetour, diff);
}