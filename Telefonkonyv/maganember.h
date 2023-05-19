#ifndef MAGANEMBER_H
#define MAGANEMBER_H

#include "ember.h"
#include "telefonszam.h"

class Maganember : public Ember { //Egy olyan ember adatait tárolja, akinek csak munkahelyi telefonszáma van
	Telefonszam privatSzam; //Egy ember céges telefonszámát
public:
	Maganember() :Ember() {} //Létrehoz egy üres Maganember-t
	String getEmberTelefonszam() override { return privatSzam.getTelefonszam(); } //Az ember magán telefonszámát adja vissza
	void setEmberTelefonszam(Telefonszam _telefonszam) override { privatSzam = _telefonszam; } //Az ember magán telefonszámát adja vissza
};

#endif //MAGANEMBER_H