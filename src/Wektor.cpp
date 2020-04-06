#include <stdio.h>
#include <math.h>
#include <iomanip>
#include "Wektor.hh"

/*
 * Konstruktor domyślny zerujący wektor
 */
Wektor::Wektor(){
    for (int i = 0; i < ROZMIAR; i++)
        (*this)[i] = 0;
}

/*
 *  Konstruktor inicjujacy wektor
 * 
 *  Parametry:
 *      tablica - kolejne współrzędne tworzace wektor
 *  Warunki wstępne:
 *      tablica musi posiadać rozmiar identyczny jak m_tab  
 */
Wektor::Wektor(double tablica[]){
    for (int i = 0; i < ROZMIAR; i++)
        (*this)[i] = tablica[i];
}

/*
 *  Przypisanie do elementów wektora tych samych wartości
 */
const Wektor &Wektor::operator=(double l)
{
    for (int i = 0; i < ROZMIAR; i++)
        (*this)[i] = l;
        
    return (*this);
}

/*
 *  Realizuje dodawania dwóch wektorów
 * 
 *  Zwraca:
 *      sume dwóch wektorów będącą wektorem
 */
const Wektor Wektor::operator+(const Wektor &W2) const
{
    Wektor Suma;

    for (int i = 0; i < ROZMIAR; i++)
        Suma[i] = (*this)[i] + W2[i];

    return Suma;
}

/*
 *  Realizuje odejmowanie dwóch wektorów
 * 
 *  Zwraca:
 *      różnicę dwóch wektorów będącą wektorem
 */
const Wektor Wektor::operator-(const Wektor &W2) const
{
    Wektor Roznica;
    for (int i = 0; i < ROZMIAR; i++)
        Roznica[i] = (*this)[i] - W2[i];

    return Roznica;
}

/*
 *  Realizuje iloczyn skalarny dwóch wektorów
 * 
 *  Zwraca:
 *      iloczyn dwóch wektorów będący skalarem
 */
double Wektor::operator*(const Wektor &W2) const
{
    double iloczyn = 0;

    for (int i = 0; i < ROZMIAR; i++)
        iloczyn += (*this)[i] * W2[i];

    return iloczyn;
}

/*
 *  Realizuje iloczyn wektora ze skalarem
 * 
 *  Zwraca:
 *      iloczyn wektora i skalara będący wektorem
 */
const Wektor Wektor::operator*(double l) const
{
    Wektor Iloczyn;

    for (int i = 0; i < ROZMIAR; i++)
        Iloczyn[i] = (*this)[i] * l;

    return Iloczyn;
}

/*
 *  Realizuje iloraz wektora i skalara
 *  W przypadku próby dzielenia przez 0 rzuca wyjątek
 * 
 *  Zwraca:
 *      iloraz wektora i skalara będący wektorem
 * 
 *  Wyjątek:
 *      (std::string) - próba dzielenia przez 0
 */
const Wektor Wektor::operator/(double l) const
{
    Wektor Iloraz;
    if (l == 0){
        std::string e = "Próba dzielenia przez 0";
        throw(e);
    }

    for (int i = 0; i < ROZMIAR; i++)
        Iloraz[i] = (*this)[i] / l;

    return Iloraz;
}

/*
 *  Realizuje sume z przypisaniem dla dwóch wektorów
 * 
 *  Zwraca:
 *      referencje do zmienionego wektora 
 */
Wektor & Wektor::operator+=(const Wektor &W2){
    for (int i = 0; i < ROZMIAR; i++)
        (*this)[i] += W2[i];

    return *this;
}

/*
 *  Realizuje różnicę z przypisaniem dla dwóch wektorów
 * 
 *  Zwraca:
 *      referencje do zmienionego wektora 
 */
Wektor &Wektor::operator-=(const Wektor &W2)
{
    for (int i = 0; i < ROZMIAR; i++)
        (*this)[i] -= W2[i];

    return *this;
}

/*
 *  Realizuje porównanie dwóch wektorów
 * 
 *  Zwraca:
 *      true jeżeli są równe
 *      false w przeciwnym wypadku 
 */
bool Wektor::operator==(const Wektor &W2)
{
    for (int i = 0; i < ROZMIAR; i++){
        if((*this)[i] != W2[i])
            return false;
    }

    return true;
}

/*
 *  Realizuje porównanie dwóch wektorów
 * 
 *  Zwraca:
 *      true jeżeli nie są równe
 *      false w przeciwnym wypadku 
 */
bool Wektor::operator!=(const Wektor &W2)
{
    return !(*this == W2);
}

/*
 *  Wartość elementu wektora
 *  W przypadku próby odniesienia się do nieistniejącego elementu rzuca wyjątek
 * 
 *  Zwraca:
 *      wartość z wektora o wybranym indeksie
 * 
 *  Wyjątek:
 *      (std::string) - próba dostępu poza tablice
 */
const double Wektor::operator[](int index) const{
    if(index < 0 || index >= ROZMIAR){
        std::string e = "Błędny indeks: " + std::to_string(index);
        throw(e);
    }
    return this->m_tab[index];
}

/*
 *  Referencja do elementu wektora
 *  W przypadku próby odniesienia się do nieistniejącego elementu rzuca wyjątek
 * 
 *  Zwraca:
 *      referencje do wartości z wektora o wybranym indeksie
 * 
 *  Wyjątek:
 *      (std::string) - próba dostępu poza tablice
 */
double &Wektor::operator[](int index){
    if (index < 0 || index >= ROZMIAR){
        std::string e = "Błędny indeks: " + std::to_string(index);
        throw(e);
    }
    return this->m_tab[index];
}

/*
 *  Długość wektora
 *  
 *  Zwraca:
 *      dlugosc wektora jako liczbe zmiennoprzecinkową
 */
double Wektor::dlugosc() const{
    double dl = 0;

    for (int i = 0; i < ROZMIAR; i++)
        dl += pow((*this)[i], 2);
    return sqrt(dl);
}

/*
 *  Realizuje iloczyn skalarem z wektora
 * 
 *  Zwraca:
 *      iloczyn skalara i wektora będący wektorem
 */
const Wektor operator*(double l, const Wektor &W2){
    Wektor Iloczyn;

    for (int i = 0; i < ROZMIAR; i++)
        Iloczyn[i] = W2[i] * l;

    return Iloczyn;
}

/*
 *  Realizuje zmiane znaków elementów wektora
 * 
 *  Zwraca:
 *      wektor, ktorego elementy mają przeciwne znaki
 */
const Wektor operator-(const Wektor &W2){
    Wektor Zmiana;

    for (int i = 0; i < ROZMIAR; i++)
        Zmiana[i] = -W2[i];

    return Zmiana;
}

/*
 *  Wczytuje wszystkie współżędne wektora
 * 
 *  Zwraca:
 *      strumień wejściowy jako referencje
 */
std::istream &operator>>(std::istream &strm, Wektor &W){
    for (int i = 0; i < ROZMIAR; i++)
        strm >> W[i];

    return strm;
}

/*
 *  Wypisuje wszystkie współżędne wektora
 * 
 *  Zwraca:
 *      strumień wyjściowy jako referencje
 */
std::ostream &operator<<(std::ostream &strm, const Wektor &W){
    for (int i = 0; i < ROZMIAR; i++)
        strm << std::setw(3) << W[i] << " ";

    return strm;
}