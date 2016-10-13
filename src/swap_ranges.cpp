#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

/*
        template <class ForwardIterator1,
                  class ForwardIterator2 >
        ForwardIterator2
        swap_range( ForwardIterator1 first1,
                    ForwardIterator1 last,
                    ForwardIterator2 first2);

generuje:
piewotny ciąg elementów pierwszej kolekcji:
0 1 2 3 4 5 6 7 8 9
piewotny ciąg elementów drugiej kolekcji:
5 6 7 8 9
tablica po wykonaniu swap_ranges() dla jej środka:
5 6 7 8 9 0 1 2 3 4
pierwsza kolekcja po wykonaniu swap_ranges() dwóch wektorów:
5 6 7 8 9 5 6 7 8 9
druga kolekcja po wykonaniu swap_ranges() dwóch wektorów:
0 1 2 3 4

*/

int main()
{
    int ti[]  = {0,1,2,3,4,5,6,7,8,9};
    int ti2[] = {5,6,7,8,9};

    vector<int, allocator<int> > wek(ti, ti+10);
    vector<int, allocator<int> > wek2(ti2, ti2+5);

    ostream_iterator<int> plikwy(cout, " ");

    cout << "pierwotny ciąg elementów pierwszej kolekcji:\n";
    copy(wek.begin(), wek.end(), plikwy); cout << '\n';

    cout << "pierwotny ciąg elementów drugiej kolekcji:\n";
    copy(wek2.begin(), wek2.end(), plikwy); cout << '\n';

    // zamiana wewnątrz samego ciągu
    swap_ranges(&ti[0], &ti[5], &ti[5]);

    cout << "talica po wykonaniu swap_ranges() dla jej środka:\n";
    copy(ti, ti+10, plikwy); cout << '\n';

    // zamiana między kolekcjami
    vector<int, allocator<int> >::iterator last =
        find(wek.begin(), wek.end(), 5);

    swap_ranges(wek.begin(), last, wek2.begin());

    cout << "pierwsza kolekcja po wykonaniu swap_ranges() "
         << "dwóch wektorów:\n";
    copy(wek.begin(), wek.end(), plikwy); cout << '\n';

    cout << "druga kolekcja po wykonaniu swap_ranges() "
         << "dwóch wektorów:\n";
    copy(wek2.begin(), wek2.end(), plikwy); cout << '\n';

}

