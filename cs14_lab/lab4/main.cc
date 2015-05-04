//Roger Halftermeyer
//SID: 861143675
//4/27/15

#include "lab4.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Invalid number of arguments." << endl;
        exit(-1);
    }
    int k = atoi(argv[1]);
    
    cout << "Pre-order: " << endl;
	preorder(k);
	cout << endl;
	
	cout << "Post-order: " << endl;
	postorder(k);
	cout << endl;
	
	cout << "In-order: " << endl;
	inorder(k);
	cout << endl;
	
}