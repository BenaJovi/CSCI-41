/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  Purpose: 
 *  
 */
#include <iostream>
using namespace std;

double getMax(double* x, int n)
{
   
}

void getMax(int n, double* maxPtr)
{
    
}



void getMax(double* x, int n, double& vmax)
{
    vmax=x[0];
    for (int i=0; i<n; ++i)
    {
        if(x[i]>vmax)
        {
            vmax=x[i];
        }
    }

}

int main()
{
    int n;      
    cout<<"Please enter a value for n:";
    cin>>n;

     cout<<"Enter the values for array a."<<endl;
    double a[n];

    for (int i=1; i<=n; ++i)
    {
        cout<<"Enter a["<<i<<"]: ";
        cin>>a[i-1];
    }
    
}