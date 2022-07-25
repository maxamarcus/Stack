#include "Stack.h"

// DEFINITIONS
template <class t>
struct node {
    t info;
    t * next;
};

templace <class t>
class LinkedStack : public Stack <t> {

public:

    // CONSTRUCTOR
    LinkedStack();
    ~LinkedStack();

    // TRANSFORMERS
    virtual void Push(t);
    virtual void Pop();

    // OBSERVERS
    virtual t Top();
    virtual bool IsFull();
    virtual bool IsEmpty();

private:

    // MEMBER VARIABLES
    node <t> * top;
};



template <class t>
LinkedStack <t> :: LinkedStack() {
    this->top = nullptr;
}



template <class t>
LinkedStack <t> :: ~LinkedStack() {
    /* Linear iteration. */
    node <t> * ptr;
    while (this->top != nullptr) {
        ptr = this->top;
        this->top = this->top->next;
        delete ptr;
    }
}



template <class t>
void LinkedStack <t> :: Push(t pushMe) {
    node <t> * toAdd = new node <t>;
    toAdd->info = pushMe;
    toAdd->next = this->top;
    this->top = toAdd;
}



template <class t>
void LinkedStack <t> :: Pop() {
    if (IsEmpty()) {
        throw EmptyStack();
    }
    node <t> * toPop = this->top;
    this->top = this->top->next;
    delete toPop;
}



template <class t>
t LinkedStack <t> :: Top() {
    if (IsEmpty()) {
        throw EmptyStack();
    }
    return this->top->info;
}



template <class t>
bool LinkedStack <t> :: IsFull() {
    return false;
}



template <class t>
bool LinkedStack <t> :: IsEmpty() {
    return this->top == nullptr;
}