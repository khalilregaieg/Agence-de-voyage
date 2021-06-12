#include "client.h"
using namespace std;

/**** méthodes de la classe client ****/
client::client(const string& numP, const string& n, const string& pren, Date dateN)
{
    numPasseport = numP ;
    Nom = n ;
    Prenom = pren ;
    DateNaissance = dateN;
}

client::client(){}

client::~client(){}

string client::getNumPasseport()
{
    return numPasseport;
}

string client::getNom()
{
    return Nom;
}

string client::getPrenom()
{
    return Prenom;
}

Date client::getDateNaissance()
{
    return DateNaissance;
}

int client::participe_au_voyage(string idVoy)
{
    for (int i=0; i < VoyagesClient.size(); i++)
        if ( VoyagesClient[i] == idVoy )
            return i;
    return -1;
}
bool client::ajouter_voyage(string idVoy)
{
    if (participe_au_voyage(idVoy) == -1)    
    {
        VoyagesClient.push_back(idVoy);
        return true;
    }
    return false;
}

int client::getAge()
{
    int anneeSysteme = date_systeme().getAnnee();
    int anneeNaissance = DateNaissance.getAnnee();
    return (anneeSysteme - anneeNaissance);
}

vector<string> client::getVoyagesClient()
{
    return VoyagesClient;
}

ostream& operator<<(ostream& output, const client& c)
{
    output << "   * " << c.Prenom << " " << c.Nom << endl;
    output << "   * Passeport: " << c.numPasseport << endl;
    output << "   * Date de naissance: " << c.DateNaissance << endl;
    return output;
}


/**** autres fonctions ****/
bool est_majus(const string& s)
{
    for (int i=0; i < s.length(); i++)
        if (!isupper(s[i]))
            return false;
    return true;
}
bool est_numPasseport(const string& s) // à vérifier le format correcte du numPass .....
{
    // 1 lettres majuscules + 7 chiffres
    if (s.length() != 8)
        return false;
    if (!est_majus(s.substr(0,1)))
        return false;
    if (!est_numerique(s.substr(1)))
        return false;
    return true;
}
string saisir_numPasseport()
{
    string numPass;
    cout <<"--->  Donner le numéro de passeport  : ";
    do
    {
        cin >> numPass;
        if (!est_numPasseport(numPass))
            cout << "Le numéro que vous avez entré n'est pas conforme au format demandé ! Réessayez :  ";
    } while (!est_numPasseport(numPass));
    return numPass;
}

void client::annuler_voyage(const string& idVoy)
{
    if (participe_au_voyage(idVoy) != -1)
    {
        int pos = participe_au_voyage(idVoy);
        for (int i=pos; i<VoyagesClient.size()-1;i++)
            VoyagesClient[i]=VoyagesClient[i+1];
        VoyagesClient.pop_back();
    }
}


ostream& client::write(ostream& out)
{
    out << numPasseport << " " << Nom << " " << Prenom << " ";
    DateNaissance.write(out);
    writeVect(VoyagesClient, out);
    return out;
}

istream& client::read(istream& in)
{
    in >> numPasseport  >> Nom >> Prenom;
    DateNaissance.read(in);
    readVect(VoyagesClient, in);
    return in;
}




ostream& writeVect(vector<string>& vect, ostream& out)
{
    out << vect.size() << " ";
    for (int i=0; i < vect.size(); i++)
        out << vect[i] << " ";
}

istream& readVect(vector<string>& vect, istream& in)
{
    int nb;
    in >> nb;
    for (int i=0; i < nb; i++){
        string s;
        in >> s;
        vect.push_back(s);
    }
    return in;
}