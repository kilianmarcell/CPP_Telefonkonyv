#ifndef STRING_H
#define STRING_H

#include <iostream>

class String { //Karaktersorozatok kezel�s�hez
	char* szoveg; //A karaktersorozat itt t�rol�dik
	size_t hossz; //A karaktersorozat hossza (\0-t nem sz�moljuk bele)
public:
	String() :szoveg(0), hossz(0) {} //Egy �res karaktersorozatot hozunk l�tre
	String(char karakter); //Egy bej�v� karaktert elt�rolunk
	String(const char* str); //Egy bej�v� karaktersorozatot elt�rolunk
	String(const String& str); //Egy m�sik String-b�l m�solunk
	~String() { delete[] szoveg; } //Felszabad�tja a lefoglalt szoveg-et
	const char* getString() const { if (szoveg) return szoveg; else return ""; } //Visszaadja a szoveg kezd� pointer�t
	size_t getHossz() { return hossz; } //Visszaadja a String hossz �rt�k�t
	String& operator=(const String& str); //Lem�solja a String-et
	bool operator==(const char* str) const; //Megvizsg�lja, hogy a Stringek szoveg adatai megegyeznek-e bej�v� sz�veges param�terrel
	bool operator==(const String& str) const; //Megvizsg�lja, hogy a Stringek szoveg adatai megegyeznek-e bej�v� String param�terrel
	char& operator[](size_t index); //Visszaadja az indexedik elem�t a karaktert�mbnek
	const char& operator[](size_t index) const; //Visszaadja az indexedik elem�t a karaktert�mbnek (const)
	bool vanESzam(); //Megmondja, hogy szerepel-e sz�m a String-ben
	bool lehetETelefonszam(); //Megmondja, hogy telefonsz�m lehet-e a String
	String& operator+=(char karakter); //A String-hez hozz�ad egy karaktert a szoveg v�g�re
};

std::ostream& operator<<(std::ostream& os, const String& str); //Ki�r�sokn�l a szoveget kell megjelen�teni
std::istream& operator>>(std::istream& is, String& str); //String-be beolvashatunk input adatot

#endif //STRING_H