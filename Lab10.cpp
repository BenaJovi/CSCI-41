/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *
 *
 */
#include <iostream>
using namespace std;


class PriorityQueue {
private:
    struct Node {
        int item;
        int priority;
    };

    Node* heap;
    int capacity;
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index) {
        while (index > 0 && heap[index].priority < heap[parent(index)].priority) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int minIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && heap[left].priority < heap[minIndex].priority) {
            minIndex = left;
        }

        if (right < size && heap[right].priority < heap[minIndex].priority) {
            minIndex = right;
        }

        if (index != minIndex) {
            swap(heap[index], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    PriorityQueue(int capacity) {
        this->capacity = capacity;
        heap = new Node[capacity];
        size = 0;
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    void insert(int item, int priority) {                                          // insert function that assigns an element with a priority value
        if (size == capacity) {
            cerr << "Priority queue is full. Cannot insert more items." << endl;
            return;
        }

        heap[size].item = item;
        heap[size].priority = priority;
        size++;
        heapifyUp(size - 1);
    }

    int poll() {                                                                    // Will select and remove the element with the highest priority 
        if (size == 0) {
            cerr << "Priority queue is empty. Cannot poll." << endl;
            return -1;  // A default value to indicate an empty queue
        }

        int highestPriorityItem = heap[0].item;
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return highestPriorityItem;
    }

    int peek() {                                                                    // Returns the highest priority value
        if (size == 0) {    
            cerr << "Priority queue is empty. Cannot peek." << endl;
            return -1;  // A default value to indicate an empty queue
        }

        return heap[0].item;
    }
    void printHeap() {                                                              // Displays the heap for the user with its element and priority value.
        cout << "Heap Contents:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "(" << heap[i].item << ", " << heap[i].priority << ") ";
        }
        cout << endl;
    }
};


int main() {
   int capacity;
    cout << "Enter the capacity of the priority queue: ";
    cin >> capacity;

    PriorityQueue pq(capacity);

    int numItems;
    cout << "Enter the number of items to insert: ";
    cin >> numItems;

    for (int i = 0; i < numItems; ++i) {
        int item, priority;
        cout << "Enter item " << i + 1 << ": ";
        cin >> item;
        cout << "Enter its priority: ";
        cin >> priority;
        pq.insert(item, priority);
    }
    pq.printHeap();
    // Peeking at the highest priority item
    cout << "Highest priority item: " << pq.peek() << endl;

    // Removing and getting the highest priority item
    cout << "Popped item: " << pq.poll() << endl;

    // Peeking highest priority after poll to show the highest priority has changed.
    cout << "Highest priority item: " << pq.peek() << endl;

    return 0;
}

