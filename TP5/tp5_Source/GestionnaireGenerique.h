/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Foncteur.h"

using namespace  std;

//              T   = pair<string, Plat*> ou Table*; 
//              C   = map<string, Plat*> ou set<Table*>; 
template<typename T, typename C>
class GestionnaireGenerique
{
public:
	//Nom:getConteneur()
	//Description:Donne l'accès a l'attribut conteneur_
	//Retour:Elle retourne l'attribut conteneur_
	//-----------------------------------------------------
	C getConteneur() const {return conteneur_;}//TODO
	//-----------------------------------------------------
	//Nom:ajouter(T t)
	//Description:Permet d'ajouter un élément au conteneur conteneur_
	//Retour:Elle ne retourne rien
	//-----------------------------------------------------
	inline void ajouter(T t) {
	     conteneur_.insert(t);
	}//TODO
	//-----------------------------------------------------
	//Nom:getNombreElements()
	//Description:Donne l'accès a la taille du conteneur
	//Retour:Elle retourne la taille du conteneur_
	//-----------------------------------------------------
	int getNombreElements() const { return conteneur_.size(); }//TODO

protected:
	C conteneur_;
};
