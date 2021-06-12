#ifndef VOYAGESEUL_H
#define VOYAGESEUL_H

#include "destination.h"
#include "date.h"
#include "clients.h"
#include "voyage.h"
#include <string>
using namespace std;

class voyageSeul : public voyage
{
    protected:
        string numPasseport;
    public:
        voyageSeul();
        voyageSeul(const string&, const string& numPass, Destination, Date, Date );
        string getNumPasseport();
        void afficher_voyage();
        ostream& write(ostream&);
        istream& read(istream&);
};

#endif