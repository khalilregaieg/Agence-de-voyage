#include "destinations.h"


/**** Méthodes de la classe Destinations ****/

Destinations::Destinations(){}

Destinations::~Destinations(){}

int Destinations::existe(const Destination& dest)
{
    for(int i=0; i<tabDestination.size(); i++)
        if (tabDestination[i] == dest)
            return i;
    return -1;
}

bool Destinations::ajouter_destination(const Destination& dest)
{
    if (existe(dest) == -1)
    {
        tabDestination.push_back(dest);
        return true;
    }
    return false;
}

bool Destinations::supprimer_destination(const Destination& dest)
{
    if (existe(dest) != -1)
    {
        int pos = existe(dest);
        for (int i=pos; i<tabDestination.size()-1; i++)
            tabDestination[i] = tabDestination [i+1];
        tabDestination.pop_back();
        return true;
    }
    return false;
        
}

ostream& operator<<(ostream& output, const Destinations& d)
{
    if (d.tabDestination.empty())
        output << "   *  Aucune destination" << endl;
    else
    {
        for (int i=0; i < d.tabDestination.size(); i++)
            output << "   *  " << d.tabDestination[i] << endl;
    }
    return output;
}


void Destinations::saisir_destination()
{
    cout <<"--->  Donner le pays de la destination à ajouter :  ";
    string p;
    cin >> p;
    cout << "--->  Donner le nom de la ville :  ";
    string v;
    cin >> v;
    Destination dest (p, v);
    if (ajouter_destination(dest))
        cout << "La destination " << dest <<" à bien été ajoutée" << endl;
    else
        cout << "La destination " << dest <<" n'a pas pu être ajoutée" << endl;
}

void Destinations::enlever_destination()
{
    cout <<"Donner le pays de la destination à enlever :  ";
    string p;
    cin >> p;
    cout << "Donner le nom de la ville :  ";
    string v;
    cin >> v;
    Destination dest (p, v);
    if (supprimer_destination(dest))
        cout << "La destination " << dest <<" à bien été enlevée" << endl;
    else
        cout << "La destination " << dest <<" n'a pas pu être enlevée" << endl;
}

bool Destinations::est_vide()
{
    if (tabDestination.size()==0)
        return true;
    else
        return false;
}

int Destinations::nb_dest()
{
    return tabDestination.size();
}

Destination& Destinations::getDest(int i)
{
    return tabDestination[i];
}



void Destinations::writeToFile()
{
    //1ere ligne est le nbre de destinations
    ofstream out;
    out.open("fichier_Destinations.txt",ios::trunc);
    out << tabDestination.size() << endl;
    for (int i=0; i<tabDestination.size();i++)
    {
        tabDestination[i].write(out);
        out << endl;
    }
    out.close();
}

void Destinations::readFile()
{
    ifstream in;
    in.open("fichier_Destinations.txt");
    if (in.is_open())
    {
        int nb;
        in >> nb;
        for (int i=0; i < nb; i++)
        {
            Destination dest;
            dest.read(in);
            tabDestination.push_back(dest); 
        }
        in.close();
    }
}