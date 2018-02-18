#include <iostream>
#include <string>
#include <unordered_map>

#include "arraysAndStrings.h"

using namespace std;

int main()
{
	cout << "Hello, algorithms!\n";

	if (hasUniqueChar("azerty"))
		cout << "blbl";

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