#ifndef VOYAGE_H
#define VOYAGE_H

#include "destination.h"
#include "date.h"
#include <string>
#include <cstdlib>
using namespace std;


class voyage
{
    protected:
        string idVoyage;
        Destination Dest;
        Date dateDepart;
        Date dateRetour;

    public:
        voyage();
        voyage(const string&, Destination, Date, Date );
        string getIdVoyage();
        Destination getDestination();
        Date getDateDepart();
        Date getDateRetour();
        void afficher_voyage();
        void retarder_voyage();
};

#endif
