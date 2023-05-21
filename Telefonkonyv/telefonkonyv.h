#ifndef TELEFONKONYV_H
#define TELEFONKONYV_H

#include "vektor.hpp"
#include "ember.h"

class Telefonkonyv { //Telefonk�nyvek l�trehoz�s�hoz
	Vektor<Ember*> emberek; //Ember t�mbb�l �ll a telefonk�nyv, az emberek adatait t�rolja, az Ember-ek felszabad�t�s�ra az oszt�lyon bel�l figyel�nk
	Vektor<String*> egyebAdatok; //Egy�b adatok megnevez�seit t�rolja
public:
	Telefonkonyv() :emberek(), egyebAdatok() {} //L�trehoz egy �res telefonk�nyvet, nincs benne egy Ember sem
	Ember* getEmber(size_t index) { return emberek[index]; } //Visszat�r az indexedik ember objektum pointer�vel
	Ember* getEmber(const String& nev); //Visszat�r a nev nev� ember objektum pointer�vel
	size_t getEmberekSzama() { return emberek.getElemekSzama(); } //Visszaadja, hogy h�ny ember van a telefonk�nyvben
	String* getEgyebAdatok(size_t index) { return egyebAdatok[index]; } //Visszaadja az indexedik egy�b adat nev�t
	size_t getEgyebAdatokSzama() { return egyebAdatok.getElemekSzama(); } //Visszaadja, hogy h�ny ember van a telefonk�nyvben
	void addEmber(Ember* ember) { emberek.add(ember); } //A telefonk�nyvh�z egy ember-t adunk hozz�
	void addEgyebAdat(String* nev) { egyebAdatok.add(nev); } //A telefonk�nyvh�z egy �j adatot adunk hozz�
	void removeEmber(String nev) { for(size_t i = 0; i < emberek.getElemekSzama(); i++) if(emberek[i]->getNev() == nev) emberek.remove(i); } //T�rli a nev nev� embert a telefonk�nyvb�l
	void removeEgyebAdat(String* nev) { for (size_t i = 0; i < egyebAdatok.getElemekSzama(); i++) if (egyebAdatok[i] == nev) egyebAdatok.remove(i); } //Az egy�b adatok nev megnevez�s� adat�t elt�vol�tjuk
	void kiir(); //Ki�rja az �sszes ember adatait, az els� sorba az adatt�pusok szerepelnek
};

#endif //TELEFONKONYV_H