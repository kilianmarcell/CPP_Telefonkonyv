#ifndef VEKTOR_H
#define VEKTOR_H

template <typename T>
class Vektor { //Dinamikus memóriakezeléshez használjuk
	T* adatok; //Egy T tömböt tárol
	size_t elemekSzama; //A T tömb elemszámát tárolja
public:
	Vektor() :elemekSzama(0) { adatok = new T[0]; } //Létrehoz egy üres tömböt, 0 elemszámmal
	size_t getElemekSzama() { return elemekSzama; } //Az elemek számát adja vissza
	void add(const T& adat); //Egy T elemet adhatunk a tömbünkhöz
	void remove(size_t index); //Egy elemet töröl a tömbünkbõl
	T& operator[](size_t index); //A tömb egyik elemével tér vissza
	const T& operator[](size_t index) const; //A tömb egyik elemével tér vissza (const)
	~Vektor(); //Felszabadítja a dinamikusan foglalt adatok memóriát
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
	if (index >= elemekSzama || index < 0) throw std::out_of_range("Túl/alulindexelés");
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
	if (index >= elemekSzama || index < 0) throw std::out_of_range("Túl/alulindexelés");
	return adatok[index];
}

template <typename T>
inline const T& Vektor<T>::operator[](size_t index) const {
	if (index >= elemekSzama || index < 0) throw std::out_of_range("Túl/alulindexelés");
	return adatok[index];
}

template <typename T>
inline Vektor<T>::~Vektor() {
	delete[] adatok;
}

#endif //VEKTOR_H