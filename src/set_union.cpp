#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

/*
    template < class InputIterator1, class InputIterator2,
               class OutputIterator >
    OutputIterator
    set_union(
        InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2,
        OutputIterator result );

    template < class InputIterator1, class InputIterator2,
               class OutputIterator, class Compare >
    OutputIterator
    set_union(
        InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2,
        OutputIterator result, Compare comp );
*/
/* generuje:
elementy zbioru #1:
		Kłapouchy Prosiaczek Puchatek Tygrysek

elementy zbioru #2:
		Kangurzyca Puchatek Maleństwo

elementy wyniku set_union():
		Kłapouchy Kangurzyca Prosiaczek Puchatek Tygrysek Maleństwo

elementy wyniku set_intersection():
		Puchatek

elementy wyniku set_difference():
		Kłapouchy Prosiaczek Tygrysek

elementy wyniku symmetric_difference():
		Kłapouchy Kangurzyca Prosiaczek Tygrysek Maleństwo
*/

int main()
{
		string napis1[] = {"Puchatek", "Prosiaczek", "Tygrysek", "Kłapouchy"};
		string napis2[] = {"Puchatek", "Kangurzyca", "Maleństwo"};
		ostream_iterator<string> plikwy(cout, " ");

		set<string,less<string>,allocator<string> > zbior1(napis1, napis1+4);
		set<string,less<string>,allocator<string> > zbior2(napis2, napis2+3);

		cout << "elementy zbioru #1:\n\t";
		copy(zbior1.begin(), zbior1.end(), plikwy); cout << "\n\n";

		cout << "elementy zbioru #2:\n\t";
		copy(zbior2.begin(), zbior2.end(), plikwy); cout << "\n\n";

		set<string,less<string>,allocator<string> > wynik;
		set_union(zbior1.begin(), zbior1.end(),
							zbior2.begin(), zbior2.end(),
							inserter(wynik, wynik.begin()));

		cout << "elementy wyniku set_union():\n\t";
		copy(wynik.begin(), wynik.end(), plikwy); cout << "\n\n";

		wynik.clear();
		set_intersection(zbior1.begin(), zbior1.end(),
										 zbior2.begin(), zbior2.end(),
										 inserter(wynik, wynik.begin()));

		cout << "elementy wyniku set_itersection():\n\t";
		copy(wynik.begin(), wynik.end(), plikwy); cout << "\n\n";

		wynik.clear();
		set_difference(zbior1.begin(), zbior1.end(),
									 zbior2.begin(), zbior2.end(),
									 inserter(wynik, wynik.begin()));

		cout << "elementy wyniku set_difference():\n\t";
		copy(wynik.begin(), wynik.end(), plikwy); cout << "\n\n";

		wynik.clear();
		set_symmetric_difference(zbior1.begin(), zbior1.end(),
														 zbior2.begin(), zbior2.end(),
														 inserter(wynik, wynik.begin()));

		cout << "elementy wyniku set_symmetric_difference():\n\t";
		copy(wynik.begin(), wynik.end(), plikwy); cout << "\n\n";

}
