#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
/*

    template< class ForwardIterator, class Size, class Type >
    ForwardIterator
    search_n( ForwardIterator first,
              ForwardIterator last,
              Size count, const Type &value );
              
    template< class ForwardIterator, class Size,
              class Type, class BinaryPredicate >
    ForwardIterator
    search_n( ForwardIterator first,
              ForwardIterator last,
              Size count, const Type &value,
              BinaryPredicate pred );

/*
 * generuje:
   Oczekujemy znalezienia dwóch egzemplarzy znaku 'o': o o
   Oczekujemy znalezienia podnapisu "ret": r e t
*/ 

int main()
{
  ostream_iterator<char> plikwy(cout, " ");
  
  const char odstep = ' ';
  const char zn_o   = 'o';

  char napis[26] = "o rety mysz zjadła słonia";
  //char napis[] = "o rety mysz zjadła słonia";
  char *znal_napis = search_n(napis, napis+25, 2, zn_o);

  cout << "Oczekujemy znalezienia dwóch egzemplarzy znaku 'o': ";
  copy(znal_napis, znal_napis+2, plikwy); cout << '\n';

  vector<char, allocator<char> > wek(napis, napis+25);
  
  // szukamy pierwszego ciągu złożonego z trzech znaków
  // nie będących odstępen: ret w słowie rety

  vector<char, allocator<char> >:: iterator iter;
  iter = search_n(wek.begin(), wek.end(), 3,
                  odstep, not_equal_to<char>());

  cout << "Oczekujemy znalezienia podnapisu \"ret\": ";
  copy(iter, iter+3, plikwy); cout << '\n';

}
