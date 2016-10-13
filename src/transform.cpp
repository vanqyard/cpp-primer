#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

/*

    template< class InputIterator, class OutputIterator,
              class UnaryOperation>
    OutputIterator
    transform( InputIterator first, InputIterator last,
               OutputIterator result, UnaryOperation op );

    template< class InputIterator1, class InputIterator2,
              class OutputIterator, class BinaryOperation >
    OutputIterator
    transform( InputIterator1 first1,
               InputIterator1 last,
               InputIterator2 first2, OutputIterator result,
               BinaryOperation bop );

generuje:
  pierwotne wartości tablicy: 3 5 8 13 21
  transform -- podwojenie każdego elementu: 6 10 16 26 42
  transform -- odejmowanie każdego elementy: 3 5 8 13 21

*/

int podwojona_wrt(int wrt) { return wrt + wrt; }
int odejmowanie(int wrt1, int wrt2) {
    return abs(wrt1 - wrt2);
}

int main()
{
    int ti[] = {3, 5, 8, 13, 21};

    vector<int, allocator<int> > wek(5);
    ostream_iterator<int> plikwy(cout, " ");

    cout << "pierwotne wartości tablicy: ";
    copy(ti, ti+5, plikwy); cout << endl;

    cout << "transform -- podwojenie każdego elementu: ";
    transform(ti, ti+5, wek.begin(), podwojona_wrt);
    copy(wek.begin(), wek.end(), plikwy); cout << endl;

    cout << "transform -- odejmowanie każdego elementu: ";
    transform(ti, ti+5, wek.begin(), plikwy, odejmowanie);
    cout << endl;

}


