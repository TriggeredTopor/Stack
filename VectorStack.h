#pragma once
#include "StackImplementation.h"
#include <vector>

using ValueType = double;
using namespace std;

class VectorStack : public IStackImplementation{
private:
	vector <ValueType> Vector; 
public:
	VectorStack();
	// добавление в хвост
	void push(const ValueType& value)override;
    // удаление с хвоста
     void pop()override;
    // посмотреть элемент в хвосте
    const ValueType& top() const override;
    // проверка на пустоту
	bool isEmpty() const override;
    // размер 
    size_t size() const override;
    // виртуальный деструктор
   	virtual ~VectorStack();
};