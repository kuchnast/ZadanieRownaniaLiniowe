#include "MacierzKw.hh"
#include "Wektor.hh"
#include <iostream>
#include <math.h>
#include <iomanip>

/*
 * Konstruktor inicjujący macierz tablicą wektorów
 */
MacierzKw::MacierzKw(const Wektor macierz[])
{
    for (int i = 0; i < ROZMIAR; i++)
        (*this)[i] = macierz[i];
}

/*
 *  Realizuje dodawania dwóch macierzy kwadratowych
 * 
 *  Zwraca:
 *      sume dwóch macierzy będącą macierzą
 */
const MacierzKw MacierzKw::operator+(const MacierzKw &M2) const{
    MacierzKw Suma;

    for (int i = 0; i < ROZMIAR; i++)
        Suma[i] = (*this)[i] + M2[i];

    return Suma;
}

/*
 *  Realizuje odejmowanie dwóch macierzy kwadratowych
 * 
 *  Zwraca:
 *      różnicę dwóch macierzy będącą macierzą
 */
const MacierzKw MacierzKw::operator-(const MacierzKw &M2) const{
    MacierzKw Roznica;

    for (int i = 0; i < ROZMIAR; i++)
        Roznica[i] = (*this)[i] - M2[i];

    return Roznica;
}

/*
 *  Realizuje mnożenie dwóch macierzy kwadratowych 
 *  metodą współczynniki - wektory 
 * 
 *  Zwraca:
 *      iloczyn dwóch macierzy będący macierzą
 */
const MacierzKw MacierzKw::operator*(const MacierzKw &M2) const
{
    MacierzKw Iloczyn;

    for (int i = 0; i < ROZMIAR; i++)
        for (int j = 0; j < ROZMIAR; j++)
            Iloczyn[i] += (*this)[i][j] * M2[j];

    return Iloczyn;
}

/*
 *  Realizuje mnożenie macierzy kwadratowej i skalara
 * 
 *  Zwraca:
 *      iloczyn macierzy i skalara będący macierzą
 */
const MacierzKw MacierzKw::operator*(double l) const
{
    MacierzKw Iloczyn;

    for (int i = 0; i < ROZMIAR; i++)
        Iloczyn[i] = (*this)[i] * l;

    return Iloczyn;
}

/*
 *  Realizuje mnożenie macierzy kwadratowej i wektora
 * 
 *  Zwraca:
 *      iloczyn macierzy i wektora będący wektorem
 */
const Wektor MacierzKw::operator*(const Wektor &W2) const
{
    Wektor Iloczyn;

    for (int i = 0; i < ROZMIAR; i++)
        for (int j = 0; j < ROZMIAR; j++)
            Iloczyn[i] += (*this)[i][j] * W2[j];

    return Iloczyn;
}

/*
 *  Realizuje dzielenie macierzy kwadratowej przez skalar
 * 
 *  Zwraca:
 *      iloraz macierzy i skalara będący macierzą
 * 
 *  Wyjątek:
 *      (std::string) - próba dzielenia przez 0
 */
const MacierzKw MacierzKw::operator/(double l) const
{
    MacierzKw Iloraz;

    if (l == 0){
        std::string e = "Próba dzielenia przez 0";
        throw(e);
    }

    for (int i = 0; i < ROZMIAR; i++)
        Iloraz[i] = (*this)[i] / l;

    return Iloraz;
}

/*
 *  R-wartość elementu macierzy
 * 
 *  Zwraca:
 *      referencję do wektora z macierzy
 * 
 *  Wyjątek:
 *      (std::string) - próba dostępu poza tablice
*/
const Wektor &MacierzKw::operator[](int index) const 
{
    if (index < 0 || index >= ROZMIAR){
        std::string e = "Błędny indeks: " + std::to_string(index);
        throw(e);
    }

    return this->m_macierz[index];
}

/*
 *  L-wartość elementu macierzy
 * 
 *  Zwraca:
 *      referencję do wektora z macierzy
 * 
 *  Wyjątek:
 *      (std::string) - próba dostępu poza tablice
*/
Wektor &MacierzKw::operator[](int index)
{
    if (index < 0 || index >= ROZMIAR){
        std::string e = "Błędny indeks: " + std::to_string(index);
        throw(e);
    }

    return this->m_macierz[index];
}

/*
 *   Transponowanie macierzy kwadratowej
 * 
 *   Zwraca:
 *      referencje na przetransponowaną macierz wejściową
*/
const MacierzKw &MacierzKw::transponuj(){
    MacierzKw Temp = (*this);

    for (int i = 0; i < ROZMIAR; i++)
        for (int j = 0; j < ROZMIAR; j++)
            (*this)[i][j] = Temp[j][i];

    return (*this);
}

/*
 *  Wyznacznik macierzy kwadratowej obliczany metodą Gaussa
 * 
 *  Zwraca:
 *      wyznacznik macierzy
 * 
 *   Wyjątek:
 *      (const * char) - macierz jest osobliwa
*/
double MacierzKw::wyznacznik() const
{
    int i, j;
    MacierzKw Wyz = (*this);
    double mnoznik, temp = 1;

    for (i = 0; i < ROZMIAR; i++){ //petla kolejnych elementów z przekątnej
    if(Wyz[i][i] == 0){    //jeśli na przekątnej jest 0, wybierz wiersz do zamiany
        j = i;
        while (Wyz[j][i] == 0){
            if (++j == ROZMIAR)
                throw("Macierz jest osobliwa.");
        }
        Wyz[i] = Wyz[j];
        Wyz[j] = -(*this)[i];
    }
    
    for (j = i + 1; j < ROZMIAR; j++){  //petla zerowania kolejnych kolumn
        mnoznik = -Wyz[j][i] / Wyz[i][i];
        Wyz[j] += mnoznik * Wyz[i];
        if(Wyz[j].dlugosc() == 0)
            return 0;
    }
    temp *= Wyz[i][i];
    }
    return temp;
 }

 /*
 *   Odwracanie macierzy kwadratowej metodą Gaussa-Jordana
 * 
 *   Zwraca:
 *      referencje do odwroconej macierzy wejsciowej
 * 
 *   Wyjątek:
 *      (const * char) - macierz jest osobliwa
*/
 const MacierzKw &MacierzKw::odwroc()
 {
     int i, j;
     double mnoznik;
     MacierzKw OdwA, A = (*this);
     Wektor Temp;

     for (i = 0; i < ROZMIAR; i++)
     {
         OdwA[i][i] = 1;
     }

     for (i = 0; i < ROZMIAR; i++)
     { //petla dla dolnej części przekątnej
         if (A[i][i] == 0)
         { //jeśli na przekątnej jest 0, wybierz wiersz do zamiany
             j = i;
             while (A[j][i] == 0)
             {
                 if (++j == ROZMIAR)
                     throw("Macierz jest osobliwa.");
             }
             A[i] = A[j];
             A[j] = (*this)[i];
             Temp = OdwA[i];
             OdwA[i] = OdwA[j];
             OdwA[j] = Temp;
         }

         OdwA[i] = OdwA[i] / A[i][i];
         A[i] = A[i] / A[i][i];

         for (j = i + 1; j < ROZMIAR; j++)
         { //petla zerowania kolejnych kolumn
             mnoznik = -A[j][i] / A[i][i];
             A[j] += mnoznik * A[i];
             OdwA[j] += mnoznik * OdwA[i];
         }
     }

     for (i = ROZMIAR - 1; i > 0; i--)
     { //petla dla górnej części przekątnej
         for (j = i - 1; j >= 0; j--)
         { //petla zerowania kolejnych kolumn
             OdwA[j] -= A[j][i] * OdwA[i];
             A[j] -= A[j][i] * A[i];
         }
     }
     (*this) = OdwA;

     return (*this);
}

std::ostream &operator<<(std::ostream &strm, const MacierzKw &M){

    for (int i = 0; i < ROZMIAR; i++)
        strm << M[i] << std::endl;

    return strm;
}

std::istream &operator>>(std::istream &strm, MacierzKw &M){
    for (int i = 0; i < ROZMIAR; i++)
        strm >> M[i];

    return strm;
}