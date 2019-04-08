/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include "Table.h"
#include "Foncteur.h"
#include "GestionnaireGenerique.h"
#include<iterator>
#include <set>
#include "algorithm"
#include<functional>
using namespace std;
using namespace std::placeholders;


class GestionnaireTables:public GestionnaireGenerique <Table*, set<Table*>>// TODO : Ajouter l'héritage 
{
public:
	
	//Nom:GestionnaireTables()
	//Description:Constructeur de la classe GestionnaireTables
	//Retour:Elle ne retourne rien
	//---------------------------------------------------------------------------------
	GestionnaireTables() = default;
	//-----------------------------------------------------
	//Nom: getTable(int id)
	//Description: Permet de trouver la table dans le conteneur avec l'id voulu
	//Retour: Elle retourne un pointeur vers cette table
	//-----------------------------------------------------
	Table* getTable(int id) const; // TODO
	//-----------------------------------------------------
	//Nom:getMeilleureTable(int tailleGroupe)
	//Description:Permet de trouver la table la plus petite pouvant contenir le groupe de taille tailleGroupe
	//Retour: Elle retourne un pointeur vers cette table
	//-----------------------------------------------------
	Table* getMeilleureTable(int tailleGroupe) const; // TODO
	//--------------------------------------------------------------------------------
	//Nom: lireTables(const string& nomFichier)
	//Description: Permet de lire les tables dans un fichier dont on specifie le nom et le type de menu
	//Parametre  : const string& nomFichier, pour le nom du fichier a lire
	//Retour:Elle ne retourne rien
	//---------------------------------------------------------------------------------
	void lireTables(const string& nomFichier);
	//----------------------------------------------------------
	//Nom:operator+=(Table* table)
	//Description:Permet d'ajouter la table dans le gestionnaire de tables
	//Parametre  : Table* table pour la table que l'on veut ajouter
	//Retour:Elle retourne une reference a l'objet courant
	//----------------------------------------------------------
	GestionnaireTables& operator+=(Table* table);
	//-----------------------------------------------------
	//Nom:afficherTables(ostream& os)
	//Description:Permet d'afficher les caractéristiques des Tables 
	//Parametre  : ostream& o correspond au flux
	//Retour :Elle retourne les caractéristiques des tables
	//-----------------------------------------------------
	void afficherTables(ostream& os) const; // TODO
};