#include "voyageSeul.h"
using namespace std;

voyageSeul::voyageSeul(){};
voyageSeul::voyageSeul(const string& id,const string& numPass, Destination d, Date dep, Date ret)
{
    idVoyage = id;
    numPasseport = numPass;
    Dest = d;
    dateDepart = dep;
    dateRetour = ret;
}


string voyageSeul::getNumPasseport()
{
    return numPasseport;
}


void voyageSeul::afficher_voyage()
{
    cout << "   *IdVoyage       : " << idVoyage << endl;
    cout << "   -Destination    : " << Dest << endl;
    cout << "   -Date de depart : " << dateDepart;
    cout << "   -Date de retour : " << dateRetour << endl;
}


ostream& voyageSeul::write(ostream& out)
{
    out << numPasseport << " " << idVoyage << " ";
    Dest.write(out);
    out << " ";
    dateDepart.write(out);
    out << " ";
    dateRetour.write(out);
    out << " ";
    return out;
}

istream& voyageSeul::read(istream& in)
{
    in >> numPasseport >> idVoyage ;
    Dest.read(in);
    dateDepart.read(in);
    dateRetour.read(in);
    return in;
}
