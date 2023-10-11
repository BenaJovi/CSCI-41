

#include <iostream> 
#include <ctime> 
using namespace std; 
 
// Function to perform bubble sort 
void bubbleSort(int arr[], int n) 
{ 
    for (int i = 0; i < n - 1; i++) 
    { 
        for (int j = 0; j < n - i - 1; j++) 
        { 
            if (arr[j] > arr[j + 1]) 
            { 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
} 
 
// Function to generate an array of random integers 
void generateRandomArray(int arr[], int n) 
{ 
    srand(time(NULL)); 
    for (int i = 0; i < n; i++) 
    { 
        arr[i] = rand() % 100; 
    } 
} 
 
// Function to print an array 
void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
} 
 
int main() 
{ 
    const int n = 100; 
    int arr[n]; 
    generateRandomArray(arr, n); 
 
    clock_t start_time, end_time; 
 
    // Measure the time taken by bubble sort 
    start_time = clock(); 
    bubbleSort(arr, n); 
    end_time = clock(); 
    cout << "Time taken by bubble sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; 
 
    // Measure the time taken by other sorting algorithms 
    // ... 
 
    return 0; 
} 