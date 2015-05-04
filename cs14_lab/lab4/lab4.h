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
		// compares the pairs in order to sort them in the vector
		for (int i = entries.size()-1; i != 0; --i )
		{
		    if (entries[i].first + entries[i].second >= entries[i-1].first
		    + entries[i-1].second) break;
			swap(entries[i], entries[i-1]); // swaps the pairs to sort them
	   }
	}
	void print_q() 
	{
		// loop to print the pairs in the vector(priority_queue)
		for (unsigned i = 0; i < entries.size(); ++i)
		{
			cout << entries[i].first << ' ' << entries[i].second << endl;
		}
	}
};
	
void inorder_(int m, int n, int k, priority_queue& q)
{
	if(m + n >= k) // base case
	{
		return;
	}
	else
	{
		Entry t(m, n);
		q.push(t); // push the pair onto the queue
		// recursively call inorder_ three times using the formulas given
	    inorder_(2 * m - n, m, k, q);
		inorder_(2 * m + n, m, k, q);
		inorder_(m + 2 * n, n, k, q);
	}
}
	
void inorder(int num) // function to print coprime pairs in inorder order
{
	priority_queue qu; // create que to pass into the inorder helper function
	inorder_(2, 1, num, qu); // call the helper function
	inorder_(3, 1, num, qu); // call the helper function
	qu.print_q(); // print the queue
}
	

void preorder_(int m, int n, int k) // preorder helper function
{
	if(m + n >= k) // base case
	{
		return;
	}
	else
	{
		cout << m << ' ' << n << endl; // print the coprime pair
		// recursively call preorder_ three times using the given formulas
		preorder_(2 * m - n, m, k);
		preorder_(2 * m + n, m, k);
		preorder_(m + 2 * n, n, k);
	}
}
	
void preorder(int num) // function to print coprime pairs in preorder traversal
{
    // call the preorder helper function(preorder_)
	preorder_(2, 1, num);
	preorder_(3, 1, num);
}
	
void postorder_(int m, int n, int k) // postorder helper function 
{
	if(m + n >= k) // base case
	{
		return;
	}
	else
	{
		// recursively call postorder_ three times
		postorder_(2 * m - n, m, k);
		postorder_(2 * m + n, m, k);
		postorder_(m + 2 * n, n, k);
		cout << m << ' ' << n << endl; // print the coprime pair
	}
}
	
void postorder(int num) //function to print coprime pairs in postorder traversal
{
	// call the postorder helper function(postorder_)
	postorder_(2, 1, num);
	postorder_(3, 1, num);
}
#endif
