#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

//La classe date
class Date
{
    private:
        int Jour;
        int Mois;
        int Annee;
    public:
        Date();
        Date(int,int,int);
        ~Date();
        int getJour();
        int getMois();
        int getAnnee();
        void setDate(const int&,const int&,const int&);
        int date_cmp(const Date& d);     //retourne 1 si *this>d, 0 si *this = d et -1 sinon
        bool operator<(const Date& d);   // 
        bool operator>(const Date& d);   //    opérateurs de comparaisons des dates
        bool operator==(const Date& d);  //
        void retarder_date();
        friend ostream& operator<<(ostream&, const Date&); //affichage sous la forme "jj/mm/aaaa"
        ostream& write(ostream&);
        istream& read(istream&);
        bool Dans_printemps();
        bool Dans_ete();
        bool Dans_automne();
        bool Dans_hiver();
};



//Fonctions sur les dates
Date date_systeme();        //retourne la date systeme
bool date_valide(int,int,int); //vérifie si les valeur de jour, mois et année sont valides
bool est_numerique(const string&); //vérifie si une chaine est numérique
bool format_date(const string&); // vérifie si une chaine est de la format jj/mm/aaaa
Date saisir_date();     //saisir une datee à partir du clavier
bool est_dateNaissance(Date); //vérifie que la date de naissance est dans le passé (càd < date systeme)
Date saisir_date_depart();
Date saisir_date_retour(Date); //date de retour > date de départ
bool annee_bissextile(int); //verifie si une annee est bissextile
int nb_annee_bissextile(Date); // retourne le nombre d'annee bissextiles avant la date donnee
int difference_date(Date, Date); //calcule la durée en jours entre deux dates
Date prochain_jour(Date);   // donne le jour suivant de la date donnee
Date ajouter_nbJours(Date, int); // ajoute un nombre de jours a la date donnée et retourne la nouvelle date
#endif