#include <iostream>
#include <cstdlib>

using namespace std;

template <typename Type>
struct Node
{
    Type data;
    Node<Type> *next;
    Node<Type>( Type data ) : data(data), next(0) {}
};

#ifndef __LAB2_H__
#define __LAB2_H__

template <typename Type>
class forward_list
{
    private:
        Node<Type> *head;
        Node<Type> *tail;
    public:
        forward_list()
         :head(NULL),tail(NULL)
        {}
        
        int primeCheck(Node<Type>* x)
        {
            if(x -> next == 0)
            {
                if(isPrime(x -> data))
                {
                    return + 1;
                }
            }
            else if(isPrime(x -> data))
            {
                return primeCheck(x -> next) + 1;
            }
            else if (isPrime(x -> data) == false)
            {
                return primeCheck(x -> next) + 0;
            }
            return 0;
        }
        
        int primeCount(forward_list<int> lst )
        {
            return primeCheck(lst.head);
        }
        
        bool isPrime(int i);
        
        void listCopy(forward_list<Type> L, forward_list<Type> &P)
        {
            Node<Type>* temp1 = L.head;
            Node<Type>* temp2 = P.head;
            cpyfunc(temp1,temp2);
        }
        
        void cpyfunc(Node<Type>* a, Node<Type>* b)
        {
            if(a == 0 || b == 0) return;
            cpyfunc(a->next, b->next);
            b -> data = a-> data;
        }
        
        void printLots (forward_list<Type> L, forward_list <int> P)
        {
            Node<int> *temp = P.head;   
            
            int cnt = 0;
            for (Node<int> *i = L.head; i != 0; i = i-> next)
            {
                if (temp->data == cnt)
                {
                    cout << i->data << " ";
                    if(temp-> next != 0)
                    {
                        temp = temp->next;
                    }
                }
                ++cnt;
            }
            return;
        }
        
        void display() const 
        {
            for (Node<Type> *x = head; x != 0; x = x->next) 
            {
                if (x->next != 0) 
                {
                    
                    cout << x->data << ' ';
                }
                else {
                    cout << x->data;
                }
            }
            
        }
        
        void push_front(Type value) 
        {
            Node<Type>* temp = new Node<Type>(value);
            temp->next = head;
            head = temp;
            if (tail == 0) 
            {
                tail = head;
            }
        }
};

template <typename Type>
class List
{
    private:
        Node<Type> *head;
        Node<Type> *tail;
    public:
        List()
         :head(NULL),tail(NULL)
        {}
        void elementSwap(int pos)
        {
            if(head->next == 0)
            {
                exit(1);
            }
            int cnt = 0;
            Node<Type> *temp1;
            Node<Type> *temp2;
            Node<Type> *temp3;
            for (Node<Type> *i = head; i != 0; i = i->next)
            {
                if (cnt == pos - 1)
                {
                    temp1 = i;
                }
                
                else if (cnt == pos)
                {
                    temp2 = i;
                }
                
                else if (cnt == pos + 1)
                {
                    temp3 = i;
                }
                ++cnt;
            }
            temp1->next = temp3;
            temp2->next = temp3->next;
            temp3->next = temp2;
            return;
        }
        
        void display_list() const 
        {
            for (Node<Type> *a = head; a != 0; a = a->next) 
            {
                if (a->next != 0) 
                {
                    cout << a->data << ' ';
                }
                else {
                    cout << a->data;
                }
            }
        }
        void push_front_list(Type value) 
        {
            Node<Type>* temp = new Node<Type>(value);
            temp->next = head;
            head = temp;
            if (tail == 0) 
            {
                tail = head;
            }
        }
        
};

#endif

