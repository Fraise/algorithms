#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

#include "arraysAndStrings.h"

using namespace std;

int main()
{
	cout << "Hello, algorithms!\n";

	cin.get();

	return 0;
}

/*
	Implements an algorithm to determine if a string has all unique characters.
*/

bool hasUniqueChar(string str)
{
	unordered_map<char, int> letters;

	for (int i = 0; i < str.length(); i++)
	{
		unordered_map<char, int>::const_iterator charItr = letters.find(str[i]);

		if (charItr == letters.end())
		{
			pair<char, int> values(str[i], i);

			letters.insert(values);
		}
		else
		{
			return false;
		}
	}

	return true;
}

/*
	Determines if a string is a permutation of another.
*/

bool isPermutation(string str1, string str2)
{
	if (str1.length() != str2.length())
		return false;

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	if (str1 == str2)
		return true;
	else
		return false;
}

/*
	Determines if a string can be arranged in a palindrome.
*/

bool palindromePossible(string str)
{
	int alphabet[26] = { 0 };

	for (int i = 0; i < str.length(); i++)
	{
		int pos = charToAlphabetPos(str[i]);

		if (pos >= 0)
		{
			alphabet[pos]++;
		}
	}

	bool odd = false;

	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] % 2 != 0 && !odd)
			odd = true;
		else if (alphabet[i] % 2 != 0 && odd)
			return false;
	}

	return true;
}

int charToAlphabetPos(char c)
{
	int pos = -1;

	if (c >= 65 && c <= 90)
		pos = (int)c - 65;
	else if (c >= 97 && c <= 122)
		pos = (int)c - 97;

	return pos;
}

/*
	Implements a method to perform basic string compression using the count of repeated characters.
	If the compressed string is bigger than the non compressed one, the function return the original.
*/

string basicCompress(string str)
{
	char currChar = str[0];
	int charNum = 0;
	string retStr = "";

	for (int i = 0; i < str.length(); i++)
	{
		if (currChar != str[i])
		{
			retStr += currChar;
			retStr += to_string(charNum);

			currChar = str[i];
			charNum = 1;
		}
		else
		{
			charNum++;
			currChar = str[i];
		}
	}

	retStr += currChar;
	retStr += to_string(charNum);

	if (retStr.length() > str.length())
		return str;
	else
		return retStr;
}