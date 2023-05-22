#include <iostream>
#include "dolgozo.h"
#include "telefonkonyv.h"

Ember* Telefonkonyv::getEmber(const String& nev) {
	for (size_t i = 0; i < emberek.getElemekSzama(); i++) {
		if (emberek[i]->getNev() == nev) return emberek[i];
	}
	return nullptr;
}

void Telefonkonyv::removeEmber(String nev) {
	for (size_t i = 0; i < emberek.getElemekSzama(); i++) {
		if (emberek[i]->getNev() == nev) {
			delete emberek[i];
			emberek.remove(i);
		}
	}
}

void Telefonkonyv::kiir() {
	std::cout << "Név" << '\t' << "Becenév" << '\t' << "Cím" << '\t' << "Telefonszám";
	for (size_t i = 0; i < egyebAdatok.getElemekSzama(); i++) {
		std::cout << '\t' << egyebAdatok[i]->getString();
	}
	std::cout << std::endl;
	for (size_t i = 0; i < emberek.getElemekSzama(); i++) {
		std::cout << *emberek[i] << std::endl;
	}
}

Telefonkonyv::~Telefonkonyv() {
	for (size_t i = 0; i < emberek.getElemekSzama(); i++) delete emberek[i];
	for (size_t i = 0; i < egyebAdatok.getElemekSzama(); i++) delete egyebAdatok[i];
}