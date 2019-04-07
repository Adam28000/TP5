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
{ // TODO

public:
	bool operator()(Plat* plat1, Plat* plat2 ) const
	{
		return plat1->getPrix() <= plat2->getPrix();

	}
	/*void setPlat1(Plat* plat)
	{
		plat1_ = plat;
	}
	void setPlat2(Plat* plat)
	{
		plat2_ = plat;
	}
private:
	Plat* plat1_;
	Plat* plat2_;
	*/

    
};

class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup):borneInf_(borneInf),borneSup_(borneSup)
	{

	}

	bool operator()(Plat* platDuConteneur) const
	{
		double prixPlat = platDuConteneur->getPrix();
		if (prixPlat > borneSup_ || prixPlat < borneInf_)
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	void setBorneInf(double borne)
	{
		borneInf_ = borne;
	}
	void setBorneSup(double borne)
	{
		borneSup_ = borne;
	}
   // TODO


public:
	double borneInf_;
	double borneSup_;
};

