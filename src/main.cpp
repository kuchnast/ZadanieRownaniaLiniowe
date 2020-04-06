#include <iostream>
#include <iomanip>
#include "rozmiar.h"
#include "Wektor.hh"
#include "MacierzKw.hh"
#include "UkladRownanLiniowych.hh"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{
  UkladRownanLiniowych UklRow;
  Wektor Blad;

  cout << endl << " Start programu " << endl << endl;
  cin >> UklRow;
  while (!cin.good()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << ":/ Błąd zapisu układu równań. Spróbuj jeszcze raz:" << endl;
    cin >> UklRow;
  }
  cout << std::setprecision(4) << std::left;
  cout << "Macierz A^T:" << endl << UklRow.PrzekazA() << endl << endl;
  cout << "Wektor wyrazów wolnych b:" << endl << UklRow.PrzekazB() << endl << endl;

  try{
    UklRow.Oblicz();
  }
  catch (const char * error){
    cout << error << endl;
    cout << "Program kończy działanie." << endl;
    return 0;
  }
  catch(std::string error){
     cerr << "Błąd wewnętrzny: " << error << endl;
     return -1;
  }

  cout << "Rozwiązanie: " << endl << UklRow << endl;

  Blad = UklRow.WektorBledu();

  cout << std::scientific << std::setprecision(2);
  cout << "Wektor błędu: " << endl << Blad << endl;
  cout << "Długość wektora błędu: " << Blad.dlugosc() << endl;

  return 0;
}
