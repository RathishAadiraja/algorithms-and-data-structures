#include <iostream>

using namespace std;

template <typename Key, typename Info>
class Sequence{
    typedef struct Node{
        Key key;
        Info data;
        Node *next;
    }Node;
    Node *head;
    int length;


public:

    Sequence();
    ~Sequence();
    void insert_node_top(const Key &my_key, const Info &my_info);
    bool insert_node_bottom(const Key &my_key, const Info &my_info);
    bool insert_node_at_pos(const Key &my_key, const Info &my_info, const int & pos);
    int count_instances(const Key &my_key)const;
    int get_position(const Key &my_key) const;
    int get_position_with_instance(const Key &my_key, const int &instance)const;
    Node* get_element(const Key &my_key, const int &instance) const;
    Node* get_element_with_pos(const int &position)const;
    Key get_key_at_pos(const int &position)const;
    Info get_data_from_key(const Key &my_key, const int &instance) const;
    int get_instance_with_key_and_position(const Key &my_key, const int &position) const;
    bool insert_node_after(const Key &my_key, const Info &my_info, const Key &after_key, const int &instance);
    bool insert_node_before(const Key &my_key, const Info &my_info, const Key &before_key, const int &instance);
    bool remove_node(const Key &remove_key, const int &instance);
    int check_length() const;
    int update_length();
    bool empty_list();
    bool is_list_empty() const;
    void print_sequence();


    const Sequence<Key, Info> & operator=(const Sequence<Key, Info> &rhs);
    Sequence(const Sequence<Key, Info> & seq);
    bool operator==(const Sequence<Key, Info> & seq) const;
    bool operator!=(const Sequence<Key, Info> & seq) const;



};

template <typename Key, typename Info> Sequence<Key, Info>::Sequence(){
    head = nullptr;
    length = 0;
}

template <typename Key, typename Info> Sequence<Key, Info>::~Sequence(){
    empty_list();
}

template <typename Key, typename Info> bool Sequence<Key, Info>::empty_list(){
    Node* current = head;
    Node* current_next;

    while (current != NULL) {
        current_next = current->next;
        delete current;
        current = current_next;
    }

    length = 0;
    if(head == nullptr){
        return true;
    }else{
        return false;
    }


}

template <typename Key, typename Info> bool Sequence<Key, Info>::is_list_empty() const{
    return (head == nullptr);
}

template <typename Key, typename Info> int Sequence<Key, Info>::check_length() const{
    return length;
}

template <typename Key, typename Info> int Sequence<Key, Info>::update_length(){
    int count_list = 0;

    Node *temp_node = head;
    while(temp_node != nullptr){
        count_list++;
        temp_node = temp_node->next;
    }

    if(length == count_list){
        return length;
    }else{
        length = count_list;
        return length;
    }

}

template <typename Key, typename Info> void Sequence<Key, Info>::insert_node_top(const Key &my_key, const Info &my_info){
    Node *new_node = new Node();
    new_node->key = my_key;
    new_node->data = my_info;
    new_node->next = head;
    head = new_node;
    length++;

}

template <typename Key, typename Info> bool Sequence<Key, Info>::insert_node_bottom(const Key &my_key, const Info &my_info){

    Node *new_node = new Node();
    new_node->key = my_key;
    new_node->data = my_info;
    new_node->next = nullptr;

    if(head == nullptr){
        head = new_node;
        length++;
        return true;
    }
    else{
        Node *temp = head;
        while(temp->next != nullptr){
           temp = temp->next;
        }

        temp->next = new_node;
        length++;

        return true;

    }

    cout << "Error the element in not added to the bottom of the list!!!" << endl;
    return false;


}


template <typename Key, typename Info> bool Sequence<Key, Info>::insert_node_at_pos(const Key &my_key, const Info &my_info, const int & pos){


    if(head == nullptr || pos == 1){
        insert_node_top(my_key, my_info);
        cout << "The element inserted at the top" << endl;
        return true;
    }else if(pos == length+1){
        insert_node_bottom(my_key, my_info);
        cout << "The element inserted at the bottom" << endl;
        return true;
    }else if(pos <= 0){
        cout << "Invalid position!!!" << endl;
        cout << "Position must be greater than 0" << endl;
        return false;
    }else{
        Node *current = head;
        Node *previous = head;
        Node *new_node = new Node();
        new_node->key = my_key;
        new_node->data = my_info;
        new_node->next = nullptr;
        if(pos <= length){
            for(int i=1; i<pos; i++){
                if (i == 1){
                    current = current->next;
                }else{
                    previous = previous->next;
                    current = current->next;
                }
            }
            previous->next = new_node;
            new_node->next = current;
            length++;

            return true;
        }
    }

    cout << "Error, the element with key '" << my_key << "' and info '" << my_info<<  "' is not added to the list!!!" << endl;
    cout << "Please check the entered position, the length of the list is: "<< length << endl;
    return false;


}


template <typename Key, typename Info>  int Sequence<Key, Info>::count_instances(const Key &my_key) const{
    Node *temp = head;
    int temp_instance = 0;

    while(temp != nullptr){
        if(temp->key == my_key ){
            temp_instance++;
        }

        temp = temp->next;
    }


    return temp_instance;

}

template <typename Key, typename Info>  int Sequence<Key, Info>::get_position(const Key &my_key) const{
    Node *temp = head;
    int position = 0;

    while(temp != nullptr){
        position++;
        if(temp->key == my_key ){
            //cout << "The element is at position: "<< position << endl;
            return position;
        }else{
            temp = temp->next;
        }
    }

    //cout << "The element is not in the list"<< endl;
    return -1;


}

template <typename Key, typename Info>  int Sequence<Key, Info>::get_position_with_instance(const Key &my_key, const int &instance)const{

    if(instance <= 0){
        cout << "The instance cannot be less than or equal to zero" << endl;
        return -1;
    }else if(instance == 1){
        return get_position(my_key);
    }else{
        int count_ins = count_instances(my_key);
        if(count_ins == 0){
            return -1;
        }else if(count_ins < instance){
            return -1;
        }else{

            Node *temp = head;
            int temp_instance = 0;
            int i = 0;
            int position = 0;

            while(temp != nullptr){
                i++;
                if(temp->key == my_key){
                    temp_instance++;
                    position = i;

                    if(temp_instance == instance){
                        return position;
                    }
                }

                temp = temp->next;
            }

            return -1;
        }

        return -1;
    }

}



template <typename Key, typename Info>  typename Sequence<Key, Info>::Node* Sequence<Key, Info>::get_element(const Key &my_key, const int &instance) const{

    int position = get_position_with_instance(my_key, instance);
    return get_element_with_pos(position);

}


template <typename Key, typename Info>  Key Sequence<Key, Info>::get_key_at_pos(const int &position) const{


    Node *temp_node = get_element_with_pos(position);
    if(temp_node != nullptr){
        return temp_node->key;
    }else{
        return 0;
    }



}


template <typename Key, typename Info>  Info Sequence<Key, Info>::get_data_from_key(const Key &my_key, const int &instance) const{


    Node *temp_node = get_element(my_key, instance);
    if(temp_node != nullptr){
        return temp_node->data;
    }else{
        return 0;
    }



}

template <typename Key, typename Info>  typename Sequence<Key, Info>::Node* Sequence<Key, Info>::get_element_with_pos(const int &position) const{

    if(position <= 0){
        cout << "Position cannot be less than or equal to zero" << endl;
        return nullptr;
    }else if(position > length){
        cout << "position cannot be greater then the list length" << endl;
        cout << "Length of the list is: " << length << endl;
    }else{

        Node *temp = head;
        int i = 0;

        while(temp != nullptr){
            i++;
            if(i == position){
                //cout << temp->key << "  " << temp->data << endl;
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    return nullptr;
}


template <typename Key, typename Info>  int Sequence<Key, Info>::get_instance_with_key_and_position(const Key &my_key, const int &position) const{


    Node *temp_node = head;
    int key_instance = 0;
    int iter = 0;
    while(temp_node != nullptr){
        iter ++;
        if(temp_node->key == my_key){
            key_instance++;

            if(iter == position){
                return key_instance;
            }
        }

        temp_node = temp_node->next;

    }

    return -1;



}



template <typename Key, typename Info> bool Sequence<Key, Info>::insert_node_after(const Key &my_key, const Info &my_info, const Key &after_key, const int &instance){

    int after_key_position = get_position_with_instance(after_key, instance);

    if(after_key_position <= 0){
        return false;
    }else{
        insert_node_at_pos(my_key, my_info, after_key_position+1);
        return true;
    }


/*
    Node *new_node = new Node();
    new_node->key = my_key;
    new_node->data = my_info;
    new_node->next = nullptr;

    Node *after_element = get_element(after_key, instance);
    if(after_element != nullptr){
        Node *after_element_next = after_element->next;
        after_element->next = new_node;
        new_node->next = after_element_next;

        return true;
    }else{
        return false;
    }
*/


}


template <typename Key, typename Info> bool Sequence<Key, Info>::insert_node_before(const Key &my_key, const Info &my_info, const Key &before_key, const int &instance){

    int before_key_position = get_position_with_instance(before_key, instance);

    if(before_key_position <= 0){
        return false;
    }else{
        insert_node_at_pos(my_key, my_info, before_key_position);
        return true;
    }

}

template <typename Key, typename Info> bool Sequence<Key, Info>::remove_node(const Key &remove_key, const int &instance){

    int remove_key_position = get_position_with_instance(remove_key, instance);

    if(remove_key_position <=0 ){
        return false;
    }else{
        Node *temp_node = head;
        Node *prev_node = head;

        if(remove_key_position == 1){
            head = temp_node->next;
            temp_node->next = nullptr;
            delete temp_node;
            length--;

            return true;
        }else{
            temp_node = get_element_with_pos(remove_key_position);
            prev_node = get_element_with_pos(remove_key_position-1);
            if(remove_key_position == length){
                prev_node->next = nullptr;
                delete temp_node;
                length--;

                return true;
            }else{
                prev_node->next = temp_node->next;
                temp_node->next = nullptr;
                delete temp_node;
                length--;

                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

//template <typename T> const Sequence<T> & Sequence<T>::operator=(const Sequence<T> & rhs)

template <typename Key, typename Info> const Sequence<Key, Info> &Sequence<Key, Info>::operator=(const Sequence<Key, Info> &rhs){

    if (this == &rhs){
        return *this;
    }

    empty_list();


    if (rhs.is_list_empty()){
       return *this;
    }

    Node *temp = rhs.head;

    while (temp != NULL){
     insert_node_bottom(temp->key, temp->data);
     temp = temp->next;
    }

    return *this;
}

template <typename Key, typename Info> bool Sequence<Key, Info>::operator==(const Sequence<Key, Info> & seq) const
{
    if (this->is_list_empty() && seq.is_list_empty()){
        return true;
    }

    if (this->length != seq.length){
        return false;
    }

    Node *temp1 = this->head;
    Node *temp2 = seq.head;

    do {
        if (temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    } while ((temp1 == nullptr) || (temp2 == nullptr));

    return true;
}

template <typename Key, typename Info> bool Sequence<Key, Info>::operator!=(const Sequence<Key, Info> & s) const{
    return *this != s;
}





template <typename Key, typename Info> Sequence<Key, Info>::Sequence(const Sequence<Key, Info> & seq){

    head = nullptr;
    *this = seq;
}


template <typename Key, typename Info>  void Sequence<Key, Info>::print_sequence(){
    Node *temp = head;
    while(temp != nullptr){

        cout << temp->key << endl;
        temp = temp->next;
    }

    cout << "End of list" << endl;

}




template<typename Key, typename Info> void split_pos (const Sequence<Key, Info>& seq, int start_pos, int len1, int len2, int count, Sequence<Key, Info>& seq1, Sequence<Key, Info>& seq2){

    Sequence<Key, Info> split1;
    Sequence<Key, Info> split2;
    int iter = start_pos;
    for(int repeat=0; repeat<count; repeat++){
        for(int i=0; i<len1; i++){
            iter++;
            if(iter <= seq.check_length()){
                split1.insert_node_bottom(seq.get_key_at_pos(iter), seq.get_data_from_key(seq.get_key_at_pos(iter),seq.get_instance_with_key_and_position(seq.get_key_at_pos(iter),iter)));
            }
        }
        for(int j=0; j<len2; j++){
            iter++;
            if(iter <= seq.check_length()){
                split2.insert_node_bottom(seq.get_key_at_pos(iter), seq.get_data_from_key(seq.get_key_at_pos(iter),seq.get_instance_with_key_and_position(seq.get_key_at_pos(iter),iter)));
            }
        }
    }


    cout << "\n\nSplit sequence 1\n";

    split1.print_sequence();
    cout << endl;
    cout << "\n\nSplit sequence 2\n";

    split2.print_sequence();
    cout << endl;

}




template<typename Key, typename Info> void split_key (const Sequence <Key, Info>& seq, const Key &start_key, int start_occ, int len1, int len2, int count, Sequence <Key, Info>& seq1, Sequence <Key, Info>& seq2){
    Sequence<Key, Info> split1;
    Sequence<Key, Info> split2;
    int iter = seq.get_position_with_instance(start_key, start_occ)-1;
    for(int repeat=0; repeat<count; repeat++){
        for(int i=0; i<len1; i++){
            iter++;
            if(iter <= seq.check_length()){
                split1.insert_node_bottom(seq.get_key_at_pos(iter), seq.get_data_from_key(seq.get_key_at_pos(iter),seq.get_instance_with_key_and_position(seq.get_key_at_pos(iter),iter)));
            }
        }
        for(int j=0; j<len2; j++){
            iter++;
            if(iter <= seq.check_length()){
                split2.insert_node_bottom(seq.get_key_at_pos(iter), seq.get_data_from_key(seq.get_key_at_pos(iter),seq.get_instance_with_key_and_position(seq.get_key_at_pos(iter),iter)));
            }
        }
    }


    cout << "\n\nSplit sequence 1\n";

    split1.print_sequence();
    cout << endl;
    cout << "\n\nSplit sequence 2\n";

    split2.print_sequence();
    cout << endl;

}


