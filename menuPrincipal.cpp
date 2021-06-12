#include "menuPrincipal.h"
using namespace std;

void menu_principal(clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDest)
{
    cout <<"***********************************************"<< endl;
    cout <<"*                                             *"<< endl;
    cout <<"*    BIENVENUE CHEZ NOTRE AGENCE DE VOYAGE    *"<< endl;
    cout <<"*                                             *"<< endl;
    cout <<"***********************************************"<< endl << endl;
    int choix;
    do
    {
        cout << endl;
        cout<<" 1 - GESTION AGENCE:"<<endl;
        cout<<" 2 - AFFICHER LES STATISTIQUES:"<<endl;
        cout<<" 3 - QUITTER"<<endl<<endl;
        cout<<" VOTRE CHOIX ---> ";
        cin >> choix;
        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch(choix)
        {
            case 1 :
                gerer_agence(tabClient, tabVoySeul, tabVoyGroupe, tabDest);
            break;
            case 2 :
                afficher_statistiques(tabClient, tabVoySeul, tabVoyGroupe, tabDest);
            break;
            case 3 :
                break;
            default :
                cout<<"MAUVAIS CHOIX VEUILLEZ SAISIR DE NOUVEAU LE NUMERO";
        }
    }while(choix!=3);
}


void gerer_agence(clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDest)
{
    int choix;
    do
    {
        cout << endl << endl;
        cout<<"  GESTION AGENCE: "<<endl;
        cout<<"  ----------------"<<endl;
        cout<<" 1 - GERER LES DESTINATIONS:"<<endl;
        cout<<" 2 - GERER LES GROUPES:"<<endl;
        cout<<" 3 - ESPACE CLIENT:"<<endl;
        cout<<" 4 - AFFICHER TOUS LES VOYAGES DE L'AGENCE"<<endl;
        cout<<" 5 - RETARDER TOUS LES VOYAGES POUR UNE DATE DONNÉE " << endl;
        cout<<" 6 - DONNER LA LISTE DES VOYAGES PAR PAYS:"<<endl;
        cout<<" 7 - TIRAGE AU SORT POUR UN CLIENT GAGNANT:"<<endl;
        cout<<" 8 - RETOUR"<<endl<<endl;
        cout<<" VOTRE CHOIX --> ";
        cin>>choix;
        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch(choix)
        {
            case 1 :
                gerer_destinations(tabDest);
            break;
            case 2 :
                gerer_groupes(tabVoyGroupe, tabDest, tabClient);
            break;
            case 3 :
                gerer_clients(tabClient, tabVoySeul, tabVoyGroupe,tabDest);
            break;
            case 4 :
                afficher_tous_les_voyages(tabVoySeul, tabVoyGroupe, tabClient);
            break;
            case 5 :
                retarder_tous_les_voyages(tabVoySeul, tabVoyGroupe);
            break;
            case 6 :
                liste_voyages_pays(tabVoySeul, tabVoyGroupe, tabDest);
            break;
            case 7 :
                client_gagnant(tabVoySeul, tabVoyGroupe,tabClient, tabDest);
            break;
            case 8 :
                break;
            default :
                cout<<"MAUVAIS CHOIX VEUILLEZ SAISIR DE NOUVEAU LE NUMERO";

        }
    }while(choix!=8);
}


void afficher_statistiques(clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDest)
{
    int choix;

    do
    {
        cout<<"  AFFICHER LES STATISTIQUES:"<<endl;
        cout<<"  --------------------------"<<endl;
        cout<<"  1 - AFFICHER LE NOMBRE TOTAL DE VOYAGE EFFECTUE PAR L'AGENCE DEPUIS SA CREATION:"<<endl;
        cout<<"  2 - AFFICHER LE NOMBRE MOYEN DES VOYAGES ANNUELS:"<<endl;
        cout<<"  3 - AFFICHER LE NOMBRE MOYEN DES VOYAGES EN GROUPES ANNUELS:"<<endl;
        cout<<"  4 - AFFICHER LE NOMBRE MOYEN DES VOYAGES SEULS ANNUELS:"<<endl;
        cout<<"  5 - AFFICHER LE NOMBRE MOYEN DES VOYAGES MENSUELS CHAQUE ANNEE:"<<endl;
        cout<<"  6 - AFFICHER LE NOMBRE MOYEN DES VOYAGES EN GROUPES MENSUELS CHAQUE ANNEE:"<<endl;
        cout<<"  7 - AFFICHER LE NOMBRE MOYEN DES VOYAGES SEULS MENSUELS CHAQUE ANNEE:"<<endl;
        cout<<"  8 - AFFICHER CONSECUTIVEMENT LE NOMBRE DE VOYAGES EFFECTUES PENDANT CHAQUE SAISON DANS UNE ANNEE:"<<endl;
        cout<<"  9 - AFFICHER CONSECUTIVEMENT LE NOMBRE DE VOYAGES EN GROUPES EFFECTUES PENDANT CHAQUE SAISON DANS UNE ANNEE:"<<endl;
        cout<<" 10 - AFFICHER CONSECUTIVEMENT LE NOMBRE DE VOYAGES SEULS EFFECTUES PENDANT CHAQUE SAISON DANS UNE ANNEE:"<<endl;
        cout<<" 11 - AFFICHER LA PERIODE DU TEMPS DURANT LAQUELLE L'AGENCE A LE PLUS DE DEMANDES:"<<endl;
        cout<<" 12 - AFFICHER LA PERIODE DU TEMPS DURANT LAQUELLE L'AGENCE A LE MOINS DE DEMANDES:"<<endl;
        cout<<" 13 - AFFICHER LE NOMBRE DES CLIENTS DISTINCTS DE L'AGENCE DEPUIS SA CREATION:"<<endl;
        cout<<" 14 - AFFICHER LA TRANCHE D'AGES LA PLUS FREQUENTE DE LA CLIENTELE:"<<endl;
        cout<<" 15 - RETOUR"<<endl<<endl;
        cout<<" VOTRE CHOIX --> ";
        cin>>choix;
        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch(choix)
        {
            case 1 :
                afficher_nombre_voyages_total(tabVoyGroupe, tabVoySeul);
            break;
            case 2 :
                afficher_lemoyen_annuel_des_voyages(tabVoyGroupe, tabVoySeul);
            break;
            case 3 :
                afficher_lemoyen_annuel_des_voyages_engroupes(tabVoyGroupe);
            break;
            case 4 :
                afficher_lemoyen_annuel_des_voyages_seuls(tabVoySeul);
            break;
            case 5 :
                afficher_lemoyen_mensuel_des_voyages(tabVoyGroupe, tabVoySeul);
            break;
            case 6 :
                afficher_lemoyen_mensuel_des_voyages_engroupes(tabVoyGroupe);//tranche_age_frequente(tabClient);
            break;
            case 7 :
                afficher_lemoyen_mensuel_des_voyages_seuls(tabVoySeul);
            break;
            case 8 :
                afficher_lesvoyages_chaque_saison(tabVoyGroupe, tabVoySeul);
            break;
            case 9 :
                afficher_lesvoyages_engroupes_chaque_saison(tabVoyGroupe);
            break;
            case 10 :
                afficher_lesvoyages_seuls_chaque_saison(tabVoySeul);
            break;
            case 11 :
                la_periode_la_plus_demandee_par_annee(tabVoyGroupe, tabVoySeul);
            break;
            case 12 :
                la_periode_la_moins_demandee_par_annee(tabVoyGroupe, tabVoySeul);
            break;
            case 13 :
                afficher_nombre_clients_distincts(tabClient);
            break;
            case 14 :
                tranche_age_frequente(tabClient);
            break;
            case 15 :
            break;
            default :
                cout<<"MAUVAIS CHOIX VEUILLEZ SAISIR DE NOUVEAU LE NUMERO";
        }
    }while(choix!=15);
}
