// Stack ABC

// EXCEPTIONS
class EmptyStack {};
/* When Stack is empty, Pop() and Top() methods throw EmptyStack exception. */

template <class t>
class Stack {
public:

    // TRANSFORMERS
    virtual void Push(t) = 0;
    virtual void Pop() = 0;
    /* ^ Pop() does not return a value! */

    // OBSERVERS
    virtual t Top() = 0;
    /* Observe top of stack without popping. */
    virtual bool IsFull() = 0;
    virtual bool IsEmpty() = 0;

};