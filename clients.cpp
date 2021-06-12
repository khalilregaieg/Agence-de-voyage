
#include "clients.h"
#include <stdlib.h>
#include <cmath>
using namespace std;

/**** Méthodes de la classe clients ****/
clients::clients(){};
clients::~clients(){};

int clients::existe(const string& numPass)
{
    for (int i=0; i<tabClient.size(); i++)
        if (tabClient[i].getNumPasseport() == numPass)
            return i;
    return -1;
}

bool clients::ajouter_client( client c )
{
    if (existe(c.getNumPasseport()) != -1)
        return false;
    else
    {
            tabClient.push_back(c);
            return true;
    } 
}

bool clients::supprimer_client(const string& numPass)
{
    if (existe(numPass) == -1)
        return false;
    else
    {
        int pos = existe(numPass);
        for (int i=pos; i < tabClient.size()-1; i++)
            tabClient[i] = tabClient[i+1];
        tabClient.pop_back();
        return true;
    }
}

void clients::saisir_client(const string& numPass)
{
    cout << "--->  Donner le nom du client : ";
    string n;
    cin >> n;
    cout << "--->  Donner le prénom du client : " ;
    string p;
    cin >> p;
    cout << "--->  Donner la date de naissance (jj/mm/aaaa) : ";
    Date naissance;
    do
    {
        naissance = saisir_date();
        if (!est_dateNaissance(naissance))
            cout << "La date n'est pas valide, réessayez : ";
    } while (!est_dateNaissance(naissance));
    
    client c(numPass, n, p, naissance);
    if (ajouter_client(c))
        cout << "Le client a bien été ajouté." << endl;
    else
        cout << "Une erreur s'est produite lors de l'ajout du client." << endl;
}

client& clients::getClient(string numPass)
{
    int pos = existe(numPass);
    if (pos != -1)
        return tabClient[pos];
}

client& clients::get_ieme_client(int i)
{
    return tabClient[i];
}


void clients::annuler_voyage(const string& idVoy)
{
    for (int i=0; i<tabClient.size();i++)
        if (tabClient[i].participe_au_voyage(idVoy) != -1)
            tabClient[i].annuler_voyage(idVoy);
}

string clients::numPass_client_gagnant()
{
    if (tabClient.size()==0)
        return "";
    else
    {
        vector<string> vect;
        for (int i=0; i < tabClient.size(); i++)
        {
            vector<string> voyC = tabClient[i].getVoyagesClient();
            for (int j=0; j < voyC.size(); j++)
                vect.push_back(tabClient[i].getNumPasseport());
        }
        srand(time(0));
        int posGagnant = rand() % vect.size();
        return (vect[posGagnant]);
    }
}

vector<int> clients::agesClients()
{
    vector<int> ages;
    for (int i=0; i < tabClient.size(); i++)
        ages.push_back(tabClient[i].getAge());
    return ages;
}


int clients::nb_clients()
{
    return tabClient.size();
}
void clients::writeToFile()
{
    //1ere ligne est le nbre de destinations
    ofstream out;
    out.open("fichier_clients.txt", ios::trunc);
    out << tabClient.size() << endl;
    for (int i=0; i<tabClient.size();i++)
    {
        tabClient[i].write(out);
        out << endl;
    }
    out.close();
}

void clients::readFile()
{
    ifstream in;
    in.open("fichier_clients.txt");
    if (in.is_open())
    {
        int nb;
        in >> nb;
        for (int i=0; i < nb; i++)
        {
            client cli;
            cli.read(in);
            tabClient.push_back(cli);
        }
        in.close();
    }
}