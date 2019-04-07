/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include "Table.h"
#include "Foncteur.h"
#include "GestionnaireGenerique.h"

#include <set>

template<typename T, typename C>
class GestionnaireTables // TODO : Ajouter l'héritage 
{
public:
	GestionnaireTables() = default;
	Table* getTable(int id) const
	{
		Table* pointeurTable(nullptr);
		for (set<Table*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
		{
			if (id == *it->getId())
			{
				pointeurTable = *it;
				break;
			}
		}
		return pointeurTable;
	}
	// TODO
	Table* getMeilleureTable(int tailleGroupe) const
	{
		Table* pointeurTable(nullptr);
		int nombreOptimise(NULL);
		for (set<Table*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
		{	
			if (it== conteneur_.begin())
			{
				nombreOptimise = *it->getNbPlaces();
				pointeurTable = *it;
			}
			else if (nombreOptimise > *it->getNbPlaces())
			{
				nombreOptimise = *it->getNbPlaces();
				pointeurTable = *it;
			}
		}
		return pointeurTable;

	}// TODO
	void lireTables(const string& nomFichier);

	void afficherTables(ostream& os) const
	{
		for (set<Table*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
		{
			os << *(*it) << endl;
		}
	} // TODO
};