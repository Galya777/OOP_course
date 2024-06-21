// #pragma once
#ifndef __STACK_HPP
#define __STACK_HPP

#include "abstract_stack.hpp"

class Stack : public AbstractStack<int> {
    static const unsigned MAX_STACK = 100;
    int a[MAX_STACK];
    int top; // индекс на последно включения елемент в стека

    // проверка дали стекът е пълен
    bool full() const;
public:
    // създаване на празен стек 
    Stack();

    // проверка за празнота
    bool empty() const;

    // включване на елемент
    void push(int const& x);

    // изключване на елемент
    int pop();

    // поглеждане на последно включения елемент
    int peek() const;
};

#endif