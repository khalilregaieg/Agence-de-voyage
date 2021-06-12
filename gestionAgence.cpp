#include "gestionAgence.h"
using namespace std;

/***************************GESTION DES DESTINATIONS ******************/
void menu_gestion_destinations()
{   cout << endl ;
    cout << "   1- Afficher les destinations actuelles" << endl ;
    cout << "   2- Ajouter une destination" << endl ;
    cout << "   3- Supprimer une destination" << endl;
    cout << "   4- Retour au menu précédent" << endl << endl; 
}
void gerer_destinations(Destinations& tabDestination)
{
    int choix;
    do
    {
        menu_gestion_destinations();
        cout << "votre choix ---> ";
        cin >> choix;
        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (choix)
        {
        case 1:
            cout << tabDestination ; break;
        case 2:
            tabDestination.saisir_destination(); break;
        case 3:
                if (tabDestination.est_vide())
                    cout << " Aucune destination à enlever "<< endl;
                else
                    tabDestination.enlever_destination();
                break;
        case 4: break;
        default:
            cout << "Choix invalide, réessayez" << endl ; 
        }
    }
    while (choix != 4);
    
}

Destination choisir_destination(Destinations& tabDestination)
{
    if (tabDestination.est_vide())
        cout << "Aucune destination n'est disponible" << endl << endl;
    else
    {
        cout << endl;
        cout << " Les destinations disponibles :  "<< endl << endl;
        cout << tabDestination << endl;
        cout << "Choisir une destination :" << endl << endl;
        string pays;
        string ville;
        Destination dest;
        do
        {
            cout << " Donner le pays ---> ";
            cin >> pays;
            cout << " Donner la vile ---> ";
            cin >> ville;
            dest.setPays(pays);
            dest.setVille(ville);
            if (tabDestination.existe(dest) == -1)
                cout << endl << "   Choix invalide, réessayez "<< endl << endl;
        } 
        while (tabDestination.existe(dest) == -1);
        cout << endl << "La destination " << dest << " a été choisie." << endl << endl;
        return dest;
    }
}

/******************** GESTIONS DES GROUPES *******************************/
void menu_gestion_groupe()
{
    cout << endl;
    cout << "   1- Afficher tous les groupes" << endl;
    cout << "   2- Afficher tous les groupes pour une destination donnée" << endl;
    cout << "   3- Créer un nouveau groupe " << endl;
    cout << "   4- Annuler un voyage en groupe" << endl;
    cout << "   5- Retour" << endl << endl;
}

void saisir_voyage_en_groupe(voyagesEnGroupe& tabVoyGroupe, Destinations& tabDest)
{
    string idVoy = generer_id_voyage_groupe(tabVoyGroupe);
    Destination dest = choisir_destination(tabDest);
    Date dep = saisir_date_depart();
    Date ret = saisir_date_retour(dep);
    voyageEnGroupe voy (idVoy, dest, dep, ret);
    tabVoyGroupe.ajouter_voyageEnGroupe(voy);
    cout << endl << " Le groupe suivant a bien été ajouté : "<< endl;
    voy.afficher_voyage();
    cout << endl;
}

void annuler_voyage_groupe(voyagesEnGroupe& tabVoyGroupe, clients& tabClient)
{
    /*
    cout << "  Donner l'id du voyage en groupe que vous voulez annuler" << endl;
    cout << " ---> ";*/
    vector<string> tabId = tabVoyGroupe.tous_les_groupes();
    string idVoy = saisir_idVoyage_groupe(tabId);
    tabVoyGroupe.annuler_voyage(idVoy); // suppression de tabVoyGroupe
    tabClient.annuler_voyage(idVoy); //supprime le voyage pour tous les clients qui y participent
    cout << " Le voyage en groupe a bien été annulé." << endl << endl;
}

void gerer_groupes(voyagesEnGroupe& tabVoyGroupe, Destinations& tabDest, clients& tabClient)
{
    if (tabDest.nb_dest()==0)
        cout << endl << "  Veuillez ajouter des destinations" << endl << endl;
    else
    {
        int choix;
        do
        {
            menu_gestion_groupe();
            cout << "votre choix ---> ";
            cin >> choix;
            if (!cin)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (choix == 1)
            {
                tabVoyGroupe.afficher_groupes();
            }   
            if (choix == 2)
            {
                if (tabVoyGroupe.est_vide())
                    cout << endl << " Aucun groupe pour le moment " << endl;
                else
                {
                    Destination dest = choisir_destination(tabDest);
                    tabVoyGroupe.afficher_groupes(dest);
                }
            }  
            if (choix == 3)
                saisir_voyage_en_groupe(tabVoyGroupe, tabDest);
            if (choix == 4)
                annuler_voyage_groupe(tabVoyGroupe, tabClient);
        } 
        while  (choix != 5);  
    }    
}




/********************    GESTION DES CLIENTS ******************************/
bool en_groupe(string id)
{
    if (id.substr(0,3) == "000")
        return false;
    return true;
}
string generer_id_voyage_seul(voyagesSeul& tabVoySeul)
{
    srand(time(0));
    string id;
    do
    {
        long x = rand() % 10000 + 89999;
        id = to_string(x);
        id = "000" + id;
    }
    while ( tabVoySeul.existe(id) != -1 );
    return id;
}

string generer_id_voyage_groupe(voyagesEnGroupe& tabVoyGroupe)
{
    srand(time(0));
    string id;
    do
    {
        long x = rand() % 10000 + 89999;
        id = to_string(x);
        int nb = tabVoyGroupe.nb_voyagesEnGroupe() +1;
        string ch = to_string(nb);
        string ch1;
        if (nb < 10)
        {
            ch1 = "00"+ch;
        }
        if ((nb<100) && (nb >= 10))
        {
            ch1 = "0"+ch;
        }
        if ((nb >=100))
        {
            ch1 = ch;
        }
        id = ch1 + id;
    }
    while ( tabVoyGroupe.existe(id) != -1 );
    return id;
}


int existe(vector<string>& vect, const string& ch)
{
    for (int i=0; i < vect.size(); i++)
        if ( vect[i] == ch )
            return i;
    return -1;
}
string saisir_idVoyage_groupe( vector<string>& dispo)
{
    cout << endl << "Saisir l'id voyage du groupe choisi :" << endl;
    cout << "   --->  ";
    string id;
    do
    {
        cin >> id;
        if (existe(dispo, id) == -1)
            cout << "Id incorrect ,réessayez ---> "; 
    }
    while (existe(dispo, id) == -1);
    return id;
}

void voyager_en_groupe(const string& numPass, clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDestinations)
{
    int choix;
    do
    {
        cout << endl << "   1- Afficher tous les groupes disponibles" << endl;
        cout << "   2- Afficher tous les groupes pour une certaine destination" << endl;
        cout << "   3- Retour" << endl << endl;
        cout << "votre choix ---> ";
        cin >> choix;
        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (choix == 1)
        {
            vector<string> dispo = tabVoyGroupe.groupes_disponibles();
            if (dispo.size()==0)
                cout << " Aucun groupe n'est diponible pour le moment " << endl << endl;
            if (dispo.size() != 0)
            {
                string idVoy = saisir_idVoyage_groupe(dispo);
                if (tabVoyGroupe.getVoyage(idVoy).est_paticipant(numPass) != -1)
                    cout << " Le client participe déja à ce voyage en groupe "<< endl << endl;
                else
                {
                    tabVoyGroupe.getVoyage(idVoy).ajouter_participant(numPass);
                    tabClient.getClient(numPass).ajouter_voyage(idVoy);
                    cout << endl << "  L'ajout au groupe a été bien effectué" << endl << endl;
                }
            }
        }
        if (choix == 2)
        {
            Destination dest = choisir_destination( tabDestinations) ;
            vector<string> dispo = tabVoyGroupe.groupes_disponibles(dest);
            if (dispo.size() != 0)
            {
                string idVoy = saisir_idVoyage_groupe(dispo);
                tabVoyGroupe.getVoyage(idVoy).ajouter_participant(numPass);
                tabClient.getClient(numPass).ajouter_voyage(idVoy);
                cout << endl << "  L'ajout au groupe a été bien effectué" << endl << endl;
            }
        }
    } while (choix != 3);    
}

void nouveau_voyage(const string& numPass, clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDestinations)
{
    int choix;
    do
    {
        cout << endl << "   1- Voyager seul" << endl;
        cout << "   2- Voyager en groupe" <<endl;
        cout << "   3- Retour" << endl << endl;
        cout << endl << "votre choix --->";
        cin >> choix;
        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (choix == 1)
        {
            Destination dest = choisir_destination(tabDestinations);
            Date dep = saisir_date_depart();
            Date ret = saisir_date_retour(dep);
            string idVoy = generer_id_voyage_seul(tabVoySeul);
            voyageSeul voyS (idVoy, numPass, dest, dep, ret);
            tabVoySeul.ajouter_voyageSeul(voyS);// ajout du voyage au tableau des voyages seul
            tabClient.getClient(numPass).ajouter_voyage(idVoy);// ajout de l'id voyage au tableau des voyages du client
            cout << endl <<  "Le voyage à bien été créé " << endl;
        }
        if (choix == 2)
            voyager_en_groupe(numPass, tabClient, tabVoySeul, tabVoyGroupe, tabDestinations);
    } while (choix != 3); 
}

void menu_ancien_client()
{
    cout << endl;
    cout << "   1- Nouveau voyage" << endl;
    cout << "   2- Afficher les voyages à venir" << endl;
    cout << "   3- Afficher tous les voyages" << endl;
    cout << "   4- Annuler un voyage" << endl;
    cout << "   5- Afficher les informations du client "<< endl;
    cout << "   6- Retour" << endl << endl; 
}

void afficher_voyages_client(const string& numPass, clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe)
{
    vector<string> voyG = tabVoyGroupe.afficher_voyages_client(numPass);
    vector<string> voyS = tabVoySeul.afficher_voyages_client(numPass);
    voyS.insert(voyS.end(), voyG.begin(), voyG.end());
    if (voyS.size()==0)
        cout << " Le client n'a aucun voyage pour le moment " << endl;
};

vector<string> afficher_futur_voyages_client(const string& numPass, clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe)
{
    vector<string> voyG = tabVoyGroupe.afficher_futur_voyages_client(numPass);
    vector<string> voyS = tabVoySeul.afficher_futur_voyages_client(numPass);
    voyS.insert(voyS.end(), voyG.begin(), voyG.end());
    if (voyS.size()==0)
        cout << " Le client n'a aucun voyage dans le futur " << endl;
    return voyS;
}

string saisir_id_voyage_client(vector<string>& tabVoy)
{
    cout << endl << "Saisir l'id du voyage à annuler " << endl;
    string id;
    do
    {
        cin >> id;
        if (existe(tabVoy, id) == -1)
            cout << "Id incorrect ,réessayez ---> "; 
    }
    while (existe(tabVoy, id) == -1);
    return id;
}

void annuler_voyage_client(const string& numPass, clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe)
{
    vector<string> tabVoy = afficher_futur_voyages_client(numPass, tabClient, tabVoySeul, tabVoyGroupe);
    string idVoy = saisir_id_voyage_client(tabVoy);
    if (!en_groupe(idVoy))
    {
        tabClient.getClient(numPass).annuler_voyage(idVoy); //suppression de l'idVoy du client
        tabVoySeul.annuler_voyage(idVoy);   // supression du tableau des voyages seul
        cout << "Le voyage a bien été annulé"<< endl  << endl;
    }
    else
    {
        tabClient.getClient(numPass).annuler_voyage(idVoy); // suppression pour le client
        tabVoyGroupe.annuler_voyage(idVoy); // supprimer le client du groupe
        cout << "Le voyage en groupe a bien été annulé "<< endl << endl;
    }
}

void gerer_ancien_client(const string& numPass, clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDestinations)
{
    int choix;
    do
    {
        menu_ancien_client();
        cout << "votre choix ---> ";
        cin >> choix;
        if (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (choix)
        {
            case 1:
                nouveau_voyage(numPass, tabClient, tabVoySeul, tabVoyGroupe, tabDestinations);
                break;
            case 2:
                afficher_futur_voyages_client(numPass, tabClient, tabVoySeul, tabVoyGroupe);
                break;
            case 3:
                afficher_voyages_client(numPass, tabClient, tabVoySeul, tabVoyGroupe);
                break;
            case 4:
                annuler_voyage_client(numPass, tabClient, tabVoySeul, tabVoyGroupe);
                break;
            case 5:
                cout << tabClient.getClient(numPass);
            default:
                break;
        }

        } while (choix != 6);
}

void gerer_clients(clients& tabClient, voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDestinations)
{
    if (tabDestinations.nb_dest()==0)
        cout << endl << "  Veuillez ajouter des destinations" << endl << endl;
    else
    {
        string numPass;
        cout << "  Donner un numéro passeport :" << endl;
        numPass = saisir_numPasseport();
        // si c'est un ancien client :
        if (tabClient.existe(numPass) != -1)
            gerer_ancien_client(numPass, tabClient, tabVoySeul, tabVoyGroupe, tabDestinations);
    
    
        if ( tabClient.existe(numPass) == -1)
        {
            //ajout du nouveau client
            tabClient.saisir_client(numPass);
            //nouveau voyage
            nouveau_voyage(numPass, tabClient, tabVoySeul, tabVoyGroupe, tabDestinations);
        
            //on répéte la meme chose que pour un ancien client
            gerer_ancien_client(numPass, tabClient, tabVoySeul, tabVoyGroupe, tabDestinations);
        }   
    }
}






/*************** reste des fonctions ****************************/
void afficher_tous_les_voyages(voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, clients& tabClient)
{
    if ((tabVoySeul.nb_voyagesSeul()+tabVoyGroupe.nb_voyagesEnGroupe()) == 0)
        cout << endl << "  Aucun voyage pour le moment " << endl << endl;
    if (tabVoyGroupe.nb_voyagesEnGroupe()!=0)
    {
        cout << endl << "Les voyages en groupes :  " << endl;
        tabVoyGroupe.afficher_groupes();
    }
    if (tabVoySeul.nb_voyagesSeul()!=0)
    {
        cout << endl << "Les voyages de clients seul : " << endl << endl;
        tabVoySeul.afficher_voyagesSeul(tabClient);
    }
}

void retarder_tous_les_voyages(voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe)
{
    Date d;
    do
    {
        cout << "  Donner la date pour laquelle vous voulez retarder tous les voyages : " << endl;
        cout << "  --->  ";
        d = saisir_date();
    }
    while ((d < date_systeme()) || ( d == date_systeme()));
    int retS = tabVoySeul.retarder_voyages_seul(d);
    int retG = tabVoyGroupe.retarder_voyages_en_groupe(d);
    if (retS != 0)
    {
        if (retS == 1 )
            cout << endl << "   " << retS << " voyage seul a été retardé" << endl << endl;
        else
            cout << endl << "   " << retS << " voyages seul ont été retardé" << endl << endl;
    }
    if (retG != 0)
    {
        if (retG == 1 )
            cout << endl << "   " << retG << " voyage en groupe a été retardé" << endl << endl;
        else
            cout << endl << "   " << retG << " voyages en groupe ont été retardé" << endl << endl;
    }
    if ((retS==0) && (retG ==0))
        cout << endl << "  Aucun voyage n'a été retardé" << endl << endl;
}

void liste_voyages_pays(voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, Destinations& tabDest)
{
    if (tabDest.nb_dest()==0)
        cout << endl << "  Il faut ajouter des destinations "<< endl << endl;
    else
    {
        for (int i=0; i < tabDest.nb_dest(); i++)
        {
            Destination d = tabDest.getDest(i);
            cout << endl;
            cout << "  ----- POUR LA DESTINATION -----  " << d << endl;
            cout << endl << "    Les voyages seul :" << endl << endl;
            tabVoySeul.liste_voyages_pays(d);
            cout << "    Les voyages en groupe :" << endl;
            tabVoyGroupe.afficher_groupes(d);
        }   
    }
}


void client_gagnant(voyagesSeul& tabVoySeul, voyagesEnGroupe& tabVoyGroupe, clients& tabClient, Destinations& tabDest)
{
    if (tabClient.nb_clients() == 0)
        cout << endl << " Aucun client pour effectuer le tirage " << endl << endl;
    else
    {
        string numPass;
        numPass = tabClient.numPass_client_gagnant();
        cout << "  Le client gagnant  : " << endl;
        cout << tabClient.getClient(numPass) << endl;
        cout << "  Saisir le nouveau voyage pour le client gagnant :"<< endl;
        nouveau_voyage(numPass, tabClient, tabVoySeul, tabVoyGroupe, tabDest);
    }
}