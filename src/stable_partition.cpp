#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

/*

    template< class BidirectionalIterator, class Predicate >
    BidirectionalIterator
    stable_partition( BidirectionalIterator first,
                      BidirectionalIterator last,
                      Predicate pred);

*/
/* generuje:
	 pierwotny ciąg elementów:
	 29 23 20 22 17 15 26 51 19 12 35 40
	 stable_partition na elemencie parzystym:
	 20 22 26 12 40 29 23 17 15 51 19
	 stable_partition na elemencie mniejszym niż 25:
	 23 20 22 17 15 19 12 29 26 51 35 40
*/ 
class element_parszysty {
public:
		bool operator()(int elem) {
				return elem%2 ? false : true;
		}
};

int main()
{
		int ti[] = {29,23,20,22,17,15,26,51,19,12,35,40};

		vector<int, allocator<int> > wek(ti, ti+12);
		ostream_iterator<int> plikwy(cout, " ");

		cout << "pierwotny ciąg elementów:\n";
		copy(wek.begin(), wek.end(), plikwy); cout << '\n';

		stable_partition(&ti[0], &ti[12], element_parszysty());

		cout << "stable_partition na elemencie parzystym: \n";
		copy(ti, ti+11, plikwy); cout << '\n';

		stable_partition(wek.begin(), wek.end(),
							bind2nd(less<int>(),25));

		cout << "stable_partition na elemencie mniejszym niż 25:\n";
		copy(wek.begin(), wek.end(), plikwy); cout << '\n';
}
