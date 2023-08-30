/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  Purpose: In exercise 1 we are tasked to create a tenary function and a If statement function that will state whether a number is
 *  odd or even.
 */

#include <iostream>
using namespace std;

void  TernaryFunction(int x)                                                                                          // A tenary function is an if else statement in one line. 
{
cout<<x<< (x %2==0 ? " is an Even number using ternary function":" is an Odd number using ternary function")<<endl;   // The ternary function checks if the value is even with the modulo operator 
}                                                                                                                     // by checking if the remainder of x is equal to 0, if not then it is odd.

void IfStatement (int x)                                                                                              // An If statement will perform an action if it is true 
{                                                                                                   

    if (x %2 == 0)                                                                                                    // The modulo operator is checking if the reaminder of x is equal to 0
    {                                                                                                                 // if it is equal to 0 it deems it even, if it is not 0 it deems it odd.
        cout<<x<<" is an Even number using else/if statment "<<endl;                                                  // This prompt will be given if it is even.
    }
    if (x %2 !=0)
    {
        cout<<x<<" is an Odd number using else/if statment"<<endl;                                                    // This prompt will be given if it is odd.
    
    }
}

int main()
{
    int i;                                                                                                            // Declaring the integer i that will be inputted by the user.
    cout<<"Please enter an integer:";                                                                                 // Prompt asking the user to enter a integer value.
    cin>>i;                                                                                                           // Stores the input value of i. 
    TernaryFunction(i);                                                                                               // Executes TernaryFunction with the given value of i.
    IfStatement(i);                                                                                                   // Executes IfStatement with the given value of i.
   return 0;
}

