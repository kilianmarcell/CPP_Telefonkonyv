#include <iostream>
#include "string.h"

String::String(char karakter) {
    hossz = 1;
    szoveg = new char[hossz+ 1];
    szoveg[0] = karakter;
    szoveg[1] = '\0';
}

String::String(const char* str) {
    size_t strHossz = 0;
    const char* s = str;
    while (*s != '\0') {
        strHossz++;
        s++;
    }
    hossz = strHossz;
    szoveg = new char[hossz + 1];
    for(size_t i = 0; i < hossz; i++) {
        szoveg[i] = str[i];
    }
    szoveg[hossz] = '\0';
}

String::String(const String& str) {
    hossz = str.hossz;
    szoveg = new char[hossz + 1];
    for (size_t i = 0; i < hossz; i++) {
        szoveg[i] = str[i];
    }
    szoveg[hossz] = '\0';
}

String& String::operator=(const String& str) {
    if (this != &str) {
        delete[] szoveg;
        hossz = str.hossz;
        if ((szoveg = str.szoveg) == NULL) return *this;
        szoveg = new char[hossz + 1];
        for (size_t i = 0; i < hossz; i++) {
            szoveg[i] = str.szoveg[i];
        }
        szoveg[hossz] = '\0';
    }
    return *this;
}

bool String::operator==(const char* str) const {
    String s = String(str);
    if (hossz != s.hossz) return false;
    for (size_t i = 0; i < s.hossz; i++) {
        if (szoveg[i] != s[i]) return false;
    }

    return true;
}

bool String::operator==(const String& str) const {
    if (hossz != str.hossz) return false;
    for (size_t i = 0; i < str.hossz; i++) {
        if (szoveg[i] != str[i]) return false;
    }

    return true;
}

char& String::operator[](size_t index) {
    if (index >= hossz || index < 0) throw std::out_of_range("Túl/alulindexelés");
    return szoveg[index];
}

const char& String::operator[](size_t index) const {
    if (index >= hossz || index < 0) throw std::out_of_range("Túl/alulindexelés");
    return szoveg[index];
}

bool String::vanESzam() {
    if (hossz == 0) return false;
    char szamok[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    for (size_t i = 0; i < hossz; i++) {
        for (size_t j = 0; j < 10; j++) {
            if (szoveg[i] == szamok[j]) return true;
        }
    }
    return false;
}

bool String::lehetETelefonszam() {
    if (hossz == 0) return false;
    char karakterek[12] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', ' '};
    for (size_t i = 0; i < hossz; i++) {
        int szamol = 0;
        for (size_t j = 0; j < 12; j++) {
            if (szoveg[i] == karakterek[j]) szamol++;
        }
        if (szamol == 0) return false;
    }
    return true;
}

String& String::operator+=(char karakter) {
    String temp = String(szoveg);
    delete[] szoveg;
    hossz = hossz + 1;

    szoveg = new char[hossz + 1];
    if (hossz == 1) {
        szoveg[0] = karakter; szoveg[1] = '\0';
    } else {
        for (size_t i = 0; i < temp.hossz; i++) {
            szoveg[i] = temp.szoveg[i];
        }
        szoveg[hossz - 1] = karakter;
        szoveg[hossz] = '\0';
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.getString();
    return os;
}

std::istream& operator>>(std::istream& is, String& str) {
    unsigned char ch;
    str = String("");
    std::ios_base::fmtflags fl = is.flags();
    is.setf(std::ios_base::skipws);
    while (is >> ch) {
        is.unsetf(std::ios_base::skipws);
        if (isspace(ch)) {
            is.putback(ch);
            break;
        }
        else {
            str += ch;
        }
    }
    is.setf(fl);
    return is;
}