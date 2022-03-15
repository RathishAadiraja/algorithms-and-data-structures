#include<iostream>
#include"tree.h"

using namespace std;

int main()
{

    Dictionary<int,string> myDIctionary;
    myDIctionary.insert_Element(1,"one");
    myDIctionary.insert_Element(2,"two");
    myDIctionary.insert_Element(3,"three");
    myDIctionary.insert_Element(4,"four");
    myDIctionary.insert_Element(5,"five");
    myDIctionary.insert_Element(6,"six");
    myDIctionary.insert_Element(7,"seven");
    myDIctionary.insert_Element(9,"nine");
    myDIctionary.insert_Element(10,"ten");
    myDIctionary.insert_Element(11,"eleven");





    //myDIctionary.print("",true);

    cout << endl << endl;

    myDIctionary.display_tree();

    cout << endl << endl;

    myDIctionary.display();
    cout << endl << endl;

    myDIctionary.remove_Element(7);
    cout << endl << endl;

    myDIctionary.display_tree();

    cout << endl << endl;
    cout << endl << endl;

    myDIctionary.find_Element(6);

    myDIctionary.update_Info(6,"SIX");
    cout << endl << endl;
    myDIctionary.find_Element(6);
    cout << endl << endl;
    myDIctionary.get_Info(4);


 // ASSIGNMENT OPERATOR AND COPY CONSTRUCTOR
    Dictionary<int,string> myDIctionary2;
    myDIctionary2 = myDIctionary;

    cout << endl << endl;

    //myDIctionary2.print("",true);
    myDIctionary2.display_tree();

    cout << endl << endl;

    Dictionary<int,string> myDIctionary3 = myDIctionary;

    //myDIctionary3.print("",true);
    myDIctionary3.display_tree();


}
