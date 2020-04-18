#include <stdio.h>
#include <math.h>
#include <iomanip>
#include "Wektor.hh"

Wektor::Wektor()
{
    for (int i = 0; i < ROZMIAR; i++)
        (*this)[i] = 0;
}

Wektor::Wektor(double tablica[])
{
    for (int i = 0; i < ROZMIAR; i++)
        (*this)[i] = tablica[i];
}

Wektor Wektor::operator+(const Wektor &W2) const
{
    Wektor Suma;

    for (int i = 0; i < ROZMIAR; i++)
        Suma[i] = (*this)[i] + W2[i];

    return Suma;
}

Wektor Wektor::operator-(const Wektor &W2) const
{
    Wektor Roznica;
    for (int i = 0; i < ROZMIAR; i++)
        Roznica[i] = (*this)[i] - W2[i];

    return Roznica;
}

double Wektor::operator*(const Wektor &W2) const
{
    double iloczyn = 0;

    for (int i = 0; i < ROZMIAR; i++)
        iloczyn += (*this)[i] * W2[i];

    return iloczyn;
}

Wektor Wektor::operator*(double l) const
{
    Wektor Iloczyn;

    for (int i = 0; i < ROZMIAR; i++)
        Iloczyn[i] = (*this)[i] * l;

    return Iloczyn;
}

Wektor Wektor::operator/(double l) const
{
    Wektor Iloraz;

    if (l == 0)
        throw(std::invalid_argument("Próba dzielenia przez 0"));

    for (int i = 0; i < ROZMIAR; i++)
        Iloraz[i] = (*this)[i] / l;

    return Iloraz;
}

const Wektor & Wektor::operator+=(const Wektor &W2){
    for (int i = 0; i < ROZMIAR; i++)
        (*this)[i] += W2[i];

    return *this;
}

const Wektor &Wektor::operator-=(const Wektor &W2)
{
    for (int i = 0; i < ROZMIAR; i++)
        (*this)[i] -= W2[i];

    return *this;
}

bool Wektor::operator==(const Wektor &W2) const
{
    for (int i = 0; i < ROZMIAR; i++){
        if(abs((*this)[i] - W2[i]) > 0.000001)
            return false;
    }

    return true;
}

bool Wektor::operator!=(const Wektor &W2) const
{
    return !(*this == W2);
}

double Wektor::operator[](int index) const
{
    if(index < 0 || index >= ROZMIAR)
        throw(std::out_of_range("Próba dostępu poza indeks tablicy (" + std::to_string(index) + ')'));

    return this->m_tab[index];
}

double &Wektor::operator[](int index)
{
    if (index < 0 || index >= ROZMIAR)
        throw(std::out_of_range("Próba dostępu poza indeks tablicy (" + std::to_string(index) + ')'));

    return this->m_tab[index];
}

double Wektor::dlugosc() const{
    double dl = 0;

    for (int i = 0; i < ROZMIAR; i++)
        dl += pow((*this)[i], 2);
    return sqrt(dl);
}

Wektor operator*(double l, const Wektor &W2){
    return W2 * l;
}

Wektor operator-(const Wektor &W2){
    Wektor Zmiana;

    for (int i = 0; i < ROZMIAR; i++)
        Zmiana[i] = -W2[i];

    return Zmiana;
}

std::istream &operator>>(std::istream &strm, Wektor &W){
    for (int i = 0; i < ROZMIAR; i++)
        strm >> W[i];

    return strm;
}

std::ostream &operator<<(std::ostream &strm, const Wektor &W){
    for (int i = 0; i < ROZMIAR; i++)
        strm << std::setw(3) << W[i] << " ";

    return strm;
}