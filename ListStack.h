#pragma once
#include "StackImplementation.h"
#include <list>

using ValueType = double;
using namespace std;

class ListStack : public IStackImplementation{
private:
	list <ValueType> List;
public:
  	// do new construct list = null ptr
	ListStack();
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
   	virtual  ~ListStack();
};
	