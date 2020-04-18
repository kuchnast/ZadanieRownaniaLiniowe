#include "MacierzKw.hh"
#include "Wektor.hh"
#include <iostream>
#include <math.h>

MacierzKw::MacierzKw(const Wektor macierz[])
{
    for (int i = 0; i < ROZMIAR; i++)
        (*this)[i] = macierz[i];
}

MacierzKw MacierzKw::operator+(const MacierzKw &M2) const
{
    MacierzKw Suma;

    for (int i = 0; i < ROZMIAR; i++)
        Suma[i] = (*this)[i] + M2[i];

    return Suma;
}

MacierzKw MacierzKw::operator-(const MacierzKw &M2) const
{
    MacierzKw Roznica;

    for (int i = 0; i < ROZMIAR; i++)
        Roznica[i] = (*this)[i] - M2[i];

    return Roznica;
}

MacierzKw MacierzKw::operator*(const MacierzKw &M2) const
{
    MacierzKw Iloczyn;

    for (int i = 0; i < ROZMIAR; i++)
        for (int j = 0; j < ROZMIAR; j++)
            Iloczyn[i] += (*this)[i][j] * M2[j];

    return Iloczyn;
}

MacierzKw MacierzKw::operator*(double l) const
{
    MacierzKw Iloczyn;

    for (int i = 0; i < ROZMIAR; i++)
        Iloczyn[i] = (*this)[i] * l;

    return Iloczyn;
}


Wektor MacierzKw::operator*(const Wektor &W2) const
{
    Wektor Iloczyn;

    for (int i = 0; i < ROZMIAR; i++)
        for (int j = 0; j < ROZMIAR; j++)
            Iloczyn[i] += (*this)[i][j] * W2[j];

    return Iloczyn;
}

MacierzKw MacierzKw::operator/(double l) const
{
    MacierzKw Iloraz;

    if (l == 0)
        throw(std::invalid_argument("Próba dzielenia przez 0"));

    for (int i = 0; i < ROZMIAR; i++)
        Iloraz[i] = (*this)[i] / l;

    return Iloraz;
}

const Wektor &MacierzKw::operator[](int index) const 
{
    if (index < 0 || index >= ROZMIAR)
        throw(std::out_of_range("Próba dostępu poza indeks tablicy (" + std::to_string(index) + ')'));

    return this->m_macierz[index];
}

Wektor &MacierzKw::operator[](int index)
{
    if (index < 0 || index >= ROZMIAR)
        throw(std::out_of_range("Próba dostępu poza indeks tablicy (" + std::to_string(index) + ')'));

    return this->m_macierz[index];
}

const MacierzKw &MacierzKw::transponuj()
{
    MacierzKw Temp = (*this);

    for (int i = 0; i < ROZMIAR; i++)
        for (int j = 0; j < ROZMIAR; j++)
            (*this)[i][j] = Temp[j][i];

    return (*this);
}

double MacierzKw::wyznacznik() const
{
    int i, j;
    MacierzKw Wyz = (*this);
    double temp = 1;

    for (i = 0; i < ROZMIAR; i++){ //petla kolejnych elementów z przekątnej
        if(Wyz[i][i] == 0){    //jeśli na przekątnej jest 0, wybierz wiersz do zamiany
            j = i;
            while (Wyz[j][i] == 0){
                if (++j == ROZMIAR)
                    return 0; //macierz jest osobliwa
            }
            Wyz[i] = Wyz[j];
            Wyz[j] = -(*this)[i];
        }
        
        for (j = i + 1; j < ROZMIAR; j++){  //petla zerowania kolejnych kolumn
            Wyz[j] += (-Wyz[j][i] / Wyz[i][i]) * Wyz[i];
            if(Wyz[j].dlugosc() == 0)
                return 0;
        }
        temp *= Wyz[i][i];
    }
    return temp;
 }

 const MacierzKw &MacierzKw::odwroc()
 {
     int i, j;
     double mnoznik;
     MacierzKw OdwA, A = (*this);

     for (i = 0; i < ROZMIAR; i++)
     {
         OdwA[i][i] = 1;
     }

     for (i = 0; i < ROZMIAR; i++)
     { //petla dla części pod przekątną
         if (A[i][i] == 0)
         { //jeśli na przekątnej jest 0, wybierz wiersz do zamiany
             j = i;
             while (A[j][i] == 0)
             {
                 if (++j == ROZMIAR)
                     throw(std::runtime_error("Macierz jest osobliwa."));
             }
             std::swap(A[i], A[j]);
             std::swap(OdwA[i], OdwA[j]);
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
     { //petla dla części nad przekątną
         for (j = i - 1; j >= 0; j--)
         { //petla zerowania kolejnych kolumn
             OdwA[j] -= A[j][i] * OdwA[i];
             A[j] -= A[j][i] * A[i];
         }
     }
     (*this) = OdwA;

     return (*this);
}

MacierzKw operator*(double l, const MacierzKw &M2){
    return M2 * l;
}

std::istream &operator>>(std::istream &strm, MacierzKw &M)
{
    for (int i = 0; i < ROZMIAR; i++)
        strm >> M[i];

    return strm;
}

std::ostream &operator<<(std::ostream &strm, const MacierzKw &M){

    for (int i = 0; i < ROZMIAR; i++)
        strm << M[i] << std::endl;

    return strm;
}