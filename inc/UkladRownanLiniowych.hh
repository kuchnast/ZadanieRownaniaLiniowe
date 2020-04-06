#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <fstream>
#include "rozmiar.h"
#include "MacierzKw.hh"
#include "Wektor.hh"


/*
 *  Klasa realizuje pojęcie układu równań liniowych złożonego z macierzy 
 *  i wektora wyrazów wolnych
 */
class UkladRownanLiniowych {
  Wektor m_b, m_x;
  MacierzKw m_A;

public:
  UkladRownanLiniowych() = default;

  UkladRownanLiniowych(const MacierzKw M, const Wektor W);

  const Wektor &PrzekazB() const;

  const Wektor &PrzekazX() const;

  const MacierzKw &PrzekazA() const;

  void Oblicz();

  const Wektor WektorBledu() const;
};

std::istream &operator>>(std::istream &strm, UkladRownanLiniowych &UklRown);

std::ostream &operator<<(std::ostream &strm, const UkladRownanLiniowych &UklRown);


#endif
