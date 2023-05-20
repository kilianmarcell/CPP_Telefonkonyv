#include <iostream>
#include "ember.h"

void Ember::kiir() {
	std::cout << "\n" << nev << " adatai\n" << std::endl;
	std::cout << "N�v: " << nev << std::endl;
	std::cout << "Becen�v: " << becenev << std::endl;
	std::cout << "C�m: " << cim << std::endl;
	std::cout << "Telefonsz�m: " << getEmberTelefonszam().getString() << std::endl;
	if (masAdatok.getElemekSzama() > 0) {
		for (size_t i = 0; i < masAdatok.getElemekSzama(); i++) {
			std::cout << masAdatok[i].getNev().getString() << ": " << masAdatok[i].getAdat().getString() << std::endl;
		}
	}
}

std::ostream& operator<<(std::ostream& os, Ember& ember) {
	os << ember.getNev() << '\t' << ember.getBecenev() << '\t' << ember.getCim() << '\t' << ember.getEmberTelefonszam();
	for (size_t i = 0; i < ember.getMasAdatokElemszama(); i++) {
		os << '\t' << ember.getMasAdatokAdata(i).getAdat().getString();
	}
	os << std::endl;

	return os;
}