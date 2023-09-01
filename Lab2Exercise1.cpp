/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  Purpose: 
 *  
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

double getMax(int n, double* x)
{
    double Vmax=*x;
    for(int i=1; i<n; ++i)
    {
        if(Vmax< *(x+i))
        {
            Vmax= *(x+i);
        }
    }
    return Vmax;
}

void PointergetMax(int n, double* x, double* vmax)
{
    *vmax=*x;
    for(int i=1; i<n; ++i)
    {
        if(*vmax< *(x+i))
        {
            *vmax= *(x+i);
        }
    }
    
}


void ReffgetMax(double* x, int n, double& vmax)
{
    vmax= *x;
    for(int i=1; i<n; ++i)
    {
        if(vmax< *(x+i))
        {
            vmax= *(x+i);
        }
    }

}

int main()
{
    double *x;
    int n;    
    double reffvmax;
    double* PointerSum;
    cout<<"Please enter a value for n:";
    cin>>n;

     cout<<"Enter the values for array a."<<endl;
    double a[n];
    x=a;

    for (int i=1; i<=n; ++i)
    {
        cout<<"Enter a["<<i<<"]: ";
        cin>>a[i-1];
    }

    cout<<"Entered array [";
    for (int j=0; j<n; ++j)
    {
        if (n==1){cout <<a[j];break;}
        cout<<a[j]<<", ";
    }
    cout<<"]"<<endl;

    cout<<"vmax="<<getMax(n,x)<<endl;

    ReffgetMax(x,n,reffvmax);
    cout<<"reffVmax="<<reffvmax<<endl;

    PointergetMax(n,x,PointerSum);
    cout<<"pointer vmax="<<PointerSum;


    return 0;
    
}