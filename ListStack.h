#pragma once
#include "StackImplementation.h"
#include <list>

using ValueType = double;
using namespace std;

class ListStack : public IStackImplementation {
private:
    list <ValueType> List;
public:

    ListStack();

    void push(const ValueType& value)override;

    void pop()override;

    const ValueType& top() const override;

    bool isEmpty() const override;

    size_t size() const override;

    virtual  ~ListStack();
};
