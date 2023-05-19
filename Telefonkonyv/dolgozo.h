#ifndef DOLGOZO_H
#define DOLGOZO_H

#include "ember.h"
#include "telefonszam.h"

class Dolgozo : public Ember { //Egy olyan ember adatait tárolja, akinek csak munkahelyi telefonszáma van
	Telefonszam munkahelyiSzam; //Egy ember céges telefonszámát
public:
	Dolgozo() :Ember() {} //Létrehoz egy üres Dolgozo-t
	String getEmberTelefonszam() override { return munkahelyiSzam.getTelefonszam(); } //Az ember céges telefonszámát adja vissza
	void setEmberTelefonszam(Telefonszam _telefonszam) override { munkahelyiSzam = _telefonszam; } //Az ember céges telefonszámát adja vissza
};

#endif //DOLGOZO_H