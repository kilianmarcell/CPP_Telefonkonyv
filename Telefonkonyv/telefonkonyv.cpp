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
	std::cout << "Név" << '\t' << "Becenév" << '\t' << "Cím";
	for (size_t i = 0; i < emberek[0]->getMasAdatokElemszama(); i++) {
		std::cout << '\t' << emberek[0]->getMasAdatokAdata(i).getNev();
	}
	std::cout << std::endl;
	for (size_t i = 0; i < emberek.getElemekSzama(); i++) {
		std::cout << *emberek[i] << std::endl;
	}
}