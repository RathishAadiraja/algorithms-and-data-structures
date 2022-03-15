#include <iostream>
#include <sstream>
#include "ring.h"

using namespace std;

int main() {

    Ring<int, string> ring7;
    ring7.pushBack(7,"A");
    ring7.pushBack(8,"B");
    ring7.pushBack(9,"C");
    ring7.pushBack(10,"D");
    ring7.pushBack(11,"E");
    ring7.pushBack(12,"G");
    ring7.pushBack(13,"H");
    ring7.pushBack(14,"I");
    ring7.pushBack(15,"J");
    ring7.pushBack(16,"K");
    ring7.pushBack(17,"L");
    ring7.pushBack(18,"M");

    cout << ring7 ;

    cout << endl << endl;

    ring7.search_element(11);

    cout << endl << endl;

    Ring<int, string> ring9;
    ring9.pushBack(19,"AA");
    ring9.pushBack(20,"BB");
    ring9.pushBack(21,"CC");
    ring9.pushBack(22,"DD");
    ring9.pushBack(23,"EE");
    ring9.pushBack(24,"FF");
    ring9.pushBack(25,"GG");
    ring9.pushBack(26,"HH");
    ring9.pushBack(27,"II");
    ring9.pushBack(28,"JJ");
    ring9.pushBack(29,"KK");
    cout << ring9 ;

    cout << endl << endl;
    cout << endl;
    cout << endl << endl;

    cout << "ring 9 " << endl;
    cout << ring9;

    cout << endl << endl;

    cout << "split function " << endl;

    Ring<int, string> ring11;
    Ring<int, string> ring12;

    Ring<int, string> ring10 = split(ring9,false,ring11,2,3,ring12,3,3);


    cout << endl;
    Ring<int, string> ring2 = ring7;
    cout << ring7;

    cout << endl;

    cout << "Ring 2 length is: " << ring2.length() << endl;

    cout << endl;

    //ring1.deleteAll();

    //cout << ring1 << endl;

    cout << endl;

    Ring<int, string>::iterator iterator = ring2.beginning();

    iterator = iterator.add(5, "Z");

    cout << ring2 << endl;

    iterator++;
    iterator.add(6, "M");
    iterator -= 4;
    iterator.add(1, "T");

    cout << ring2 << endl << endl;

    Ring<int, string> ring3(ring2);
    Ring<int, string> ring4;
    Ring<int, string> *ring5 = new Ring<int, string>(ring2);

    cout << "Ring5: " << *ring5 << endl << endl;

    delete ring5;
    cout << "Ring5: " << *ring5 << endl << endl;

    iterator++;
    iterator.removeCurrent();
    iterator += 19;
    iterator.removeCurrent();

    cout << "Ring2: " << ring2 << endl << endl;
    cout << "Ring3: " << ring3 << endl << endl;

    return 0;
}
