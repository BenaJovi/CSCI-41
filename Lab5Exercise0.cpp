/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  
 *  
 */
#include <iostream>
using namespace std; 

class MyStack {
public:
    MyStack();
    MyStack(int capacity);
    ~MyStack();
    bool IsFull();
    bool IsEmpty();
    double Pop();
    double Top();
    void Push(double x);
    void Display();

private:
    double* s;
    int capacity;
    int size;
};

MyStack::MyStack() {
    capacity = 10; // Fixed Capacity 
    s = new double[capacity];
    size = 0;
}

MyStack::MyStack(int capacity) {
    this->capacity = capacity;
    s = new double[capacity];
    size = 0;
}

MyStack::~MyStack() {
    delete[] s;
}

bool MyStack::IsFull() {
    return size == capacity;
}

bool MyStack::IsEmpty() {
    return size == 0;
}

double MyStack::Pop() {
    if (IsEmpty()) {
        throw "Stack is empty. Cannot pop.";
    }
    return s[--size];
}

double MyStack::Top() {
    if (IsEmpty()) {
        throw "Stack is empty. Cannot get top element.";
    }
    return s[size - 1];
}

void MyStack::Push(double x) {
    if (IsFull()) {
        throw "Stack is full. Cannot push.";
    }
    s[size++] = x;
}

void MyStack::Display() {
    if (IsEmpty()) {
        cout << "Stack is empty." <<endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}


int main() {
    // Create a stack with default capacity (10)
    MyStack stack1;

    // Push elements into the stack
    for (int i = 1; i <= 5; i++) {
        stack1.Push(i * 3);
    }

    // Display the elements in the stack
    cout << "Stack 1: ";
    stack1.Display();

    // Create a stack with capacity of 3
    MyStack stack2(3);

    // Push elements into the second stack
    stack2.Push(4);
    stack2.Push(6);
    stack2.Push(8);

    // Try to push one more element 
    try {
        stack2.Push(10);
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    // Display the elements in the second stack
    std::cout << "Stack 2: ";
    stack2.Display();

    // Pop elements from the second stack
    while (!stack2.IsEmpty()) {
        cout << "Popped: " << stack2.Pop() <<endl;
    }

    // Try to pop from an empty stack 
    try {
        stack2.Pop();
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}