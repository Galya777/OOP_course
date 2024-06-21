#include <iostream>
#include <cassert>
#include "rstack.hpp"

const int EMPTY_STACK = -1;
const unsigned INITIAL_CAPACITY = 10;

// създаване на празен стек 
ResizingStack::ResizingStack() {
    top = EMPTY_STACK;
    capacity = INITIAL_CAPACITY;
    a = new int[INITIAL_CAPACITY];
}

// проверка дали стекът е пълен
bool ResizingStack::full() const {
    return top == capacity - 1;
}

// проверка за празнота
bool ResizingStack::empty() const {
    return top == EMPTY_STACK;
}

// включване на елемент
void ResizingStack::push(int const& x) {
    if (full())
        resize();
    a[++top] = x;
    // !!! top++ = 4;
    // OK: ++top = 4;
}

// изключване на елемент
int ResizingStack::pop() {
    assert(!empty()); // не искаме да позволяваме изключване на елемент от празен стек
    return a[top--];
}

// поглеждане на последно включения елемент
int ResizingStack::peek() const {
    assert(!empty()); // не искаме да позволяваме поглеждане на елемент от празен стек
    return a[top];
}

// разширяване на стека
void ResizingStack::resize() {
    // удвояваме капацитета
    unsigned newCapacity = capacity * 2;
    std::clog << "Разширяваме стека до капацитет " << newCapacity << std::endl;
    // запазваме си стария указател
    int *olda = a;
    // заделяме памет за новия стек
    a = new int[newCapacity];
    // копираме елементите от стария стек
    copy(olda);
    capacity = newCapacity;
    // унищожаваме стария масив
    delete[] olda;
}

ResizingStack::~ResizingStack() {
    delete[] a;
}

ResizingStack::ResizingStack(ResizingStack const& other) : top(other.top), capacity(other.capacity) {
    copy(other.a);
}

ResizingStack& ResizingStack::operator=(ResizingStack const& other) {
    if (this != &other) {
        delete[] a;
        top = other.top;
        capacity = other.capacity;
        copy(other.a);
    }
    return *this;
}

void ResizingStack::copy(int* othera) {
   for(int i = 0; i < capacity; i++)
        a[i] = othera[i];
}