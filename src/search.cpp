#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

/*

template< class ForwardIterator1, class ForwardIterator2 >
        ForwardIterator
        search( ForwardIterator1 first1, ForwardIterator1 last1,
                     ForwardIterator2 first2, ForwardIterator2 last2 );
        template< class ForwardIterator1, class ForwardIterator2,
                       class BinaryPredicate >
        ForwardIterator
        search( ForwardIterator1 first1, ForwardIterator1 last1,
                     ForwardIterator2 first2, ForwardIterator2 last2,
                     BinaryPredicate pred );
*/
/*
 * generuje: 
   Oczekujemy znalezienia podnapisu "ate": a t e
   Oczekujemy znalezienia podnapisu "vat": v a t
*/

int main()
{
  ostream_iterator<char> plikwy(cout, " ");
  char napis[25] = "a fine and private place";
  char podnapis[] = "ate";
  char *znal_napis = search(napis,napis+25,podnapis,podnapis+3);
  
  cout << "Oczekujemy znalezienia podnapisu \"ate\": ";
  copy(znal_napis, znal_napis+3, plikwy); cout << '\n';
  
  vector<char, allocator<char> > wek(napis, napis+24);
  vector<char, allocator<char> > podwektor(3);

  podwektor[0]='v'; podwektor[1]='a'; podwektor[2]='t';

  vector<char, allocator<char> >::iterator iter;
  iter = search(wek.begin(), wek.end(),
          podwektor.begin(), podwektor.end(),
          equal_to<char>() );

  cout << "Oczekujemy znalezienia podnapisu \"vat\": ";
  copy(iter, iter+3, plikwy); cout << '\n';
}
