#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

// Sorting Algorithms
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high-1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
void shuffleTenPercent(vector<int>& arr) {
    int n = arr.size();
    int shuffleCount = n * 0.1;

    random_device rd;
    mt19937 g(rd());

    for (int i = 0; i < shuffleCount; ++i) {
        int idx1 = uniform_int_distribution<>(0, n - 1)(g);
        int idx2 = uniform_int_distribution<>(0, n - 1)(g);
        swap(arr[idx1], arr[idx2]);
    }
}
// Array Types
void generateArray(vector<int>& arr, int type) {
    int n = arr.size();

    switch(type) {
        case 1: // Array already sorted (in-order)
            for (int i = 0; i < n; ++i) {
                arr[i] = i + 1;
            }
            break;
        case 2: // Array sorted but shuffled at 10%
            for (int i = 0; i < n; ++i) {
                arr[i] = i + 1;
            }
            shuffleTenPercent(arr);
            break;
        case 3: // Array completely shuffled (random numbers)
            for (int i = 0; i < n; ++i) {
                arr[i] = rand() % 1000; // You can adjust the range of random numbers here
            }
            break;
        case 4: // Array in reverse order
            for (int i = 0; i < n; ++i) {
                arr[i] = n - i;
            }
            break;
    }
}

void printArray(const vector<int>& arr, int numColumns, int numRows) {
    int n = arr.size();
    int perRow = numColumns;
    int rowCount = 0;

    for (int i = 0; i < min(n, numColumns * numRows); ++i) {
        cout << setw(7) << arr[i]; // Set a fixed width of 4 for each element
        rowCount++;

        if (rowCount == perRow) {
            cout << endl;
            rowCount = 0;
        }
    }
    cout << endl;
}


void startOfCode(){
    cout<<string(70, '*')<<endl;
    cout<<"This is the start of the code where each sorting algortihm\n";
    cout<<"will be used in 4 different array types and the array size\n";
    cout<<"will be selected by the user."<<endl;
    cout<<string(70, '*')<<endl;
    return;
}

void spacer(){
    cout<<string(70,'-')<<endl;
    return;
}

void endOfCode(){
    cout<<string(70, '*')<<endl;
    cout<<setw(35)<<"End of Code"<<endl;
    cout<<string(70, '*')<<endl;
    return;
}

void algorithmMenu(int& chosenAlgorithm) {
    cout << "\nSorting Algorithm Menu:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Merge Sort\n";
    cout << "0. Exit Program\n";
    cout << "Enter your choice: ";
    cin >> chosenAlgorithm;
}

void sizeMenu(int& arraySize, bool& returnToAlgorithmMenu) {
    cout << "\nArray Size Menu:\n";
    cout << "1. Array Size 10000\n";
    cout << "2. Array Size 100000\n";
    cout << "3. Array Size 1000000\n";
    cout << "0. Return to Algorithm Menu\n";
    cout << "Enter your choice: ";
    cin >> arraySize;

    if (arraySize == 0) {
        returnToAlgorithmMenu = true;
    }
}

int main() {
    vector<int> arr;
    int arraySize; 
    int chosenAlgorithm;
    const int arrayTypes[] = {1, 2, 3, 4}; // Array Types
    clock_t start_time, end_time;

    startOfCode();

    while (true) {
        algorithmMenu(chosenAlgorithm);

        if (chosenAlgorithm == 0) {
            endOfCode();
            return 0;
        }

        bool returnToAlgorithmMenu = false;

        while (!returnToAlgorithmMenu) {
            sizeMenu(arraySize, returnToAlgorithmMenu);

            if (returnToAlgorithmMenu) {
                break;
            }

            for (int type : arrayTypes) {
                arr.resize(arraySize);
                generateArray(arr, type);
                spacer();
            switch(arraySize){
                case 1: arraySize=10000;
                        break;
                case 2: arraySize=100000;
                        break;
                case 3: arraySize=1000000;
                        break;
            }
                cout << "Array Size: " << arraySize << ", Sorting Algorithm: " << chosenAlgorithm << ", Array Type: " << type << endl;
                cout << "Before Sorting:" << endl;
                printArray(arr, 10, 10);

                vector<int> copy = arr;
                start_time = clock();             

                switch(chosenAlgorithm) {
                    case 1: // Insertion Sort            
                        cout << "Using Insertion Sort:" << endl;
                        start_time = clock(); 
                        insertionSort(copy);
                        end_time = clock();
                        cout << "Time taken: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl;
                        break;
                    case 2: // Selection Sort
                        cout << "Using Selection Sort:" << endl;
                        start_time = clock(); 
                        selectionSort(copy);
                        end_time = clock();
                        cout << "Time taken: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; 
                        break;
                    case 3: // Bubble Sort
                        cout << "Using Bubble Sort:" << endl;
                        start_time = clock(); 
                        bubbleSort(copy);
                        end_time = clock();
                        cout << "Time taken: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl;
                        break;
                    case 4: // Quick Sort
                        cout << "Using Quick Sort:" << endl;
                        start_time = clock(); 
                        quickSort(copy, 0, copy.size() - 1);
                        end_time = clock();
                        cout << "Time taken: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl;
                        break;
                    case 5: // Merge Sort
                        cout << "Using Merge Sort:" << endl;
                        start_time = clock(); 
                        mergeSort(copy, 0, copy.size() - 1);
                        end_time = clock();
                        cout << "Time taken: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl;
                        break;
                }

                end_time = clock(); 

                cout << "After Sorting:" << endl;
                printArray(copy, 10, 10);

                cout << "Time taken: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; 

                arr.clear();
            }
        }
    }

    endOfCode();

    return 0;
}


