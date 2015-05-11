#include "lab5.h"
#include <iostream>
#include <map>

using namespace std;

int main()
{
    cout << "Test Case 1:" << endl;
    BST<int> bst2;
    
    bst2.insert(50);
    bst2.insert(20);
    bst2.insert(10);
    bst2.insert(40);
    bst2.insert(35);
    bst2.insert(45);
    bst2.insert(60);
    bst2.insert(70);
    
    cout << "Part 1:" << endl;
    bst2.minCover();
    bst2.displayMinCover();
    
    cout << "Part 2: " << endl;
    int a[1000];
    bst2.findSumPath(bst2.getRoot(), 80, a);
    
    cout << "Part 3: " << endl;
    map<int, int> m2;
    bst2.vertSum(bst2.getRoot(), 0, m2);
    cout << endl << endl;

    cout << "Test Case 2: " << endl;
    BST<int> bst1;
    
    bst1.insert(6);
    bst1.insert(2);
    bst1.insert(1);
    bst1.insert(4);
    bst1.insert(3);
    bst1.insert(5);
    bst1.insert(7);
    bst1.insert(9);
    bst1.insert(8);
    bst1.insert(-2);
    bst1.insert(-3);
    bst1.insert(-1);
    bst1.insert(12);
    bst1.insert(11);
    bst1.insert(13);
    
    cout << "Part 1: " << endl;
    bst1.minCover();
    bst1.displayMinCover();
    
    cout << "Part 2: " << endl;
    int b[1000];
    bst1.findSumPath(bst1.getRoot(), 17, b);
    
    cout << "Part 3: " << endl;
    map<int, int> m1;
    bst1.vertSum(bst1.getRoot(), 0, m1);
    cout << endl << endl;
    
    return 0;
}