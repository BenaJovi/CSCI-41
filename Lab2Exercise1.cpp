/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  
 *  
 */
#include <iostream>

using namespace std;

double ReturnGetmax(double* x, int n) 
{
    double vmax = x[0];
    for (int i = 1; i < n; ++i) {
        if (x[i] > vmax) {
            vmax = x[i];
        }
    }
    return vmax;
}

void PointergetMax(int n, double* x, double* vmax)
{
    *vmax= x[0];
    for(int i=1; i<n; ++i)
    {
        if(x[i]> *vmax)
        {
            *vmax= x[i];
        }
    }
    
}

void ReffGetMax(double* x, int n, double& vmax) 
{
    vmax = x[0];
    for (int i = 1; i < n; ++i) {
        if (x[i] > vmax) {
            vmax = x[i];
        }
    }
}

int main()
{
    int n;    
    cout<<"Please enter a value for n:";
    cin>>n;
    cout<<"Enter the values for array a."<<endl;

    double* a= new double[n];

    for (int i=1; i<=n; ++i)
    {
        cout<<"Enter a["<<i<<"]: ";
        cin>>a[i-1];
    }

    cout<<"Entered array [";
    for (int j=0; j<n; ++j)
    {
        if (n==1){cout <<a[j];break;}
        cout<<a[j]<<",";
    }
    cout<<"]"<<endl;

    double max1 = ReturnGetmax(a, n);

    double max2;
    PointergetMax(n,a,&max2); 

    double max3;
    ReffGetMax(a, n, max3); 

    cout << "Maximum value (using return): " << max1 << endl;
    cout << "Maximum value (using pointer): " << max2 << endl;
    cout << "Maximum value (using reference): " << max3 << endl;

    delete[] a;
    return 0;
    
}