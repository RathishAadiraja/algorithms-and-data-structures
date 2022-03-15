#include<iostream>
#include<cstring>


using namespace std;

template<typename Key,typename Info>
class Dictionary
{
   struct Node
   {
       Key key;
       Info info;
       Node* left;
       Node* right;
       int height;

       Node(){}
       Node(const Key& p_key,const Info& p_info,Node* p_left,Node* p_right,int p_height)
       {
           key = p_key;
           info = p_info;
           left = p_left;
           right = p_right;
           height = p_height;

       }

   };

   Node* root;


int height(Node* my_node)
{
    if(my_node == nullptr)
    {
        return 0;
    }
    return my_node->height;
}

int get_balance_factor(Node* my_node)
{
    if(my_node==nullptr)
    {
        return 0;
    }
    return height(my_node->left)-height(my_node->right);
}

int compare(int a,int b)
{
    return(a > b) ? a : b;

}

Node* new_node(const Key& key,const Info& info)
{
    Node* node = new Node();
    node->key = key;
    node->info = info;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;

}

Node* right_rotate(Node* my_node)
{
    Node *current = my_node->left;
    Node *temp = current->right;

    current->right = my_node;
    my_node->left = temp;
    my_node->height = compare(height(my_node->left),height(my_node->right)) +1;
    current->height = compare(height(current->left),height(current->right)) +1;

    return current;
}

Node* left_rotate(Node* my_node)
{
    Node *current = my_node->right;
    Node *temp = current->left;

    current->left = my_node;
    my_node->right = temp;
    my_node->height = compare(height(my_node->left),height(my_node->right)) +1;
    current->height = compare(height(current->left),height(current->right)) +1;

    return current;
}

Node* doubleLeftRotate(Node* t)
{
    t->right = right_rotate(t->right);
    return left_rotate(t);
}

Node* doubleRightRotate(Node* t)
{
    t->left = left_rotate(t->left);
    return right_rotate(t);
}

Node* node_with_min_value(Node* my_node)
{
    Node *current = my_node;
    while (current->left != NULL)
    {
        current = current->left;
    }

        return current;
}

Node* node_with_max_value(Node* my_node)
{
    Node *current = my_node;
    while (current->right != NULL)
    {
        current = current->right;
    }
        cout << current->key << endl;
        return current;
}

Node* insert_element(const Key& key,const Info& info,Node* my_node)
{
    if (my_node == NULL)
    {
        return (new_node(key,info));
    }

    if (key < my_node->key)
    {
        my_node->left = insert_element(key,info,my_node->left);
    }

    else if (key > my_node->key)
    {
        my_node->right = insert_element(key,info,my_node->right);
    }

    else
       return my_node;

    my_node->height = 1 + compare(height(my_node->left),height(my_node->right));

    int balanceFactor = get_balance_factor(my_node);

    if (balanceFactor > 1)
    {
        if (key < my_node->left->key)
        {
            return right_rotate(my_node);
        }
        else if (key > my_node->left->key)
        {
            return doubleRightRotate(my_node);
        }

    }

    if (balanceFactor < -1)
    {
        if (key > my_node->right->key)
        {
            return left_rotate(my_node);
        }
        else if (key < my_node->right->key)
        {
            return doubleLeftRotate(my_node);
        }
    }

        return my_node;
}

Node* remove_element(Node* t,const Key& key)
{
    Node* temp;

    if(t == NULL)
        return NULL;

    else if(key< t->key)
        t->left = remove_element(t->left,key);
    else if(key> t->key)
        t->right = remove_element(t->right,key);


    else if(t->left && t->right)
    {
        temp = node_with_min_value(t->right);
        t->key= temp->key;
        t->info = temp->info;
        t->right = remove_element(t->right,t->key);
    }

    else
    {
        temp = t;
        if(t->left == NULL)
            t = t->right;
        else if(t->right == NULL)
            t = t->left;
        delete temp;
    }
    if(t == NULL)
        return t;

    t->height = compare(height(t->left), height(t->right))+1;

    if(height(t->left) - height(t->right) == 2)
    {

        if(height(t->left->left) - height(t->left->right) == 1)
            return left_rotate(t);

        else
            return doubleLeftRotate(t);
    }

    else if(height(t->right) - height(t->left) == 2)
    {

        if(height(t->right->right) - height(t->right->left) == 1)
            return right_rotate(t);

        else
            return doubleRightRotate(t);
    }

    return t;

}

Node* copy_Node(Node* my_node)
{
    if(my_node!=nullptr)
    {
        Node* left = copy_Node(my_node->left);
        Node* right = copy_Node(my_node->right);

        return new Node(my_node->key,my_node->info,left,right,my_node->height);
    }
    else
    {
        return nullptr;
    }
}

Node* make_empty(Node* my_node)
{
    if(my_node!=nullptr)
    {
        make_empty(my_node->left);
        make_empty(my_node->right);
        delete my_node;
        my_node = nullptr;
        return my_node;
    }

}


void print_tree(Node* my_node,string indent,bool last)
{
    if (my_node != nullptr)
    {
        cout << indent;
        if (last)
        {
            cout << "R----";
            indent += "   ";
        }
        else
        {
            cout << "L----";
            indent += "|  ";
        }
     cout << my_node->key /*<< " || " << my_node->info */<< endl;
     print_tree(my_node->left, indent, false);
     print_tree(my_node->right, indent, true);
    }
}


Node* find_element(Node* root,const Key&p_key)
{
    if(root!=nullptr)
    {
        if(root->key == p_key)
        {

           cout << "Key: "<<root->key << "  Info: " << root->info <<endl;
           return root;

        }
        find_element(root->left,p_key);
        find_element(root->right,p_key);
    }

}

void update_info(Node* my_node,const Key& key,const Info& new_info)
{
    if(my_node!=nullptr)
    {
        if(my_node->key == key)
        {
            my_node->info = new_info;
        }
        update_info(my_node->left,key,new_info);
        update_info(my_node->right,key,new_info);
    }

}

void display(Node* my_node,int level)
{
    int i;
    if (my_node!=NULL)
    {
        display(my_node->right, level + 1);
        cout<<"\n";
        if (my_node == root)
        cout<<"Root -> ";
        for (i = 0; i < level && my_node != root; i++)
            cout<<"       ";
        cout<<my_node->key;
        display(my_node->left, level + 1);
    }

}

void display_key_and_info(Node* my_node,int level)
{
    int i;
    if (my_node!=NULL)
    {
        display_key_and_info(my_node->right, level + 1);
        cout<<"\n";
        if (my_node == root)
        cout<<"Root -> ";
        for (i = 0; i < level && my_node != root; i++)
            cout<<"       ";
        cout<<my_node->key<<"["<<my_node->info<<"]";
        display_key_and_info(my_node->left, level + 1);
    }

}

Info get_info(Node* my_node,const Key& key)
{
    if(my_node!=nullptr)
    {
        if(my_node->key == key)
        {
            cout << "Info of given key: " << my_node->key << " is: " << my_node->info << endl;
            return my_node->info;
        }
        get_info(my_node->left,key);
        get_info(my_node->right,key);
    }

}




public:

Dictionary()
{
    root = NULL;
}
~Dictionary()
{
    make_empty(root);
}

void insert_Element(const Key& key,const Info& info)
{
    root = insert_element(key,info,root);
}

void remove_Element(const Key& key)
{
    root = remove_element(root,key);
}

void print(string indent,bool last)
{
    print_tree(root,indent,last);
}

void update_Info(const Key& key,const Info& new_info)
{
    update_info(root,key,new_info);
}

void find_Element(const Key& key)
{
    find_element(root,key);

}

Dictionary(const Dictionary& rhs)
{
    root = copy_Node(rhs.root);
}

Dictionary& operator=(const Dictionary& my_dictionary)
{
    if(this == &my_dictionary)
    {
        return *this;
    }

        *this->make_empty(root);
        root = copy_Node(my_dictionary.root);
        return *this;
}

void display_tree()
{
    int level = 1 ;
    display(root,level);
}

void display()
{
    int level = 1 ;
    display_key_and_info(root,level);
}

Info get_Info(const Key& key)
{
    get_info(root,key);
}


};


