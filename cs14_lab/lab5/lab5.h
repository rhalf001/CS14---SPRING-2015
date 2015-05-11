#ifndef LAB5_H
#define LAB5_H

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <vector>
#include <iterator>

using namespace std;

#define nil 0

// #define Value int // restore for testing.
template < typename Value >
class BST 
{
  class Node 
  {
    // binary tree node
    public:
      Node* left;
      Node* right;
      Value value;
      bool selected;
      
      Node( const Value v = Value() )
        : left(nil), right(nil), value(v), selected(false)
      {}
      
      Value& content()
      {
        return value; 
      }
      
      bool isInternal()
      {
        return left != nil && right != nil; 
      }
      
      bool isExternal() 
      {
        return left != nil || right != nil; 
      }
      
      bool isLeaf() 
      {
        return left == nil && right == nil; 
      }
      
      int height() 
      {
        // returns the height of the subtree rooted at this node
        // FILL IN
        if(this == 0)
        {
          return 0;
        }
        
        return heightHelper(0, this);
      }
      
      int heightHelper(int i, Node* n)
      {
        int l = i;
        int r = i;
        
        if(n->left != nil)
        {
          l++;
          l = heightHelper(l, n->left);
        }
        if(n->right != nil)
        {
          r++;
          r = heightHelper(r, n->right);
        }
        
        if(l > r)
        {
          return l;
        }
        return r;
      }
      
      int size() 
      {
        // returns the size of the subtree rooted at this node,
        // FILL IN
        return sizeHelper(this);
      }
      
      int sizeHelper(Node* n)
      {
        int i = 0;
        
        if(n == nil)
        {
          return i;
        }
        
        i++;
        
        if(n->left != nil)
        {
          i += sizeHelper(n->left);
        }
        if(n->right != nil)
        {
          i += sizeHelper(n->right);
        }
        
        return i;
      }
  }; // Node
  
  // const Node* nil; // later nil will point to a sentinel node.
  Node* root;
  int count;
  
  public:
    // //FOR TESTING
    Node* getRoot()
    {
      return root;
    }
    
    int size() 
    {
      // size of the overall tree.
      // FILL IN
      return root->size();
    }
  
    bool empty()
    {
      return size() == 0;
    }
    
    void print_node( const Node* n ) 
    {
      // Print the node’s value.
      // FILL IN
      assert(n != 0);
      
      cout << n->value;
    }
  
    bool search ( Value x ) 
    {
      // search for a Value in the BST and return true iff it was found.
      // FILL IN
      assert(root != 0);
      
      return searchHelper(x, root);
    }
    
    bool searchHelper(Value x, Node* n)
    {
      if(n->value == x)
      {
        return true;
      }
      
      bool l = false;
      bool r = false;
      
      if(n->left != nil)
      {
        l = searchHelper(x, n->left);
      }
      if(n->right != nil)
      {
        r = searchHelper(x, n->right);
      }
      
      if(r || l)
      {
        return true;
      }
      
      return false;
    }
    
    void preorder()const 
    {
      // Traverse and print the tree one Value per line in preorder.
      // FILL IN
      assert(root != 0);
      
      preorderHelper(root);
    }
    
    void preorderHelper(Node* n) const
    {
      cout << n->value << endl;
      
      if(n->left != nil)
      {
        preorderHelper(n->left);
      }
      if(n->right != nil)
      {
        preorderHelper(n->right);
      }
    }
    
    void postorder()const 
    {
      // Traverse and print the tree one Value per line in postorder.
      // FILL IN
      assert(root != 0);
      
      postorderHelper(root);
    }
    
    void postorderHelper(Node* n) const
    {
      if(n->left != nil)
      {
        postorderHelper(n->left);
      }
      
      if(n->right != nil)
      {
        postorderHelper(n->right);
      }
      
      cout << n->value << endl;
    }
    
    void inorder()const 
    {
      // Traverse and print the tree one Value per line in inorder.
      // FILL IN
      assert(root != 0);
      
      inorderHelper(root);
    }
    
    void inorderHelper(Node* n) const
    {
      if(n->left != nil)
      {
        inorderHelper(n->left);
      }
      
      cout << n->value << endl;
      
      if(n->right != nil)
      {
        inorderHelper(n->right);
      }
    }
    
    Value& operator[] (int n) 
    {
      // returns reference to the value field of the n-th Node.
      // FILL IN

      assert(n < size() && n > -1);
    
      vector<Node*> v;
      
      opatHelper(root, v);
      
      return (v.at(n))->value;
    }
    
    void opatHelper(Node* n, vector<Node*> &v)
    {
      if(n->left != nil)
      {
        opatHelper(n->left, v);
      }
      
      v.push_back(n);
      
      if(n->right != nil)
      {
        opatHelper(n->right, v);
      }
    }
  
    BST() 
      : root(nil), count(0)
    {}
    
    void insert( Value X ) 
    {
      root = insert( X, root ); 
    }
  
    Node* insert( Value X, Node* T ) 
    {
      // The normal binary-tree insertion procedure ...
      if ( T == nil ) 
      {
        T = new Node( X ); // the only place that T gets updated.
      } 
      else if ( X < T->value ) 
      {
        T->left = insert( X, T->left );
      } 
      else if ( X > T->value ) 
      {
        T->right = insert( X, T->right );
      } 
      else 
      {
        T->value = X;
      }
      // later, rebalancing code will be installed here
      
      return T;
    }
  
    void remove( Value X )
    {
      root = remove( X, root ); 
    }
  
    Node* remove( Value X, Node*& T ) 
    {
      // The normal binary-tree removal procedure ...
      // Weiss’s code is faster but way more intricate.
      if ( T != nil ) 
      {
        if ( X > T->value ) 
        {
          T->right = remove( X, T->right );
        }
        else if ( X < T->value ) 
        {
          T->left = remove( X, T->left );
        } 
        else 
        { 
          // X == T->value
          if ( T->right != nil ) 
          {
            Node* x = T->right;
            while ( x->left != nil ) x = x->left;
            T->value = x->value; // successor’s value
            T->right = remove( T->value, T->right );
          } 
          else if ( T->left != nil ) 
          {
            Node* x = T->left;
            while ( x->right != nil ) x = x->right;
            T->value = x->value; // predecessor’s value
            T->left = remove( T->value, T->left );
          }
          else
          { 
            // *T is external
            delete T;
            T = nil; // the only updating of T
          }
        }
      }
      // later, rebalancing code will be installed here
      return T;
    }
  
    void okay( ) 
    { 
      okay( root ); 
    }
    
    void okay( Node* T ) 
    {
      // diagnostic code can be installed here
      return;
    }
    
    void minCover()
    {
        minCoverHelper(root, 0);
    }
    
    void minCoverHelper(Node* n, int i)
    {
      if(n != root && (n->left != nil) 
        && (n->left->left == nil || n->left->right == nil))
      {
        n->selected = true;
        i = 0;
      }
      else if(n != root && (n->right != nil) 
        && (n->right->right == nil || n->right->right == nil))
      {
        n->selected = true;
        i = 0;
      }
      else if(n != root && i == 1)
      {
        n->selected = true;
        i = 0;
      }
      else
      {
        i = 1;
      }
      
      if(n->left != nil)
      {
        minCoverHelper(n->left, i);
      }
      
      if(n->right != nil)
      {
        minCoverHelper(n->right, i);
      }
    }
    
    void displayMinCover()
    {
        count = 0;
        
        displayMinCoverHelper(root);
        
        cout << endl << count << endl;
        
        count = 0;
    }
    
    void displayMinCoverHelper(Node* n)
    {
      if(n->left != nil)
      {
        displayMinCoverHelper(n->left);
      }
      
      if(n->selected)
      {
        cout << n->value <<  ' ';
        count++;
      }
      
      if(n->right != nil)
      {
        displayMinCoverHelper(n->right);
      }
    }
    
    void vertSum(Node* node, int hd, map<int, int>& m)
    {
      vertSumHelper(node, hd, m);
      
      for(map<int,int>::iterator it = m.begin(); it != m.end(); it++)
      {
        cout << it->second << ' ';
      }
    }
    
    void vertSumHelper(Node* node, int hd, map<int,int>& m)
    {
      if(node->left != nil)
      {
        int tempL = hd - 1;
        vertSumHelper(node->left, tempL, m);
      }
      
      m[hd] += node->value;
      
      if(node->right != nil)
      {
        int tempR = hd + 1;
        vertSumHelper(node->right, tempR, m);
      }
    }
    
    void findSumPath(Node* n, int sum, int buffer[])
    {
      count = 0;
      
      bool check = false;
      
      findSumPathHelper(n, buffer, sum, 0, check);
      
      if(!check)
      {
        cout << '0' << endl;
      }
      
      count = 0;
    }
    
    void findSumPathHelper(Node* n, int* a, int sum, int len, bool& check)
    {
      if(n == 0)
      {
        return;
      }
      
      a[len] = n->value;
      len++;
      
      if (n->left == nil && n->right == nil) 
      {
        printPath(a, len, sum, check);
      }
      
      findSumPathHelper(n->left, a, sum, len, check);
      findSumPathHelper(n->right, a, sum, len, check);
    }
    
    void printPath(int* a, int len, int sum, bool& check)
    {
      int pSum = 0;
      for(int i = 0; i < len; i++)
      {
        pSum += a[i];
      }
      if(pSum == sum)
      {
        check = true;
        for(int i = len - 1; i > -1; i--)
        {
          cout << a[i] << ' ';
        }
        cout << endl;
      }
    }
}; // BST

#endif