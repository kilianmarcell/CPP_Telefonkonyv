#include <Windows.h>
#include <iostream>
#include "memtrace.h"
#include "string.h"
#include "stringpar.h"
#include "vektor.hpp"
#include "ember.h"
#include "maganember.h"
#include "dolgozo.h"
#include "telefonszam.h"
#include "telefonkonyv.h"
#include "teszt.h"

Telefonkonyv teleonkonyv_letrehoz();
void telefonkonyv_mentes(Telefonkonyv t);
Telefonkonyv telefonkonyv_betolt();
Telefonkonyv menu();
void telefonkonyv_muveletek(Telefonkonyv t);
void ember_hozzaadasa(Telefonkonyv t);
void ember_eltavolitasa(Telefonkonyv t);
void ember_modositasa(Telefonkonyv t);
void adat_felvetele(Telefonkonyv t);
void ember_keresese(Telefonkonyv t);
void ember_letrehozasa(Telefonkonyv t, Ember* e);

Telefonkonyv teleonkonyv_letrehoz() {
	Telefonkonyv t = Telefonkonyv();
	return t;
}

void telefonkonyv_mentes(Telefonkonyv t) {
	std::cout << "Mi legyen a f�jl neve?" << std::endl;
	String beolvas = String();
	std::cin >> beolvas;
	beolvas += '.';
	beolvas += 't';
	beolvas += 'x';
	beolvas += 't';
	try {
		std::ofstream fajl(beolvas.getString());
		if(fajl.is_open())
		{
			fajl << "N�v" << '\t' << "Becen�v" << '\t' << "C�m" << '\t' << "Telefonsz�m";
			for(size_t i = 0; i < t.getEgyebAdatokSzama(); i++) fajl << '\t' << t.getEgyebAdatok(i)->getString();
			fajl << '\n';
			for(size_t i = 0; i < t.getEmberekSzama(); i++) {
				fajl << t.getEmber(i)->getTipus() << '\t';
				fajl << t.getEmber(i)->getNev() << '\t' << t.getEmber(i)->getBecenev() << '\t' << t.getEmber(i)->getCim() << '\t' << t.getEmber(i)->getEmberTelefonszam();
				for(size_t j = 0; j < t.getEgyebAdatokSzama(); j++) {
					size_t szamol = 0;
					for(size_t k = 0; k < t.getEmber(i)->getMasAdatokElemszama(); k++) {
						if(t.getEmber(i)->getMasAdatokAdata(k)->getNev() == t.getEgyebAdatok(j)->getString()) {
							fajl << '\t' << t.getEmber(i)->getMasAdatokAdata(k)->getAdat();
							szamol++;
						}
					}
					if(szamol == 0) fajl << '\t';
				}
				fajl << std::endl;
			}
			fajl.close();
		} else { std::cout << "Probl�ma a f�jlba ment�ssel!" << std::endl; }
	}
	catch (const char* hiba) {
		std::cerr << hiba << std::endl;
	}

	system("CLS");
	std::cout << "A telefonk�nyv sikeresen mentve!" << std::endl;
	system("pause");
	telefonkonyv_muveletek(t);
}

Telefonkonyv telefonkonyv_betolt() {
	Telefonkonyv t = Telefonkonyv();
	std::cout << "Telefonk�nyv bet�lt�se, k�rem adja meg az elmentett telefonk�nyv nev�t!" << std::endl;
	std::cout << "Telefonk�nyv neve: ";
	String beolvas = String();
	std::fstream fajl;
	std::cin >> beolvas;
	beolvas += '.';
	beolvas += 't';
	beolvas += 'x';
	beolvas += 't';
	fajl.open(beolvas.getString());
	if (fajl.fail()) std::cout << "Nincs ilyen nev� f�jl!\nTelefonk�nyv neve: " << std::endl;
	while (fajl.fail()) {
		std::cin >> beolvas;
		beolvas += '.';
		beolvas += 't';
		beolvas += 'x';
		beolvas += 't';
		fajl.open(beolvas.getString());
		if (fajl.fail()) std::cout << "Nincs ilyen nev� f�jl!\nTelefonk�nyv neve: ";
		beolvas = "";
	}
	char karakter = ' ';
	String szo = String("");
	size_t sor = -1;
	size_t adat = 0;
	while (fajl >> std::noskipws >> karakter) {
		if (sor == -1) {
			if (karakter != '\t' && karakter != '\n' && karakter != '\r') {
				szo += karakter;
			}
			if (karakter == '\t' || karakter == '\n') {
				adat++;
				if (sor == -1 && adat > 4) {
					String* egyebAdat = new String(szo);
					t.addEgyebAdat(egyebAdat);
				}
				szo = "";
			}
			if (karakter == '\n') {
				sor = 0;
				adat = 0;
			}
		} else {
			if (karakter != '\t' && karakter != '\n' && karakter != '\r') {
				szo += karakter;
			}
			if (karakter == '\t' || karakter == '\n') {
				adat++;
				if (adat == 1) {
					if (szo == "Dolgozo") {
						Dolgozo* d = new Dolgozo();
						t.addEmber(d);
					}
					else if (szo == "Maganember") {
						Maganember* m = new Maganember();
						t.addEmber(m);
					}
				} else if (adat == 2) t.getEmber(sor)->setNev(szo);
				else if (adat == 3) t.getEmber(sor)->setBecenev(szo);
				else if (adat == 4) t.getEmber(sor)->setCim(szo);
				else if (adat == 5) t.getEmber(sor)->setEmberTelefonszam(Telefonszam(szo));
				else if (adat > 5) {
					StringPar* sp = new StringPar(t.getEgyebAdatok((adat - 6))->getString(), szo);
					t.getEmber(sor)->addMasAdatok(sp);
				}
				szo = "";
			}
			if (karakter == '\n') {
				adat = 0;
				sor++;
			}
		}
	}
	std::cout << "A f�jl sikeresen beolvasva!" << std::endl;
	system("pause");
	return t;
}

Telefonkonyv menu() {
	std::cout << " - Telefonk�nyv -" << std::endl << std::endl;
	std::cout << "1 - �j telefonk�nyv l�trehoz�s" << std::endl;
	std::cout << "2 - Telefonk�nyv bet�lt�se" << std::endl;
	int muvelet = 0;
	std::cin >> muvelet;

	while (muvelet < 1 || muvelet > 2) {
		std::cout << "K�rem �rv�nyes m�veletet v�lasszon! (1 vagy 2)" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> muvelet;
	}
	switch (muvelet) {
	case 1:
		return teleonkonyv_letrehoz();
		break;
	case 2:
		return telefonkonyv_betolt();
		break;
	}
	return teleonkonyv_letrehoz();
}

void telefonkonyv_muveletek(Telefonkonyv t) {
	system("CLS");
	std::cout << " - Telefonk�nyv -" << std::endl << std::endl;
	std::cout << "Mit szeretne csin�lni a telefonk�nyvvel?" << std::endl;
	std::cout << "1 - Ember hozz�ad�sa a telefonk�nyvh�z" << std::endl;
	std::cout << "2 - Ember elt�vol�t�sa a telefonk�nyvb�l" << std::endl;
	std::cout << "3 - Ember m�dos�t�sa a telefonk�nyvb�l" << std::endl;
	std::cout << "4 - Ember keres�se a telefonk�nyvben" << std::endl;
	std::cout << "5 - Egy�b adat felv�tele a telefonk�nyvh�z" << std::endl;
	std::cout << "6 - Telefonk�nyv ment�se" << std::endl;
	std::cout << "7 - Telefonk�nyv ki�r�sa" << std::endl;
	std::cout << "8 - Kil�p�s" << std::endl;

	int muvelet = 0;
	std::cin >> muvelet;

	while (muvelet < 1 || muvelet > 8) {
		std::cout << "K�rem �rv�nyes m�veletet v�lasszon! (1 - 8)" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> muvelet;
	}
	switch (muvelet) {
	case 1:
		ember_hozzaadasa(t);
		break;
	case 2:
		ember_eltavolitasa(t);
		break;
	case 3:
		ember_modositasa(t);
		break;
	case 4:
		ember_keresese(t);
		break;
	case 5:
		adat_felvetele(t);
		break;
	case 6:
		telefonkonyv_mentes(t);
		break;
	case 7:
		system("CLS");
		if (t.getEmberekSzama() > 0) t.kiir();
		else std::cout << "A telefonk�nyv �res!" << std::endl;
		system("pause");
		telefonkonyv_muveletek(t);
		break;
	}

}

void ember_hozzaadasa(Telefonkonyv t) {
	system("CLS");
	std::cout << "Dolgoz�t vagy mag�nembert szeretne hozz�adni a telefonk�nyvh�z?" << std::endl;
	std::cout << "1 - Dolgoz�" << std::endl;
	std::cout << "2 - Mag�nember" << std::endl;

	int tipus = 0;
	std::cin >> tipus;

	while (tipus < 1 || tipus > 2) {
		std::cout << "K�rem �rv�nyes embert v�lasszon! (1 vagy 2)" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> tipus;
	}
	if (tipus == 1) {
		Dolgozo* d = new Dolgozo();
		ember_letrehozasa(t, d);
	}
	else if (tipus == 2) {
		Maganember* m = new Maganember();
		ember_letrehozasa(t, m);
	}
}

void ember_letrehozasa(Telefonkonyv t, Ember* e) {
	String beolvas = String();

	system("CLS");
	std::cout << "Az ember neve: ";
	size_t lehetEIlyenNev = 0;
	while (lehetEIlyenNev == 0) {
		std::cin >> beolvas;
		if (!beolvas.vanESzam()) {
			size_t seged = 0;
			for (size_t i = 0; i < t.getEmberekSzama(); i++) {
				if (t.getEmber(i)->getNev() == beolvas) {
					lehetEIlyenNev = 0;
					seged = 1;
				}
			}
			if (seged == 0) lehetEIlyenNev = 1;
			else if (seged == 1) std::cout << "Van m�r ilyen nev� ember a telefonk�nyvben!" << std::endl;
		} else { std::cout << "Az ember nev�ben nem szerepelhet sz�m karakter!" << std::endl; lehetEIlyenNev = 0; }
		if (beolvas == "-") { std::cout << "Az ember neve nem lehet - karakter!" << std::endl; lehetEIlyenNev = 0; }
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	e->setNev(beolvas);

	system("CLS");
	std::cout << "Az ember beceneve: ";
	std::cin >> beolvas;
	while (beolvas.vanESzam()) {
		std::cout << "Az ember becenev�ben nem szerepelhet sz�m karakter!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> beolvas;
	}
	e->setBecenev(beolvas);

	system("CLS");
	std::cout << "Az ember c�me: ";
	std::cin >> beolvas;
	while (!beolvas.vanESzam()) {
		std::cout << "Az ember c�m�ben szerepelnie kell sz�m karakternek!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> beolvas;
	}
	e->setCim(beolvas);

	system("CLS");
	std::cout << "Az ember telefonsz�ma: ";
	std::cin >> beolvas;
	while (!beolvas.lehetETelefonszam()) {
		std::cout << "Az ember telefonsz�m�ban csak sz�m karakterek �s a + karakter szerepelhetnek!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> beolvas;
	}
	e->setEmberTelefonszam(Telefonszam(beolvas));

	for (size_t i = 0; i < t.getEgyebAdatokSzama(); i++) {
		system("CLS");
		std::cout << "Az ember " << t.getEgyebAdatok(i)->getString() << ": ";
		std::cin >> beolvas;
		size_t szamol = 0;
		for (size_t j = 0; j < e->getMasAdatokElemszama(); j++) {
			if (e->getMasAdatokAdata(j)->getNev().getString() == t.getEgyebAdatok(i)->getString()) {
				szamol++;
				e->setMasAdatok(j, beolvas);
			}
		}
		if (szamol == 0) {
			StringPar* sp = new StringPar(t.getEgyebAdatok(i)->getString(), beolvas);
			e->addMasAdatok(sp);
		}
	}

	t.addEmber(e);
	telefonkonyv_muveletek(t);
}

void ember_eltavolitasa(Telefonkonyv t) {
	system("CLS");
	size_t darab = t.getEmberekSzama();
	if (darab == 0) {
		std::cout << "A telefonk�nyv �res!" << std::endl;
		system("pause");
	}
	else {
		std::cout << "1 - Vissza a men�be" << std::endl;
		std::cout << "Adja meg az ember nev�t, akit el szeretne t�vol�tani a telefonk�nyvb�l!" << std::endl;
		String beolvas = String();
		std::cout << "Az ember neve: ";
		std::cin >> beolvas;
		t.removeEmber(beolvas);
		while (darab == t.getEmberekSzama()) {
			if (beolvas == "1") {
				darab = -1;
			}
			else {
				std::cout << "Nincs ilyen nev� ember a telefonk�nyvben!" << std::endl;
				std::cout << "A telefonk�nyvb�l egy ember neve: ";
				std::cin >> beolvas;
				t.removeEmber(beolvas);
			}
		}
		if (darab > -1) {
			std::cout << beolvas << " sikeresen t�r�lve lett a telefonk�nyvb�l!" << std::endl;
			system("pause");
		}
	}
	telefonkonyv_muveletek(t);
}

void ember_modositasa(Telefonkonyv t) {
	system("CLS");
	size_t darab = t.getEmberekSzama();
	if (darab == 0) {
		std::cout << "A telefonk�nyv �res, nincs lehet�s�g ember adatainak m�dos�t�s�ra!" << std::endl;
		system("pause");
	}
	else {
		std::cout << "1 - Vissza a men�be" << std::endl;
		std::cout << "Adja meg az ember nev�t, akinek az adatait m�dos�tani szeretn� a telefonk�nyvb�l!" << std::endl;
		String beolvas = String();
		std::cout << "Az ember neve: ";
		std::cin >> beolvas;
		while (t.getEmber(beolvas) == nullptr) {
			if (beolvas == "1") {
				telefonkonyv_muveletek(t);
				return;
			}
			else {
				std::cout << "Nincs ilyen nev� ember a telefonk�nyvben!" << std::endl;
				std::cout << "A telefonk�nyvb�l egy ember neve: ";
				std::cin >> beolvas;
			}
		}
		if (darab > 0) {
			String regi_nev = String(beolvas);
			regi_nev = beolvas;
			Ember* e = t.getEmber(beolvas);
			size_t seged = 0;

			system("CLS");
			std::cout << regi_nev << " �j neve: ";
			size_t lehetEIlyenNev = 0;
			while (lehetEIlyenNev == 0 && seged == 0) {
				std::cin >> beolvas;
				if (beolvas == "-") seged = 1;
				if (!beolvas.vanESzam() && seged == 0) {
					size_t seged = 0;
					for (size_t i = 0; i < t.getEmberekSzama(); i++) {
						if (t.getEmber(i)->getNev() == beolvas) {
							lehetEIlyenNev = 0;
							seged = 1;
						}
					}
					if (seged == 0) lehetEIlyenNev = 1;
					else if (seged == 1) std::cout << "Van m�r ilyen nev� ember a telefonk�nyvben!" << std::endl;
				}
				else if (beolvas.vanESzam()) { std::cout << "Az ember nev�ben nem szerepelhet sz�m karakter!" << std::endl; lehetEIlyenNev = 0; }
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			if (seged == 0) { e->setNev(beolvas); }

			seged = 0;
			system("CLS");
			std::cout << regi_nev << " �j beceneve: ";
			std::cin >> beolvas;
			if (beolvas == "-") seged = 1;
			while (beolvas.vanESzam() && seged == 0) {
				std::cout << "Az ember becenev�ben nem szerepelhet sz�m karakter!" << std::endl;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cin >> beolvas;
			}
			if (seged == 0) { e->setBecenev(beolvas); }

			seged = 0;
			system("CLS");
			std::cout << regi_nev << " �j c�me: ";
			std::cin >> beolvas;
			if (beolvas == "-") seged = 1;
			while (!beolvas.vanESzam() && seged == 0) {
				std::cout << "Az ember c�m�ben szerepelnie kell sz�m karakternek!" << std::endl;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cin >> beolvas;
			}
			if (seged == 0) { e->setCim(beolvas); }

			seged = 0;
			system("CLS");
			std::cout << regi_nev << " �j telefonsz�ma: ";
			std::cin >> beolvas;
			if (beolvas == "-") seged = 1;
			while (!beolvas.lehetETelefonszam() && seged == 0) {
				std::cout << "Az ember telefonsz�m�ban csak sz�m karakterek �s a + karakter szerepelhetnek!" << std::endl;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cin >> beolvas;
			}
			if (seged == 0) { e->setEmberTelefonszam(Telefonszam(beolvas)); }

			for (size_t i = 0; i < t.getEgyebAdatokSzama(); i++) {
				seged = 0;
				system("CLS");
				std::cout << "Az ember " << t.getEgyebAdatok(i)->getString() << ": ";
				std::cin >> beolvas;
				if (beolvas == "-") seged = 1;
				if (seged == 0) {
					size_t szamol = 0;
					for (size_t j = 0; j < e->getMasAdatokElemszama(); j++) { //Ellen�rizz�k, hogy m�r l�tezik-e az ember objektumban a stringpar
						if (e->getMasAdatokAdata(j)->getNev() == t.getEgyebAdatok(i)->getString()) {
							szamol = 1;
							e->setMasAdatok(j, beolvas);
						}
					}
					if (szamol == 0) { //Ha nem, itt adjuk hozz�
						StringPar* sp = new StringPar(t.getEgyebAdatok(i)->getString(), beolvas);
						e->addMasAdatok(sp);
					}
				}
			}

			system("CLS");
			std::cout << regi_nev << " �j adatai:" << std::endl;
			e->kiir();
			system("pause");
		}
	}
	telefonkonyv_muveletek(t);
}

void adat_felvetele(Telefonkonyv t) {
	system("CLS");
	std::cout << "1 - Vissza a men�be" << std::endl;
	std::cout << "Mi legyen az extra adat neve?" << std::endl;
	std::cout << "Extra adat neve: ";
	String beolvas = String();
	std::cin >> beolvas;
	if (beolvas == "1") {}
	else {
		String* s = new String(beolvas);
		t.addEgyebAdat(s);
	}

	telefonkonyv_muveletek(t);
}

void ember_keresese(Telefonkonyv t) {
	system("CLS");
	size_t darab = t.getEmberekSzama();
	if (darab == 0) {
		std::cout << "A telefonk�nyv �res, nincs lehet�s�g embert keresni a telefonk�nyvben!" << std::endl;
		system("pause");
	}
	else {
		std::cout << "1 - Vissza a men�be" << std::endl;
		std::cout << "Adja meg az ember nev�t, akit ki szeretne �rni a telefonk�nyvb�l!" << std::endl;
		String beolvas = String();
		std::cout << "Az ember neve: ";
		std::cin >> beolvas;
		while (t.getEmber(beolvas) == nullptr) {
			if (beolvas == "1") {
				telefonkonyv_muveletek(t);
				return;
			}
			else {
				std::cout << "Nincs ilyen nev� ember a telefonk�nyvben!" << std::endl;
				std::cout << "A telefonk�nyvb�l egy ember neve: ";
				std::cin >> beolvas;
			}
		}
		if (darab > 0) {
			t.getEmber(beolvas)->kiir();
			system("pause");
		}
	}
	telefonkonyv_muveletek(t);
}

int main() {
	//teszt();
	setlocale(LC_ALL, ""); //Az op rendszer �ltal haszn�lt k�dol�t �ll�tja be
	Telefonkonyv t = menu();
	telefonkonyv_muveletek(t);
}