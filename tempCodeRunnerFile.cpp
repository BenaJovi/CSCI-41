/*  Author: Jovani Benavides
    Course: CSCI-41 
    Purpose:    
*/
#include <iostream>
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

    void displayHeap() {
        cout << "Heap: ";
        for (int i = 0; i < size; ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void heapifyUpFromArray(int arr[], int size) {
        for (int i = 1; i < size; ++i) {
            int index = i;
            int parent = (index - 1) / 2;
            while (index > 0 && arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
                parent = (index - 1) / 2;
            }
        }
    }

    void heapifyDownFromArray(int arr[], int size, int index) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }

        if (rightChild < size && arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapifyDownFromArray(arr, size, largest);
        }
    }
};

int main() {
    // Build a Max heap of random numbers
    
    MaxHeap maxHeap(10);

    cout << "Inserting random numbers into the heap: ";
    for (int i = 0; i < 10; ++i) {
        int randomNumber = rand() % 10;
        cout << randomNumber << " ";
        maxHeap.insert(randomNumber);
    }
    cout << endl;

    // Display the Max heap
    maxHeap.displayHeap();

    // Perform deletion
    maxHeap.removeMax();
    cout << "After deletion: ";
    maxHeap.displayHeap();

    // Perform insertion
    int newValue = 11;
    maxHeap.insert(newValue);
    cout << "After insertion of " << newValue << ": ";
    maxHeap.displayHeap();
    cout<<endl;
    // Perform heapify operations on a given array
    int arrayToHeapify[] = {30, 20, 10, 15, 25, 5, 40, 35};
    int arraySize = sizeof(arrayToHeapify) / sizeof(arrayToHeapify[0]);

    cout << "Original array: ";
    for (int i = 0; i < arraySize; ++i) {
        cout << arrayToHeapify[i] << " ";
    }
    cout << endl;

    maxHeap.heapifyUpFromArray(arrayToHeapify, arraySize);
    cout << "Array after heapify up: ";
    for (int i = 0; i < arraySize; ++i) {
        cout << arrayToHeapify[i] << " ";
    }
    cout << endl;

    maxHeap.heapifyDownFromArray(arrayToHeapify, arraySize, 0);
    cout << "Array after heapify down: ";
    for (int i = 0; i < arraySize; ++i) {
        cout << arrayToHeapify[i] << " ";
    }
    cout << endl;

    return 0;
}
