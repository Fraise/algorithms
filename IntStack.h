#pragma once

#include <iostream>

typedef struct IntStackNode
{
	int value;
	struct IntStackNode *nextNode = nullptr;
	bool empty = false;
} IntStackNode_t;

struct EmptyStackException : public std::exception
{
	const char* what() throw() { return "The stack is empty.\n"; }
};

class IntStack
{
	IntStackNode_t *top;

public:
	IntStack(int value);
	~IntStack();
	int pop();
	void push(int value);
	int peek();
	bool isEmpty();
};

