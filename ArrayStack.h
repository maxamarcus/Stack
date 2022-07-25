#include "Stack.h"

template <class t>
class ArrayStack : public Stack <t> {

public:

    // CONSTRUCTOR
    ArrayStack(int);
    ~ArrayStack();

    // TRANSFORMERS
    virtual void Push(t);
    virtual void Pop();

    // OBSERVERS
    virtual t Top();
    virtual bool IsFull();
    virtual bool IsEmpty();

protected:

    // MEMBER VARIABLES
    t * stack;
    int capacity;
    int top;
    /* ^ top represents the index number of the stack's top element. */

    // HELPER FUNCTIONS
    void DoubleCapacity();
};




template <class t>
ArrayStack <t> :: ArrayStack(int arraySize) {
    this->capacity = arraySize;
    this->top = -1;
    this->stack = new t [arraySize];
}



template <class t>
ArrayStack <t> :: ~ArrayStack() {
    delete this->stack;
}



template <class t>
void ArrayStack <t> :: Push(t pushMe) {
    /* Linear iteration if stack is full. Constant time otherwise. */
    if (IsFull()) {
        DoubleCapacity();
    }
    top ++;
    stack[top] = pushMe;
}



template <class t>
void ArrayStack <t> :: Pop() {
    if (IsEmpty()) {
        throw EmptyStack();
    }
    top --;
}



template <class t>
t ArrayStack <t> :: Top() {
    if (IsEmpty()) {
        throw EmptyStack();
    }
    return stack[top];
}



template <class t>
bool ArrayStack <t> :: IsFull() {
    return (top + 1 == capacity);
}



template <class t>
bool ArrayStack <t> :: IsEmpty() {
    return (top == -1);
}



template <class t>
void ArrayStack <t> :: DoubleCapacity() {
    /* Linear iteration. */
    t * newStack = new t [capacity * 2];
    for (int i = 0; i < capacity; i ++) {
        newStack[i] = this->stack[i];
    }
    delete this->stack;
    this->stack = newStack;
    capacity *= 2;
}