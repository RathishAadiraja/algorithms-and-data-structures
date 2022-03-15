#include <iostream>
#include <sstream>

using namespace std;

template<typename Key, typename Info>
class Ring {

    struct Node {
        Key key;
        Info info;
        Node *next;
        Node *prev;

        Node() {};

        Node(Key key1, Info info1, Node *node, Node *prevNode) {
            key = key1;
            info = info1;
            next = node;
            prev = prevNode;

        };
    } *any;

public:
    class Iterator {
    private:
        Node *targetNode;

    public:
        friend class Ring;

        Iterator()
        {
            targetNode = NULL;
        }

        Iterator(const Iterator &copy)
        {
            targetNode = copy.targetNode;
        }

        Iterator(Node *copy)
        {
            targetNode = copy;
        }

        const Key &getKey()
        {
            return targetNode->key;
        }

        const Info &getInfo()
        {
            return targetNode->info;
        }

        bool operator!=(const Iterator &compare) const
        {
            return targetNode != compare.targetNode;
        }

        bool operator==(const Iterator &compare) const
        {
            return targetNode == compare.targetNode;
        }

        Iterator &operator+(const int add)
        {
            if (targetNode == NULL)
            {
                return *this;
            }

            Iterator *tempIterator = new Iterator(*this);
            for (int i = 0; i < add; i++)
            {
                tempIterator->targetNode = tempIterator->targetNode->next;
            }
            return *tempIterator;
        }

        Iterator &operator-(const int substract)
        {
            if (targetNode == NULL)
            {
                return *this;
            }

            Iterator *tempIterator = new Iterator(*this);
            for (int i = 0; i < substract; i++)
            {
                tempIterator->targetNode = tempIterator->targetNode->prev;
            }
            return *tempIterator;
        }

        Iterator &operator++()
        {
            if (targetNode != NULL)
            {
                   targetNode = targetNode->next;
            }
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator tempIterator(*this);
            if (targetNode != NULL)
            {
                targetNode = targetNode->next;
            }
            return tempIterator;
        }

        Iterator &operator--()
        {
            if (targetNode != NULL)
            {
                targetNode = targetNode->prev;
            }
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator tempIterator(*this);
            if (targetNode != NULL)
            {
                targetNode = targetNode->prev;
            }
            return tempIterator;
        }

        Iterator &operator=(const Iterator &equal)
        {
            targetNode = equal.targetNode;
            return *this;
        }

        Iterator &operator+=(const int add)
        {
            for (int i = 0; i < add; i++)
            {
                targetNode = targetNode->next;
            }
            return *this;
        }

        Iterator operator-=(const int substract)
        {
            for (int i = 0; i < substract; i++)
            {
                targetNode = targetNode->prev;
            }
            return *this;
        }

        Iterator &add(const Key &key, const Info &info)
        {
            if (targetNode == NULL)
            {
                return *this;
            }

            Node *newNode = new Node(key, info, targetNode->next, targetNode);
            targetNode->next->prev = newNode;
            targetNode->next = newNode;
            return *(new Iterator(newNode));
        }

        Iterator &removeCurrent()
        {
            if (targetNode == NULL)
            {
                return *this;
            }
            else if (targetNode->next == targetNode && targetNode->prev == targetNode)
            {
                return *this;
            }

            Node *deleteNode = targetNode;
            Node *tempNode = deleteNode->prev;
            tempNode->next = deleteNode->next;
            tempNode = deleteNode->next;
            tempNode->prev = deleteNode->prev;


            targetNode = targetNode->next;
            delete deleteNode;
            return *this;
        }
    };

    typedef Iterator iterator;

    Ring(){
        any = new Node();
        any->next = any;
        any->prev = any;
    };

    Ring(const Ring<Key, Info> &copyRing)
    {
        any = new Node();
        any->next = any;
        any->prev = any;

        Ring<Key, Info>::iterator copyIterator = copyRing.beginning();
        Ring<Key, Info>::iterator iterator = any;

        while (copyIterator != copyRing.end())
        {
            iterator.add(copyIterator.getKey(), copyIterator.getInfo());
            copyIterator++;
        }
    };

    ~Ring()
    {
        deleteAll();
    };

    Ring<Key, Info> &operator=(const Ring<Key, Info> &Ring)
    {
        deleteAll();
        ::Ring<Key, Info>::iterator copyIterator = Ring.beginning();

        while (copyIterator != Ring.end())
        {
            pushBack(copyIterator.getKey(), copyIterator.getInfo());
            copyIterator++;
        }
        return *this;
    };

    Ring<Key, Info> &operator+(const Ring <Key, Info> &ring)
    {
        ::Ring<Key, Info> *newRing = new ::Ring<Key, Info>(*this);
        ::Ring<Key, Info>::iterator copyIterator = ring.beginning();

        while (copyIterator != ring.end())
        {
            (*newRing).pushBack(copyIterator.getKey(), copyIterator.getInfo());
            copyIterator++;
        }

        return *newRing;
    };

    int length() const
    {
        int counter = 0;
        ::Ring<Key, Info>::Iterator countIterator = beginning();
        while (countIterator != end())
        {
            counter++;
            countIterator++;
        }
        return counter;
    }

    Iterator beginning() const
    {
        return ++(iterator(any));
    };

    Iterator end() const
    {
        return iterator(any);
    };

    Iterator pushFront(const Key &key, const Info &info)
    {
        Iterator tempIterator = beginning();
        tempIterator--;
        return tempIterator.add(key, info);
    };

    Iterator pushBack(const Key &key, const Info &info)
    {
        Iterator tempIterator = end();
        tempIterator--;
        return tempIterator.add(key, info);
    };


    void deleteAll()
    {
        Iterator tempIterator = beginning();

        while (tempIterator != end())
        {
            tempIterator.removeCurrent();
        }
    };

    Iterator search_element(const Key& key)
    {
        Iterator tempIterator(NULL);
        if(!any)
        {
             cout << "Search_element(): Cannot find anything in empty Ring" << endl;
            return tempIterator;
        }
         int pos = 1 ;
        tempIterator = beginning();
        do
        {
            if(tempIterator.getKey() == key)
            {

                cout << "the element with key " <<"'"<< tempIterator.getKey() <<"'"<< " is at pos: " << pos << endl;
                return tempIterator;
            }
            pos++;
            tempIterator++;
        }while(tempIterator!=beginning());

        tempIterator = beginning();
        pos = 1;
        cout << "Element not Found" << endl;
        return tempIterator;
    }

    friend ostream &operator<<(ostream &os, const Ring <Key, Info> &Ring) {
        stringstream strStream;
        iterator tempIterator = Ring.beginning();
        if (tempIterator == Ring.end())
        {
            strStream << "The ring is empty";
        }

        while (tempIterator != Ring.end())
        {
            strStream << tempIterator.getInfo() << " ";
            tempIterator++;
        }

        return os << strStream.str();
    };
};




template<typename Key, typename Info>
Ring<Key, Info>
split(const Ring<Key, Info> &source,bool direction,const Ring<Key, Info> &result1,int sequence1,int rep1,const Ring<Key, Info> &result2,int sequence2,int rep2)
{

    Ring<int, string>::iterator iterator9 = source.beginning() ;
    Ring<int, string>::iterator iterator10 = source.end() ;

    if (direction)
    {

        Ring<Key, Info> resultRing1;
        Ring<Key, Info> resultRing2;

        int temp_rep;
        if(rep1>rep2)
        {
            temp_rep = rep1;
        }
        else if(rep2>rep1)
        {
            temp_rep = rep2;
        }


        for(int k=0;k<temp_rep;k++)
        {
            if(rep1>0)
            {
                for(int i=0;i<sequence1;i++)
                {
                   resultRing1.pushBack(iterator9.getKey(),iterator9.getInfo());
                   iterator9++;
                }
                rep1--;
            }
            if(rep2>0)
            {
                for(int j=0;j<sequence2;j++)
               {
                  resultRing2.pushBack(iterator9.getKey(),iterator9.getInfo());
                  iterator9++;
               }
                rep2--;
            }
        }

        cout << resultRing1;
        cout << endl;

        cout << resultRing2;
        cout << endl;

    }

    else
    {

        Ring<Key, Info> resultRing1;
        Ring<Key, Info> resultRing2;

        int temp_rep;
        if(rep1>rep2)
        {
            temp_rep = rep1;
        }
        else if(rep2>rep1)
        {
            temp_rep = rep2;
        }


        for(int k=0;k<temp_rep;k++)
        {
            if(rep1>0)
            {
                for(int i=0;i<sequence1;i++)
                {
                     resultRing1.pushBack(iterator10.getKey(),iterator10.getInfo());
                     iterator10--;
                }
                rep1--;
            }

            if(rep2>0)
            {
                for(int j=0;j<sequence2;j++)
                {
                    resultRing2.pushBack(iterator10.getKey(),iterator10.getInfo());
                    iterator10--;
                }
                rep2--;
            }
        }

        cout << resultRing1;
        cout << endl;

        cout << resultRing2;
        cout << endl;

    }


}
