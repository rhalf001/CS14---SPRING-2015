//Roger Halftermeyer
//SID: 861143675
//4/20/15

#include "lab3.h"
#include <stack>
#include <iostream>

using namespace std;

int main()
{
    //Test for TwoStackFixed
    
    TwoStackFixed<int> a(6,3);
    a.pushStack1(3);
    a.pushStack1(4);
    a.pushStack1(5);
    a.pushStack1(6);
    a.pushStack2(5);
    a.pushStack2(6);
    a.pushStack1(7);
    a.pushStack2(6);
    a.display();
    cout << endl;
    cout << a.popStack1();
    cout << endl;
    a.display();
    cout << endl;
    cout << a.popStack2();
    cout << endl;
    a.display();
    cout << endl;
    
    
    //Test for TwoStackOptimal
    
    TwoStackOptimal<int> b(5);
    b.pushFlexStack1(3);
    b.display();
    cout << endl;
    b.pushFlexStack2(4);
    b.display();
    cout << endl;
    b.pushFlexStack1(2);
    b.display();
    cout << endl;
    b.pushFlexStack1(1);
    b.display();
    cout << endl;
    b.pushFlexStack2(5);
    b.display();
    cout << endl;
    b.pushFlexStack2(5);
    b.pushFlexStack1(3);
    cout << b.popFlexStack1();
    cout << endl;
    b.display();
    cout << endl;
    cout << b.popFlexStack1();
    cout << endl;
    b.display();
    cout << endl;
    cout << b.popFlexStack2();
    cout << endl;
    b.display();
    cout << endl;
    
    
    // Testing tower of Hanoi
    stack<int> A;
    A.push(1);
    A.push(2);
    A.push(3);
    cout << A.size();
    cout << endl;
    int n = A.size();
    stack<int> B;
    stack<int> C;
    showTowerStates(n,A,B,C);
    
    
    
    return 0;
}