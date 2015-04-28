// Roger Halftermeyer
// 861143675
// 4/10/15
// I tried to do as much as possible. I looked at what was needed for other 
// steps and worked from there. I posted on piazza for help but was still 
// confused but managed to do most of the lab.
// My main focus was on the smaller parts so that the bigger operations would
// be easier to work with.
#include "Lab1List.h"
#include <iostream>
#include <string>

using namespace std;

Lab1List::Lab1List() 
:head(NULL), tail (NULL) 
{}

Lab1List::Lab1List(const string& str)
: head(NULL) ,tail(NULL)
{
    for (int i = 0; i < str.size(); ++i)
        {
            push(str.at(i));
        }
}

Lab1List::~Lab1List() {
    Node *temp;
    while (head) 
    {
        temp = head;
        head = head->next;
        delete temp;
    }
            
}
Lab1List::Lab1List(const Lab1List &cpy)
 :head(NULL), tail(NULL)
{
    for(Node *current = cpy.head; current != 0; current = current -> next)
    {
        push(current->data);
    }
}


void Lab1List::rotate(int k)
{
    if(k == 0)
    {
        return;
    }
    int x = 1;
    Node *prev;
    Node *temp;
    for (Node *current = head; current != 0; current = current->next)
    {
        if(x == k -1)
        {
            prev = current;
        }
                
        else if (x == k)
        {
            temp = current;
        }
        ++x;
    }
    if (k > x)
    {
        return;
    }
    tail -> next = head;
    head = temp;
    tail = prev;
    tail -> next = NULL;
}
        
void Lab1List::display() const 
{
    for (Node *current = head; current != 0; current = current->next) 
    {
        cout << current->data << " ";
    }
}
        
        
void Lab1List::push(char value) 
{
    if (head == 0) 
    {
        head = new Node(value);
        tail = head;
    }
    else 
    {
        tail->next = new Node(value);
        tail = tail->next;
    }
}
        
Lab1List& Lab1List::operator+(Lab1List& head2)
{
    char a;
    char b;
    char c;
    Lab1List* sum;
    Node* list1 = this-> head;
    Node* list2 = head2.head;
    while (list1->next != this -> tail || list2->next != head2.tail) 
    {
        b = list1 -> data;
        c = list2 -> data;
        a = b + c;
        sum -> push(a);
        list1 = list1->next;
        list2 = list2->next;
    }
    
    return *sum;
}