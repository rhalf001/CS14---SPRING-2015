//Roger Halftermeyer
//SID: 861143675
//4/27/15

#include <iostream>
#include <vector>
#include <algorithm>
	
using namespace std;

#ifndef __LAB4_H__
#define __LAB4_H__

typedef pair<int,int> Entry;
class priority_queue 
{
	public:
	vector<Entry> entries;
	Entry& front() { return entries.back(); }
	void pop() { entries.pop_back(); }
	void push(Entry e) 
	{ 
		entries.push_back( e );
		for (int i = entries.size()-1; i != 0; --i )
		{
		    if (entries[i].first + entries[i].second >= entries[i-1].first
		    + entries[i-1].second) break;
			swap(entries[i], entries[i-1]); 
	   }
	}
	void print_q() 
	{
		for (unsigned i = 0; i < entries.size(); ++i)
		{
			cout << entries[i].first << ' ' << entries[i].second << endl;
		}
	}
};
	
void inorder_(int m, int n, int k, priority_queue& q)
{
	if(m + n >= k)
	{
		return;
	}
	else
	{
		Entry t(m, n);
		q.push(t);
	    inorder_(2 * m - n, m, k, q);
		inorder_(2 * m + n, m, k, q);
		inorder_(m + 2 * n, n, k, q);
	}
}
	
void inorder(int num)
{
	priority_queue qu; 
	inorder_(2, 1, num, qu); 
	inorder_(3, 1, num, qu); 
	qu.print_q(); 
}
	

void preorder_(int m, int n, int k) 
{
	if(m + n >= k) 
	{
		return;
	}
	else
	{
		cout << m << ' ' << n << endl;
		preorder_(2 * m - n, m, k);
		preorder_(2 * m + n, m, k);
		preorder_(m + 2 * n, n, k);
	}
}
	
void preorder(int num) 
{
    
	preorder_(2, 1, num);
	preorder_(3, 1, num);
}
	
void postorder_(int m, int n, int k) 
{
	if(m + n >= k) 
	{
		return;
	}
	else
	{
		postorder_(2 * m - n, m, k);
		postorder_(2 * m + n, m, k);
		postorder_(m + 2 * n, n, k);
		cout << m << ' ' << n << endl;
	}
}
	
void postorder(int num) 
{
	postorder_(2, 1, num);
	postorder_(3, 1, num);
}
#endif
