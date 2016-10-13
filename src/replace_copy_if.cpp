#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

/*
	pierwotny ciąg elementów:
	0 1 1 2 3 5 8 13 21 34
	ciąg po wykonaniu replace_if dla < 10 i wartości 0:
	0 0 0 0 0 0 0 13 21 34
	ciąg po wykonaniu repace_if dla parzystych i wartości 0:
	0 1 1 0 3 5 0 13 21 0
*/

class WartoscParzysta {
public:
    bool operator()(int wartosc) {
        return wartosc % 2 ? false : true; 
    }
};

int main()
{
    int nowa_wartosc = 0;
    
    int ti[] = {0,1,1,2,3,5,8,13,21,34};
    vector<int, allocator<int> > wek(ti, ti+10);
    ostream_iterator<int> plikwy(cout, " ");
    cout << "pierwotny ciag elementow:\n";
    copy(ti, ti+10, plikwy); cout << '\n';
    
    replace_if(&ti[0], &ti[10],
               bind2nd(less<int>(),10), nowa_wartosc);
    
    cout << "ciag po wykonaniu replace_if dla < 10 i wartosci 0:\n";

    copy(ti, ti+10, plikwy); cout << '\n';
    
    replace_if(wek.begin(), wek.end(),
               WartoscParzysta(), nowa_wartosc);

    cout << "ciag po wykonaniu replace_if "
         << "dla przaystych i wartosci 0:\n";
    copy(wek.begin(), wek.end(), plikwy); cout << '\n';

}
