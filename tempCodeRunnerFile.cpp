#include <iostream> 
#include <iomanip> //setw
#include <vector> // traveral 
#include <algorithm> 
#include <ctime> // time functions
#include <cstdlib>
#include <queue> //priority queue
#include <cmath> //floor
using namespace std;


template<typename T>
class BinaryTreeHeap {
private:
    vector<T> heap;

    void heapify(int i);

public:
    void push(const T& value);
    T pop();
    size_t size() const;

    int computeHeight() const;
    int computeLeaves() const;
    bool lookup(const T& key) const;
    bool descendant(const T& current, const T& aNode) const;
    bool descendantHelper(int index, const T& current, const T& aNode) const;
    vector<T> sameLevel(const T& targetValue) const;
    void sameLevelHelper(int index, int targetIndex, int currentLevel, int targetLevel, vector<T>& result) const;

private:
    int computeHeightHelper(int index) const;
    int computeLeavesHelper(int index) const;
    bool lookupHelper(int index, const T& key) const;

};

template<typename T>
int BinaryTreeHeap<T>::computeLeaves() const {
    return computeLeavesHelper(0);
}

template<typename T>
int BinaryTreeHeap<T>::computeLeavesHelper(int index) const {
    if (index >= heap.size()) {
        return 0; // Number of leaves in an empty tree is 0
    }

    if (index * 2 + 1 >= heap.size() && index * 2 + 2 >= heap.size()) {
        return 1; // Node at index is a leaf
    }

    int leftLeaves = computeLeavesHelper(2 * index + 1);
    int rightLeaves = computeLeavesHelper(2 * index + 2);

    return leftLeaves + rightLeaves;
}

template<typename T>
bool BinaryTreeHeap<T>::lookup(const T& key) const {
    return lookupHelper(0, key);
}

template<typename T>
bool BinaryTreeHeap<T>::lookupHelper(int index, const T& key) const {
    if (index >= heap.size()) {
        return false; // Key not found in an empty tree
    }

    if (heap[index] == key) {
        return true; // Key found at the current node
    }

    if (key < heap[index]) {
        return lookupHelper(2 * index + 1, key); // Search in the left subtree
    } else {
        return lookupHelper(2 * index + 2, key); // Search in the right subtree
    }
}

template<typename T>
bool BinaryTreeHeap<T>::descendant(const T& current, const T& aNode) const {
    return descendantHelper(0, current, aNode);
}

template<typename T>
bool BinaryTreeHeap<T>::descendantHelper(int index, const T& current, const T& aNode) const {
    if (index >= heap.size()) {
        return false; // aNode is not a descendant of the current node
    }

    if (heap[index] == aNode) {
        return true; // aNode is a descendant of the current node
    }

    bool leftDescendant = descendantHelper(2 * index + 1, current, aNode);
    bool rightDescendant = descendantHelper(2 * index + 2, current, aNode);

    return leftDescendant || rightDescendant;
}

template<typename T>
void BinaryTreeHeap<T>::heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() && heap[left] < heap[largest])
        largest = left;

    if (right < heap.size() && heap[right] < heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

template<typename T>
void BinaryTreeHeap<T>::push(const T& value) {
    heap.push_back(value);
    int index = heap.size() - 1;

    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

template<typename T>
T BinaryTreeHeap<T>::pop() {
    if (heap.empty()) {
        throw out_of_range("Heap is empty");
    }

    T root = heap.front();
    pop_heap(heap.begin(), heap.end(), greater<T>());
    heap.pop_back();

    return root;
}

template<typename T>
size_t BinaryTreeHeap<T>::size() const {
    return heap.size();
}

template<typename T>
int BinaryTreeHeap<T>::computeHeight() const {
    if (heap.empty()) {
        return 0; // Height of an empty tree is 0
    }

    return computeHeightHelper(0) - 1;
}

template<typename T>
int BinaryTreeHeap<T>::computeHeightHelper(int index) const {
    if (index >= heap.size()) {
        return 0; // Height of an empty tree is 0
    }

    int leftHeight = computeHeightHelper(2 * index + 1);
    int rightHeight = computeHeightHelper(2 * index + 2);

    return max(leftHeight, rightHeight) + 1;
}

template<typename T>
void BinaryTreeHeap<T>::sameLevelHelper(int index, int targetIndex, int currentLevel, int targetLevel, vector<T>& result) const {
    if (index >= heap.size() || currentLevel > targetLevel) {
        return;
    }

    if (currentLevel == targetLevel) {
        result.push_back(heap[index]);
    }

    sameLevelHelper(2 * index + 1, targetIndex, currentLevel + 1, targetLevel, result); // Traverse left subtree

    // Limit the result to 10 elements
    if (result.size() >= 10) {
        return;
    }

    sameLevelHelper(2 * index + 2, targetIndex, currentLevel + 1, targetLevel, result); // Traverse right subtree
}

template<typename T>
vector<T> BinaryTreeHeap<T>::sameLevel(const T& targetValue) const {
    vector<T> result;
    int targetIndex = -1;

    for (int i = 0; i < heap.size(); ++i) {
        if (heap[i] == targetValue) {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex == -1) {
        cerr << "Target value not found in the heap.\n";
        return result; // Target not found
    }

int targetLevel = static_cast<int>(floor(log2(targetIndex + 1))); // Level of the target node

    sameLevelHelper(0, targetIndex, 0, targetLevel, result);

    // Limit the result to 10 elements
    if (result.size() > 10) {
        result.resize(10);
    }

    return result;
}

template<typename T>
void printFormattedOutput(const vector<T>& smallest, const string& label) {
    cout << "Top 100 smallest elements using " << label << ":\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << setw(13) << smallest[i * 10 + j];
        }
        cout << '\n';
    }
    cout << "\n\n";
}

template<typename T>
void measureTimeAndPrintPriorityQueue(const vector<T>& vec, const string& label) {
    priority_queue<T, vector<T>, greater<T> > pqArray(vec.begin(), vec.end());

    clock_t startArray = clock();
    vector<T> smallestArray;
    for (int i = 0; i < 100 && !pqArray.empty(); ++i) {
        smallestArray.push_back(pqArray.top());
        pqArray.pop();
    }
    clock_t endArray = clock();
    double durationArray = static_cast<double>(endArray - startArray) / CLOCKS_PER_SEC;

    cout << "Time taken for " << label << " with Heap using array/vector (Priority Queue): " << durationArray << " seconds\n";
    printFormattedOutput(smallestArray, label + " (Priority Queue)");
}

template<typename T>
void measureTimeAndPrintBinaryTreeHeap(const vector<T>& vec, const string& label) {
    BinaryTreeHeap<T> heapTree;

    // Construct the binary tree
    for (const auto& elem : vec) {
        heapTree.push(elem);
    }

    int intTreeHeight = heapTree.computeHeight();
    int intTreeLeaves = heapTree.computeLeaves();

    clock_t startTree = clock();
    // Perform additional operations on the existing binary tree
    for (const auto& elem : vec) {
        if (heapTree.size() < 100) {
            heapTree.push(elem);
        } else if (elem < heapTree.pop()) {
            heapTree.push(elem);
        }
    }

    vector<T> smallestTree;
    for (int i = 0; i < 100; ++i) {
        smallestTree.push_back(heapTree.pop());
    }
    clock_t endTree = clock();
    double durationTree = static_cast<double>(endTree - startTree) / CLOCKS_PER_SEC;

    cout << "Time taken for " << label << " with Heap using binary tree (Priority Queue): " << durationTree << " seconds\n";
    cout << "Height of binary tree for " << label << ": " << intTreeHeight << "\n";
    cout << "Number of leaves in binary tree for " << label << ": " << intTreeLeaves << "\n";
    printFormattedOutput(smallestTree, label + " (Priority Queue)");
}