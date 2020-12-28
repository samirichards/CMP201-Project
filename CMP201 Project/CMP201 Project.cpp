#include <iostream>
#include <list>
#include <unordered_map>
#include "StringSearching.h"

using namespace std;

int main() 
{
    list<int> bmIndexList;
    string text = "test";
    string pattern = "t";
    cout << "---Boyer-Moore---\n";
    cout << "Text to Search: " << text << endl;
    cout << "Pattern Searcing for: " << pattern << endl;
    bmSearch(&text, &pattern, &bmIndexList);
    if (bmIndexList.size() > 0)
    {
        cout << "Found pattern at the following indexes: ";
        for (auto item : bmIndexList)
        {
            cout << item << " ";
        }
        cout << endl << endl;
    }
    else
    {
        cout << "No items found\n";
    }

    list<int> rkIndexList;

    cout << "---Rabin-Karp---\n";
    cout << "Text to Search: " << text << endl;
    cout << "Pattern Searcing for: " << pattern << endl;
    rkSearch(&text, &pattern, &rkIndexList);
    if (rkIndexList.size() > 0)
    {
        cout << "Found pattern at the following indexes: ";
        for (auto item : rkIndexList)
        {
            cout << item << " ";
        }
        cout << endl << endl;
    }
    else
    {
        cout << "No items found\n";
    }
    return 0;
}