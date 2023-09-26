/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  
 *  
 */

#include <iostream>
using namespace std;

class MyQueue {
public:
    MyQueue();
    MyQueue(int capacity);
    ~MyQueue();
    bool IsFull();
    bool IsEmpty();
    void Enqueue(double x);
    double Dequeue();
    double Front();
    double Rear();
    void DisplayQueue();
    void DisplayAll();

private:
    int front, rear;
    int size;
    int capacity;
    double* q;
};

MyQueue::MyQueue() {
    capacity = 10; // Default capacity is 10
    q = new double[capacity];
    size = 0;
    front = rear = -1;
}

MyQueue::MyQueue(int capacity) {
    this->capacity = capacity;
    q = new double[capacity];
    size = 0;
    front = rear = -1;
}

MyQueue::~MyQueue() {
    delete[] q;
}

bool MyQueue::IsFull() {
    return size == capacity;
}

bool MyQueue::IsEmpty() {
    return size == 0;
}

void MyQueue::Enqueue(double x) {
    if (IsFull()) {
        throw "Queue is full. Cannot enqueue.";
    }

    if (IsEmpty()) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % capacity;
    }

    q[rear] = x;
    size++;
}

double MyQueue::Dequeue() {
    if (IsEmpty()) {
        throw "Queue is empty. Cannot dequeue.";
    }

    double item = q[front];
    front = (front + 1) % capacity;
    size--;

    if (size == 0) {
        front = rear = -1;
    }

    return item;
}

double MyQueue::Front() {
    if (IsEmpty()) {
        throw "Queue is empty. Cannot access front element.";
    }

    return q[front];
}

double MyQueue::Rear() {
    if (IsEmpty()) {
        throw "Queue is empty. Cannot access rear element.";
    }

    return q[rear];
}

void MyQueue::DisplayQueue() {
    if (IsEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    int index = front;
    while (index != rear) {
        cout << q[index] << " ";
        index = (index + 1) % capacity;
    }
    cout << q[rear] << endl;
}

void MyQueue::DisplayAll() {
    if (IsEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    for (int i = 0; i < capacity; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main() {
    // Create a queue with default capacity (10)
    MyQueue queue1;

    // Enqueue elements into the queue
    for (int i = 1; i <= 5; i++) {
        queue1.Enqueue(i * 5);
    }

    // Display the elements in the queue
    cout << "Queue 1: ";
    queue1.DisplayQueue();

    // Create a queue with capacity of 3
    MyQueue queue2(4);

    // Enqueue elements into the second queue
    queue2.Enqueue(3);
    queue2.Enqueue(6);
    queue2.Enqueue(9);

    // Try to enqueue one more element (should throw an error)
    try {
        queue2.Enqueue(12);
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    // Display the elements in the second queue
    cout << "Queue 2: ";
    queue2.DisplayQueue();

    // Dequeue elements from the second queue
    while (!queue2.IsEmpty()) {
        cout << "Dequeued: " << queue2.Dequeue() << endl;
    }

    // Try to dequeue from an empty queue (should throw an error)
    try {
        queue2.Dequeue();
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}
