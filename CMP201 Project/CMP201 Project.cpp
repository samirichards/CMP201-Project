#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

//TODO: REMOVE THIS ONCE YOU KNOW YOU DON'T NEED IT
bool in_pattern[256];
int skip[256];

/// <summary>
/// Populates in_pattern array, used to quickly determine if any given character is in the pattern
/// TODO: REMOVE THIS ONCE YOU KNOW YOU DON'T NEED IT
/// </summary>
/// <param name="pattern">: Pointer to the string representing the pattern to search for</param>
void getPattern(string* pattern) {
    for (int i = 0; i < 256; ++i) 
    {
        in_pattern[i] = false; //Default to not in pattern
    }
    for (size_t i = 0; i < pattern->length(); i++)
    {
        in_pattern[int(pattern->data()[i])] = true; //Set value at index equal to current char code in pattern to true (to know that char shows up in the pattern)
    }
}

/// <summary>
/// Gets the number of places that can be skipped for each occurance of a letter in the pattern
/// </summary>
/// <param name="pattern">: The text being searched for</param>
void getSkip(string* pattern) {
    for (size_t i = 0; i < 256; ++i) 
    {
        skip[i] = pattern->length(); // Not in the pattern, skip to end
    }
    for (size_t i = 0; i < pattern->length(); ++i) 
    {
        skip[int(pattern->data()[i])] = (pattern->length() - 1) - i; //Sets how many characters the algorithm is allowed to skip
    }
}

/// <summary>
/// Implements the Boyer-Moore Search algorithm for use with std::strings, returns a list of ints represnting the start index of each occurance of the needle
/// </summary>
/// <param name="haystack">The text to be searched</param>
/// <param name="needle">The text being searched for within the haystack</param>
/// <returns></returns>
list<int> bmSearch(string* haystack, string* needle) {
    list<int> indexes;
    getSkip(needle);
    getPattern(needle);
    auto needle_length = needle->length();
    auto haystack_length = haystack->length();

    for (size_t i = 0; i < haystack_length - needle_length + 1; i++)
    {
        int s = skip[int(haystack->data()[i + needle_length - 1])];
        if (s != 0) {
            i += s - 1; // Skip forwards.
            continue;
        }
        for (size_t j = 0; j < needle_length; j++)
        {
            if (tolower(haystack->data()[i + j]) != tolower(needle->data()[j]) || toupper(haystack->data()[i + j]) != toupper(needle->data()[j]))
            {
                break;
            }
            else
            {
                indexes.push_back(i);
                j = needle_length;
            }
        }
    }
    return indexes;
}

size_t hashString(string input) {
    hash<string> hasher;
    return hasher(input);
}

/// <summary>
/// Implements the Rabin-Karp Search Algorithm for use with std::strings, returns a list of ints represnting the start index of each occurance of the needle
/// </summary>
/// <param name="haystack">The text to be searched</param>
/// <param name="needle">The text being searched for within the haystack</param>
/// <returns></returns>
list<int> rkSearch(string* haystack, string* needle) {
    list<int> indexes;
    auto needle_length = needle->length();
    auto haystack_length = haystack->length();




    return indexes;
}

int main()
{
    //Implement the next algorithm now
    string text = "This is a test, this is also a test whoah";
    string pattern = "is";
    cout << "---Boyer-Moore---\n";
    cout << "Text to Search: " << text << endl;
    cout << "Pattern Searcing for: " << pattern << endl;
    auto bmIndexList = bmSearch(&text, &pattern);
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
    cout << "---Rabin-Karp---\n";
    cout << "Text to Search: " << text << endl;
    cout << "Pattern Searcing for: " << pattern << endl;
    auto rkIndexList = rkSearch(&text, &pattern);
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