/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  
 *  
 */

#include <iostream> 
using namespace std;

//bubble sort
void bubbleSort(int arr[], int n )
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
// selection sort
/*int minIndex(int a[], int i, int j)
{
    if(i==j)
    return i;

    int k =minIndex(a, i+1,j);
    return (a[i]<a[k])? i:k;
}
void selectionSort(int a[],int n, int index=0)
{
    if (index==0)
    return;
   int k= minIndex(a, index, n-1);
   if (k !=index)
   swap(a[k],a[index]);
   selectionSort(a,n,index+1);

}*/



// insertion sort



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
    arr[i]=rand()%10; 
   cout<<"Elements of the array:"<<endl;
   for(int i=0;i<size;i++)
   cout<<"Elements no "<<i+1<<":"<<arr[i]<<endl;

    int n = sizeof(arr)/sizeof(arr[0]); 
    
    bubbleSort(arr, n);                                //bubble sort
    cout<<"sorted array using bubble sort:"<<endl;
    printArray(arr,n);
   
    /*selectionSort(arr,n);
    cout<<"Sorted:"<<endl;
    printArray(arr,n);*/

   return 0;
}