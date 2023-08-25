/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  Purpose: In exercise 2 we are tasked to create a "Else If Statment" and a "Switch Statment" that will return the month corresponding
 *  with its month number.
 */

#include <iostream> 

using namespace std;                                           // All funtions are to be written outside of the main. 

void IfElseifStatment (int x)                                  // An Else If statement will perform an action if the conditons are true and a different action if they are false. 
{
 if (x == 1)
    cout<<"january using If/Else if statement"<<endl;          // Lines 15-39 will pass through all cases until the conditon is true and if there is an invalid number it will
    else if (x ==2)                                            // give you a notice that the number entered was invalid.
    cout<< "Febuary using If/Else if statement"<<endl;
    else if (x ==3)
    cout<< "March using If/Else if statement"<<endl;
    else if (x ==4)
    cout<< "April using If/Else if statement"<<endl;
    else if (x ==5)
    cout<< "May using If/Else if statement"<<endl;
    else if (x ==6)
    cout<< "June using If/Else if statement"<<endl;
    else if (x ==7)
    cout<< "July using If/Else if statement"<<endl;
    else if (x ==8)
    cout<< "August using If/Else if statement"<<endl;
    else if (x ==9)
    cout<< "September using If/Else if statement"<<endl;
    else if (x ==10)
    cout<< "October using If/Else if statement"<<endl;
    else if (x ==11)
    cout<< "November using If/Else if statement"<<endl;
    else if (x ==12)
    cout<< "December using If/Else if statement"<<endl;
    else 
    cout<<"invalid number"<<endl;
}

void SwitchStatement(int x)                                  // The switch statement will test the given value against a list of values until it is true. 
{                                                            // If the value is not true the default block will be executed. 
    switch (x)
        {
        case 1:                                             // Lines 45-96 is the list of values created using the switch statement and with each value
        cout<< "January using case statement"<<endl;        // if the value is entered it will output the month with that corresponding number. If one
        break;                                              // the listed values is not entered it will default to a prompt stating it is invalid. 
        
        case 2:
        cout<< "Febuary using case statement"<<endl;
        break; 

        case 3:
        cout<<"March using case statement"<<endl;
        break;

        case 4:
        cout<<"April using case statement"<<endl;
        break;

        case 5:
        cout<<"May using case statement"<<endl;
        break;

        case 6:
        cout<< "June using case statement"<<endl;
        break;

        case 7: 
        cout<<"July using case statement"<<endl;
        break;

        case 8:
        cout<<"August using case statement"<<endl;
        break;
        
        case 9:
        cout<<"September using case statement"<<endl;
        break;

        case 10:
        cout<<"October using case statement"<<endl;
        break;

        case 11:
        cout<<"November using case statement"<<endl;
        break;

        case 12:
        cout<<"December using case statement"<<endl;
        break;

        default:
        cout<<"invalid number"<<endl;
        }
}


int main () 
{
    int number;                                             // Declaring the variable as an integer.   

    cout<<"Please choose a number 1-12:";                    // Prompt asking the user to enter a number using that criteria.
    cin>>number;                                            // Stores number inputted by the user.
    IfElseifStatment(number);                               // Executes If/Else if function using the value inputted by the user.
    SwitchStatement(number);                                // Executes the Switch funtion using the value inputted by the user. 
}


