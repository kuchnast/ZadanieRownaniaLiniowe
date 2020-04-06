#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

/*
 *  Klasa modeluje pojęcie wektora o stałym rozmiarze
 */
class Wektor 
{
private:

  double m_tab[ROZMIAR]; // tablica współżędnych wektora

public:

/*
 *  Konstruktor domyślny zerujący wektor.
 */
  Wektor();

/*
 *  Konstruktor inicjujacy wektor
 */
  Wektor(double tablica[]);

/*
 *  Przypisanie do elementów wektora tych samych wartości
 */
  const Wektor & operator=(double l);

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
 *  Wartość elementu wektora
 */
  const double operator[](int index) const;

/*
 *  Referencja do elementu wektora
 */
  double &operator[](int index);

/*
 *  Długość wektora
 */
  double dlugosc() const;
};

/*
 *  Realizuje iloczyn skalara z wektora
 */
const Wektor operator*(double l, const Wektor &W2);

/*
 *  Realizuje zmiane znaków elementów wektora
 */
const Wektor operator-(const Wektor &W2);

/*
 *  Wczytuje wszystkie współżędne wektora
 */
std::istream &operator>>(std::istream &strm, Wektor &W);

/*
 *  Wypisuje wszystkie współżędne wektora
 */
std::ostream &operator<<(std::ostream &strm, const Wektor &W);

#endif