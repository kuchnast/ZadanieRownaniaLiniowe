#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using std::cin;
using std::cout;
using std::endl;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  //UkladRownanLiniowych UklRown;   // To tylko przykladowe definicje zmiennej
  double tab1[] = {1, 0, 0};
  double tab2[] = {0, 1, 0};
  double tab3[] = {0, 0, 1};
  Wektor w1(tab1);
  Wektor w2(tab2);
  Wektor w3(tab3);
  Wektor suma;
  suma = w1 + w2 + w3;

  cout << endl << " Start programu " << endl << endl;
  
}
