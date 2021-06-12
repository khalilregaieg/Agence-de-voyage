#include "voyagesEnGroupe.h"
using namespace std;

voyagesEnGroupe::voyagesEnGroupe(){};
voyagesEnGroupe::~voyagesEnGroupe(){};
int voyagesEnGroupe::existe(string idVoy)
{
    for (int i=0; i < tabVoyageEnGroupe.size() ; i++)
        if (tabVoyageEnGroupe[i].getIdVoyage() == idVoy)
            return i;
    return -1;
}
bool voyagesEnGroupe::ajouter_voyageEnGroupe(voyageEnGroupe g)
{
    if (existe(g.getIdVoyage()) != -1)
        return false;
    else
        {
            tabVoyageEnGroupe.push_back(g);
            return true;
        }
}

void voyagesEnGroupe::afficher_groupes()
{
    if (tabVoyageEnGroupe.size()==0)
        cout << "  * Aucun groupe pour le moment " << endl << endl;
    else
        for (int i=0; i<tabVoyageEnGroupe.size(); i++)
            tabVoyageEnGroupe[i].afficher_voyage();
}

void voyagesEnGroupe::afficher_groupes(Destination dest)
{
    if (tabVoyageEnGroupe.size()==0)
        cout << "  * Aucun groupe vers cette destination pour le moment " << endl;
    else
    {
        bool test = false;
        for (int i=0; i<tabVoyageEnGroupe.size(); i++)
            if (tabVoyageEnGroupe[i].getDestination() == dest)
            {
                tabVoyageEnGroupe[i].afficher_voyage();
                test = true;
            }
        if (test == false)
            cout << "  * Aucun voyage en groupe vers cette destination pour le moment " << endl;
    }
}

int voyagesEnGroupe::nb_voyagesEnGroupe()
{
    return tabVoyageEnGroupe.size();
}

vector<string> voyagesEnGroupe::groupes_disponibles()
{
    vector <string> disponibles;
    if (existe_groupes_disponibles())
    {
        cout << "Les groupes disponibles :  " << endl;
        for (int i =0; i< tabVoyageEnGroupe.size(); i++)
        {
            if ((tabVoyageEnGroupe[i].nb_participants() < 15) && ( tabVoyageEnGroupe[i].getDateDepart() > date_systeme()))
                tabVoyageEnGroupe[i].afficher_voyage();
                disponibles.push_back(tabVoyageEnGroupe[i].getIdVoyage());   
        }
    }
    else
        cout << endl << "   Aucun groupe disponible " << endl << endl;
    return disponibles;
}

vector<string> voyagesEnGroupe::groupes_disponibles(Destination d)
{
    vector <string> disponibles;
    if (existe_groupes_disponibles(d))
    {
        cout << "Les groupes disponibles :  " << endl;
        for (int i =0; i< tabVoyageEnGroupe.size(); i++)
        {
            if ((tabVoyageEnGroupe[i].nb_participants() < 15) && (tabVoyageEnGroupe[i].getDestination() == d) && (tabVoyageEnGroupe[i].getDateDepart() > date_systeme()))
                tabVoyageEnGroupe[i].afficher_voyage();
                disponibles.push_back(tabVoyageEnGroupe[i].getIdVoyage());   
        }
    }
    else
        cout << endl << "   Aucun groupe disponible " << endl << endl;
    return disponibles;
}

vector<string> voyagesEnGroupe::tous_les_groupes()
{
    vector<string> v;
    for (int i=0; i<tabVoyageEnGroupe.size(); i++)
        v.push_back(tabVoyageEnGroupe[i].getIdVoyage());
    return v;
}

bool voyagesEnGroupe::existe_groupes_disponibles()
{
    for (int i=0; i < tabVoyageEnGroupe.size(); i++)
        if ((tabVoyageEnGroupe[i].nb_participants() < 15 ) && (tabVoyageEnGroupe[i].getDateDepart() > date_systeme()))
            return true ;
    return false;
}

bool voyagesEnGroupe::existe_groupes_disponibles(Destination d)
{
    for (int i=0; i < tabVoyageEnGroupe.size(); i++)
        if ((tabVoyageEnGroupe[i].nb_participants() < 15) && (tabVoyageEnGroupe[i].getDestination() == d ) && (tabVoyageEnGroupe[i].getDateDepart() > date_systeme()))
            return true ;
    return false;
}

voyageEnGroupe& voyagesEnGroupe::getVoyage(const string& idVoy)
{
    if (existe(idVoy) != -1)
        return tabVoyageEnGroupe[existe(idVoy)];
}


void voyagesEnGroupe::annuler_voyage(const string& idVoy)
{
    if (existe(idVoy) != -1)
    {
        int pos = existe(idVoy);
        for (int i=pos; i<tabVoyageEnGroupe.size()-1;i++)
            tabVoyageEnGroupe[i] = tabVoyageEnGroupe[i+1];
        tabVoyageEnGroupe.pop_back();
    }
}



vector<string> voyagesEnGroupe::afficher_voyages_client(const string& numPass)
{
    vector<string> vect;
    for (int i=0; i < tabVoyageEnGroupe.size();i++)
        if (tabVoyageEnGroupe[i].est_paticipant(numPass) != -1)
        {
            tabVoyageEnGroupe[i].afficher_voyage();
            vect.push_back(tabVoyageEnGroupe[i].getIdVoyage());
        }
    return vect;    
}

vector<string> voyagesEnGroupe::afficher_futur_voyages_client(const string& numPass)
{
    vector<string> vect;
    for (int i=0; i < tabVoyageEnGroupe.size();i++)
        if ((tabVoyageEnGroupe[i].est_paticipant(numPass) != -1) && (tabVoyageEnGroupe[i].getDateDepart() > date_systeme()))
        {
            tabVoyageEnGroupe[i].afficher_voyage();
            vect.push_back(tabVoyageEnGroupe[i].getIdVoyage());
        }
    return vect;    
}

bool voyagesEnGroupe::est_vide()
{
    if (tabVoyageEnGroupe.size()==0)
        return true;
    return false;
}

int voyagesEnGroupe::retarder_voyages_en_groupe(Date dep)
{
    int nbRet =0;
    for (int i=0; i < tabVoyageEnGroupe.size(); i++)
        if (tabVoyageEnGroupe[i].getDateDepart() == dep)
        {
            tabVoyageEnGroupe[i].retarder_voyage();
            nbRet++;
        }
    return nbRet;
}


void voyagesEnGroupe::writeToFile()
{

    ofstream out;
    out.open("fichier_voyagesEnGroupe.txt",ios::trunc);
    out << tabVoyageEnGroupe.size() << endl;
    for (int i=0; i<tabVoyageEnGroupe.size();i++)
    {
        tabVoyageEnGroupe[i].write(out);
        out << endl;
    }
    out.close();
}

void voyagesEnGroupe::readFile()
{
    ifstream in;
    in.open("fichier_voyagesEnGroupe.txt");
    if (in.is_open())
    {
        int nb;
        in >> nb;
        for (int i=0; i < nb; i++)
        {
            voyageEnGroupe voy;
            voy.read(in);
            tabVoyageEnGroupe.push_back(voy);
        }
        in.close();
    }
}










/***********************************************************************************************************/

vector<int> voyagesEnGroupe::liste_des_annees()
{
    vector<int> annees;
    for(int i=0;i<tabVoyageEnGroupe.size();i++)
        annees.push_back(tabVoyageEnGroupe[i].getDateDepart().getAnnee());
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
vector<int> voyagesEnGroupe::nbre_desvoyages_engroupes_chaquemois(int annee)
{
    vector<int> a;
    for(int i=0;i<12;i++)
        a.push_back(0);
    for(int i=0;i<tabVoyageEnGroupe.size();i++)
    {
        if(tabVoyageEnGroupe[i].getDateDepart().getAnnee()==annee)
        {
            int mois=tabVoyageEnGroupe[i].getDateDepart().getMois();
            a[mois-1]++;
        }
    }
    return a;
}
vector<int> voyagesEnGroupe::nbre_desvoyages_engroupes_chaquesaison(int annee)
{
    vector<int> a;
    for(int i=0;i<4;i++)
        a.push_back(0);
    for(int i=0;i<tabVoyageEnGroupe.size();i++)
        if(tabVoyageEnGroupe[i].getDateDepart().getAnnee()==annee)
        {
            if(tabVoyageEnGroupe[i].getDateDepart().Dans_hiver())
                a[0]++;
            if(tabVoyageEnGroupe[i].getDateDepart().Dans_printemps())
                a[1]++;
            if(tabVoyageEnGroupe[i].getDateDepart().Dans_ete())
                a[2]++;
            if(tabVoyageEnGroupe[i].getDateDepart().Dans_automne())
                a[3]++;
        }
    return a;
}