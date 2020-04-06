#include <iomanip>
#include <iostream>
#include "rozmiar.h"
#include "Wektor.hh"
#include "MacierzKw.hh"
#include "UkladRownanLiniowych.hh"

inline UkladRownanLiniowych::UkladRownanLiniowych(const MacierzKw M, const Wektor W){
    m_A = M;
    m_b = W;
}

inline const Wektor &UkladRownanLiniowych::PrzekazB() const{
    return m_b;
}

inline const Wektor &UkladRownanLiniowych::PrzekazX() const{
    return m_x;
}

inline const MacierzKw &UkladRownanLiniowych::PrzekazA() const{
    return m_A;
}

void UkladRownanLiniowych::Oblicz(){
    MacierzKw OdwA = this->m_A;
    this->m_x = OdwA.odwroc() * this->m_b;
}

const Wektor UkladRownanLiniowych::WektorBledu() const{
    return this->m_A * this->m_x - this->m_b;
}

std::istream &operator>>(std::istream &strm, UkladRownanLiniowych &UklRown){
    MacierzKw M;
    Wektor W;
    
    strm >> M >> W;
    UkladRownanLiniowych Temp(M.transponuj(), W);
    UklRown = Temp;

    return strm;
}

std::ostream &operator<<(std::ostream &strm, const UkladRownanLiniowych &UklRown){
    for (int i = 0; i < ROZMIAR; i++)
    {
        strm << "| " << UklRown.PrzekazA()[i] << " | | " << std::setw(8) << UklRown.PrzekazX()[i] << " |";
        if(i == ROZMIAR / 2)
            strm << " = ";
        else
            strm << "   ";
        strm << "| " << std::setw(8) << UklRown.PrzekazB()[i] << " |" << std::endl;
    }

    return strm;
}