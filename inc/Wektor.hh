#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

/*
 *  Klasa modeluje pojęcie wektora stałym rozmiarze
 */
class Wektor 
{
private:

  double m_tab[ROZMIAR]; // tablica współżędnych wektora

public:
  

/*
 *  Konstruktor domyślny
 */
  Wektor();

/*
 *  Konstruktor inicjujacy pola klasy przesłaną tablicą
 */
  Wektor(double tablica[]);

/*
 *  Realizacja sumy dwóch wektorów
 */
  const Wektor operator+(const Wektor &W2) const;

/*
 *  Realizuje odejmowanie dwóch wektorów
 */
  const Wektor operator-(const Wektor &W2) const;

/*
 *  Realizuje iloczyn skalarny dwóch wektorów
 */
  double operator*(const Wektor &W2) const;
/*
 *  Realizuje iloczyn wektora ze skalarem
 */
  const Wektor operator*(double l) const;

/*
 *  Realizuje iloraz wektora i skalara
 */
  const Wektor operator/(double l) const;

/*
 *  Realizuje sume z przypisaniem dla dwóch wektorów
 */
  Wektor &operator+=(const Wektor &W2);

/*
 *  Realizuje różnicę z przypisaniem dla dwóch wektorów
 */
  Wektor &operator-=(const Wektor &W2);

/*
 *  Realizuje porównanie dwóch wektorów
 */
  bool operator==(const Wektor &W2);

/*
 *  Realizuje porównanie dwóch wektorów
 */
  bool operator!=(const Wektor &W2);

/*
 *  Odczytuje i zwraca element wektora
 */
  const double &operator[](int index) const;

/*
 *  Odczytuje i zwraca referencje do elementu wektora
 */
  double &operator[](int index);

/*
 *  Długość wektora
 */
  double dlugosc() const;
};

const Wektor operator*(double l, Wektor &W2);
std::istream &operator>>(std::istream &Strm, Wektor &W);
std::ostream &operator<<(std::ostream &Strm, const Wektor &W);


#endif
