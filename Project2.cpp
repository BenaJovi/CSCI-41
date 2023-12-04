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
    vector<T> heap;// Vector to store elements in the HEAP

    void heapifyUp(int i);// Helper function to maintain HEAP 
    void heapifyDown(int index);
    void swim(int index);

public:
    void push(const T& value); // Add element to the HEAP
    T pop();// Remove top element from the HEAP
    size_t size() const;// Current Size of HEAP

    int computeHeight() const;// Function to get height of HEAP
    int computeLeaves() const;// Function to get number of Leaves in HEAP
    bool lookup(const T& key) const;// Function to check if Key exists within the HEAP
    bool descendant(const T& current, const T& aNode) const;// Function to check if aNode is a Descendant of the Current Node
    bool descendantHelper(int index, const T& current, const T& aNode) const;// Helper Function for Descendant 
    vector<T> sameLevel(const T& targetValue) const;// Function that gets all elements on the same level
    void sameLevelHelper(int index, int targetIndex, int currentLevel, int targetLevel, vector<T>& result) const; // Helper function for Same Level


private:
    int computeHeightHelper(int index) const; // Helper Function for computing height 
    int computeLeavesHelper(int index) const; // Helper Function for computing Leaves
    bool lookupHelper(int index, const T& key) const; // Helper function for LookUp

};

template<typename T>
void BinaryTreeHeap<T>::heapifyDown(int index){ // heapifyDown function 
    int left=2* index+1;
    int right=2* index +2;
    int smallest=index;

    if (left<heap.size()&& heap[left]<heap[smallest]){
        smallest=left;
    }
    if(right<heap.size()&& heap[right]< heap[smallest]){
        smallest=right;
    }
    if(smallest!=index){
        swap(heap[index],heap[smallest]);
        heapifyDown(smallest);
    }
}
template<typename T>
void BinaryTreeHeap<T>::heapifyUp(int index){
    while(index>0&& heap[index]<heap[(index-1)/2]){
        swap(heap[index],heap[(index-1)/2]);
        index=(index-1)/2;
    }
}
// Function to count the number of leaves with the HEAP 
template<typename T>
int BinaryTreeHeap<T>::computeLeaves() const {
    return computeLeavesHelper(0);
}
// Helper for computeLeaves Function 
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
// Function that checkss if a key exists in the HEAP 
template<typename T>
bool BinaryTreeHeap<T>::lookup(const T& key) const {
    return lookupHelper(0, key);
}
// Helper funciton for lookup Function
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
// Function to check if a node is a descendant of the current node selected 
template<typename T>
bool BinaryTreeHeap<T>::descendant(const T& current, const T& aNode) const {
    return descendantHelper(0, current, aNode);
}
// Helper for descendant function
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
void BinaryTreeHeap<T>::swim(int index){
    while(index>0&& heap[index]<heap[(index-1)/2]){
        swap(heap[index],heap[(index-1)/2]);
        index=(index-1)/2;
    }
}

// Function to add an element to the HEAP
template<typename T>
void BinaryTreeHeap<T>::push(const T& value) {
    heap.push_back(value);
    int index = heap.size() - 1;

    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}
// Function to remove the top element from the HEAP
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
// Function to get the current size of the HEAP
template<typename T>
size_t BinaryTreeHeap<T>::size() const {
    return heap.size();
}
// Function to compute the height of the HEAP 
template<typename T>
int BinaryTreeHeap<T>::computeHeight() const {
    if (heap.empty()) {
        return 0; // Height of an empty tree is 0
    }
    return computeHeightHelper(0) - 1;
}
// Helper for computeHeight function 
template<typename T>
int BinaryTreeHeap<T>::computeHeightHelper(int index) const {
    if (index >= heap.size()) {
        return 0; // Height of an empty tree is 0
    }
    int leftHeight = computeHeightHelper(2 * index + 1);
    int rightHeight = computeHeightHelper(2 * index + 2);
    return max(leftHeight, rightHeight) + 1;
}
// Helper for sameLevel Function 
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
// Function to check what element are on the same level as the selceted node
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
        cerr << "\tTarget value not found in the heap.\n";
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
// A function that will print out the smallest 100 elements with the vector 
template<typename T>
void printFormattedOutput(const vector<T>& smallest, const string& label) {
    cout << "\tTop 100 smallest elements using " << label << ":\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << setw(12) << smallest[i * 10 + j];
        }
        cout << '\n';
    }
    cout << "\n";
}
// Function to calculate the time taken to create the heap using a vector 
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

    cout << "\tTime taken for " << label << " with Heap using array/vector (Priority Queue): " << durationArray << " seconds\n";
    printFormattedOutput(smallestArray, label + " (Priority Queue)");
}
// Constructs the binary heap and will output the time taken, height,and the number of leaves.
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

    cout << "\tTime taken for " << label << " with Heap using binary tree (Priority Queue): " << durationTree << " seconds\n";
    cout << "\tHeight of binary tree for " << label << ": " << intTreeHeight << "\n";
    cout << "\tNumber of leaves in binary tree for " << label << ": " << intTreeLeaves << "\n";
    printFormattedOutput(smallestTree, label + " (Priority Queue)");
}



int main() {

    const int N = 100000;
    const int MAX_VALUE = 500000; // Set the maximum random value

    // Seed for random number generation
    srand(time(0));


    // Generate 100,000 random numbers less than 1,000,000 for each type
    vector<int> intVec;
    vector<long int> longIntVec;
    vector<long long int> longLongIntVec;
    vector<float> floatVec;
    vector<double> doubleVec;
    vector<long double> longDoubleVec;
    // for loop for each type
    for (int i = 0; i < N; ++i) {
        intVec.push_back(rand() % MAX_VALUE);
        longIntVec.push_back(rand() % MAX_VALUE);
        longLongIntVec.push_back(rand() % MAX_VALUE);
        floatVec.push_back(static_cast<float>(rand() % MAX_VALUE) / rand());
        doubleVec.push_back(static_cast<double>(rand() % MAX_VALUE) / rand());
        longDoubleVec.push_back(static_cast<long double>(rand() % MAX_VALUE) / rand());
    }

    // Create binary tree-based heaps
    BinaryTreeHeap<int> intHeap;
    BinaryTreeHeap<long int> longIntHeap;
    BinaryTreeHeap<long long int> longLongIntHeap;
    BinaryTreeHeap<float> floatHeap;
    BinaryTreeHeap<double> doubleHeap;
    BinaryTreeHeap<long double> longDoubleHeap;

    // Populate the heaps with random values
    for (const auto& elem : intVec) {
        intHeap.push(elem);
    }

    for (const auto& elem : longIntVec) {
        longIntHeap.push(elem);
    }

    for (const auto& elem : longLongIntVec) {
        longLongIntHeap.push(elem);
    }

    for (const auto& elem : floatVec) {
        floatHeap.push(elem);
    }

    for (const auto& elem : doubleVec) {
        doubleHeap.push(elem);
    }

    for (const auto& elem : longDoubleVec) {
        longDoubleHeap.push(elem);
    }

    // Look up a key in each heap
    int keyToLookup = 100;
    bool keyFound;

    // Define current node values and arbitarry node values for each data type 

    int currentNodeValue =intVec[0];
    long int currentNodeValueLong=longIntVec[1];
    long long int currentNodeValueLongLong=longLongIntVec[2];
    float currentNodeValueFloat=floatVec[3];
    double currentNodeValueDouble=doubleVec[4];
   long double currentNodeValueLongDouble=longDoubleVec[0];

    int aNodeValueInt = intVec[0];      
    long int aNodeValueLongInt = longIntVec[1];
   long long int aNodeValueLongLongInt= longLongIntVec[2];
    float aNodeValueFloat=floatVec[3];
    double aNodeValueDouble = doubleVec[4];
    long double aNodeValueLongDouble = longDoubleVec[5];

    // Record execution time and print the 100 smallest elements, height, and number of leaves for each implementation
    cout<<string(50, '-')<<"INT SECTION:"<<string(50, '-')<<endl;
    measureTimeAndPrintPriorityQueue(intVec, "int");
    measureTimeAndPrintBinaryTreeHeap(intVec, "int");

    // outputs if aNodeValue is a descendant of currnentNodeValue
    bool isDescendantInt = intHeap.descendant(currentNodeValue, aNodeValueInt);
    cout <<"\tIs " << aNodeValueInt << " a descendant of the current node in intHeap? "
              << boolalpha << isDescendantInt << "\n";
    // Outputs if the key was found in the heap
    keyFound = intHeap.lookup(keyToLookup);
    cout << "\tKey " << keyToLookup << " found in intHeap: " << boolalpha << keyFound << "\n";
    // Outputs only 10 values that are on the same level as the current node to reduce amount of space used in the terminal
    auto sameLevelNodesint = intHeap.sameLevel(currentNodeValue);
    cout << "\tFirst 10 nodes at the same level as " << currentNodeValue << " in intHeap: ";
    for (const auto& node : sameLevelNodesint)
        {cout << node << " ";
        }
    cout<<"\n";
    cout<<"\n";

    cout<<string(50, '-')<<"LONG INT SECTION:"<<string(50, '-')<<endl;
    measureTimeAndPrintPriorityQueue(longIntVec, "long int");
    measureTimeAndPrintBinaryTreeHeap(longIntVec,"long int");
    // outputs if aNodeValue is a descendant of currnentNodeValue
    bool isDescendantlongInt = longIntHeap.descendant(currentNodeValueLong, aNodeValueLongInt);
    cout << "\tIs " << aNodeValueLongInt << " a descendant of the current node in longIntHeap? "
              << boolalpha << isDescendantlongInt << "\n";
    // Outputs if the key was found in the heap
     keyFound = longIntHeap.lookup(keyToLookup);
     cout << "\tKey " << keyToLookup << " found in longIntHeap: " << boolalpha << keyFound << "\n";
    // Outputs only 10 values that are on the same level as the current node to reduce amount of space used in the terminal
auto sameLevelNodeslongInt = longIntHeap.sameLevel(currentNodeValueLong);
    cout << "\tFirst 10 nodes at the same level as " << currentNodeValueLong << " in longIntHeap: ";
    for (const auto& node : sameLevelNodeslongInt) {
        cout << node << " ";
    }
    cout << "\n";
    cout << "\n";

    cout<<string(50, '-')<<"LONG LONG INT SECTION:"<<string(50, '-')<<endl;
    measureTimeAndPrintPriorityQueue(longLongIntVec, "long long int");
    measureTimeAndPrintBinaryTreeHeap(longLongIntVec, "long long int");
    // outputs if aNodeValue is a descendant of currnentNodeValue
    bool isDescendantlongLongInt = longLongIntHeap.descendant(currentNodeValueLongLong, aNodeValueLongLongInt);
    cout << "\tIs " << aNodeValueLongLongInt << " a descendant of the current node in intHeap? "
              << boolalpha << isDescendantlongLongInt << "\n";
    // Outputs if the key was found in the heap
     keyFound = longLongIntHeap.lookup(keyToLookup);
     cout << "\tKey " << keyToLookup << " found in longLongIntHeap: " << boolalpha << keyFound << "\n";
    // Outputs only 10 values that are on the same level as the current node to reduce amount of space used in the terminal
auto sameLevelNodeslongLongInt = longLongIntHeap.sameLevel(currentNodeValueLongLong);
    cout << "\tFirst 10 nodes at the same level as " << currentNodeValueLongLong << " in longLongIntHeap: ";
    for (const auto& node : sameLevelNodeslongLongInt) {
        cout << node << " ";
    }
    cout << "\n";
    cout << "\n";

    cout<<string(50, '-')<<"FLOAT SECTION:"<<string(50, '-')<<endl;
    measureTimeAndPrintPriorityQueue(floatVec, "float");
    measureTimeAndPrintBinaryTreeHeap(floatVec, "float");
    // outputs if aNodeValue is a descendant of currnentNodeValue
    bool isDescendantfloat = floatHeap.descendant(currentNodeValueFloat, aNodeValueFloat);
    cout << "\tIs " << aNodeValueFloat << " a descendant of the current node in intHeap? "
              << boolalpha << isDescendantfloat << "\n";
    // Outputs if the key was found in the heap
    keyFound = floatHeap.lookup(keyToLookup);
     cout << "\tKey " << keyToLookup << " found in floatHeap: " << boolalpha << keyFound << "\n";
    // Outputs only 10 values that are on the same level as the current node to reduce amount of space used in the terminal
auto sameLevelNodesfloat = floatHeap.sameLevel(currentNodeValueFloat);
    cout << "\tFirst 10 nodes at the same level as " << currentNodeValueFloat << " in floatHeap: ";
    for (const auto& node : sameLevelNodesfloat) {
    cout << node << " ";
    }cout << "\n";
    cout << "\n";

    cout<<string(50, '-')<<"DOUBLE SECTION:"<<string(50, '-')<<endl;
    measureTimeAndPrintPriorityQueue(doubleVec, "double");
    measureTimeAndPrintBinaryTreeHeap(doubleVec, "double");
        // outputs if aNodeValue is a descendant of currnentNodeValue
    bool isDescendantdouble = doubleHeap.descendant(currentNodeValueDouble, aNodeValueDouble);
    cout << "\tIs " << aNodeValueDouble << " a descendant of the current node in intHeap? "
              << boolalpha << isDescendantdouble << "\n";
    // Outputs if the key was found in the heap
    keyFound = doubleHeap.lookup(keyToLookup);
     cout << "\tKey " << keyToLookup << " found in doubleHeap: " << boolalpha << keyFound << "\n";
    // Outputs only 10 values that are on the same level as the current node to reduce amount of space used in the terminal
    auto sameLevelNodesDouble = doubleHeap.sameLevel(currentNodeValueDouble);
    cout << "\tFirst 10 nodes at the same level as " << currentNodeValueDouble << " in doubleHeap: ";
    for (const auto& node : sameLevelNodesDouble) {
        cout << node << " ";
    }
    cout << "\n";

    cout<<string(50, '-')<<"LONG DOUBLE SECTION:"<<string(50, '-')<<endl;
    measureTimeAndPrintPriorityQueue(longDoubleVec, "long double");
    measureTimeAndPrintBinaryTreeHeap(longDoubleVec, "long double");
    // outputs if aNodeValue is a descendant of currnentNodeValue
    bool isDescendantlongDouble = longDoubleHeap.descendant(currentNodeValueLongDouble, aNodeValueLongDouble);
    cout << "\tIs " << aNodeValueLongDouble << " a descendant of the current node in intHeap? "
              << boolalpha << isDescendantlongDouble << "\n";
    // Outputs if the key was found in the heap
     keyFound = longDoubleHeap.lookup(keyToLookup);
     cout << "\tKey " << keyToLookup << " found in longDoubleHeap: " << boolalpha << keyFound << "\n";
    // Outputs only 10 values that are on the same level as the current node to reduce amount of space used in the terminal
auto sameLevelNodeslongDouble = longDoubleHeap.sameLevel(currentNodeValueLongDouble);
    cout << "\tFirst 10 nodes at the same level as " << currentNodeValueLongDouble << " in longDoubleHeap: ";
    for (const auto& node : sameLevelNodeslongDouble) {
    cout << node << " ";
    }cout << "\n";
    cout << "\n";
    return 0;
}
