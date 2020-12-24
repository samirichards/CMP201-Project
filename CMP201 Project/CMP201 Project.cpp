#include <iostream>

using namespace std;

bool in_pattern[256];
int skip[256];

void getPattern(string* pattern) {
    for (int i = 0; i < 256; ++i)
        in_pattern[i] = false;
    for (size_t i = 0; i < pattern->length(); i++)
    {
        in_pattern[int(pattern->c_str()[i])] = true;
    }
}

/// <summary>
/// Gets the number of places that can be skipped for each occurance of a letter in the pattern
/// </summary>
/// <param name="pattern">The text being searched for</param>
void getSkip(string* pattern) {
    for (int i = 0; i < 256; ++i)
        skip[i] = pattern->length(); // Not in the pattern.
    for (int i = 0; i < pattern->length(); ++i)
        skip[int(pattern->c_str()[i])] = (pattern->length() - 1) - i;
}

/// <summary>
/// Implements the Boyer-Moore Search algorithm for use with std::strings, returns first position of needle in text or -1 if needle isn't present
/// </summary>
/// <param name="haystack">The text to be searched</param>
/// <param name="needle">The text being searched for within the haystack</param>
/// <returns></returns>
void bmSearch(string* haystack, string* needle) {
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
    return 0;
}