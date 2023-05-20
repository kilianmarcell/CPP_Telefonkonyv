#include <iostream>
#include "dolgozo.h"
#include "telefonkonyv.h"

Ember* Telefonkonyv::getEmber(const String& nev) {
	for (size_t i = 0; i < emberek.getElemekSzama(); i++) {
		if (emberek[i]->getNev() == nev) return emberek[i];
	}
	return nullptr;
}

void Telefonkonyv::kiir() {
	std::cout << "N�v" << '\t' << "Becen�v" << '\t' << "C�m" << '\t' << "Telefonsz�m";
	for (size_t i = 0; i < egyebAdatok.getElemekSzama(); i++) {
		std::cout << '\t' << egyebAdatok[i]->getString();
	}
	std::cout << std::endl;
	for (size_t i = 0; i < emberek.getElemekSzama(); i++) {
		std::cout << *emberek[i] << std::endl;
	}
}