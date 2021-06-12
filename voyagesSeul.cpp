#include "voyagesSeul.h"
using namespace std;

voyagesSeul::voyagesSeul(){};
voyagesSeul::~voyagesSeul(){};

int voyagesSeul::existe(string idVoy)
{
    for (int i=0; i < tabVoyageSeul.size(); i++)
        if (tabVoyageSeul[i].getIdVoyage() == idVoy)
            return i;
    return -1;
}

bool voyagesSeul::ajouter_voyageSeul(voyageSeul v)
{
    if (existe(v.getIdVoyage()) == -1)
    {
        tabVoyageSeul.push_back(v);
        return true;
    }
    return false;
}


void voyagesSeul::afficher_voyagesSeul(clients& c)
{   
    for (int i=0; i < tabVoyageSeul.size(); i++)
    {
        cout << "Client de numéro passeport :  " << c.getClient(tabVoyageSeul[i].getNumPasseport()).getNumPasseport()<<endl;
        tabVoyageSeul[i].afficher_voyage();
    }
    
}



voyageSeul& voyagesSeul::getVoyage(const string& idVoy)
{
    if (existe(idVoy) != -1)
        return tabVoyageSeul[existe(idVoy)];
}

vector<string> voyagesSeul::afficher_voyages_client(const string& numPass)
{
    vector<string> vect;
    for (int i=0; i < tabVoyageSeul.size(); i++)
        if (tabVoyageSeul[i].getNumPasseport() == numPass)
        {
            tabVoyageSeul[i].afficher_voyage();
            vect.push_back(tabVoyageSeul[i].getIdVoyage());
        }
    return vect;
}

vector<string> voyagesSeul::afficher_futur_voyages_client(const string& numPass)
{
    vector<string> vect;
    for (int i=0; i < tabVoyageSeul.size(); i++)
        if ((tabVoyageSeul[i].getNumPasseport() == numPass) && (tabVoyageSeul[i].getDateDepart() > date_systeme()))
        {
            tabVoyageSeul[i].afficher_voyage();
            vect.push_back(tabVoyageSeul[i].getIdVoyage());
        }
    return vect;
}

bool voyagesSeul::annuler_voyage(const string& idVoy)
{
    int pos = existe(idVoy);
    if (pos == -1)
        return false;
    if (existe(idVoy)!=-1)
    {
        for (int i=pos; i<tabVoyageSeul.size()-1;i++)
            tabVoyageSeul[i]=tabVoyageSeul[i+1];
        tabVoyageSeul.pop_back();
        return true;
    }   
}

bool voyagesSeul::est_vide()
{
    if (tabVoyageSeul.size()==0)
        return true;
    return false;
}

int voyagesSeul::retarder_voyages_seul(Date dep)
{
    int nbRet = 0;
    for (int i=0; i < tabVoyageSeul.size(); i++)
        if (tabVoyageSeul[i].getDateDepart() == dep)
        {
            tabVoyageSeul[i].retarder_voyage();
            nbRet++;
        }
    return nbRet;
}

void voyagesSeul::liste_voyages_pays(Destination dest)
{
    bool test = false;
    for (int i=0; i < tabVoyageSeul.size(); i++)
        if (tabVoyageSeul[i].getDestination() == dest)
        {
            tabVoyageSeul[i].afficher_voyage();
            test = true;
        }
    if (test == false)
        cout << "  * Aucun voyage seul vers cette destination pour le moment " << endl<< endl;
}



void voyagesSeul::writeToFile()
{

    ofstream out;
    out.open("fichier_voyagesSeul.txt",ios::trunc);
    out << tabVoyageSeul.size() << endl;
    for (int i=0; i<tabVoyageSeul.size();i++)
    {
        tabVoyageSeul[i].write(out);
        out << endl;
    }
    out.close();
}

void voyagesSeul::readFile()
{
    ifstream in;
    in.open("fichier_voyagesSeul.txt");
    if (in.is_open())
    {
        int nb;
        in >> nb;
        for (int i=0; i < nb; i++)
        {
            voyageSeul voy;
            voy.read(in);
            tabVoyageSeul.push_back(voy);
        }
        in.close();
    }
}







vector<int> voyagesSeul::liste_des_annees()
{
    vector<int> annees;
    for(int i=0;i<tabVoyageSeul.size();i++)
        annees.push_back(tabVoyageSeul[i].getDateDepart().getAnnee());
    vector<int> annees1;
    for(int i=0;i<annees.size();i++)
    {
        int f=0;
        for(int j=(i+1);j<annees.size();j++)
            if(annees[i]==annees[j])
                f=1;
        if(f==0)
            annees1.push_back(annees[i]);

    }
    return annees1;
}
vector<int> voyagesSeul::nbre_desvoyages_seules_chaquemois(int annee)
{
    vector<int> a;
    for(int i=0;i<12;i++)
        a.push_back(0);
    for(int i=0;i<tabVoyageSeul.size();i++)
    {
        if(tabVoyageSeul[i].getDateDepart().getAnnee()==annee)
        {
            int mois=tabVoyageSeul[i].getDateDepart().getMois();
            a[mois-1]++;
        }
    }
    return a;
}
vector<int> voyagesSeul::nbre_desvoyages_seules_chaquesaison(int annee)
{
    vector<int> a;
    for(int i=0;i<4;i++)
        a.push_back(0);
    for(int i=0;i<tabVoyageSeul.size();i++)
        if(tabVoyageSeul[i].getDateDepart().getAnnee()==annee)
        {
            if(tabVoyageSeul[i].getDateDepart().Dans_hiver())
                a[0]++;
            if(tabVoyageSeul[i].getDateDepart().Dans_printemps())
                a[1]++;
            if(tabVoyageSeul[i].getDateDepart().Dans_ete())
                a[2]++;
            if(tabVoyageSeul[i].getDateDepart().Dans_automne())
                a[3]++;
        }
    return a;
}
int voyagesSeul::nb_voyagesSeul()
{
    return(tabVoyageSeul.size());
}
