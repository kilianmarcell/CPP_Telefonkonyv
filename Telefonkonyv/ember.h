#ifndef EMBER_H
#define EMBER_H

#include "string.h"
#include "stringpar.h"
#include "vektor.hpp"
#include "telefonszam.h"

class Ember { //Ember adatainak tárolásához
	String nev; //Az ember nevét tárolja
	String becenev; //Becenevét
	String cim; //Címét
	Vektor<StringPar*> masAdatok; //Az egyéb adatokat, amiket hozzáadtunk itt tároljuk
public:
	Ember() :nev(), becenev(), cim() {} //A sima konstruktor egyesével bekéri a felhasználótól az Ember paramétereit, az alapvetõ adatokat ki kell tölteni, az adatokat egyesével a set metódusok segítségével állítjuk majd be
	String getNev() { return nev; } //Az ember nevét adja vissza
	String getBecenev() { return becenev; } //Az ember becenevét adja vissza
	String getCim() { return cim; } //Az ember címét adja vissza
	virtual String getEmberTelefonszam() = 0; //Mindegyik származtatott osztálynak tudnunk kell majd a telefonszámát
	size_t getMasAdatokElemszama() { return masAdatok.getElemekSzama(); } //Az ember egyéb adatinak elemszámát adja vissza
	StringPar* getMasAdatokAdata(size_t index) { return masAdatok[index]; } //Az ember egyéb adatinak indexedik elemét adja vissza
	void setNev(String _nev) { if (!_nev.vanESzam()) nev = _nev; } //Az ember nevét módosítja
	void setBecenev(String _becenev) { if (!_becenev.vanESzam()) becenev = _becenev; } //Az ember becenevét módosítja
	void setCim(String _cim) { if (_cim.vanESzam()) cim = _cim; } //Az ember címét módosítja
	virtual void setEmberTelefonszam(Telefonszam _telefonszam) = 0; //Módosíthatjuk a származtatott osztályok telefonszámát
	void addMasAdatok(StringPar* sp) { masAdatok.add(sp); } //Az ember egyéb adati közül az indexedik elemét adja vissza
	void setMasAdatok(size_t index, String adat) { masAdatok[index]->setAdat(adat); } //Az ember egyéb adati közül az indexedik elemét adja vissza
	void removeMasAdatok(size_t index) { masAdatok.remove(index); } //Az ember egyéb adatinak indexedik elemét eltávolítja
	void kiir(); //Az ember adatait egymás alá kiírja, minden sorban megjelenítjük, hogy az ember melyik adattagja jelenik meg abban a sorban
	virtual String getTipus() = 0; //Megadja, hogy magánember, vagy dolgozó ember a példány
};

std::ostream& operator<<(std::ostream& os, Ember& ember); //Kiírja az ember adatait egymás mellé

#endif //EMBER_H