/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  
 *  
 */

#include <iostream> 
using namespace std;






// Print array function
void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}



int main(){
    int size=5;                                         //creates an a array with size of ten using randomly generated numbers
   int arr[size];
   cout<<"Array size is set to 10"<<endl;
   for(int i=0;i<size;i++)
    arr[i]=rand()%100; 
   cout<<"Elements of the array:"<<endl;
   for(int i=0;i<size;i++)
   cout<<"Elements no "<<i+1<<":"<<arr[i]<<endl;

    int n = sizeof(arr)/sizeof(arr[0]); 
}