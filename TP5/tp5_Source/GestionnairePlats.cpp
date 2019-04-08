/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#include "GestionnairePlats.h"
#include "LectureFichierEnSections.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"


GestionnairePlats::GestionnairePlats(const string& nomFichier, TypeMenu type) :type_(type)
{
	lirePlats(nomFichier, type);
}

GestionnairePlats::GestionnairePlats(GestionnairePlats* gestionnaire)
{
	type_ = gestionnaire->getType();
	for (map<string, Plat*>::iterator it = gestionnaire->conteneur_.begin(); it != gestionnaire->conteneur_.end(); it++)
	{
		Plat* nouveauPlatPointeur = allouerPlat(it->second);
		conteneur_[it->first] = nouveauPlatPointeur;
	}


}

GestionnairePlats::~GestionnairePlats()
{
	for (map<string, Plat*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		delete it->second;
	}


}

TypeMenu GestionnairePlats::getType() const
{
	return type_;
}

Plat* GestionnairePlats::allouerPlat(Plat* plat)
{
	Plat * nouveauPlat = new Plat(*plat);
	return nouveauPlat;
}

Plat* GestionnairePlats::trouverPlatMoinsCher() const
{
	Plat* platMoinsCher = min_element(conteneur_.begin(), conteneur_.end(), FoncteurPlatMoinsCher())->second;
	return platMoinsCher;

}

Plat* GestionnairePlats::trouverPlatPlusCher() const
{
	auto p = [](pair<string, Plat*> Pair1, pair<string, Plat*> Pair2) {
		return (Pair1.second->getPrix() > Pair2.second->getPrix());
	};

	return (max_element(conteneur_.begin(), conteneur_.end(), p))->second;
}

Plat* GestionnairePlats::trouverPlat(const string& nom) const
{
	auto it = conteneur_.find(nom); // retourne iterateur pointant a l'element qui contient la cle
	if (it != conteneur_.end())
		return it->second;
	else
		return nullptr;
}

vector<pair<string, Plat*>> GestionnairePlats::getPlatsEntre(double borneInf, double borneSup)
{
	FoncteurIntervalle foncteur(borneInf, borneSup);
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
}

void GestionnairePlats::lirePlats(const string& nomFichier, TypeMenu type)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type)]);
	while (!fichier.estFinSection())
		ajouter(lirePlatDe(fichier));
}

pair<string, Plat*> GestionnairePlats::lirePlatDe(LectureFichierEnSections& fichier)
{
	auto lectureLigne = fichier.lecteurDeLigne();
	Plat* plat;
	string nom, typeStr;
	TypePlat type;
	double prix, coutDeRevient;
	lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
	type = TypePlat(stoi(typeStr));
	double ecotaxe, vitamines, proteines, mineraux;
	switch (type) {
	case TypePlat::Bio:
		lectureLigne >> ecotaxe;
		plat = new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
		break;
	case TypePlat::BioVege:
		lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
		plat = new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
		break;
	case TypePlat::Vege:
		lectureLigne >> vitamines >> proteines >> mineraux;
		plat = new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
		break;
	default:
		plat = new Plat{ nom, prix, coutDeRevient };
	}
	return pair<string, Plat*>(plat->getNom(), plat);
}

void GestionnairePlats::afficherPlats(ostream& os)
{
	for (map<string, Plat*>::iterator it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		os << it->second << endl;
	}
}
