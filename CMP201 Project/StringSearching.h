#pragma once
#include <iostream>
#include <list>
#include <unordered_map>

/// <summary>
/// Gets the number of places that can be skipped for each occurance of a letter in the pattern
/// </summary>
/// <param name="pattern">: The text being searched for</param>
void getSkip(std::string* pattern);

/// <summary>
/// Implements the Boyer-Moore Search algorithm for use with std::strings, returns a list of ints represnting the start index of each occurance of the needle
/// </summary>
/// <param name="haystack">The text to be searched</param>
/// <param name="needle">The text being searched for within the haystack</param>
/// <returns></returns>
void bmSearch(std::string* haystack, std::string* needle, std::list<int>* indexes);

/// <summary>
/// Returns hash of given string
/// </summary>
/// <param name="input">Pointer to string (or substring)</param>
/// <returns></returns>
int hashString(std::string input);

/// <summary>
/// Re-computes given hash with remChar removed and addChar added
/// </summary>
/// <param name="hash">Hash which needs to be re-calculated</param>
/// <param name="remChar">Character to remove</param>
/// <param name="addChar">Character to add</param>
/// <returns></returns>
void hashString(int& hash, const char remChar, const char addChar);

/// <summary>
/// Returns a given string as lowercase
/// </summary>
/// <param name="input">The string to be shifted down a case</param>
/// <returns></returns>
std::string toLowerString(std::string input);

/// <summary>
/// Implements the Rabin-Karp Search Algorithm for use with std::strings, returns a list of ints represnting the start index of each occurance of the needle
/// </summary>
/// <param name="haystack">The text to be searched</param>
/// <param name="needle">The text being searched for within the haystack</param>
/// <returns></returns>
void rkSearch(std::string* haystack, std::string* needle, std::list<int>* indexes);