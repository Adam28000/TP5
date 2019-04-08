/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;


class FoncteurPlatMoinsCher
{ 

public:
	//--------------------------------------------------------------
	//Nom: FoncteurPlatMoinsCher()
	//Description: Constructeur sans parametres du foncteur FoncteurPlatMoinsCher
	//Elle ne retourne rien
	//--------------------------------------------------------------
	FoncteurPlatMoinsCher() {};
	//Nom:FoncteurPlatMoinsCher()
	//Description:operator()(pair<string, Plat* >plat1, pair<string, Plat*>plat2)
	//Parametre 1 : pair<string, Plat*>plat1, plat 1 à comparer
	//Parametre 2 : pair<string, Plat*>plat2, plat 2 à comparer 
	//Elle retourne vrai si le prix du plat 2 est supérieur a celui
	//du plat 1 et faux sinon
	//----------------------------------------------------------------
     bool operator()(pair<string, Plat* >plat1, pair<string, Plat*>plat2){
		return plat1.second->getPrix() <plat2.second->getPrix();
	}

};

class FoncteurIntervalle
{
         // TODO
public:
	///Nom:FoncteurIntervalle(double inf, double Sup)
	//Description:FoncteurIntervalle(double inf, double sup)
	//Constructeur avec parametres du foncteur FoncteurIntervalle
	//qui initialise les attributs borne_Inf_ et borne_Sup_
	//Elle ne retourne rien
	//--------------------------------------------------------------
	FoncteurIntervalle(double inf, double Sup) :borne_Inf_(inf), borne_Sup_(Sup){};
	//Nom:bool operator()(pair<string, Plat* > p)
	//Description:operator()(pair<string, Plat*>p)
	//Parametre : pair<string, Plat*>p, 
	//Elle retourne vrai si le prix du plat 2 est compris dans
	//l'intervalle définint par les attributs
	//----------------------------------------------------------------
	bool operator()(pair<string, Plat* > p){
		return (borne_Inf_ <= p.second->getPrix() && p.second->getPrix()<= borne_Sup_);
	}
private:
double  borne_Inf_;
double  borne_Sup_;
};

