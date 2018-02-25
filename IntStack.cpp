#include "IntStack.h"

IntStack::IntStack(int value)
{
	IntStackNode_t *bottom = new IntStackNode_t();

	bottom->empty = true;

	top = new IntStackNode_t();
	top->value = value;
	top->nextNode = bottom;
}

IntStack::~IntStack()
{
	while (!top->empty)
	{
		IntStackNode_t *deletedNode = top;
		top = top->nextNode;
		delete deletedNode;
	}

	delete top;
}

int IntStack::pop()
{
	if (top->nextNode == nullptr)
	{
		throw EmptyStackException();
	}

	IntStackNode_t *poppedNode = top;
	int value = poppedNode->value;

	top = top->nextNode;

	delete poppedNode;

	return value;
}

void IntStack::push(int value)
{
	IntStackNode_t *node = new IntStackNode_t();
	node->value = value;
	node->nextNode = this->top;
	this->top = node;
}

int IntStack::peek()
{
	return this->top->value;
}

bool IntStack::isEmpty()
{
	return top->empty;
}
