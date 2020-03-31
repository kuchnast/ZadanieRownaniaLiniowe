#include <stdio.h>
#include <math.h>
#include "Wektor.hh"

using std::cin;
using std::cout;
using std::endl;

/*
 * Konstruktor domyślny zerujący pola klasy.
 */
Wektor::Wektor(){
    for (int i = 0; i < ROZMIAR; i++)
        this->m_tab[i] = 0;
}

/*
 *  Konstruktor inicjujacy pola klasy przesłaną tablicą
 * 
 *  Parametry:
 *      tablica - kolejne współrzędne tworzace wektor
 *  Warunki wstępne:
 *      tablica musi posiadać rozmiar identyczny jak m_tab  
 */
Wektor::Wektor(double tablica[]){
    for (int i = 0; i < ROZMIAR; i++)
        this->m_tab[i] = tablica[i];
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
        Suma.m_tab[i] = this->m_tab[i] + W2.m_tab[i];

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
        Roznica.m_tab[i] = this->m_tab[i] - W2.m_tab[i];

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
        iloczyn += this->m_tab[i] * W2.m_tab[i];

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
        Iloczyn.m_tab[i] = this->m_tab[i] * l;

    return Iloczyn;
}

/*
 *  Realizuje iloraz wektora i skalara
 *  W przypadku próby dzielenia przez 0 rzuca wyjątek
 * 
 *  Zwraca:
 *      iloraz wektora i skalara będący wektorem
 */
const Wektor Wektor::operator*(double l) const
{
    Wektor Iloraz;
    if(l == 0)
        throw("Próba dzielenia przez 0");
    ;

    for (int i = 0; i < ROZMIAR; i++)
        Iloraz.m_tab[i] = this->m_tab[i] / l;

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
        this->m_tab[i] += W2.m_tab[i];

    return *this;
}

/*
 *  Realizuje różnicę z przypisaniem dla dwóch wektorów
 * 
 *  Zwraca:
 *      referencje do zmienionego wektora 
 */
Wektor &Wektor::operator+=(const Wektor &W2)
{
    for (int i = 0; i < ROZMIAR; i++)
        this->m_tab[i] -= W2.m_tab[i];

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
        if(this->m_tab[i] != W2.m_tab[i])
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
bool Wektor::operator==(const Wektor &W2)
{
    return !(*this == W2);
}

/*
 *  Odczytuje element wektora
 *  W przypadku próby odniesienia się do nieistniejącego elementu rzuca wyjątek
 * 
 *  Zwraca:
 *      wartość z wektora o wybranym indeksie
 */
const double &Wektor::operator[](int index) const{
    if(index < 0 || index >= ROZMIAR)
        throw("Błędny indeks");
    return this->m_tab[index];
}

/*
 *  Przypisuje wartość elementowi wektora
 *  W przypadku próby odniesienia się do nieistniejącego elementu rzuca wyjątek
 * 
 *  Zwraca:
 *      wartość z wektora o wybranym indeksie
 */
double &Wektor::operator[](int index){
    if (index < 0 || index >= ROZMIAR)
        throw("Błędny indeks");
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
        dl += pow(this->m_tab[i], 2);
    return sqrt(dl);
}