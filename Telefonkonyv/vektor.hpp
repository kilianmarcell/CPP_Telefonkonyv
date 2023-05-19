#ifndef VEKTOR_H
#define VEKTOR_H

template <typename T>
class Vektor { //Dinamikus mem�riakezel�shez haszn�ljuk
	T* adatok; //Egy T t�mb�t t�rol
	size_t elemekSzama; //A T t�mb elemsz�m�t t�rolja
public:
	Vektor() :elemekSzama(0) { adatok = new T[0]; } //L�trehoz egy �res t�mb�t, 0 elemsz�mmal
	size_t getElemekSzama() { return elemekSzama; } //Az elemek sz�m�t adja vissza
	void add(const T& adat); //Egy T elemet adhatunk a t�mb�nkh�z
	void remove(size_t index); //Egy elemet t�r�l a t�mb�nkb�l
	T& operator[](size_t index); //A t�mb egyik elem�vel t�r vissza
	const T& operator[](size_t index) const; //A t�mb egyik elem�vel t�r vissza (const)
	~Vektor(); //Felszabad�tja a dinamikusan foglalt adatok mem�ri�t
};

template <typename T>
inline void Vektor<T>::add(const T& adat) {
	T* ujAdatok = new T[elemekSzama + 1];
	for (size_t i = 0; i < elemekSzama; i++) {
		ujAdatok[i] = adatok[i];
	}
	delete[] adatok;
	adatok = ujAdatok;
	adatok[elemekSzama++] = adat;
}

template <typename T>
inline void Vektor<T>::remove(size_t index) {
	if (elemekSzama < 1) return;
	if (index >= elemekSzama || index < 0) throw std::out_of_range("T�l/alulindexel�s");
	--elemekSzama;
	T* ujAdatok = new T[elemekSzama];
	for (size_t i = 0; i < index; i++) {
		ujAdatok[i] = adatok[i];
	}
	for (size_t i = index; i < elemekSzama; i++) {
		ujAdatok[i] = adatok[i + 1];
	}
	delete[] adatok;
	adatok = ujAdatok;
}

template <typename T>
inline T& Vektor<T>::operator[](size_t index) {
	if (index >= elemekSzama || index < 0) throw std::out_of_range("T�l/alulindexel�s");
	return adatok[index];
}

template <typename T>
inline const T& Vektor<T>::operator[](size_t index) const {
	if (index >= elemekSzama || index < 0) throw std::out_of_range("T�l/alulindexel�s");
	return adatok[index];
}

template <typename T>
inline Vektor<T>::~Vektor() {
	delete[] adatok;
}

#endif //VEKTOR_H