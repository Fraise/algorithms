#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

#include "bits.h"

using namespace std;

bool getBit(int num, int pos)
{
	return ((num & (1 << pos)) != 0);
}

int setBit(int num, int pos)
{
	return (num | (1 << pos));
}

int clearBit(int num, int pos)
{
	return (num & ~(1 << pos));
}