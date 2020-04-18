#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

/**
 * @brief Klasa modeluje pojęcie wektora o stałym rozmiarze
 * 
 */
class Wektor 
{
private:

  double m_tab[ROZMIAR]; ///< Tablica współżędnych wektora

public:

/**
 * @brief Konstruktor nowego obiektu Wektor 
 * @details Wektor inicjowany jest zerami
 * 
 */
  Wektor();

/**
 * @brief Konstruktor nowego obiektu Wektor 
 * @details Wektor inicjowany jest tablicą wartości o tym samym rozmiarze
 * 
 * @param tablica tablica wartości
 */
  Wektor(double tablica[]);

/**
 * @brief Dodawania dwóch wektorów
 * 
 * @param W2 drugi wektor - składnik
 * @return Wektor suma dwóch wektorów będąca wektorem 
 */
  Wektor operator+(const Wektor &W2) const;

/**
 * @brief Odejmowanie dwóch wektorów
 * 
 * @param W2 drugi wektor - odjemnik
 * @return Wektor różnica dwóch wektorów będąca wektorem
 */
  Wektor operator-(const Wektor &W2) const;

/**
 * @brief Iloczyn skalarny dwóch wektorów
 * 
 * @param W2 drugi wektor - czynnik
 * @return double iloczyn dwóch wektorów będący skalarem
 */
  double operator*(const Wektor &W2) const;

/**
 * @brief Iloczyn wektora ze skalarem
 * 
 * @param l skalar - czynnik
 * @return Wektor iloczyn wektora i skalara będący wektorem
 */
  Wektor operator*(double l) const;

/**
 * @brief Iloraz wektora i skalara
 * 
 * @exception std::invalid_argument próba dzielenia przez 0
 * @param l skalar - dzielnik
 * @return Wektor iloraz wektora i skalara będący wektorem
 */
  Wektor operator/(double l) const;

/**
 * @brief Suma z przypisaniem dla dwóch wektorów
 * 
 * @param W2 drugi wektor - składnik
 * @return const Wektor& zmieniony wektor z wejścia
 */
  const Wektor &operator+=(const Wektor &W2);

/**
 * @brief Różnica z przypisaniem dla dwóch wektorów
 * 
 * @param W2 drugi wektor - odjemnik
 * @return const Wektor& zmieniony wektor z wejścia
 */
  const Wektor &operator-=(const Wektor &W2);

/**
 * @brief Porównanie dwóch wektorów
 * 
 * @param W2 drugi wektor
 * @return true - wektory są równe
 * @return false  - wektory są różne
 */
  bool operator==(const Wektor &W2) const;

/**
 * @brief Porównanie dwóch wektorów
 * 
 * @param W2 drugi wektor
 * @return true - wektory są różne
 * @return false  - wektory są równe
 */
  bool operator!=(const Wektor &W2) const;

/**
 * @brief Dostęp do elementu tablicy w celu odczytu
 * 
 * @exception std::out_of_range próba dostępu poza indeksy tablicy
 * @param index indeks elementu
 * @return double R-wartość elementu tablicy
 */
  double operator[](int index) const;

/**
 * @brief Dostęp do elementu tablicy w celu zapisu
 * 
 * @exception std::out_of_range próba dostępu poza indeksy tablicy
 * @param index indeks elementu
 * @return double& L-wartość elementu tablicy
 */
  double &operator[](int index);

/**
 * @brief Oblicza długość wektora
 * 
 * @return double dlugosc wektora jako liczbe zmiennoprzecinkową
 */
  double dlugosc() const;
};

/**
 * @brief Iloczyn skalara i wektora
 * 
 * @param l skalar - czynnik
 * @param W2 wektor - czynnik
 * @return Wektor iloraz skalara i wektora będący wektorem
 */
Wektor operator*(double l, const Wektor &W2);

/**
 * @brief Zmiana znaków elementów wektora na przeciwne
 * 
 * @param W2 wektor
 * @return Wektor wejściowy wektor z przeciwnymi znakami
 */
Wektor operator-(const Wektor &W2);

/**
 * @brief Wczytanie wartości do wektora
 * 
 * @param strm strumień wejściowy
 * @param W wektor do którego wprowadza się wartości
 * @return std::istream& strumień podany na wejściu 
 */
std::istream &operator>>(std::istream &strm, Wektor &W);

/**
 * @brief Wypisanie wartości z wektora
 * 
 * @param strm strumień wyjściowy
 * @param M wektor do wypisania
 * @return std::ostream& strumień podany na wejściu
 */
std::ostream &operator<<(std::ostream &strm, const Wektor &W);

#endif