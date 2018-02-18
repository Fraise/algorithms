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