#include "list.h"


int main(){
    cout << "Hello World" << endl;

    Sequence<int, int> mySequence;

    //inserting node at top and bottom
    mySequence.insert_node_top(1,101);
    mySequence.insert_node_bottom(1,102);
    mySequence.insert_node_bottom(2,200);
    mySequence.insert_node_bottom(2,201);
    mySequence.insert_node_bottom(2,202);
    mySequence.insert_node_bottom(2,203);
    mySequence.insert_node_bottom(3,300);
    mySequence.insert_node_bottom(3,301);
    mySequence.insert_node_bottom(4,400);
    mySequence.insert_node_bottom(4,401);
    mySequence.insert_node_bottom(4,402);
    mySequence.insert_node_top(1,100);

    //printing the list
    mySequence.print_sequence();
    cout << "-------------------------------------------" << endl;
    cout << endl << endl;


    //inserting node at a specified position
    mySequence.insert_node_at_pos(6,600,3);
    mySequence.insert_node_at_pos(7,700,6);

    //printing the list
    mySequence.print_sequence();
    cout << "-------------------------------------------" << endl;
    cout << endl << endl;


    //counting instances of a node with same key
    int instances = mySequence.count_instances(2);
    cout << "The number of instances of the element is: " << instances << endl;
    instances = mySequence.count_instances(4);
    cout << "The number of instances of the element is: " << instances << endl;

    //get position of first instance of an element
    int position = mySequence.get_position(3);
    cout << "The position of the element is: " << position << endl;

    //get position of an element with its instance
    position = mySequence.get_position_with_instance(2,4);
    cout << "The position of the element is: " << position << endl;

    //get the instance of an element with its key and its position
    int inst = mySequence.get_instance_with_key_and_position(2,7);
    cout << endl << "Instance: " << inst << endl << endl;

    cout << "-------------------------------------------" << endl;
    cout << endl << endl;


    //inserting element after a specified element
    mySequence.insert_node_after(15,15,2,3);

    //inserting element before a specified element
    mySequence.insert_node_before(15,15,4,1);

    //printing the list
    mySequence.print_sequence();
    cout << "-------------------------------------------" << endl;
    cout << endl << endl;


    //removing elements from the list
    mySequence.remove_node(1,1);
    mySequence.remove_node(2,2);
    mySequence.remove_node(15,1);
    mySequence.remove_node(1,2);
    mySequence.remove_node(3,1);
    mySequence.remove_node(4,2);


    mySequence.print_sequence();
    cout << "-------------------------------------------" << endl;
    cout << endl << endl;

    //updates the length of the list if it is not correct
    mySequence.update_length();

    //returns the length of the list
    int len = mySequence.check_length();
    cout << "The length of the list is: "<<len << endl;

    cout << "-------------------------------------------" << endl;
    cout << endl << endl;

    //copy constructor and operator =
    cout << "-------------------" << endl;
    cout << "-------------------" << endl;
    Sequence<int, int> mySequence2 = mySequence;
    mySequence2.print_sequence();
    cout << "-------------------" << endl;
    cout << "-------------------" << endl;
    Sequence<int, int> mySequence3;
    mySequence3 = mySequence;
    mySequence3.print_sequence();
    cout << "-------------------------------------------" << endl;
    cout << endl << endl;




    //checking for split_pos and split_key external functions
    Sequence<int, int> seq;
    Sequence<int, int> seq1;
    Sequence<int, int> seq2;



    for(int n = 0; n < 25; n++){
        seq.insert_node_bottom(n,n);
    }
    seq.print_sequence();
    cout << "-------------------------------------------" << endl;
    cout << endl << endl;

    //splitting the sequence into two sequences starting from a specified position and splitting with specified length
    split_pos (seq, 10, 2, 4, 2, seq1, seq2);
    cout << "-------------------------------------------" << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl << endl;

    Sequence<int, int> Kseq;
    Sequence<int, int> seq3;
    Sequence<int, int> seq4;

    for(int n = 0; n < 5; n++){
       Kseq.insert_node_bottom(2,2);
    }

    for(int n = 0; n < 20; n++){
       Kseq.insert_node_bottom(n,n);
    }

    Kseq.print_sequence();
    cout << "-------------------------------------------" << endl;
    cout << endl << endl;
    //splitting the sequence into two sequences starting from a specified key and splitting with specified length
    split_key(Kseq, 2, 3, 4, 2, 4, seq3, seq4);
    cout << "-------------------------------------------" << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl << endl;

}

