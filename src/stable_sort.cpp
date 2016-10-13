#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

/*
template< class RandomAccessIterator >
void
stable_sort( RandomAccessIterator first,
             RandomAccessIterator last );

template< class RandomAccessIterator, class Compare >
void
stable_sort( RandomAccessIterator first,
             RandomAccessIterator last, Compare comp );

*/

int main()
{
		int ti[] = {29,23,20,22,12,17,15,26,51,19,12,23,35,40};

		vector<int, allocator<int> > wek(ti, ti+14);
		ostream_iterator<int> plikwy(cout, " ");

		cout << "pierwotny ciag elementów:\n";
		copy(wek.begin(), wek.end(), plikwy); cout << '\n';

		stable_sort(&ti[0], &ti[14]);

		cout << "stable_sort -- domyślny porządek rosnący:\n";
		copy(ti, ti+14, plikwy); cout << '\n';

		stable_sort(wek.begin(), wek.end(), greater<int>());

		cout << "stable_sort: porządek malejący:\n";
		copy(wek.begin(), wek.end(), plikwy); cout << '\n';

}
