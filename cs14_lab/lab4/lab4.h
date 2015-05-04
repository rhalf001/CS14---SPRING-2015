//Roger Halftermeyer
//SID: 861143675
//4/27/15

#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef __LAB4_H__
#define __LAB4_H__


void coprime(int n, int x)
{
    for( a[n+1] = a[n] + a[n-1] ; a[n+1] <= 10  ; a[n+1]+=a[n] )
    {
        if((a[n] + a[n+1]) < x)
        {
            cout<<a[n]<<","<<a[n+1]<<endl;
        }
        corpime(n + 1);
    }
}
#endif