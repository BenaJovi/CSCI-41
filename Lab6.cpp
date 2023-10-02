/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  
 *  
 */

#include <iostream> 
using namespace std;

//bubble sort
/*void bubbleSort(int arr[], int n )
{
    if (n==1)
    return;
    int count=0;

    for(int i=0;i<n-1;++i)
    
        if (arr[i]> arr[i+1])
        {
            swap(arr[i], arr[i+1]);
            count ++;
        }
        if (count==0)
        return;
        bubbleSort(arr, n-1);
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
}*/
int binarySearchIteratively(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
}
// Binary Recursive
int binarySearchRecursive(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearchRecursive(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearchRecursive(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
// Print array function
void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main()
{
   int size=10;                                         //creates an a array with size of ten using randomly generated numbers
   int arr[size];
   cout<<"Array size is set to 10"<<endl;
   for(int i=0;i<size;i++)
    arr[i]=rand()%100; 
   cout<<"Elements of the array:"<<endl;
   for(int i=0;i<size;i++)
   cout<<"Elements no "<<i+1<<":"<<arr[i]<<endl;

    int n = sizeof(arr)/sizeof(arr[0]); 
    
   /*bubbleSort(arr, n);                                //bubble sort
    cout<<"Sorted using bubble sort:"<<endl;
    printArray(arr,n);
   
    selectionSort(arr,n);
    cout<<"Sorted using selection sort:"<<endl;        // selection sort
    printArray(arr,n);

    insertionSort(arr,n);
    cout<<"Sorted using insertion sort"<<endl;         // insertion sort
    printArray(arr,n);*/

    int x;                                             
    cout<<"input a number to check if it is in the array"<<endl;
    cin>>x;

    int resultIteratively = binarySearchIteratively(arr, 0, n - 1, x);                               // Binary iteratively search
    (resultIteratively == -1)
    ? cout << "Iteratively: Element is not present in array": cout << "Iteratively: Element is present at index " << resultIteratively;
    cout<<endl;

    int resultRecursive = binarySearchRecursive(arr, 0, n - 1, x);                                 // Binary Recursive search
    (resultRecursive == -1)
        ? cout << "Recurively: Element is not present in array": cout << "Recursively: Element is present at index " << resultRecursive;
        cout<<endl;






   return 0;
}