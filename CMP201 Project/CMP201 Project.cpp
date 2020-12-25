#include <iostream>
#include <list>

using namespace std;

bool in_pattern[256];
int skip[256];

/// <summary>
/// Populates in_pattern array, used to quickly determine if any given character is in the pattern
/// </summary>
/// <param name="pattern">Pointer to the string representing the pattern to search for</param>
void getPattern(string* pattern) {
    for (int i = 0; i < 256; ++i) 
    {
        in_pattern[i] = false; //Default to not in pattern
    }
    for (size_t i = 0; i < pattern->length(); i++)
    {
        in_pattern[int(pattern->c_str()[i])] = true; //Set value at index equal to current char code in pattern to true (to know that char shows up in the pattern)
    }
}

/// <summary>
/// Gets the number of places that can be skipped for each occurance of a letter in the pattern
/// </summary>
/// <param name="pattern">The text being searched for</param>
void getSkip(string* pattern) {
    for (int i = 0; i < 256; ++i) 
    {
        skip[i] = pattern->length(); // Not in the pattern, skip to end
    }
    for (int i = 0; i < pattern->length(); ++i) 
    {
        skip[int(pattern->c_str()[i])] = (pattern->length() - 1) - i; //Sets how many characters the algorithm is allowed to skip
    }
}

/// <summary>
/// Implements the Boyer-Moore Search algorithm for use with std::strings, returns a list of ints represnting the start index of each occurance of the needle
/// </summary>
/// <param name="haystack">The text to be searched</param>
/// <param name="needle">The text being searched for within the haystack</param>
/// <returns></returns>
list<int> bmSearch(string* haystack, string* needle) {
    getPattern(needle);
    getSkip(needle);
    //Uhhhhh I think this is what you need to do to do this?
    //Finish it
    //Unless it's not what you're meant to do, in which case leave it and do that instead
}

int main()
{
    string text = "This is a test, this is also a test whoah";
    string pattern = "test";
    bmSearch(&text, &pattern);
    skip;
    return 0;
}