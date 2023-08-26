/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  Purpose: In exercise 3 we are tasked to created "For Loop" functions and "while Loop" functions for each given summation problem
 */

#include <iostream>
#include <cmath>

using namespace std;

double x1For(int n)                                 // This function will calculate the summation using a for loop of the integer entered "n"
{                                                   // and will perform the stated expression in line 16.
    double sum=0.0; 
    for ( int i =1; i <= n; ++i)                    // A for loop that will output the summation of the entered value.
    {
        sum += static_cast<double>(i)/(i+1);        // Operation given by the problem statement. 
    }
    return sum;                                     // Returns the sum of the summation value after the operation has been executed.
}

double x1While(int n )                              // This function will calculate the summation using a While loop for an integer entered "n"
{                                                   // and will perform the stated expession in line 27.
    double sum=0.0;                                 
    int i=1;                                        // The sum and integer count are declared before the while statement, stating i must be less than or eqaul to n.
    while(i<=n)
    {
        sum +=static_cast<double>(i)/(i+1);         // the sum will equal the summation of n and will execute this expression. 
        i++;
    }
    return sum;                                     
}

double x2For(int n)                                // For this expression we will be outputting two summations one for i and one for j using a for loop
{                                                  // and a nested for loop.
    double sum=0.0; 
    for(int i=1; i<=n; ++i)
    {
        for (int j=i; j<=n; ++j)
        {
            sum +=(i*j);
        }
    }
    return sum;
}

double x2While(int n)
{
    int i=1;
    double sum=0.0;
    
    while(i<=n)
    {
        int j=i;
            while(j<=n)
            {
                sum += (i * j);
                j++;
            }
        i++;
    }
    return sum;
}

double x3For(int n )
{
    double sum=0.0;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            for(int k=1; k<=n; ++k)
            {
            sum +=static_cast<double>(1/sqrt(i+j+k));
            }
        }
    }
    
    return sum;
}

double x3While(int n)
{
    int i = 1, j, k;
    double sum = 0.0;

    while (i <= n) {
        j = 1;
        while (j <= n) {
            k = 1;
            while (k <= n) {
                sum += 1.0 / sqrt(i + j + k);
                k++;
            }
            j++;
        }
        i++;
    }
    return sum;
}

double x4For(int n)
{
    double product=1;
    for(int i=1; i<=n; ++i)
    {
        int sum=0;
        for(int j=1; j<=n; ++j)
        {
            sum +=j;
        }
        product *= (i*sum);
    }
 
    return product;
}

double x4While(int n) 
{
    double product = 1.0;
    int i = 1;

    while (i <= n) 
    {
        double sum = 0.0;
        int j = 1;

        while (j <= n) 
        {
            sum += j;
            j++;
        }

        product *= (i*sum);
        i++;
    }
    return product;
}

double x5For(int n)
{
    int sum=0;
    for (int i=1; i<=n; ++i)
    {
        
        if(i%2!=0)
        {
        
        sum+=4;
        }
        else 
        {
            sum+=9;
        }
    }
    return sum;
} 

double x5While(int n)
{
    int i=1;
    double sum=0;
    while(i<=n)
    {
        if(i%2==0)
        {
            sum+=4;
        }
        else
        {
            sum+=9;
        }
        i++;
    }
    return sum;
}

int main()
{
    int n;
    cout<<"Please nter a value for n:";
    cin>>n;

    if (n<=0)
    {
        cout<<"please enter a positive number"<<endl;
    }
    else
    {
        double x1summation= x1For(n);
        cout<<"When n="<<n<<" x1 For Loop outputs:"<<x1summation<<endl;

        double x1WhileSummation=x1While(n);
        cout<<"When n="<<n<< " x1 While Loop Outputs:"<<x1WhileSummation<<endl;

        double x2forProduct= x2For(n);
        cout<<"When n="<<n<<" x2 For Loop Outputs:"<<x2forProduct<<endl;

        double x2whileProduct=x2While(n);
        cout<<"When n="<<n<<" x2 While Loop Outputs:"<<x2whileProduct<<endl;

        double x3squareroot=x3For(n);
        cout<<"When n="<<n<<" x3 For Loop Outputs:"<<x3squareroot<<endl;

        double x3whileSqaureRoot=x3While(n);
        cout<<"When n="<<n<<" x3 While Loop Outputs:"<<x3whileSqaureRoot<<endl;

        double x4ProdSum= x4For(n);
        cout<<"When n="<<n<<" x4 For Loop Outputs:"<<x4ProdSum<<endl;

        double x4whileProdSum=x4While(n);
        cout<<"When n="<<n<<" x4 While Loop Outputs:"<<x4whileProdSum<<endl;

        double x5forSummation=x5For(n);
        cout<<"When n="<<n<<" x5 For Loop Outputs:"<<x5forSummation<<endl;

        double x5whileSummation=x5While(n);
        cout<<"When n="<<n<<" x5 While Loop Outputs:"<<x5whileSummation<<endl;
    }
}