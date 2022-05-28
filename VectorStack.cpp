#include "VectorStack.h"

VectorStack::VectorStack() {
}

void VectorStack::push(const ValueType& value) {
	Vector.push_back(value);
};

void VectorStack::pop() {
	Vector.pop_back();
};

const ValueType& VectorStack::top() const {
	return (Vector.back());
};

bool VectorStack::isEmpty() const {
	if (Vector.size() != 0) {
		return false;
	}
	return true;
};

size_t VectorStack::size() const {
	return (Vector.size());
};

VectorStack::~VectorStack() {
	Vector.clear();
}