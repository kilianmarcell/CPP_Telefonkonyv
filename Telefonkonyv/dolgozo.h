#ifndef DOLGOZO_H
#define DOLGOZO_H

#include "ember.h"
#include "telefonszam.h"

class Dolgozo : public Ember { //Egy olyan ember adatait t�rolja, akinek csak munkahelyi telefonsz�ma van
	Telefonszam munkahelyiSzam; //Egy ember c�ges telefonsz�m�t
public:
	Dolgozo() :Ember() {} //L�trehoz egy �res Dolgozo-t
	String getEmberTelefonszam() override { return munkahelyiSzam.getTelefonszam(); } //Az ember c�ges telefonsz�m�t adja vissza
	void setEmberTelefonszam(Telefonszam _telefonszam) override { munkahelyiSzam = _telefonszam; } //Az ember c�ges telefonsz�m�t adja vissza
};

#endif //DOLGOZO_H