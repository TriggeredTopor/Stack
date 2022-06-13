#include "ListStack.h"

ListStack::ListStack() 
{}

void ListStack::push(const ValueType& value) 
{
	List.push_back(value);
}

void ListStack::pop() 
{
	List.pop_back();
}

const ValueType& ListStack::top() const 
{
	return(List.back());
}

bool ListStack::isEmpty() const 
{
	if (List.empty()) 
	{
		return true;
	}
	return false;
}

size_t ListStack::size() const 
{
	return (List.size());
}

ListStack::~ListStack() 
{
	List.clear();
}
