//Roger Halftermeyer
//SID: 861143675
//5/11/15
#include <iostream>
#include <utility>
#include <list>
#include <map>
#include <vector>
	
using namespace std;

template<typename T>
bool operator<(T& lhs, T&rhs)
{
    return lhs.first < rhs.first;
}

template<typename L>
void selectionsort(L &l)
{
    auto first = l.begin();
	auto it = l.begin();
	auto min = l.begin();
	int copies = 0;
	int moves = 0;
	    
	while(first != l.end())
	{
	    ++it;
	        
	    if(*it < *min && it != l.end())
	    {
	        min = it;
	    }
	    if(it == l.end())
	    {
	    if(min != first && *min != *first)
	    {
	        swap(*min, *first);
	        moves += 3;
	    }
	    ++first;
	    it = first;
	    min = first;
	    }
	    
	}
	cout << "copies: " << copies << " moves: " << moves << endl;
}
