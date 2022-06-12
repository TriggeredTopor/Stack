#include "Stack.h"
#include "ListStack.h"
#include "Vector.h"
#include "StackImplementation.h"
#include <stdexcept>

Stack::Stack(StackContainer container) : _containerType(container)
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
	// принцип тот же, что и в прошлом конструкторе
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

Stack::Stack(const Stack& copyStack) : _containerType(copyStack._containerType)
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
	

	std::vector<ValueType> valueArray;
	int tempSize = copyStack.size();

	if (copyStack.size() == 0) {
		tempSize = _pimpl->size();
		std::cout << "ye reshil ne rabotat'" << std::endl;
	}
	std::cout << " in stack size " << copyStack.size() << std::endl;
	for (int i = 0; i < tempSize; i++)
	{
		valueArray.push_back(copyStack._pimpl->top());
		copyStack._pimpl->pop();
	}
	std::cout << " clear stack size " << copyStack.size() << std::endl;
	for (int k = tempSize - 1; k > -1; k--)
	{
		copyStack._pimpl->push(valueArray[k]);
	}
	std::cout << " full again stack size " << copyStack.size() << std::endl;
	for (int k = tempSize - 1; k > -1; k--)
	{
		_pimpl->push(valueArray[k]);
	}
	std::cout << "pimpl size " << _pimpl->size() << std::endl;
}

Stack& Stack::operator=(const Stack& copyStack) 
{
	// TODO: вставьте здесь оператор return;
	switch (copyStack._containerType)
	{
	case StackContainer::List: 
	{
		_pimpl = static_cast<IStackImplementation*>(new ListStack());
		break;
	}// vinesti after stack with vector(as mssive)
	case StackContainer::Vector: 
	{
		_pimpl = static_cast<IStackImplementation*>(new VectorStack());
		break;
	}
	default:
		throw std::runtime_error("Неизвестный тип контейнера");
	}
	

	std::vector<ValueType> valueArray;
	 int tempSize = copyStack.size();


	std::cout << " in stack size " << copyStack.size() << std::endl;
	for (int i = 0; i < tempSize; i++)
	{
		valueArray.push_back(copyStack._pimpl->top());
		copyStack._pimpl->pop();
	}
	std::cout << " clear stack size " << copyStack.size() << std::endl;
	for (int k = tempSize - 1; k > -1; k--)
	{
		copyStack._pimpl->push(valueArray[k]);
	}
	std::cout << " full again stack size " << copyStack.size() << std::endl;
	for (int k = tempSize - 1; k > -1; k--)
	{
		_pimpl->push(valueArray[k]);
	}
	std::cout << "pimpl size " << _pimpl->size() << std::endl;
	
	return *this;
}

Stack::Stack(Stack&& moveStack) noexcept :_containerType(moveStack._containerType)
{
	switch (_containerType)
	{
	case StackContainer::List: {
		_pimpl = static_cast<IStackImplementation*>(new ListStack());
		break;
	}

	case StackContainer::Vector: {
		_pimpl = static_cast<IStackImplementation*>(new VectorStack());
		break;
	}

	default:
		throw std::runtime_error("Неизвестный тип контейнера");
	}

	_pimpl = moveStack._pimpl;
	std::cout << _pimpl->size() << std::endl;
	moveStack._pimpl = nullptr;

};

Stack& Stack::operator=(Stack&& moveStack) noexcept {

	switch (moveStack._containerType)
	{
	case StackContainer::List: {
		_pimpl = static_cast<IStackImplementation*>(new ListStack());
		break;
	}
	case StackContainer::Vector: {
		_pimpl = static_cast<IStackImplementation*>(new VectorStack());
		break;
	}
	default:
		throw std::runtime_error("Неизвестный тип контейнера");
	}
	_pimpl = moveStack._pimpl;
	moveStack._pimpl = nullptr;

	return(*this);
};

Stack::~Stack()
{
	delete _pimpl;        // композиция!
}

void Stack::push(const ValueType& value)
{
	// можно, т.к. push определен в интерфейсе
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
