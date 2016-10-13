#include <algorithm>
#include <list>
#include <string>
#include <iostream>
using namespace std;

/* generuje:
Pierwotny ciąg napisów:
		Signature of all things I am here to
		read seaspawn adn seawrack that rusty boot

Ciąg napisów po wykonaniu algorytmu
		boot rusty seawrack and seaspawn read to
		here am I things all of Signature
*/

class drukuj_elementy {
public:
    void operator()(string elem) {
        cout << elem << ( _lcz_wierszy++%8 ? " " : "\n\t");
    }

    static void inicjuj_lcz_wierszy() { _lcz_wierszy = 1; }

private:
    static int _lcz_wierszy;
};

int drukuj_elementy::_lcz_wierszy = 1;

int main()
{
    string ts[] = {"Signature", "of", "all", "things",
                   "I", "am", "here", "to", "read",
                   "seaspawn", "and", "seawrack", "that",
                   "rusty", "boot"
    };

    list<string, allocator<string> > listanap(ts, ts+15);

    cout << "Pierwotny ciąg napisów:\n\t";
    for_each(listanap.begin(), listanap.end(),
             drukuj_elementy());
    cout << "\n\n";

    reverse(listanap.begin(), listanap.end());

    drukuj_elementy::inicjuj_lcz_wierszy();

    cout << "Ciąg napisów po wykonaniu algorytmu reverse():\n\t";
    for_each(listanap.begin(), listanap.end(),
             drukuj_elementy()); cout << "\n";
    
    list<string, allocator<string> > listanap_copy(listanap.size());
    reverse_copy(listanap.begin(), listanap.end(),
                 listanap_copy.begin());
}
