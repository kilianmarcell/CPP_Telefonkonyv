#ifndef TELEFONKONYV_H
#define TELEFONKONYV_H

#include "vektor.hpp"
#include "ember.h"

class Telefonkonyv { //Telefonkönyvek létrehozásához
	Vektor<Ember*> emberek; //Ember tömbbõl áll a telefonkönyv, az emberek adatait tárolja, az Ember-ek felszabadítására az osztályon belül figyelünk
	Vektor<String*> egyebAdatok; //Egyéb adatok megnevezéseit tárolja
public:
	Telefonkonyv() :emberek(), egyebAdatok() {} //Létrehoz egy üres telefonkönyvet, nincs benne egy Ember sem
	Ember* getEmber(size_t index) { return emberek[index]; } //Visszatér az indexedik ember objektum pointerével
	Ember* getEmber(const String& nev); //Visszatér a nev nevû ember objektum pointerével
	size_t getEmberekSzama() { return emberek.getElemekSzama(); } //Visszaadja, hogy hány ember van a telefonkönyvben
	String* getEgyebAdatok(size_t index) { return egyebAdatok[index]; } //Visszaadja az indexedik egyéb adat nevét
	size_t getEgyebAdatokSzama() { return egyebAdatok.getElemekSzama(); } //Visszaadja, hogy hány ember van a telefonkönyvben
	void addEmber(Ember* ember) { emberek.add(ember); } //A telefonkönyvhöz egy ember-t adunk hozzá
	void addEgyebAdat(String* nev) { egyebAdatok.add(nev); } //A telefonkönyvhöz egy új adatot adunk hozzá
	void removeEmber(String nev) { for(size_t i = 0; i < emberek.getElemekSzama(); i++) if(emberek[i]->getNev() == nev) emberek.remove(i); } //Törli a nev nevû embert a telefonkönyvbõl
	void removeEgyebAdat(String* nev) { for (size_t i = 0; i < egyebAdatok.getElemekSzama(); i++) if (egyebAdatok[i] == nev) egyebAdatok.remove(i); } //Az egyéb adatok nev megnevezésû adatát eltávolítjuk
	void kiir(); //Kiírja az összes ember adatait, az elsõ sorba az adattípusok szerepelnek
};

#endif //TELEFONKONYV_H