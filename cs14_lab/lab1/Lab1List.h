// Roger Halftermeyer
// 861143675
// 4/10/15
// I tried to do as much as possible. I looked at what was needed for other 
// steps and worked from there. I posted on piazza for help but was still 
// confused but managed to do most of the lab.
// My main focus was on the smaller parts so that the bigger operations would
// be easier to work with.
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef __LAB1LIST_H__
#define __LAB1LIST_H__

class Lab1List
{
    private:
        Node *head;
        Node *tail;
    public:
        Lab1List();
        Lab1List(const string& str);
        Lab1List(const Lab1List &cpy);
        ~Lab1List();
        void rotate(int k);
        void display() const;
        void push(char value);
        Lab1List& operator+(Lab1List& a);
};
#endif