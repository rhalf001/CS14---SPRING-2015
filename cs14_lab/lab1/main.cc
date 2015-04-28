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

int main()
{
    Lab1List a;
    a.push('1');
    a.push('2');
    a.push('3');
    a.push('4');
    
    a.display();
    cout << endl;
    
    Lab1List b(a);
    
    b.rotate(3);
    b.display();
    cout << endl;
    
    
    
}