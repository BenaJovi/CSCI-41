

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
// Selection sort 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}
// Insertion Sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// Quick Sort
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; ++i)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start;
    int j = end;
    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
// Quick Sort
void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);
}

// Merge Sort
void merge(int array[], int const left,int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne &&
           indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <=rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray]=leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] =rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] =leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] =rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
void mergeSort(int array[],int const begin,int const end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
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
    const int n = 10000; 
    int arr[n]; 
    generateRandomArray(arr, n); 
  
    clock_t start_time, end_time; 

    // Measure the time taken by Insertion sort
    start_time = clock(); 
    insertionSort(arr, n); 
    end_time = clock(); 
    cout << "Time taken by insertion sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; 

    // Measure the time taken by selection sort 
    start_time = clock(); 
    selectionSort(arr, n); 
    end_time = clock(); 
    cout << "Time taken by selection sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; 

    // Measure the time taken by bubble sort 
    start_time = clock(); 
    bubbleSort(arr, n); 
    end_time = clock(); 
    cout << "Time taken by bubble sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; 

     // Measure the time taken by bubble sort 
    start_time = clock(); 
    quickSort(arr,0,n);
    end_time = clock(); 
    cout << "Time taken by Quick sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; 

     // Measure the time taken by bubble sort 
    start_time = clock(); 
    mergeSort(arr, 0,n-1); 
    end_time = clock(); 
    cout << "Time taken by Merge sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; 


     
 
    // Measure the time taken by other sorting algorithms 
    // ... 
 
    return 0; 
} 