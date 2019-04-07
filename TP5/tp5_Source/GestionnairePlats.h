/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include "Plat.h"
#include "Vege.h"
#include "GestionnaireGenerique.h"
#include "Foncteur.h"

#include <utility>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
template<typename T, typename C>

class GestionnairePlats : public GestionnaireGenerique // TODO : Ajouter l'héritage 
{
public:
	GestionnairePlats(const string& nomFichier, TypeMenu type):type_(type)
	{
		lirePlats(nomFichier, type);
	} //TODO

	GestionnairePlats(GestionnairePlats* gestionnaire)
	{
		type_ = gestionnaire->getType();
		for (map<string, Plat*>::iterator it = gestionnaire->conteneur_.begin(); it != gestionnaire->conteneur_.end(); it++)
		{
			Plat* nouveauPlatPointeur = allouerPlat(it->second);
			conteneur_[it->first] = nouveauPlatPointeur;
		}


	}// TODO

	~GestionnairePlats()
	{
		for (map<string, Plat*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
		{
			delete it->second;
		}


	}// TODO

	TypeMenu getType() const
	{
		return type_;
	}// TODO

	Plat* allouerPlat(Plat* plat)
	{
		Plat * nouveauPlat = new Plat(plat);
		return nouveauPlat;
	}// TODO

	Plat* trouverPlatMoinsCher() const
	{ 
		Plat* platMoinsCher = min_element(conteneur_.begin(), conteneur_.end(), FoncteurPlatMoinsCher())->second;
		return platMoinsCher;

	}// TODO


	Plat* trouverPlatPlusCher() const
	{
		auto p = [](pair<string, Plat*> Pair1, pair<string, Plat*> Pair2) {
			return (Pair1.second->getPrix() > Pair2.second->getPrix());
		};

		return (max_element(conteneur_.begin(), conteneur_.end(), p))->second;
	}// TODO

	Plat* trouverPlat(const string& nom) const
	{
		for (map<string, Plat*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
		{
			if (nom == it->second->getNom())
			{
				return it->second;
			}
		}
		return nullptr;
	}// TODO

	vector<pair<string, Plat*>> getPlatsEntre(double borneInf, double borneSup)
	{
		FoncteurIntervalle foncteur(borneInf,borneSup);
		vector<pair<string, Plat*>> tableauPlatIntervalle;

		for (map<string, Plat*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
		{
			if (foncteur(it->second))//Si le prix du Plat est dans lintervalle
			{
				pair<string, Plat*> nouvelElementTableau;
				nouvelElementTableau.first = it->first;
				nouvelElementTableau.second = it->second;
				tableauPlatIntervalle.push_back(nouvelElementTableau);
			}

		}
		return tableauPlatIntervalle;
	}// TODO

	void lirePlats(const string& nomFichier, TypeMenu type);
	pair<string, Plat*> lirePlatDe(LectureFichierEnSections& fichier);

	void afficherPlats(ostream& os)
	{
		for (map<string, Plat*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
		{
			os<< *it->second<<endl;
		}
	}

private:
	TypeMenu type_;
};

