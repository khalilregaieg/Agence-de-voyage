#include "destination.h"
using namespace std;

/**** Méthodes de la classe Destination ****/
Destination::Destination(){}
Destination::Destination(const string& p, const string& v)
{
    Pays = p;
    Ville = v;
}

Destination::~Destination(){}

string Destination::getPays()
{
    return Pays;
}

string Destination::getVille()
{
    return Ville;
}

void Destination::setPays(const string& p)
{
    Pays = p;
}

void Destination::setVille(const string& v)
{
    Ville = v;
}

bool Destination::operator==(const Destination& dest)
{
    if ((Pays==dest.Pays) && (Ville == dest.Ville))
        return true;
    return false;
}

ostream& operator<<(ostream& output, const Destination& dest)
{
    output << dest.Pays << ", " << dest.Ville;
    return output ;
}


ostream& Destination::write(ostream& out)
{
    out << Pays << " " << Ville ;
    return out;
}

istream& Destination::read(istream& in)
{
    in >> Pays >> Ville;
    return in;
}