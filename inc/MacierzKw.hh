#ifndef MACIERZ_KW_HH
#define MACIERZ_KW_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>

/*
 *  Klasa modeluje pojęcie macierzy kwadratowej złożonej z tablicy wektorów
 */
class MacierzKw {
  Wektor m_macierz[ROZMIAR];

public:
  /*
  * Konstruktor domyślny
  */
  MacierzKw() = default;

  /*
  *  Konstruktor inicjujący macierz tablicą wektorów
  */
  MacierzKw(const Wektor macierz[]);

  /*
  *  Realizuje dodawania dwóch macierzy kwadratowych
  */
  const MacierzKw operator+(const MacierzKw &M2) const;

  /*
  *  Realizuje odejmowanie dwóch macierzy kwadratowych
  */
  const MacierzKw operator-(const MacierzKw &M2) const;

  /*
  *  Realizuje mnożenie dwóch macierzy kwadratowych
  */
  const MacierzKw operator*(const MacierzKw &M2) const;

  /*
  *  Realizuje mnożenie macierzy kwadratowej i skalara
  */
  const MacierzKw operator*(double l) const;

  /*
  *  Realizuje mnożenie macierzy kwadratowej i wektora
  */
  const Wektor operator*(const Wektor &W2) const;

  /*
  *  Realizuje dzielenie macierzy kwadratowej przez skalar
  */
  const MacierzKw operator/(double l) const;

  /*
  *  R-wartość elementu macierzy
  */
  const Wektor &operator[](int index) const;

  /*
  *  L-wartość elementu macierzy
  */
  Wektor &operator[](int index);

  /*
  *   Transponowanie macierzy kwadratowej
  */
  const MacierzKw &transponuj();

  /*
  *   Transponowanie macierzy kwadratowej
  */
  double wyznacznik() const;

  /*
  *   Odwracanie macierzy kwadratowej
  */
  const MacierzKw &odwroc();
};

const MacierzKw operator*(double l, const MacierzKw &M2);

std::istream& operator >> (std::istream &strm, MacierzKw &M);

std::ostream& operator << (std::ostream &strm, const MacierzKw &M);


#endif
