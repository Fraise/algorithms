#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

#include "recursive.h"

using namespace std;

unsigned long long int fibonacci(int index)
{
	if (index == 0 || index == 1) { return index; }

	return fibonacci(index - 1) + fibonacci(index - 2);
}

unsigned long long int fibonacciMem(int index)
{
	if (index == 0 || index == 1) { return index; }

	vector<unsigned long long int> mem(index + 1);

	return fibonacciMemRec(index, mem);
}

unsigned long long int fibonacciMemRec(int index, vector<unsigned long long int>& mem)
{
	if (index == 0 || index == 1) { return index; }

	if (mem[index] == 0)
	{
		mem[index] = fibonacciMemRec(index - 1, mem) + fibonacciMemRec(index - 2, mem);
	}

	return mem[index];
}