/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  
 *  
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;

    void heapifyUp(int index) {
        if (index == 0) return;

        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap(int capacity) : capacity(capacity), size(0) {
        heap = new int[capacity];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void buildHeapFromArray(int arr[], int size) {
        for (int i = 0; i < size; ++i) {
            heap[i] = arr[i];
            heapifyUp(i);
        }
        this->size = size;
    }

    void displayHeap() {
        cout << "Heap: ";
        for (int i = 0; i < size; ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void heapifyUpFromArray() {
        for (int i = size - 1; i > 0; --i) {
            heapifyUp(i);
        }
    }

    void heapifyDownFromArray() {
        for (int i = size / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }

        heap[size++] = value;
        heapifyUp(size - 1);
    }

    void removeMax() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        heap[0] = heap[--size];
        heapifyDown(0);
    }
};

int main() {
    const int arraySize = 10;
    int data[arraySize];

    cout << "Inserting random numbers into the array: ";
    for (int i = 0; i < arraySize; ++i) {
        data[i] = rand() % 10;
        cout << data[i] << " ";
    }
    cout << endl;

    MaxHeap maxHeap(arraySize);

    // Build Max heap from the random array
    maxHeap.buildHeapFromArray(data, arraySize);
    cout << "Max heap after building from the array: ";
    maxHeap.displayHeap();

    // Perform insertion on the Max heap
    int newValue = 50;
    maxHeap.insert(newValue);
    cout << "Max heap after insertion of " << newValue <<endl;
    maxHeap.displayHeap();

    // Perform deletion on the Max heap
    maxHeap.removeMax();
    cout << "Max heap after deletion: ";
    maxHeap.displayHeap();

    // Perform heapify up on the Max heap
    maxHeap.heapifyUpFromArray();
    cout << "Max heap after heapify up: ";
    maxHeap.displayHeap();

    // Perform heapify down on the Max heap
    maxHeap.heapifyDownFromArray();
    cout << "Max heap after heapify down: ";
    maxHeap.displayHeap();

    return 0;
}
