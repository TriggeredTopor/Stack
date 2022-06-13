#pragma once
#include "StackImplementation.h"
#include <vector>

using ValueType = double;
using namespace std;

class VectorStack : public IStackImplementation {
private:
    vector <ValueType> Vector;
public:
    VectorStack();

    void push(const ValueType& value)override;

    void pop()override;

    const ValueType& top() const override;

    bool isEmpty() const override;

    size_t size() const override;

    virtual ~VectorStack();
};
