/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  Purpose: 
 *  
 */
#include <iostream>
using namespace std;

double sumResult(double a[], double b[], int n, int m)
{
    double result=0.0;
    for(int i=1; i<n; ++i)
    {
        for( int j=1;j<m; ++j)
        {
            result +=(a[i-1])*(b[j-1]);
        }
    }
    return result;
}

double pointerSum(double a[], double b[], int n, int m, double* resultPointer)
{
    double result=0.0;
    for (int i=1; i<n; ++i)
    {
        for (int j=1; j<m; ++j)
        {
            result+= a[i-1]*b[j-1];
        }
    }
   return *resultPointer= result;
}

double ReffernceSumResult(double a[], double b[], int n, int m, double &resultReffernce)
{
    double result=0.0;
    for (int i=1; i<n; ++i)
    {
        for (int j=1; j<m; ++j)
        {
            result+= a[i-1]*b[j-1];
        }
    }
    return ref(resultReffernce)=result;
}

int main()
{
    int n;      
    cout<<"Please enter a value for n:";
    cin>>n;

    int m;
    cout<<"Please enter a value for m:";
    cin>>m;
    cout<<"Enter the values for array a."<<endl;
    double a[n];

    for (int i=1; i<=n; ++i)
    {
        cout<<"Enter a["<<i<<"]: ";
        cin>>a[i-1];
    }
    cout<<"Enter the values for array b."<<endl;
    double b[m];

    for (int i=1; i<=m; ++i)
    {
        cout<<"Enter a["<<i<<"]: ";
        cin>>b[i-1];
    }

    double resultReturn;
    double resultPointer;
    double resultRefference;

    double ResultReturn=sumResult(a,b,n,m);
    cout<<"Result:"<<ResultReturn<<endl;

    double PointerResultReturn=pointerSum(a,b,n,m,&resultPointer);
    cout<<"using pointer:"<<PointerResultReturn<<endl;

    double ReffResultReturn=ReffernceSumResult(a,b,n,m,resultRefference);
    cout<<"Using reffernce:"<<ReffResultReturn<<endl;
    
}