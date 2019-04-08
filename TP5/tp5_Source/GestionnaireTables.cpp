/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include "LectureFichierEnSections.h"

void GestionnaireTables::lireTables(const string& nomFichier)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection("-TABLES");
	while (!fichier.estFinSection()) {
		int id, nbPlaces;
		fichier >> id >> nbPlaces;
		ajouter(new Table(id, nbPlaces));
	}
}

Table* GestionnaireTables::getTable(int id) const
{
	Table* pointeurTable(nullptr);
	for (set<Table*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		if (id == (*it)->getId())
		{
			pointeurTable = *it;
			break;
		}
	}
	return pointeurTable;
}
Table* GestionnaireTables::getMeilleureTable(int tailleGroupe) const
{
	Table* pointeurTable(nullptr);
	int nombreOptimise(NULL);
	for (set<Table*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		if (it == conteneur_.begin())
		{
			nombreOptimise = (*it)->getNbPlaces();
			pointeurTable = *it;
		}
		else if (nombreOptimise > (*it)->getNbPlaces())
		{
			nombreOptimise = (*it)->getNbPlaces();
			pointeurTable = *it;
		}
	}
	return pointeurTable;

}
void GestionnaireTables::afficherTables(ostream& os) const
{
	for (set<Table*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		os << *(*it) << endl;
	}
} 
 
GestionnaireTables& GestionnaireTables::operator+=(Table* table) {
	ajouter(table);
	return *this;
}