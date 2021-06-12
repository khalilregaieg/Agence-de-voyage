#include "statistiquesAgence.h"
using namespace std;


vector<int> vecteur_unique(vector<int> a,vector<int> b)
{
    vector<int> uniq;
    for(int i=0;i<a.size();i++)
        uniq.push_back(a[i]);
    for(int i=0;i<b.size();i++)
    {
        int f=0;
        for(int j=0;j<uniq.size();j++)
            if(b[i]==uniq[j])
                f=1;
        if(f==0)
            uniq.push_back(b[i]);
    }
    return uniq;
}
int maximale(vector<int> a)
{
    int maxi=a[0];
    for(int i=0;i<a.size();i++)
        if(a[i]>maxi)
            maxi=a[i];
    return maxi;
}
int minimale(vector<int> a)
{
    int mini=a[0];
    for(int i=0;i<a.size();i++)
        if(a[i]<mini)
            mini=a[i];
    return mini;
}
vector<int> nbre_occurence(int a,vector<int> b)
{
    vector<int> occurence;
    for(int i=0;i<b.size();i++)
        if(b[i]==a)
            occurence.push_back(i);
    return occurence;
}
void mois_correspondant(int i)
{
    switch (i)
    {
        case 0:cout<<"Janvier ";break;
        case 1:cout<<"Fevrier ";break;
        case 2:cout<<"Mars ";break;
        case 3:cout<<"Avril ";break;
        case 4:cout<<"Mai ";break;
        case 5:cout<<"Juin ";break;
        case 6:cout<<"Juillet ";break;
        case 7:cout<<"Aout ";break;
        case 8:cout<<"Septembre ";break;
        case 9:cout<<"Octobre ";break;
        case 10:cout<<"Novembre ";break;
        case 11:cout<<"Decembre ";break;
    }
}
void la_periode_la_plus_demandee_par_annee(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul)
{
    vector<int> ans_grps;
    vector<int> ans_seuls;
    ans_grps=voy_en_grps.liste_des_annees();
    ans_seuls=voy_seul.liste_des_annees();
    vector<int> tout_annee;
    tout_annee=vecteur_unique(ans_grps,ans_seuls);
    if(tout_annee.size()==0)
        cout<< endl << "   Aucun voyage effectue"<<endl << endl;
    else
        cout << endl;
    for(int i=0;i<tout_annee.size();i++)
    {
        cout<<"   Pour l'annee "<<tout_annee[i]<<" : "<<endl;//pour chaque ans
        vector<int> mois;
        vector<int> mois1;
        mois=voy_seul.nbre_desvoyages_seules_chaquemois(tout_annee[i]);
        mois1=voy_en_grps.nbre_desvoyages_engroupes_chaquemois(tout_annee[i]);
        vector<int> mois2;
        for(int j=0;j<mois.size();j++)
            mois2.push_back(mois1[j]+mois[j]);
        int nbre_des_voyages_maximales=maximale(mois2);
        vector<int> occurence=nbre_occurence(nbre_des_voyages_maximales,mois2);
        if(occurence.size()==1)
        {
            cout<<"On a effectue un nombre de voyages maximale est egale a "<<nbre_des_voyages_maximales<<" durant le mois de ";
            mois_correspondant(occurence[0]);
            cout<<endl << endl;
        }

        else
        {
            cout<<"On a effectue un nombre de voyages maximale est egale a "<<nbre_des_voyages_maximales<<" durant les mois de ";
            for(int k=0;k<occurence.size();k++)
                mois_correspondant(occurence[k]);
            cout<< endl << endl;
        }
    }
}
void la_periode_la_moins_demandee_par_annee(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul)
{
    vector<int> ans_grps;
    vector<int> ans_seuls;
    ans_grps=voy_en_grps.liste_des_annees();
    ans_seuls=voy_seul.liste_des_annees();
    vector<int> tout_annee;
    tout_annee=vecteur_unique(ans_grps,ans_seuls);
    if(tout_annee.size()==0)
        cout<< endl << "   Aucun voyage effectue"<<endl << endl;
    else
        cout << endl;
    for(int i=0;i<tout_annee.size();i++)
    {
        cout<<"Pour l'annee "<<tout_annee[i]<<" : "<<endl;
        vector<int> mois;
        vector<int> mois1;
        mois=voy_seul.nbre_desvoyages_seules_chaquemois(tout_annee[i]);
        mois1=voy_en_grps.nbre_desvoyages_engroupes_chaquemois(tout_annee[i]);
        vector<int> mois2;
        for(int j=0;j<mois.size();j++)
            mois2.push_back(mois1[j]+mois[j]);
        int nbre_des_voyages_minimales=minimale(mois2);
        vector<int> occurence=nbre_occurence(nbre_des_voyages_minimales,mois2);
        if(occurence.size()==1)
        {
            cout<< endl << "   On a effectue un nombre de voyages minimale est egale a "<<nbre_des_voyages_minimales<<" durant le mois de ";
            mois_correspondant(occurence[0]);
            cout<<endl << endl;
        }

        else
        {
            cout<<"   On a effectue un nombre de voyages minimale est egale a "<<nbre_des_voyages_minimales<<" durant les mois de ";
            for(int k=0;k<occurence.size();k++)
                mois_correspondant(occurence[k]);
            cout<<endl << endl;
        }
    }
}
void afficher_lesvoyages_chaque_saison(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul)
{
    vector<int> ans_grps;
    vector<int> ans_seuls;
    ans_grps=voy_en_grps.liste_des_annees();
    ans_seuls=voy_seul.liste_des_annees();
    vector<int> tout_annee;
    tout_annee=vecteur_unique(ans_grps,ans_seuls);
    if(tout_annee.size()==0)
        cout<< endl << "   Aucun voyage effectue"<<endl << endl;
    for(int i=0;i<tout_annee.size();i++)
    {
        cout<<"Pour l'annee "<<tout_annee[i]<<" : "<<endl;
        vector<int> saison=voy_en_grps.nbre_desvoyages_engroupes_chaquesaison(tout_annee[i]);
        vector<int> saison1=voy_seul.nbre_desvoyages_seules_chaquesaison(tout_annee[i]);
        vector<int> saison2;
        for(int i=0;i<saison.size();i++)
            saison2.push_back(saison1[i]+saison[i]);
        cout<< endl << "   Le nombre des voyages effectue  pour la saison d'HIVER de cette annee       :  "<<saison2[0]<<endl;
        cout<<         "   Le nombre des voyages effectue  pour la saison de PRINTEMPS de cette annee  :  "<<saison2[1]<<endl;
        cout<<         "   Le nombre des voyages effectue  pour la saison d'ETE de cette annee         :  "<<saison2[2]<<endl;
        cout<<         "   Le nombre des voyages effectue  pour la saison d'AUTOMNE de cette annee     :  "<<saison2[3]<<endl << endl;
    }
}
void afficher_lesvoyages_seuls_chaque_saison(voyagesSeul& voy_seul)//les voyages seules seulements
{
    vector<int> ans_seuls;
    ans_seuls=voy_seul.liste_des_annees();
    if(ans_seuls.size()==0)
        cout<< endl << "   Aucun voyage seul effectue"<<endl << endl;
    for(int i=0;i<ans_seuls.size();i++)
    {
        cout<<"Pour l'annee "<<ans_seuls[i]<<" : "<<endl;
        vector<int> saison1=voy_seul.nbre_desvoyages_seules_chaquesaison(ans_seuls[i]);
        cout<< endl << "   Le nombre des voyages seuls effectue  pour la saison d'HIVER de cette annee      :  "<<saison1[0]<<endl;
        cout<<         "   Le nombre des voyages seuls effectue  pour la saison de PRINTEMPS de cette annee :  "<<saison1[1]<<endl;
        cout<<         "   Le nombre des voyages seuls effectue  pour la saison d'ETE de cette annee        :  "<<saison1[2]<<endl;
        cout<<         "   Le nombre des voyages seuls effectue  pour la saison d'AUTOMNE de cette annee    :  "<<saison1[3]<<endl << endl;
    }
}
void afficher_lesvoyages_engroupes_chaque_saison(voyagesEnGroupe& voy_en_grps)
{
    vector<int> ans_grps;
    ans_grps=voy_en_grps.liste_des_annees();
    if(ans_grps.size()==0)
        cout<< endl << "   Aucun voyage en groupe effectue"<<endl << endl;
    for(int i=0;i<ans_grps.size();i++)
    {
        cout<<"Pour l'annee "<<ans_grps[i]<<" : "<<endl;
        vector<int> saison=voy_en_grps.nbre_desvoyages_engroupes_chaquesaison(ans_grps[i]);
        cout<<endl <<"   Le nombre des voyages en groupes effectue  pour la saison d'HIVER de cette annee      :  "<<saison[0]<<endl;
        cout<<"   Le nombre des voyages en groupes effectue  pour la saison de PRINTEMPS de cette annee :  "<<saison[1]<<endl;
        cout<<"   Le nombre des voyages en groupes effectue  pour la saison d'ETE de cette annee        :  "<<saison[2]<<endl;
        cout<<"   Le nombre des voyages en groupes effectue  pour la saison d'AUTOMNE de cette annee    :  "<<saison[3]<<endl << endl;
    }
}
void afficher_lemoyen_annuel_des_voyages(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul)
{
    vector<int> ans_grps;
    vector<int> ans_seuls;
    ans_grps=voy_en_grps.liste_des_annees();
    ans_seuls=voy_seul.liste_des_annees();
    vector<int> tout_annee;
    tout_annee=vecteur_unique(ans_grps,ans_seuls);
    if(tout_annee.size()==0)
        cout<<endl << "   Aucun voyage effectue"<<endl << endl;
    else
    {
        int nbre_des_voyages;
        nbre_des_voyages=voy_en_grps.nb_voyagesEnGroupe()+voy_seul.nb_voyagesSeul();
        float moyen=(float(nbre_des_voyages)/(tout_annee.size()));
        cout<< endl << "  Le nombre moyen des voyages annuels est egale a : "<<moyen<<endl <<endl ;
    }
}
void afficher_lemoyen_annuel_des_voyages_engroupes(voyagesEnGroupe& voy_en_grps)
{
    vector<int> ans_grps;
    ans_grps=voy_en_grps.liste_des_annees();
    if(ans_grps.size()==0)
        cout<< endl << "   Aucun voyage en groupe effectue"<<endl <<endl;
    else
    {
        int nbre_des_voyages;
        nbre_des_voyages=voy_en_grps.nb_voyagesEnGroupe();
        float moyen=(float(nbre_des_voyages)/(ans_grps.size()));
        cout<< endl << " Le nombre moyen des voyages en groupes annuels est egale a : "<<moyen<<endl << endl;
    }
}
void afficher_lemoyen_annuel_des_voyages_seuls(voyagesSeul& voy_seul)
{
    vector<int> ans_seuls;
    ans_seuls=voy_seul.liste_des_annees();
    if(ans_seuls.size()==0)
        cout<< endl << "   Aucun voyage seul effectue"<<endl << endl;
    else
    {
        int nbre_des_voyages;
        nbre_des_voyages=voy_seul.nb_voyagesSeul();
        float moyen=(float(nbre_des_voyages)/(ans_seuls.size()));
        cout<< endl << "  Le nombre moyen des voyages seuls annuels est egale a : "<< moyen << endl << endl ;
    }
}
int somme_tableau(vector<int> a)
{
    int s=0;
    for(int i=0;i<a.size();i++)
        s+=a[i];
    return s;
}
void afficher_lemoyen_mensuel_des_voyages(voyagesEnGroupe& voy_en_grps,voyagesSeul& voy_seul)
{
    vector<int> ans_grps;
    vector<int> ans_seuls;
    ans_grps=voy_en_grps.liste_des_annees();
    ans_seuls=voy_seul.liste_des_annees();
    vector<int> tout_annee;
    tout_annee=vecteur_unique(ans_grps,ans_seuls);
    if(tout_annee.size()==0)
        cout<< endl << "   Aucun voyage effectue"<<endl << endl;
    for(int i=0;i<tout_annee.size();i++)
    {
        vector<int> saison=voy_en_grps.nbre_desvoyages_engroupes_chaquesaison(tout_annee[i]);
        vector<int> saison1=voy_seul.nbre_desvoyages_seules_chaquesaison(tout_annee[i]);
        vector<int> saison2;
        for(int i=0;i<saison.size();i++)
            saison2.push_back(saison1[i]+saison[i]);
        int somme=somme_tableau(saison2);
        float moyen_mensuel;
        moyen_mensuel=float(somme)/12;
        cout<< endl << "   Pour l'annee "<<tout_annee[i]<<" le nombre moyen des voyages mensuels est egale a : "<<moyen_mensuel<<endl << endl;
    }
}
void afficher_lemoyen_mensuel_des_voyages_engroupes(voyagesEnGroupe& voy_en_grps)
{
    vector<int> ans_grps;
    ans_grps=voy_en_grps.liste_des_annees();
    if(ans_grps.size()==0)
        cout<< endl << "   Aucun voyage en groupe effectue"<<endl << endl;
    for(int i=0;i<ans_grps.size();i++)
    {
        vector<int> saison=voy_en_grps.nbre_desvoyages_engroupes_chaquesaison(ans_grps[i]);
        int somme=somme_tableau(saison);
        float moyen_mensuel;
        moyen_mensuel=float(somme)/12;
        cout<< endl << "   Pour l'annee "<<ans_grps[i]<<" le nombre moyen des voyages en groupes mensuels est egale a : "<<moyen_mensuel<<endl << endl;
    }
}
void afficher_lemoyen_mensuel_des_voyages_seuls(voyagesSeul& voy_seul)
{
    vector<int> ans_seuls;
    ans_seuls=voy_seul.liste_des_annees();
    if(ans_seuls.size()==0)
        cout<<endl <<"  Aucun voyage seul effectue "<< endl << endl;
    for(int i=0;i<ans_seuls.size();i++)
    {
        vector<int> saison1=voy_seul.nbre_desvoyages_seules_chaquesaison(ans_seuls[i]);
        int somme=somme_tableau(saison1);
        float moyen_mensuel;
        moyen_mensuel=float(somme)/12;
        cout<< endl << "  Pour l'annee "<<ans_seuls[i]<<" le nombre moyen des voyages seuls mensuels est egale a : "<<moyen_mensuel<<endl << endl;
    }
}






int get_indice_max(int tab[], int taille)
{
    int iMax = 0;
    for (int i=1; i < taille; i++)
        if (tab[i] > tab[iMax])
            iMax = i;
    return iMax;
}

void tranche_age_frequente(clients& tabClient)
{
    if (tabClient.nb_clients() == 0)
        cout << endl << " Aucun client pour le moment, on ne peut pas calculer les statistiques. " << endl << endl;
    else
    {
        int tranchesAge[4] = {0,0,0,0};  //  <= 18, [19, 35], [36,60], 60>
        vector<int> agesClients = tabClient.agesClients();
        for (int i=0; i < agesClients.size(); i++)
        {
            int a = agesClients[i];
            if ( a <= 18)
                tranchesAge[0] += 1;
            else if (a <= 35)
               tranchesAge[1] += 1;
            else if ( a <= 60)
                tranchesAge[2] += 1;
            else
                tranchesAge[3] += 1;
        }   
        int tranche = get_indice_max(tranchesAge, 4);

        cout << endl << " La tranche d'age la plus fréquente est  :  ";
        switch (tranche)
        {
        case 0:
            cout << " <= 18  ";
            break;
        case 1:
            cout << " [19,35]  ";
            break;
        case 2:
            cout << " [36,60] ";
            break;
        case 3:
            cout << " >60  ";
            break;
        default:
            break;
        }

        cout << " ( " << tranchesAge[tranche] << " clients )" << endl << endl;
    }
}


void afficher_nombre_clients_distincts(clients& tabClient)
{
    cout << endl << "  Le nombre de clients distincts pour le moment :  " << tabClient.nb_clients() << endl << endl;
}


void afficher_nombre_voyages_total(voyagesEnGroupe& tabVoyGroupe, voyagesSeul& tabVoySeul)
{
    cout << endl << "Le nombre total des voyages de l'agence depuis sa création :  " << tabVoySeul.nb_voyagesSeul()+tabVoyGroupe.nb_voyagesEnGroupe() << endl;
    cout << "    Voyages seul       :  "  << tabVoySeul.nb_voyagesSeul() << endl;
    cout << "    Voyages en groupe  :  "  << tabVoyGroupe.nb_voyagesEnGroupe() << endl <<endl;
}
