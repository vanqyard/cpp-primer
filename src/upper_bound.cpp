#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

/*

    template< class ForwardIterator, class Type >
    ForwardIterator
    upper_bound( ForwardIterator first,
                 ForwardIterator last, const Type &value );
    template< class ForwardIterator, class Type, class Compare >
    ForwardIterator
    upper_bound( ForwardIterator first,
                 ForwardIterator last, const Type &value,
                 Compare comp );

*/
template <class Typ>
void drukuj_elementy(Typ elem) { cout << elem << " "; }

void (*wfi)( int ) = drukuj_elementy;

int main()
{
    int ti = {29,23,20,22,17,15,26,51,19,12,35,40};
    vector<int, allocator<int> > wek(ti,ti+12);

    sort(ti, ti+12);
    int *iter = upper_bound(ti,ti+12,19);
    assert(*iter == 20);

    sort(wek.begin(), wek.end(), greater<int>());
    vector<int, allocator<int> >::iterator iter_wek;

    iter_wek = upper_bound(wek.begin(), wek.end(),
                           27, greater<int>());

    assert(*iter_wek == 26);

    // generuje: 51 40 35 29 27 26 23 22 20 19 17 15 12
    wek.insert(iter_wek, 27);
    for_each(wek.begin(), wek.end(), wfi); cout << "\n\n";
}
