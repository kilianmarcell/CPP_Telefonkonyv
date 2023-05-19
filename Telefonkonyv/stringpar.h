#ifndef STRINGPAR_H
#define STRINGPAR_H

#include "string.h"

class StringPar {//Egy extra adat megnevez�s�t �s �rt�k�t t�roljuk itt
	String nev; //A tov�bbi adat megnevez�se
	String adat; //A tov�bbi adat �rt�ke
public:
	StringPar() :nev(String()), adat(String()) {} //Egy �res nevet �s adat p�rt hoz l�tre
	StringPar(String _nev, String _adat) :nev(String(_nev)), adat(String(_adat)) {} //Egy _nev nevet �s _adat adatot hoz l�tre
	String getNev() { return nev; } //Visszaadja a nev�t az extra adatnak
	String getAdat() { return adat; } //Visszaadja az �rt�k�t az extra adatnak
	void setNev(String _nev) { nev = _nev; } //Be�ll�thatunk egy �j �rt�ket a n�vnek
	void setAdat(String _adat) { adat = _adat; } //Be�ll�thatunk egy �j �rt�ket az adatnak
	bool operator==(String _adat) { return adat == _adat; } //Megmondja, hogy megegyeik-e a k�t adat �rt�k
};

#endif //STRINGPAR_H