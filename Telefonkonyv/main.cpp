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
void dolgozo_hozzaadasa(Telefonkonyv t);
void maganember_hozzaadasa(Telefonkonyv t);

Telefonkonyv teleonkonyv_letrehoz() {
	Telefonkonyv t = Telefonkonyv();
	std::cout << "Telefonk�nyv l�trehozva" << std::endl;
	return t;
}

void telefonkonyv_mentes(Telefonkonyv t) {
}

Telefonkonyv telefonkonyv_betolt() {
	Telefonkonyv t = Telefonkonyv();
	std::cout << "Telefonk�nyv bet�lt�se, k�rem adja meg az elmentett telefonk�nyv nev�t!" << std::endl;
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
	if (tipus == 1) dolgozo_hozzaadasa(t);
	else if (tipus == 2) maganember_hozzaadasa(t);
}

void dolgozo_hozzaadasa(Telefonkonyv t) {
	Dolgozo* d = new Dolgozo();
	String beolvas = String();

	system("CLS");
	std::cout << "Az ember neve: ";
	std::cin >> beolvas;
	while (beolvas.vanESzam()) {
		std::cout << "Az ember nev�ben nem szerepelhet sz�m karakter!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> beolvas;
	}
	d->setNev(beolvas);

	system("CLS");
	std::cout << "Az ember beceneve: ";
	std::cin >> beolvas;
	while (beolvas.vanESzam()) {
		std::cout << "Az ember becenev�ben nem szerepelhet sz�m karakter!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> beolvas;
	}
	d->setBecenev(beolvas);

	system("CLS");
	std::cout << "Az ember c�me: ";
	std::cin >> beolvas;
	while (!beolvas.vanESzam()) {
		std::cout << "Az ember c�m�ben szerepelnie kell sz�m karakternek!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> beolvas;
	}
	d->setCim(beolvas);

	system("CLS");
	std::cout << "Az ember telefonsz�ma: ";
	std::cin >> beolvas;
	while (!beolvas.lehetETelefonszam()) {
		std::cout << "Az ember telefonsz�m�ban csak sz�m karakterek �s a + karakter szerepelhetnek!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> beolvas;
	}
	d->setEmberTelefonszam(Telefonszam(beolvas));

	for (size_t i = 0; i < t.getEgyebAdatokSzama(); i++) {
		system("CLS");
		std::cout << "Az ember " << t.getEgyebAdatok(i)->getString() << ": " << std::endl;
		std::cin >> beolvas;
		size_t szamol = 0;
		for (size_t j = 0; j < d->getMasAdatokElemszama(); j++) {
			if (d->getMasAdatokAdata(j).getNev().getString() == t.getEgyebAdatok(i)->getString()) {
				szamol++;
				d->setMasAdatok(j, beolvas);
			}
		}
		if (szamol == 0) {
			StringPar sp = StringPar(t.getEgyebAdatok(i)->getString(), beolvas);
			d->addMasAdatok(sp);
		}
	}

	t.addEmber(d);
	telefonkonyv_muveletek(t);
}

void maganember_hozzaadasa(Telefonkonyv t) {
	Maganember* m = new Maganember();
	String beolvas = String();

	system("CLS");
	std::cout << "Az ember neve: ";
	std::cin >> beolvas;
	while (beolvas.vanESzam()) {
		std::cout << "Az ember nev�ben nem szerepelhet sz�m karakter!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> beolvas;
	}
	m->setNev(beolvas);

	system("CLS");
	std::cout << "Az ember beceneve: ";
	std::cin >> beolvas;
	while (beolvas.vanESzam()) {
		std::cout << "Az ember becenev�ben nem szerepelhet sz�m karakter!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> beolvas;
	}
	m->setBecenev(beolvas);

	system("CLS");
	std::cout << "Az ember c�me: ";
	std::cin >> beolvas;
	while (!beolvas.vanESzam()) {
		std::cout << "Az ember c�m�ben szerepelnie kell sz�m karakternek!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> beolvas;
	}
	m->setCim(beolvas);

	system("CLS");
	std::cout << "Az ember telefonsz�ma: ";
	std::cin >> beolvas;
	while (!String(beolvas).lehetETelefonszam()) {
		std::cout << "Az ember telefonsz�m�ban csak sz�m karakterek �s a + karakter szerepelhetnek!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> beolvas;
	}
	m->setEmberTelefonszam(Telefonszam(beolvas));

	for (size_t i = 0; i < t.getEgyebAdatokSzama(); i++) {
		system("CLS");
		std::cout << "Az ember " << t.getEgyebAdatok(i)->getString() << ": " << std::endl;
		std::cin >> beolvas;
		size_t szamol = 0;
		for (size_t j = 0; j < m->getMasAdatokElemszama(); j++) {
			if (m->getMasAdatokAdata(j).getNev().getString() == t.getEgyebAdatok(i)->getString()) {
				szamol++;
				m->setMasAdatok(j, String(beolvas));
			}
		}
		if (szamol == 0) {
			StringPar sp = StringPar(t.getEgyebAdatok(i)->getString(), String(beolvas));
			m->addMasAdatok(sp);
		}
	}

	t.addEmber(m);
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

			system("CLS");
			std::cout << regi_nev << " �j neve: ";
			std::cin >> beolvas;
			while (beolvas.vanESzam()) {
				std::cout << "Az ember nev�ben nem szerepelhet sz�m karakter!" << std::endl;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cin >> beolvas;
			}
			e->setNev(beolvas);

			system("CLS");
			std::cout << regi_nev << " �j beceneve: ";
			std::cin >> beolvas;
			while (beolvas.vanESzam()) {
				std::cout << "Az ember becenev�ben nem szerepelhet sz�m karakter!" << std::endl;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cin >> beolvas;
			}
			e->setBecenev(beolvas);

			system("CLS");
			std::cout << regi_nev << " �j c�me: ";
			std::cin >> beolvas;
			while (!beolvas.vanESzam()) {
				std::cout << "Az ember c�m�ben szerepelnie kell sz�m karakternek!" << std::endl;
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cin >> beolvas;
			}
			e->setCim(beolvas);

			system("CLS");
			std::cout << regi_nev << " �j telefonsz�ma: ";
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
				std::cout << "Az ember " << t.getEgyebAdatok(i)->getString() << ": " << std::endl;
				std::cin >> beolvas;
				size_t szamol = 0;
				for (size_t j = 0; j < e->getMasAdatokElemszama(); j++) {
					if (e->getMasAdatokAdata(j).getNev().getString() == t.getEgyebAdatok(i)->getString()) {
						szamol++;
						e->setMasAdatok(j, beolvas);
					}
				}
				if (szamol == 0) {
					StringPar sp = StringPar(t.getEgyebAdatok(i)->getString(), beolvas);
					e->addMasAdatok(sp);
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