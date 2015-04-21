#include "lab2.h"
#include<cstdlib>
#include <iostream>
using namespace std;

template <typename Type>
bool forward_list<Type>::isPrime(int i)
{
    if( i == 1 || i == 2)
    {
        return true;
    }
    for(int x=2;x < i; ++x)
    {
        if(i%x == 0)
        {
            return false;
        }
    }
    return true;
}


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
    a.push_front(23);
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
    cout << a.primeCount(a);
    cout << endl;
    cout << c.primeCount(c);
    cout << endl;
    //a.listCopy(a,b);
    
    
    List<int> x;
    x.push_front_list(100);
    x.push_front_list(300);
    x.push_front_list(500);
    x.push_front_list(700);
    x.push_front_list(900);
    x.display_list();
    cout << endl;
    x.elementSwap(2);
    x.display_list();
    cout << endl;
    
    
    a.printLots(a,c);
    cout << endl;
    a.listCopy(a,b);
    b.display();
    cout << endl;
}