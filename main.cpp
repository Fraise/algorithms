/* Using Visual Studio memory leak detector */
/* Place the following define in every class you want to test */

/*
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif
*/

/* Place the following function before an exit point */

//_CrtDumpMemoryLeaks();

#include <iostream>
#include <string>
#include <random>
#include <ctime>

//#include "arraysAndStrings.h"

using namespace std;

int main()
{
	cout << "Hello, algorithms!\n";

	clock_t tStart = clock();


	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);


	std::cin.get();

	return 0;
}