#include <iostream>
#include "string.h"
#include "stringpar.h"
#include "vektor.hpp"
#include "ember.h"
#include "maganember.h"
#include "dolgozo.h"
#include "telefonszam.h"
#include "telefonkonyv.h"
#include "gtest_lite.h"

void teszt() {
	//Vektor tesztek
	TEST(Vektor, Add Remove Getterek) {
		Vektor<int> szamok;
		szamok.add(1);
		szamok.add(2);
		szamok.add(3);
		szamok.add(4);
		EXPECT_EQ(4, szamok.getElemekSzama());
		szamok.remove(2);
		EXPECT_EQ(3, szamok.getElemekSzama());
		szamok.remove(0);
		szamok.remove(0);
		szamok.remove(0);
		EXPECT_NO_THROW(szamok.remove(0));
	} END

	TEST(Vektor, operator[]) {
		Vektor<int> szamok;
		szamok.add(1);
		szamok.add(2);
		szamok.add(3);
		szamok.add(4);
		EXPECT_EQ(3, szamok[2]);
		EXPECT_THROW(szamok[4], std::exception);
		Vektor<const char*> masSzamok;
		masSzamok.add("a");
		masSzamok.add("b");
		masSzamok.add("c");
		masSzamok.add("d");
		EXPECT_EQ("c", masSzamok[2]);
	} END

	//String tesztek
	TEST(String, Konstruktorok Getterek) {
		String s = String();
		EXPECT_EQ(0, s.getHossz());
		String s2 = String("Teszt");
		EXPECT_STREQ("Teszt", s2.getString());
		EXPECT_TRUE(s2 == "Teszt");
		EXPECT_FALSE(s2 == "teszt");
		EXPECT_FALSE(s == s2);
		s = "Teszt";
		EXPECT_EQ(5, s.getHossz());
		EXPECT_TRUE(s == s2);
		EXPECT_TRUE(s2 == s2);
	} END

	TEST(String, operator[]) {
		String s = String("Teszt");
		EXPECT_EQ('T', s[0]);
		EXPECT_THROW(s[-1], std::exception);
		EXPECT_THROW(s[5], std::exception);
	} END

	TEST(String, VanESzam lehetETelefonszam) {
		String s = String("Teszt");
		EXPECT_FALSE(s.vanESzam());
		s = "T3szt";
		EXPECT_TRUE(s.vanESzam());
		EXPECT_FALSE(s.lehetETelefonszam());
		s = "06 30 999";
		EXPECT_TRUE(s.lehetETelefonszam());
		s = "+36 30999";
		EXPECT_TRUE(s.lehetETelefonszam());
	} END

	TEST(String, Operator<<) {
		String s = String("Teszt");
		std::stringstream a;
		a << s;
		EXPECT_STREQ("Teszt", a.str().c_str());
	} END

	TEST(String, Operator=) {
		String s = String("Teszt");
		s = "";
		EXPECT_STREQ("", s.getString());
		s = String("EzEgyTeszt");
		EXPECT_STREQ("EzEgyTeszt", s.getString());
		s = String();
		EXPECT_STREQ("", s.getString());
	} END

	TEST(String, Operator+=) {
		String s = String("Teszt");
		s += 'd';
		s += '3';
		char c = 'k';
		s += c;
		EXPECT_STREQ("Tesztd3k", s.getString());
	} END

	//StringPar tesztek
	TEST(StringPar, Konstruktorok Getterek) {
		StringPar s = StringPar();
		EXPECT_STREQ("", s.getNev().getString());
		EXPECT_STREQ("", s.getAdat().getString());
		StringPar s1 = StringPar("TesztNev", "TesztAdat");
		EXPECT_STREQ("TesztNev", s1.getNev().getString());
		EXPECT_STREQ("TesztAdat", s1.getAdat().getString());
	} END

	TEST(StringPar, operator== Setterek) {
		StringPar s = StringPar();
		StringPar s1 = StringPar("TesztNev", "TesztAdat");
		EXPECT_FALSE(s == s1.getAdat());
		EXPECT_FALSE(s1 == s.getAdat());
		s.setNev("TesztNev");
		s.setAdat("TesztAdat");
		EXPECT_TRUE(s == s1.getAdat());
		EXPECT_TRUE(s1 == s.getAdat());
	} END

	//Telefonszam tesztek
	TEST(Telefonszam, Konstruktorok Getterek Setterek operator=) {
		Telefonszam t = Telefonszam();
		EXPECT_STREQ("", t.getTelefonszam().getString());
		Telefonszam t1 = Telefonszam("+36 99 999 9999");
		EXPECT_STREQ("+36 99 999 9999", t1.getTelefonszam().getString());
		t = t1;
		EXPECT_STREQ("+36 99 999 9999", t.getTelefonszam().getString());
		t1.setTelefonszam("+36");
		EXPECT_STREQ("+36", t1.getTelefonszam().getString());
	} END

	//Ember (Munkas és Dolgozo) tesztek
	TEST(Ember, Konstruktorok Getterek Setterek operator=) {
		Maganember e1 = Maganember();
		Dolgozo e2 = Dolgozo();
		EXPECT_STREQ("", e1.getNev().getString());
		EXPECT_STREQ("", e1.getBecenev().getString());
		EXPECT_STREQ("", e1.getCim().getString());
		EXPECT_STREQ("", e2.getNev().getString());
		EXPECT_STREQ("", e2.getBecenev().getString());
		EXPECT_STREQ("", e2.getCim().getString());
		e1.setNev("Teszt");
		e2.setBecenev("Elek");
		e2.setCim("Bp");
		EXPECT_STREQ("", e2.getCim().getString());
		e2.setCim("Bp 3");
		EXPECT_STREQ("Teszt", e1.getNev().getString());
		EXPECT_STREQ("Elek", e2.getBecenev().getString());
		EXPECT_STREQ("Bp 3", e2.getCim().getString());
		e1.setEmberTelefonszam(Telefonszam(String("+36 99 999 9999")));
		e2.setEmberTelefonszam(Telefonszam(String("123456")));
		e2.setEmberTelefonszam(Telefonszam(String("123a456")));
		EXPECT_STREQ("+36 99 999 9999", e1.getEmberTelefonszam().getString());
		EXPECT_STREQ("123456", e2.getEmberTelefonszam().getString());
		StringPar* sp = new StringPar("TesztNev", "TesztAdat");
		StringPar* sp1 = new StringPar("TesztNev1", "TesztAdat1");
		e1.addMasAdatok(sp);
		EXPECT_EQ(1, e1.getMasAdatokElemszama());
		e1.addMasAdatok(sp1);
		EXPECT_EQ(2, e1.getMasAdatokElemszama());
		EXPECT_STREQ("TesztNev", e1.getMasAdatokAdata(0)->getNev().getString());
		EXPECT_STREQ("TesztNev1", e1.getMasAdatokAdata(1)->getNev().getString());
		EXPECT_STREQ("TesztAdat", e1.getMasAdatokAdata(0)->getAdat().getString());
		EXPECT_STREQ("TesztAdat1", e1.getMasAdatokAdata(1)->getAdat().getString());
		e1.setMasAdatok(1, "TesztAdat2");
		e1.removeMasAdatok(0);
		EXPECT_EQ(1, e1.getMasAdatokElemszama());
		EXPECT_STREQ("TesztNev1", e1.getMasAdatokAdata(0)->getNev().getString());
		EXPECT_STREQ("TesztAdat2", e1.getMasAdatokAdata(0)->getAdat().getString());
		//std::cout << e1 << std::endl; -> tesztelve main.cpp-ben - SIKERES
		//std::cout << e2 << std::endl; -> tesztelve main.cpp-ben - SIKERES
	} END

	//Telefonkonyv tesztek
	TEST(Telefonkonyv, Konstruktor Getter Setter) {
		Telefonkonyv t = Telefonkonyv();
		Maganember e1 = Maganember();
		Dolgozo e2 = Dolgozo();
		e1.setNev("T");
		e2.setNev("Te");
		e1.setCim("TesztCim1");
		e2.setCim("TesztCim2");
		t.addEmber(&e1);
		t.addEmber(&e2);
		EXPECT_STREQ("T", t.getEmber("T")->getNev().getString());
		EXPECT_STREQ("TesztCim1", t.getEmber("T")->getCim().getString());
		EXPECT_STREQ("Te", t.getEmber("Te")->getNev().getString());
		EXPECT_STREQ("TesztCim2", t.getEmber("Te")->getCim().getString());
		t.removeEmber("T");
		EXPECT_STREQ("TesztCim2", t.getEmber(0)->getCim().getString());
		//t.kiir(); -> tesztelve main.cpp-ben - SIKERES
	} END
}