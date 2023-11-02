#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include<ctime>
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
        cout << arr[i] << " ";
        rowCount++;

        if (rowCount == perRow) {
            cout << endl;
            rowCount = 0;
        }
    }
    cout << endl;
}

int main() {
    std::vector<int> arr;
    int arraySize;  // Added variable to hold user input
    const int sortingAlgorithms[] = {1, 2, 3, 4, 5}; // Sorting Algorithms
    const int arrayTypes[] = {1, 2, 3, 4}; // Array Types

    std::cout << "Enter the array size: ";
    std::cin >> arraySize;

    for (int algorithm : sortingAlgorithms) {
        for (int type : arrayTypes) {
            arr.resize(arraySize);
            generateArray(arr, type);

            std::cout << "Array Size: " << arraySize << ", Sorting Algorithm: " << algorithm << ", Array Type: " << type << std::endl;
            std::cout << "Before Sorting:" << std::endl;
            printArray(arr, 10, 10);

            std::vector<int> copy = arr; // Create a copy of the original array for each sorting algorithm
            int start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();

            switch(algorithm) {
                case 1: // Insertion Sort
                    std::cout << "Using Insertion Sort:" << std::endl;
                    insertionSort(copy);
                    break;
                case 2: // Selection Sort
                    std::cout << "Using Selection Sort:" << std::endl;
                    selectionSort(copy);
                    break;
                case 3: // Bubble Sort
                    std::cout << "Using Bubble Sort:" << std::endl;
                    bubbleSort(copy);
                    break;
                case 4: // Quick Sort
                    std::cout << "Using Quick Sort:" << std::endl;
                    quickSort(copy, 0, copy.size() - 1);
                    break;
                case 5: // Merge Sort
                    std::cout << "Using Merge Sort:" << std::endl;
                    mergeSort(copy, 0, copy.size() - 1);
                    break;
            }

            int end = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();

            std::cout << "After Sorting:" << std::endl;
            printArray(copy, 10, 10);

            std::cout << "Time taken: " << end - start << " milliseconds" << std::endl;

            arr.clear();
        }
    }

    return 0;
}





