#include <algorithm>
#include <vector> 
#include <iostream>
#include <iterator>
using namespace std;

/*

template< class ForwardIterator, class OutputIterator >
OutputIterator
rotate_copy( ForwardIterator first, ForwardIterator middle,
             ForwardIterator last,  OutputIterator result );

*/ 
/* generuje:
   pierwotny ciąg elementów:
   1 3 5 7 9 0 2 4 6 8 10
   rotate dla środkowego elementu(0) ::
   0 2 4 6 8 10 1 3 5 7 9
   rotate dla przedostatniego elementu(8) ::
   8 10 1 3 5 7 9 0 2 4 6
   rotate_copy dla środkowego elementu ::
   7 9 0 2 4 6 8 10 1 3 5
*/

int main()
{
    int ti[] = {1,3,5,7,9,0,2,4,6,8,10};

    vector<int, allocator<int> > wek(ti, ti+11);
    ostream_iterator<int> plikwy(cout, " ");

    cout << "pierwotny ciag elementow:\n";
    copy(wek.begin(), wek.end(), plikwy); cout << '\n';
    
    rotate(&ti[0], &ti[5], &ti[11]);
    
    cout << "rotate dla środkowego elementu(0) ::\n";
    copy(ti, ti+11, plikwy); cout << '\n';

    rotate(wek.begin(), wek.end()-2, wek.end());

    cout << "rotate dla przedostatniego elementu(8) ::\n";
    copy(wek.begin(), wek.end(), plikwy); cout << '\n';

    vector<int, allocator<int> > wek_wynik(wek.size());

    rotate_copy(wek.begin(), wek.begin()+wek.size()/2,
                wek.end(), wek_wynik.begin());

    cout << "rotate_copy dla środkowego elementu ::\n";
    copy(wek_wynik.begin(), wek_wynik.end(), plikwy);
    cout << '\n';
}
