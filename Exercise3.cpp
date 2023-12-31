/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  Purpose: In exercise 3 we are tasked to created "For Loop" functions and "while Loop" functions for each given summation problem
 */

#include <iostream>
#include <cmath>
#include <cctype>


using namespace std;

double x1For(int n)                                 // For lines 11-175 are all the functions using a while loop and a for loop.
{                                                   // Each function will execute a summation of "n" inputted by the user and will
    double sum=0.0;                                 // perform each expression that is embedd within the function and return the value.
    for ( int i =1; i <= n; ++i)                    
    {
        sum += static_cast<double>(i)/(i+1);       
    }
    return sum;                                     
}

double x1While(int n )                              
{                                                   
    double sum=0.0;                                 
    int i=1;                                        
    while(i<=n)
    {
        sum +=static_cast<double>(i)/(i+1);         
        i++;
    }
    return sum;                                     
}

double x2For(int n)                                
{                                                  
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

char ch;                                                            // Declares character for repeat function. 
void repeat();                                                      // Protype for repeat function.

int main()                                                          // In the main there is an if else statement that checks if the value of "n" is valid.
{                                                                   // "n" must be greater than 0.
    int n;      
    cout<<"Please enter a value for n:";
    cin>>n;

    if (n<=0)
    {
        cout<<"please enter a positive number"<<endl;               
    }                                                               
    else
    {                                                                       // If the number entered is valid it will call each function with the number entered 
        double x1summation= x1For(n);                                       // each function will be executed and will return the output of each function/expression
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
    repeat();
}

void repeat()                                                                  // This function is something I added so you can perform the code multiple times 
{                                                                              // with one run. But, for some reason if you want to exit the program you
    do                                                                         // have to enter N, how ever many times you ran the code. So if you entered Y 2 times 
    {                                                                          // you need to enter N 2 times to exit.
        cout << "\nWould you like to try another equation? (Y/N)\n";
        cin >> ch;
        cout << endl;
        ch = tolower (ch);  //changes ch to lowercase to simplify checks
        if (ch == 'y')
        {
            main();
            repeat();
        }
        //ends program
        else if (ch == 'n')
        {
            break;
        }
        //response to invalid entry
        else
            cout << "Input not recognized, try again. (Y/N)";
    }while(!(ch == 'y' || ch == 'n'));
}
