#ifndef MAGANEMBER_H
#define MAGANEMBER_H

#include "ember.h"
#include "telefonszam.h"

class Maganember : public Ember { //Egy olyan ember adatait t�rolja, akinek csak munkahelyi telefonsz�ma van
	Telefonszam privatSzam; //Egy ember c�ges telefonsz�m�t
public:
	Maganember() :Ember() {} //L�trehoz egy �res Maganember-t
	String getEmberTelefonszam() override { return privatSzam.getTelefonszam(); } //Az ember mag�n telefonsz�m�t adja vissza
	void setEmberTelefonszam(Telefonszam _telefonszam) override { privatSzam = _telefonszam; } //Az ember mag�n telefonsz�m�t adja vissza
	String getTipus() { return String("Maganember"); } //Megadja, hogy a p�ld�ny mag�nember
};

#endif //MAGANEMBER_H