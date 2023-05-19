#ifndef STRING_H
#define STRING_H

#include <iostream>

class String { //Karaktersorozatok kezeléséhez
	char* szoveg; //A karaktersorozat itt tárolódik
	size_t hossz; //A karaktersorozat hossza (\0-t nem számoljuk bele)
public:
	String() :szoveg(0), hossz(0) {} //Egy üres karaktersorozatot hozunk létre
	String(const char* str); //Egy bejövõ karaktersorozatot eltárolunk
	String(const String& str); //Egy másik String-bõl másolunk
	~String() { delete[] szoveg; } //Felszabadítja a lefoglalt szoveg-et
	const char* getString() const { if (szoveg) return szoveg; else return ""; } //Visszaadja a szoveg kezdõ pointerét
	size_t getHossz() { return hossz; } //Visszaadja a String hossz értékét
	String& operator=(const String& str); //Lemásolja a String-et
	bool operator==(const char* str) const; //Megvizsgálja, hogy a Stringek szoveg adatai megegyeznek-e bejövõ szöveges paraméterrel
	bool operator==(const String& str) const; //Megvizsgálja, hogy a Stringek szoveg adatai megegyeznek-e bejövõ String paraméterrel
	char& operator[](size_t index); //Visszaadja az indexedik elemét a karaktertömbnek
	const char& operator[](size_t index) const; //Visszaadja az indexedik elemét a karaktertömbnek (const)
	bool vanESzam(); //Megmondja, hogy szerepel-e szám a String-ben
	bool lehetETelefonszam(); //Megmondja, hogy telefonszám lehet-e a String
};

std::ostream& operator<<(std::ostream& os, const String& str); //Kiírásoknál a szoveget kell megjeleníteni

#endif //STRING_H