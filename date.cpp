#include "date.h"
using namespace std;


/**** Les méthodes de la classes Date ****/
Date::Date(){}

Date::Date(int j, int m, int a)
{  
    Jour =j;
    Mois = m;
    Annee = a;
}

Date::~Date(){}

int Date::getJour()
{
    return Jour;
}

int Date::getMois()
{
    return Mois;
}

int Date::getAnnee()
{
    return Annee;
}

void Date::setDate(const int& j, const int& m, const int& a)
{
    Jour = j;
    Mois = m;
    Annee = a;
}

int Date::date_cmp(const Date& d)
{
    if (Annee > d.Annee)
        return 1;
    else if (Annee < d.Annee)
        return -1;
    else
        if (Mois > d.Mois)
            return 1;
        else if (Mois < d.Mois)
            return -1;
        else
            if (Jour > d.Jour)
                return 1;
            else if (Jour < d.Jour)
                return -1;
            else
                return 0;
}

bool Date::operator<(const Date& d)
{
    if (date_cmp(d) == -1)
        return true;
    return false;
}

bool Date::operator>(const Date& d)
{
    if (date_cmp(d) == 1)
        return true;
    return false;
}

bool Date::operator==(const Date& d)
{
    if (date_cmp(d) == 0)
        return true;
    return false;
}

void Date::retarder_date()
{
    cout << "La date actuelle :  "<< *this;
    cout << "--->  Donner la nouvelle date :  ";
    Date d;
    do
    {
        d = saisir_date();
        if ((d < *this) || (d == *this))
            cout << "Cette date n'est pas valide, réessayez :  ";
    }
    while ((d < *this) || (d == *this));
    *this = d;
}

ostream& Date::write(ostream& out)
{
    out << Jour << " " << Mois << " " << Annee << " ";
    return out;
}

istream& Date::read(istream& in)
{
    in >> Jour >> Mois >> Annee;
    return in;
}






/*****************************************************************/
bool Date::Dans_printemps()
{
    if((Mois>=3)&&(Mois<=5))
        return true;
    else
        return false;
}
bool Date::Dans_automne()
{
    if((Mois>=9)&&(Mois<=11))
        return true;
    else
        return false;
}
bool Date::Dans_ete()
{
    if((Mois>=6)&&(Mois<=8))
        return true;
    else
        return false;
}
bool Date::Dans_hiver()
{
    if((Mois==12)||(Mois==1)||(Mois==2))
        return true;
    else
        return false;
}








//fonction amie de la classe Date
ostream& operator<<(ostream& output, const Date& d)
{
    if (d.Jour<10)
        output << "0" << d.Jour ;
    else
        output << d.Jour ;
    output << "/" ;

    if (d.Mois<10)
        output << "0" << d.Mois ;
    else
        output << d.Mois ;
    output << "/" << d.Annee << endl ;
    return output ; 
}





/**** Fonctions  ****/
Date date_systeme()
{
    //periodes courant basé sur le periodes systeme
    time_t periodesCourant = time(0);

    /* la structure tm contient la date est le periodes sous forme
       de structure C                                        */                       
    tm* periodes = localtime(&periodesCourant);
    
    /* on extrait les variables de la structure tm et on les affecte
       à des entiers */
    int j = periodes->tm_mday;
    int m = 1 + periodes->tm_mon;
    int a = 1900 + periodes->tm_year;

    Date dateCourante(j,m,a);
    return dateCourante;
}

bool date_valide(int j, int m, int a)
{
    /*if ((a < date_systeme().getAnnee() - 100) || ( a > date_systeme().getAnnee() + 5 ))
        return false;*/
    switch (m)
    {
    //les mois ayant 31 jours
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: 
        if ((j>31)||(j<1))
            return false;
        break;
    //le mois de Fevrier
    case 2:
        if ((j==29) && (!annee_bissextile(a))   )
            return false;
        else if((j==29) && (a%4 == 0))
            break;
        else if ((j>28) || (j<1))
            return false;
        break;
    // les mois ayant 30 jours
    case 4:
    case 6:
    case 9:
    case 11:
        if ((j>30) || (j<1))
            return false;
        break; 
    default:
        return false;
        break;
    }
    return true;
}

//utilisée aussi pour vérifier le numPasseport
bool est_numerique(const string& s)
{
    for (int i=0; i < s.length(); i++)
        if (!isdigit(s[i]))
            return false;
    return true;
}
bool format_date(const string& d)
{
    if (d.length() != 10)
        return false;    
    if ((d[2] != '/') || d[5] != '/')
        return false;
    if (!est_numerique( d.substr(0,2)))
        return false;
    if (!est_numerique( d.substr(3,2)))
        return false;
    if (!est_numerique( d.substr(6,4)))
        return false;
    return true;
}

Date saisir_date()
{
    string d;
    int j, m, a;
    do
    {
        cin >> d;
        if (!format_date(d))
            cout << "Veuilliez respecter le format jj/mm/aaaa :  ";
        else
        {
            j = stoi(d.substr(0,2));
            m = stoi(d.substr(3,2));
            a = stoi(d.substr (6));
            if (!date_valide(j,m,a))
                cout << "Date invalide ! Réessayez :  "; 
        }
    } while ((!date_valide(j,m,a)) || !format_date(d));
    Date date(j, m, a);
    return date;
}

bool est_dateNaissance(Date d)
{
    if  (( d < date_systeme()) && (d.getAnnee() > date_systeme().getAnnee() - 150 ))
        return true;
    else
        return false;    
}

Date saisir_date_depart()
{
    cout << "--->  Donner la date de départ :  ";
    Date dep;
    do
    {
        dep = saisir_date();
        if (dep < date_systeme())
            cout << "La date fournie est invalide, réessayez : ";
    }
    while (dep < date_systeme());  
    
    return dep;  
}


Date saisir_date_retour(Date dep)
{
    cout << " Donner la date de retour ( la durée minimale du voyage est de 7 jours ) :  " << endl;
    cout << "   --->  ";
    Date retour;
    do
    {
        retour = saisir_date();
        if (difference_date(dep,retour) < 7)
        {
            cout << "La date fournie est invalide, réessayez : " << endl;
            cout << "   --->  ";
        }
    } 
    while (difference_date(dep,retour) < 7);  
    return retour;  
}

bool annee_bissextile (int annee)
{
    if (( annee % 4 == 0) && ((annee % 100 != 0) || ( annee % 400 ==0)))
        return true;
    return false;
}

int nb_annee_bissextile(Date d) //nbre annee bissextile avant date d
{
    int annees = d.getAnnee();
    if (d.getMois() <= 2)
        annees--;
    return annees / 4 - annees / 100 + annees / 400 ; // l'annee est bissextile si : (divisible par 4 et non divisible par 100) ou (divisible par 400)
}

int difference_date(Date d1, Date d2)
{
    int nbJoursMois [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int j1 = d1.getJour();
    int m1 = d1.getMois();
    int a1 = d1.getAnnee();
    int j2 = d2.getJour();
    int m2 = d2.getMois();
    int a2 = d2.getAnnee();

    long int nb1 = a1*365 + j1; // nb jours avant d1
    for (int i =0; i < m1 - 1 ;i++)
        nb1 += nbJoursMois[i];
    nb1 += nb_annee_bissextile(d1); // +1j pour chaque annee bissextile

    long int nb2 = a2*365 + j2; // nb jours avant d1
    for (int i =0; i < m2 - 1 ;i++)
        nb2 += nbJoursMois[i];
    nb2 += nb_annee_bissextile(d2); // +1j pour chaque annee bissextile
    
    return abs(nb2 - nb1);
}


Date prochain_jour(Date d)
{
    Date d2;
    int j = d.getJour();
    int m = d.getMois();
    int a = d.getAnnee();
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        if (j == 31)
            d2.setDate(1,m+1, a);
        else
            d2.setDate(j+1,m,a);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (j == 30)
            d2.setDate(1,m+1, a);
        else
            d2.setDate(j+1,m,a);
        break;
    case 12:
        if (j==31)
            d2.setDate(1,1,a+1);
        else
            d2.setDate(j+1,m,a);
        break;
    case 2:
        if ((j==29) && (annee_bissextile(a)))
            d2.setDate(1,3,a);
        else if ((j==28) && (!annee_bissextile(a)))
            d2.setDate(1,3,a);
        else
            d2.setDate(j+1,m,a);
        break;
    default:
        break;
    }
    return d2;
}


Date ajouter_nbJours(Date d, int nbJours)
{  
    if (nbJours >= 1)
    {
        Date d2 = d;
        do
        {
            d2 = prochain_jour(d2);
        }
        while ( difference_date(d,d2) != nbJours);
        return d2;
    }
}
