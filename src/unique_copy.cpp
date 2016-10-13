#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

/*

    template< class InputIterator, class OutputIterator >
    OutputIterator
    unique_copy( InputIterator first, InputIterator last,
                 OutputIterator result );

    template< class InputIterator, class OutputIterator,
              class BinaryPredicate >
    OutputIterator
    unique_copy( InputIterator first,   InputIterator last,
                 OutputIterator result, BinaryPredicate pred )

 */

template <class Typ>
void drukuj_elementy(Typ elem) { cout << elem << " "; }

void (*wfi)( int ) = drukuj_elementy;
void (*wfn)( string ) = drukuj_elementy;

int main()
{
    int ti[] = {0,1,0,2,0,3,0,4,0,5};

    vector<int, allocator<int> > wek(ti, ti+10);
    vector<int, allocator<int> >::iterator wek_iter;

    // nie powoduje zmiany ciągu: nie ma dwóch kolejnych zer
    // generuje: 0 1 0 2 0 3 4 0 5

    wek_iter = unique(wek.begin(), wek.end());
    for_each(wek.begin(), wek.end(), wfi);
    cout << "\n\n";

    // sortujemy wektor i wywołujemy unique: ciąg zmieniony
    // generuje: 0 1 2 3 4 5 2 3 4 5

    sort(wek.begin(), wek.end());
    wek_iter = unique(wek.begin(), wek.end());
    for_each(wek.begin(), wek.end(), wfi);
    cout << "\n\n";

    // usuwamy niepotrzebne elementy kolekcji
    // generuje: 0 1 2 3 4 5
    wek.erase(wek_iter, wek.end());
    for_each(wek.begin(), wek.end(), wfi);
    cout << "\n\n";

    string ts[] = { "enough", "is", "enough",
                    "enough", "is", "good" };

    vector<string, allocator<string> > weknap(ts, ts+6);
    vector<string, allocator<string> > wek_wynik(weknap.size());
    vector<string, allocator<string> >::iterator weknap_iter;

    sort(weknap.begin(), weknap.end());

    weknap_iter = unique_copy(weknap.begin(), weknap.end(),
                              wek_wynik.begin());

    // generuje: enough good is
    for_each(wek_wynik.begin(), weknap_iter, wfn);
    cout << "\n\n";
}
