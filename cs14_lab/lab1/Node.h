// Roger Halftermeyer
// 861143675
// 4/10/15
// I tried to do as much as possible. I looked at what was needed for other 
// steps and worked from there. I posted on piazza for help but was still 
// confused but managed to do most of the lab.
// My main focus was on the smaller parts so that the bigger operations would
// be easier to work with.
#include <iostream>

using namespace std;

struct Node
{
    char data;
    Node *next;
    Node (char data) : data(data), next(0) {}
};
