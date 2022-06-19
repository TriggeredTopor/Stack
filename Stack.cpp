#include "Stack.h"
#include "ListStack.h"
#include "Vector.h"
#include "StackImplementation.h"
#include <stdexcept>

Stack::Stack(StackContainer container) 
	: _containerType(container)
{
	switch (_containerType)
	{
		case StackContainer::List: 
		{
			_pimpl = static_cast<IStackImplementation*>(new ListStack());
			break;
		}
			
		case StackContainer::Vector: 
		{
			_pimpl = static_cast<IStackImplementation*>(new VectorStack());
			break;
		}
			
		default:
			throw std::runtime_error("Неизвестный тип контейнера");
	}
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container) : _containerType(container)
{
	switch (_containerType)
	{
		case StackContainer::List: 
		{
			_pimpl = static_cast<IStackImplementation*>(new ListStack());
			break;
		}

		case StackContainer::Vector: 
		{
			_pimpl = static_cast<IStackImplementation*>(new VectorStack());
			break;
		}

		default:
			throw std::runtime_error("Неизвестный тип контейнера");
	}

	for (int i = 0; i < arraySize; i++)
	{
		_pimpl->push(valueArray[i]);
	}	
}

Stack::Stack(const Stack& copyStack) 
	: _containerType(copyStack._containerType)
{
	
	switch (_containerType)
	{
		case StackContainer::List:
		{
			_pimpl = static_cast<IStackImplementation*>(new ListStack());
			break;
		}

		case StackContainer::Vector:
		{
			_pimpl = static_cast<IStackImplementation*>(new VectorStack());
			break;
		}

		default:
			throw std::runtime_error("Неизвестный тип контейнера");
	}

	std::vector<ValueType> tempArray;
	const int tempSize = copyStack.size();
	
	for (int i = (tempSize - 1); i > -1; i--)
	{
		tempArray.push_back(copyStack._pimpl->top());
		copyStack._pimpl->pop();
	}

	for (int j = (tempSize - 1); j > -1; j--)
	{
		copyStack._pimpl->push(tempArray[j]);
	}
	
	for (int k = (tempSize - 1); k > -1; k--)
	{
		_pimpl->push(tempArray[k]);
	}

	tempArray.clear();
}

Stack& Stack::operator=(const Stack& copyStack) 
{
	if (this == &copyStack)
	{
		return *this;
	}

	switch (copyStack._containerType)
	{
		case StackContainer::List: 
		{
			_pimpl = static_cast<IStackImplementation*>(new ListStack());
			break;
		}

		case StackContainer::Vector: 
		{
			_pimpl = static_cast<IStackImplementation*>(new VectorStack());
			break;
		}
			
		default:
			throw std::runtime_error("Неизвестный тип контейнера");
	}
	
	std::vector<ValueType> tempArray;
	const int tempSize = copyStack.size();
	
	for (int i = (tempSize - 1); i > -1; i--)
	{
		tempArray.push_back(copyStack._pimpl->top());
		copyStack._pimpl->pop();
	}

	for (int j = (tempSize - 1); j > -1; j--)
	{
		copyStack._pimpl->push(tempArray[j]); 
	}
	
	for (int k = (tempSize - 1); k > -1; k--)
	{
		_pimpl->push(tempArray[k]);
	}
	
	tempArray.clear();

	return *this;
}

Stack::Stack(Stack&& moveStack) noexcept 
	:_containerType(moveStack._containerType)
{
	switch (_containerType)
	{
		case StackContainer::List: 
		{
			_pimpl = static_cast<IStackImplementation*>(new ListStack());
			break;
		}

		case StackContainer::Vector: 
		{
			_pimpl = static_cast<IStackImplementation*>(new VectorStack());
			break;
		}

		default:
			throw std::runtime_error("Неизвестный тип контейнера");
	}

	_pimpl = moveStack._pimpl;
	moveStack._pimpl = nullptr;
}

Stack& Stack::operator=(Stack&& moveStack) noexcept 
{
	if (this == &moveStack)
	{
		return *this;
	}

	switch (moveStack._containerType)
	{
		case StackContainer::List: 
		{
			_pimpl = static_cast<IStackImplementation*>(new ListStack());
			break;
		}
			
		case StackContainer::Vector: 
		{
			_pimpl = static_cast<IStackImplementation*>(new VectorStack());
			break;
		}
			
		default:
			throw std::runtime_error("Неизвестный тип контейнера");
	}
	
	_pimpl = moveStack._pimpl;
	moveStack._pimpl = nullptr;

	return(*this);
}

Stack::~Stack()
{
	delete _pimpl;       
}

void Stack::push(const ValueType& value)
{
	_pimpl->push(value);
}

void Stack::pop()
{
	_pimpl->pop();
}

const ValueType& Stack::top() const
{
	return _pimpl->top();
}

bool Stack::isEmpty() const
{
	return _pimpl->isEmpty();
}

size_t Stack::size() const
{
	return _pimpl->size();
}
