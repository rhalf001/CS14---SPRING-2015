#include "lab2.h"
#include<cstdlib>
#include <iostream>
using namespace std;

int main()
{
    forward_list<int> a;
    forward_list<int> b;
    forward_list<int> c;
    c.push_front(2);
    c.push_front(1);
    a.push_front(10);
    a.push_front(15);
    a.push_front(16);
    a.push_front(1);
    b.push_front(1);
    b.push_front(16);
    b.push_front(15);
    b.push_front(10);
    a.display();
    cout << endl;
    b.display();
    cout << endl;
    c.display();
    cout << endl;
    a.listCopy(a,b);
    //a.primeCount(a);
    // c.listCopy(a,b);
    // a.printLots(a,c);
    // a.display();
}