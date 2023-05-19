#ifndef TELEFONSZAM_H
#define TELEFONSZAM_H

#include "string.h"

class Telefonszam { //telefonsz�mok l�trehoz�s�hoz
	String telefonszam; //A telefonsz�mot t�roljuk itt
public:
	Telefonszam() :telefonszam() {} //Egy �res Telefonszam-ot hoz l�tre
	Telefonszam(String _telefonszam) :telefonszam(_telefonszam) {} //Egy telefonsz�mot hoz l�tre a bej�v� String param�terrel
	String getTelefonszam() { return telefonszam; } //Visszaadja a telefonsz�mot
	void setTelefonszam(String _telefonszam) { if(_telefonszam.lehetETelefonszam()) telefonszam = _telefonszam; } //A telefonsz�mnak egy �j �rt�ket lehet be�ll�tani, figyelni kell, hogy egyedi maradjon a telefonsz�m
	Telefonszam& operator=(Telefonszam& _telefonszam); //Lehet, hogy f�lre�rtunk egy telefonsz�mot, a jav�t�s�hoz kell
};

#endif //TELEFONSZAM_H