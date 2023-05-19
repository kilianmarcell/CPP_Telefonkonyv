#ifndef TELEFONSZAM_H
#define TELEFONSZAM_H

#include "string.h"

class Telefonszam { //telefonszámok létrehozásához
	String telefonszam; //A telefonszámot tároljuk itt
public:
	Telefonszam() :telefonszam() {} //Egy üres Telefonszam-ot hoz létre
	Telefonszam(String _telefonszam) :telefonszam(_telefonszam) {} //Egy telefonszámot hoz létre a bejövõ String paraméterrel
	String getTelefonszam() { return telefonszam; } //Visszaadja a telefonszámot
	void setTelefonszam(String _telefonszam) { if(_telefonszam.lehetETelefonszam()) telefonszam = _telefonszam; } //A telefonszámnak egy új értéket lehet beállítani, figyelni kell, hogy egyedi maradjon a telefonszám
	Telefonszam& operator=(Telefonszam& _telefonszam); //Lehet, hogy félreírtunk egy telefonszámot, a javításához kell
};

#endif //TELEFONSZAM_H