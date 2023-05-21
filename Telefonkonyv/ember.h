#ifndef EMBER_H
#define EMBER_H

#include "string.h"
#include "stringpar.h"
#include "vektor.hpp"
#include "telefonszam.h"

class Ember { //Ember adatainak t�rol�s�hoz
	String nev; //Az ember nev�t t�rolja
	String becenev; //Becenev�t
	String cim; //C�m�t
	Vektor<StringPar*> masAdatok; //Az egy�b adatokat, amiket hozz�adtunk itt t�roljuk
public:
	Ember() :nev(), becenev(), cim() {} //A sima konstruktor egyes�vel bek�ri a felhaszn�l�t�l az Ember param�tereit, az alapvet� adatokat ki kell t�lteni, az adatokat egyes�vel a set met�dusok seg�ts�g�vel �ll�tjuk majd be
	String getNev() { return nev; } //Az ember nev�t adja vissza
	String getBecenev() { return becenev; } //Az ember becenev�t adja vissza
	String getCim() { return cim; } //Az ember c�m�t adja vissza
	virtual String getEmberTelefonszam() = 0; //Mindegyik sz�rmaztatott oszt�lynak tudnunk kell majd a telefonsz�m�t
	size_t getMasAdatokElemszama() { return masAdatok.getElemekSzama(); } //Az ember egy�b adatinak elemsz�m�t adja vissza
	StringPar* getMasAdatokAdata(size_t index) { return masAdatok[index]; } //Az ember egy�b adatinak indexedik elem�t adja vissza
	void setNev(String _nev) { if (!_nev.vanESzam()) nev = _nev; } //Az ember nev�t m�dos�tja
	void setBecenev(String _becenev) { if (!_becenev.vanESzam()) becenev = _becenev; } //Az ember becenev�t m�dos�tja
	void setCim(String _cim) { if (_cim.vanESzam()) cim = _cim; } //Az ember c�m�t m�dos�tja
	virtual void setEmberTelefonszam(Telefonszam _telefonszam) = 0; //M�dos�thatjuk a sz�rmaztatott oszt�lyok telefonsz�m�t
	void addMasAdatok(StringPar* sp) { masAdatok.add(sp); } //Az ember egy�b adati k�z�l az indexedik elem�t adja vissza
	void setMasAdatok(size_t index, String adat) { masAdatok[index]->setAdat(adat); } //Az ember egy�b adati k�z�l az indexedik elem�t adja vissza
	void removeMasAdatok(size_t index) { masAdatok.remove(index); } //Az ember egy�b adatinak indexedik elem�t elt�vol�tja
	void kiir(); //Az ember adatait egym�s al� ki�rja, minden sorban megjelen�tj�k, hogy az ember melyik adattagja jelenik meg abban a sorban
	virtual String getTipus() = 0; //Megadja, hogy mag�nember, vagy dolgoz� ember a p�ld�ny
};

std::ostream& operator<<(std::ostream& os, Ember& ember); //Ki�rja az ember adatait egym�s mell�

#endif //EMBER_H