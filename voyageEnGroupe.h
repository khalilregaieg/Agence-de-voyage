#ifndef VOYAGEENGROUPE_H
#define VOYAGEENGROUPE_H

#include "voyage.h"
#include "client.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class voyageEnGroupe : public voyage
{
    private:
        vector<string> participants;
    public:
        voyageEnGroupe();
        voyageEnGroupe(const string&, Destination, Date, Date);
        ~voyageEnGroupe();
        int est_paticipant(string numPass);// position si il existe et -1 sinon
        bool ajouter_participant(string numPass);
        void afficher_voyage();
        vector<string> getParticipants();
        int nb_participants();
        ostream& write(ostream&);
        istream& read(istream&);
};

#endif