#ifndef STRINGPAR_H
#define STRINGPAR_H

#include "string.h"

class StringPar {//Egy extra adat megnevezését és értékét tároljuk itt
	String nev; //A további adat megnevezése
	String adat; //A további adat értéke
public:
	StringPar() :nev(String()), adat(String()) {} //Egy üres nevet és adat párt hoz létre
	StringPar(String _nev, String _adat) :nev(String(_nev)), adat(String(_adat)) {} //Egy _nev nevet és _adat adatot hoz létre
	String getNev() { return nev; } //Visszaadja a nevét az extra adatnak
	String getAdat() { return adat; } //Visszaadja az értékét az extra adatnak
	void setNev(String _nev) { nev = _nev; } //Beállíthatunk egy új értéket a névnek
	void setAdat(String _adat) { adat = _adat; } //Beállíthatunk egy új értéket az adatnak
	bool operator==(String _adat) { return adat == _adat; } //Megmondja, hogy megegyeik-e a két adat érték
};

#endif //STRINGPAR_H