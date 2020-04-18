#ifndef MACIERZ_KW_HH
#define MACIERZ_KW_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>

/**
 * @brief Klasa modeluje pojęcie macierzy kwadratowej złożonej z tablicy wektorów
 * 
 */
class MacierzKw {
  Wektor m_macierz[ROZMIAR]; ///< Tablica wektorów

public:

/**
 * @brief Konstruktor nowego obiektu Macierz Kwadratowa
 * 
 */
  MacierzKw() = default;

/**
 * @brief Konstruktor nowego obiektu Macierz Kw inicjujący go tablicą wektorów
 * 
 * @param macierz tablica wektorów
 */
  MacierzKw(const Wektor macierz[]);

/**
 * @brief Dodawania dwóch macierzy kwadratowych
 * 
 * @param M2 druga macierz - składnik
 * @return MacierzKw suma dwóch macierzy będąca macierzą
 */
  MacierzKw operator+(const MacierzKw &M2) const;

/**
 * @brief Odejmowanie dwóch macierzy kwadratowych
 * 
 * @param M2 druga macierz - odjemnik
 * @return MacierzKw Różnica dwóch macierzy będąca macierzą
 */
  MacierzKw operator-(const MacierzKw &M2) const;

/**
 * @brief Mnożenie dwóch macierzy kwadratowych
 * @details metodą współczynniki - wektory
 * 
 * @param M2 druga macierz - czynnik
 * @return MacierzKw iloczyn dwóch macierzy będący macierzą
 */
  MacierzKw operator*(const MacierzKw &M2) const;

/**
 * @brief Mnożenie macierzy kwadratowej i skalara
 * 
 * @param l skalar - czynnik
 * @return MacierzKw iloczyn macierzy i skalara będący macierzą
 */
  MacierzKw operator*(double l) const;

/**
 * @brief Mnożenie macierzy kwadratowej i wektora
 * 
 * @param W2 wektor - czynnik
 * @return Wektor iloczyn macierzy i wektora będący wektorem
 */
  Wektor operator*(const Wektor &W2) const;

/**
 * @brief Dzielenie macierzy kwadratowej przez skalar
 * 
 * @exception std::invalid_argument próba dzielenia przez 0
 * @param l skalar - dzielnik
 * @return MacierzKw iloraz macierzy i skalara będący macierzą
 */
  MacierzKw operator/(double l) const;

/**
 * @brief Dostęp do elementu tablicy w celu odczytu
 * 
 * @exception std::out_of_range próba dostępu poza indeksy tablicy
 * @param index indeks elementu
 * @return const Wektor& R-wartość elementu macierzy
 */
  const Wektor &operator[](int index) const;

/**
 * @brief Dostęp do elementu tablicy w celu zapisu
 * 
 * @exception std::out_of_range próba dostępu poza indeksy tablicy
 * @param index indeks elementu
 * @return Wektor& L-wartość elementu macierzy
 */
  Wektor &operator[](int index);

/**
 * @brief Transponowanie macierzy kwadratowej
 * 
 * @return const MacierzKw& transponowana macierz z wejścia
 */
  const MacierzKw &transponuj();

/**
 * @brief Wyznacznik macierzy kwadratowej obliczany metodą Gaussa
 * 
 * @exception std::runtime_error wyznacznik jest równy 0
 * @return double wyznacznik macierzy
 */
  double wyznacznik() const;

/**
 * @brief Odwracanie macierzy kwadratowej metodą Gaussa-Jordana
 * 
 * @return const MacierzKw& odwrócona macierz wejściowa
 */
  const MacierzKw &odwroc();
};

/**
 * @brief Mnożenie skalara i macierzy kwadratowej
 * 
 * @param l skalar - czynnik
 * @param M2 macierz - czynnik
 * @return const MacierzKw iloczyn skalara i macierzy będący macierzą
 */
MacierzKw operator*(double l, const MacierzKw &M2);

/**
 * @brief Wczytanie wartości do macierzy
 * 
 * @param strm strumień wejściowy
 * @param M macierz do której wprowadza się wartości
 * @return std::istream& strumień podany na wejściu 
 */
std::istream& operator>> (std::istream &strm, MacierzKw &M);

/**
 * @brief Wypisanie wartości z macierzy
 * 
 * @param strm strumień wyjściowy
 * @param M macierz do wypisania
 * @return std::ostream& strumień podany na wejściu
 */
std::ostream& operator<< (std::ostream &strm, const MacierzKw &M);


#endif
