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
    for(int i=0; i<n; ++i)
    {
        for( int j=0;j<m; ++j)
        {
            result +=(a[i])*(b[j]);
        }
    }
    return result;
}

double pointerSum(double a[], double b[], int n, int m, double* resultPointer)
{
    double result=0.0;
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<m; ++j)
        {
            result+= a[i]*b[j];
        }
    }
   return *resultPointer= result;
}

double ReffernceSumResult(double a[], double b[], int n, int m, double &resultReffernce)
{
    double result=0.0;
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<m; ++j)
        {
            result+= a[i]*b[j];
        }
    }
    return ref(resultReffernce)=result;
}

int main()
{
    int n=5;      
    //cout<<"Please enter a value for n:";
    //cin>>n;

    int m=5;
    //cout<<"Please enter a value for m:";
    //cin>>m;

    double a[5]={1,2,3,4,5};
    double b[5]={1,2,3,4,5};

    for (int i=1; i<=(n); ++i)
    {
        
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