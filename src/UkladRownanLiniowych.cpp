#include <iomanip>
#include <iostream>
#include <math.h>
#include "rozmiar.h"
#include "Wektor.hh"
#include "MacierzKw.hh"
#include "UkladRownanLiniowych.hh"

using std::cin;
using std::cout;
using std::endl;
using std::setw;

UkladRownanLiniowych::UkladRownanLiniowych(const MacierzKw M, const Wektor W)
{
    m_A = M;
    m_b = W;
}

const Wektor &UkladRownanLiniowych::PrzekazB() const
{
    return m_b;
}

const Wektor &UkladRownanLiniowych::PrzekazX() const
{
    return m_x;
}

const MacierzKw &UkladRownanLiniowych::PrzekazA() const
{
    return m_A;
}

void UkladRownanLiniowych::ObliczMacierzOdwrotna()
{
    MacierzKw OdwA = this->m_A;
    this->m_x = OdwA.odwroc() * this->m_b;
}

void UkladRownanLiniowych::ObliczCramer()
{
    MacierzKw tempA = this->m_A;
    Wektor tempWiersz;
    double detA = tempA.wyznacznik();

    if (abs(detA) < 0.000001)
        throw(std::runtime_error("Wyznacznik jest równy 0."));

    tempA.transponuj();
    for (int i = 0; i < ROZMIAR; ++i)
    {
        tempWiersz = tempA[i];
        tempA[i] = this->m_b;
        this->m_x[i] = tempA.wyznacznik() / detA;
        tempA[i] = tempWiersz;
    }
}

Wektor UkladRownanLiniowych::WektorBledu() const
{
    return this->m_A * this->m_x - this->m_b;
}

void UkladRownanLiniowych::WyswietlUkladBlad(const std::string &nazwa) const{
    Wektor Blad = (*this).WektorBledu();

    cout << endl << "====== " << nazwa << " ======" << endl;
    cout << "Rozwiązanie: " << endl << *this << endl;
    cout << std::scientific << std::setprecision(2);
    cout << "Wektor błędu: " << endl << Blad << endl;
    cout << std::defaultfloat;
    cout << "Długość wektora błędu: " << Blad.dlugosc() << endl;
}

std::istream &operator>>(std::istream &strm, UkladRownanLiniowych &UklRown)
{
    MacierzKw M;
    Wektor W;
    
    strm >> M >> W;
    UkladRownanLiniowych Temp(M.transponuj(), W);
    UklRown = Temp;

    return strm;
}

std::ostream &operator<<(std::ostream &strm, const UkladRownanLiniowych &UklRown)
{
    cout << std::setprecision(4) << std::left;
    for (int i = 0; i < ROZMIAR; i++)
    {
        strm << "| " << UklRown.PrzekazA()[i] << " | | " << setw(8) << UklRown.PrzekazX()[i] << " |";
        if(i == ROZMIAR / 2)
            strm << " = ";
        else
            strm << "   ";
        strm << "| " << setw(8) << UklRown.PrzekazB()[i] << " |" << endl;
    }

    return strm;
}