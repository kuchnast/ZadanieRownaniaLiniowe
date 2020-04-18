#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <fstream>
#include "rozmiar.h"
#include "MacierzKw.hh"
#include "Wektor.hh"

/**
 * @brief Klasa realizuje pojęcie układu równań liniowych
 * @details Układ równań liniowych opisywany jest przy użyciu kwadratowej macierzy współczynników
 *          wektora wyrazów wolnych oraz wyliczonego wektora rozwiązań.
 */
class UkladRownanLiniowych {
  Wektor m_b;     ///< Wektor wyrazów wolnych
  Wektor m_x;     ///< Wektor rozwiązań
  MacierzKw m_A;  ///< Macierz współczynników

public:
/**
 * @brief Konstruktor nowego obiektu Uklad Rownan Liniowych
 * 
 */
  UkladRownanLiniowych() = default;

/**
 * @brief Konstruktor nowego obiektu Uklad Rownan Liniowych
 * 
 * @param M Macierz współczynników
 * @param W Wektor wyrazów wolnych
 */
  UkladRownanLiniowych(const MacierzKw M, const Wektor W);

/**
 * @brief Przekazuje wektor wyrazów wolnych
 * 
 * @return const Wektor& wektor wyrazów wolnych
 */
  const Wektor &PrzekazB() const;

/**
 * @brief Przekazuje wektor rozwiązań
 * 
 * @return const Wektor& wektor rozwiązań
 */
  const Wektor &PrzekazX() const;

/**
 * @brief Przekazuje macierz współczynników
 * 
 * @return const MacierzKw& macierz współczynników
 */
  const MacierzKw &PrzekazA() const;

/**
 * @brief Oblicza wektor rozwiązań układu równań metodą macierzy odwrotnej
 * 
 */
  void ObliczMacierzOdwrotna();

/**
 * @brief Oblicza wektor rozwiązań układu równań metodą Cramera
 * 
 */
  void ObliczCramer();

  /**
 * @brief Oblicza wektor błędu 
 *        wynikający z ograniczeń przetwarzania liczb zmiennoprzecinkowych
 * 
 * @return Wektor wektor błędu
 */
  Wektor WektorBledu() const;

/**
 * @brief Wyświetla układ równań, wektor błędu oraz długość wektora błędu z odpowiednim nagłówkiem
 * 
 * @param nazwa nazwa wyświetlana u góry wyników
 */
  void WyswietlUkladBlad(const std::string &nazwa) const;
};

/**
 * @brief Wczytuje macierz współczynników oraz wektor wyrazów wolnych w postaci transponowanej
 * 
 * @param strm strumień wejściowy
 * @param UklRown układ równań
 * @return std::istream& referencja do strumienia wejściowego
 */
std::istream &operator>>(std::istream &strm, UkladRownanLiniowych &UklRown);

/**
 * @brief Wyświetla układ równań 
 *        w postaci macierz, wektor rozwiązań, wektor wyrazów wolnych
 * 
 * @param strm strumień wyjściowy
 * @param UklRown układ równań
 * @return std::ostream& referencja do strumienia wyjściowego
 */
std::ostream &operator<<(std::ostream &strm, const UkladRownanLiniowych &UklRown);


#endif
