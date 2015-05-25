//Roger Halftermeyer
//SID: 861143675
//5/11/15
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <ctime>
#include <algorithm>

using namespace std;

void setInsert(unsigned n, vector<string> v, set<string> &s)
{
    for(unsigned i = 0; i < n; i++)
    {
        s.insert(v.at(i));
    }
}

void unorderedInsert(unsigned n, vector<string> v, unordered_set<string> &s)
{
    for(unsigned i = 0; i < n; i++)
    {
        s.insert(v.at(i));
    }
}

void setFind(unsigned n, vector<string> v, set<string> s)
{
    for(unsigned i = 0; i < n; i++)
    {
        s.find(v.at(i));
    }
}

void unorderedFind(unsigned n, vector<string> v, unordered_set<string> s)
{
    for(unsigned i = 0; i < n; i++)
    {
        s.find(v.at(i));
    }
}

int main()
{
    vector<string> words;
    ifstream fin("words.txt");
    if(!fin.is_open())
    {
        cout << "words.txt did not open properly!\n";
    }
    string inputWord;
    while(fin >> inputWord)
    {
        words.push_back(inputWord);
    }
    fin.close();
    
    ofstream fout("data.txt");
        
    if(!fout.is_open())
    {
        cout << "Error opening data.txt!\n";
    }
    
    for(unsigned n = 5000; n <= 50000; n += 5000)
    {
        cout << "n = " << n << endl;
        
        float avgSetInsertTime = 0.0;
        for(unsigned i = 0; i < 10; i++)
        {
            random_shuffle(words.begin(), words.end());
            set<string> s;
            clock_t t;
            t = clock();
            setInsert(n, words, s);
            t = clock() - t;
            avgSetInsertTime += t;
        }
        avgSetInsertTime = avgSetInsertTime / 10;
        avgSetInsertTime = ((float)avgSetInsertTime)/CLOCKS_PER_SEC;
        cout << "Average set insert time: " << avgSetInsertTime << endl;
        
        float avgSetFindTime = 0.0;
        set<string> s;
        setInsert(50000, words, s);
        for(unsigned i = 0; i < 10; i++)
        {
            random_shuffle(words.begin(), words.end());
            clock_t t;
            t = clock();
            setFind(n, words, s);
            t = clock() - t;
            avgSetFindTime += t;
        }
        avgSetFindTime = avgSetFindTime / 10;
        avgSetFindTime = ((float)avgSetFindTime)/CLOCKS_PER_SEC;
        cout << "Average set find time: " << avgSetFindTime << endl;
        
        float avgUSetInsertTime = 0.0;
        for(unsigned i = 0; i < 10; i++)
        {
            random_shuffle(words.begin(), words.end());
            unordered_set<string> us;
            clock_t t;
            t = clock();
            unorderedInsert(n, words, us);
            t = clock() - t;
            avgUSetInsertTime += t;
        }
        avgUSetInsertTime = avgUSetInsertTime / 10;
        avgUSetInsertTime = ((float)avgUSetInsertTime)/CLOCKS_PER_SEC;
        cout << "Average unordered set insert time: " << avgUSetInsertTime 
            << endl;
        
        float avgUSetFindTime = 0.0;
        unordered_set<string> us;
        unorderedInsert(50000, words, us);
        for(unsigned i = 0; i < 10; i++)
        {
            random_shuffle(words.begin(), words.end());
            clock_t t;
            t = clock();
            unorderedFind(n, words, us);
            t = clock() - t;
            avgUSetFindTime += t;
        }
        avgUSetFindTime = avgUSetFindTime / 10;
        avgUSetFindTime = ((float)avgUSetFindTime)/CLOCKS_PER_SEC;
        cout << "Average unordered set find time: " << avgUSetFindTime 
            << endl << endl;
        
        fout << n << " " << avgSetInsertTime << " " 
            << avgUSetInsertTime << " " << avgSetFindTime << " " 
            << avgUSetFindTime << "\n";
    }
    
    return 0;
}