//Roger Halftermeyer
//SID: 861143675
//4/20/15

#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef __LAB3_H__
#define __LAB3_H__

template<typename T>
class TwoStackFixed
{
    private:
        T *a;
        int size;
        int max;
        int top1;
        int top2;
    public:
        TwoStackFixed(int size, int maxtop)
        {
            a  = new T [size];
            this -> size =  size;
            max = maxtop;
            top1 = 0;
            top2 = size - 1;
        }
        
        void pushStack1(T value)
        {
            if(isFullStack1())
            {
                cout << "ERROR: stack 1 is filled.";
                cout << endl;
                return;
            }
            if(!isEmptyStack1())
            {
                for(int j = top1; j >= 1; --j)
                {
                    a[j] = a[j - 1];
                }
            }
            a[0] = value;
            ++top1;
        }
        
        void pushStack2(T value)
        {
            if(isFullStack2())
            {
                cout << "ERROR: stack 2 is filled.";
                cout << endl;
                return;
            }
            if(!isEmptyStack2())
            {
                for(int i = top2 ; i <= (size -1); ++i)
                {
                    if((i - 1) == max)
                    {}
                    else
                    {
                        a[i - 1] = a[i]; 
                    }
                }
            }
            a[size - 1] = value;
            --top2;
        }
        
        T popStack1()
        {
            if(isEmptyStack1())
            {
                cout << "ERROR: stack 1 is empty.";
                cout << endl;
                exit(1);
            }
            T x = a[0];
            for(int i = 0; i < top1; ++i)
            {
                a[i] = a[i+1]; 
            }
            a[top1 - 1] = '\0';
            top1 = top1 - 1;
            return x; 
        }
        
        T popStack2()
        {
            if(isEmptyStack2())
            {
                cout << "ERROR: stack 2 is empty.";
                cout << endl;
                exit(1);
            }
            T x = a[size - 1];
            for(int i = size - 1; i >= top2; --i)
            {
                a[i] = a[i - 1];
            }
            a[top2] = '\0';
            top2 = top2 + 1; 
            return x;
        }
        
        bool isFullStack1()
        {
            if (top1 > max )
            {
                return true;
            }
            return false;
        }
        
        bool isFullStack2()
        {
            if(top2 == max)
            {
                return true;
            }
            return false;
        }
        
        bool isEmptyStack1()
        {
            if(top1 == 0)
            {
                return true;
            }
            return false;
        }
        
        bool isEmptyStack2()
        {
            if(top2 == (size - 1))
            {
                return true;
            }
            return false;
        }
        
        void display()
        {
            for (int i = 0; i < size; ++i)
            {
                if(a[i] == 0)
                {
                    cout << " " << " ";
                }
                else
                {
                    cout << a[i] << " ";
                }
            }
        }
   
};



template<typename T>
class TwoStackOptimal
{
    private:
        T *a;
        int size;
        int top1;
        int top2;
    public:
        TwoStackOptimal(int size)
        {
            a  = new T [size];
            this -> size =  size;
            top1 = 0;
            top2 = size - 1;
        }
        
        void pushFlexStack1(T value)
        {
            if(isFullStack1())
            {
                cout << "ERROR: stack 1 is filled.";
                cout << endl;
                return;
            }
            if(!isEmptyStack1())
            {
                for(int j = top1; j >= 1; --j)
                {
                    a[j] = a[j - 1];
                }
            }
            a[0] = value;
            ++top1;
        }
        
        void pushFlexStack2(T value)
        {
            if(isFullStack2())
            {
                cout << "ERROR: stack 2 is filled.";
                cout << endl;
                return;
            }
            if(!isEmptyStack2())
            {
                for(int i = top2 ; i <= (size - 1); ++i)
                {
                    if((i - 1) == top1 - 1)
                    {}
                    else
                    {
                        a[i - 1] = a[i]; 
                    }
                }
            }
            a[size - 1] = value;
            --top2;
        }
        
        T popFlexStack1()
        {
            if(isEmptyStack1())
            {
                cout << "ERROR: stack 1 is empty.";
                cout << endl;
                exit(1);
            }
            T x = a[0];
            for(int i = 0; i < top1; ++i)
            {
                a[i] = a[i+1]; 
            }
            a[top1 - 1] = '\0';
            top1 = top1 - 1;
            return x; 
        }
        
        T popFlexStack2()
        {
            if(isEmptyStack2())
            {
                cout << "ERROR: stack 2 is empty.";
                cout << endl;
                exit(1);
            }
            T x = a[size - 1];
            for(int i = size - 1; i >= top2; --i)
            {
                a[i] = a[i - 1];
            }
            a[top2] = '\0';
            top2 = top2 + 1; 
            return x;
        }
        
        bool isFullStack1()
        {
            if (top1 > top2 )
            {
                return true;
            }
            return false;
        }
        
        bool isFullStack2()
        {
            if(top2 < top1)
            {
                return true;
            }
            return false;
        }
        
        bool isEmptyStack1()
        {
            if(top1 == 0)
            {
                return true;
            }
            return false;
        }
        
        bool isEmptyStack2()
        {
            if(top2 == (size - 1))
            {
                return true;
            }
            return false;
        }
        
        void display()
        {
            for (int i = 0; i < size; ++i)
            {
                if(a[i] == 0)
                {
                    cout << " " << " ";
                }
                else
                {
                    cout << a[i] << " ";
                }
            }
        }
   
};

#include <stack>

template<typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
    if(n == 1)
    {
        C.push(A.top());
        A.pop();
        cout << "Moved " << "1" << " from peg C to B";
        cout << endl;
        return;
    }
    else
    {
        showTowerStates(n-1, A, C, B);
        cout << "Moved " << A.top() << " from peg A to C";
        cout << endl;
        C.push(A.top());
        A.pop();
        showTowerStates(n-1, C, B, A);
        cout << "Moved " << A.top() << " from peg A to B";
        cout << endl;
    }
    return;
}

#endif