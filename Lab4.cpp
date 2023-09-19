/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  
 *  
 */

#include <iostream>
using namespace std;
#define MAX_SIZE 100
//Q1
void printNaturalNumbers(int n)
{
    if (n>0)
    {
        printNaturalNumbers(n-1);
        cout<<n<<" ";
    }
}
//Q2
int calculateFactorial(int n)
{   
    if(n==0 || n==1)
    {
    return 1;
    }
    else
    {
        return n*calculateFactorial(n-1);
    }
}
//Q3
int calculateFibonacci(int n)
{
    if(n<=1)
    
        return n;
        return calculateFibonacci(n-1)+calculateFibonacci(n-2);
    
}
void printFibonacci(int n)
{
    for(int i=1; i<=n; ++i)
    {
        cout<<calculateFibonacci(i)<<" ";
    }
    cout<<endl;
}
//Q4
void printArray(int arr[], int size, int index) {
    if (index >= size) 
    {
        return;
    }
    
    cout << arr[index] << " ";
    printArray(arr, size, index + 1);
}
//Q5
int countDigits(int number) 
{
    if (number < 10) 
    {
        return 1;
    }
    
    return 1 + countDigits(number / 10);
}
//Q6
int gcd(int a, int b) 
{
    if (b == 0) 
    {
        return a;
    }
    return gcd(b, a % b);
}
//Q8
int findLargest(int arr[], int size) 
{
    if (size == 1) 
    {
        return arr[0];
    }
    
    int maxInRest = findLargest(arr, size - 1);
    
    return (maxInRest > arr[size - 1]) ? maxInRest : arr[size - 1];
}
//Q9
string decimalToBinary(int decimal) 
{
    if (decimal == 0) {
        return "0";
    }
    if (decimal == 1) {
        return "1";
    }
    return decimalToBinary(decimal / 2) + to_string(decimal % 2);
}
//Q10
bool isPrime(int n, int divisor = 2) 
{
    if (n <= 2) {
        return (n == 2);
    }
    if (n % divisor == 0) {
        return false;
    }
    if (divisor * divisor > n) {
        return true;
    }
    return isPrime(n, divisor + 1);
}


int main()
{
    
    //Q1
    cout<<"Question 1:"<<endl;
    cout<<"This will print all the natural numbers leading up to 7"<<endl;
    cout<<"the natural numbers are: "<<endl;
    printNaturalNumbers(7);
    cout<<endl;
    cout<<"****************"<<endl;

    //Q2
    cout<<"Question 2:"<<endl;
    cout << "The Factorial of number 5 is: " << calculateFactorial(5) << endl;
    cout<<"****************"<<endl;

    //Q3
    cout<<"Question 3:"<<endl;
    cout<<"This will print the fibonacci sequence for the number you enter."<<endl;

    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    cout << "The Series using the fibonacci sequence for "<<num<<" is : ";
    printFibonacci(num);
    cout<<"****************"<<endl;

    //Q4
    cout<<"Question 4:"<<endl;
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Array elements: ";
    printArray(arr1, size1, 0);
    cout<<endl;
    cout<<"****************"<<endl;

    //Q5
    cout<<"Question 5:"<<endl;
    int number;
    cout << "Enter a number you would like how many digits are in that number: ";
    cin >> number;
    int numDigits = countDigits(number);
    cout << "The number of digits in the number " << number << " is: " << numDigits << endl;
    cout<<"****************"<<endl;

    //Q6
    cout<<"Question 6:"<<endl;
    int num1, num2;
    cout<<"You will be able to find the GCD of two numbers"<<endl;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    int result = gcd(num1, num2);
    cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    cout<<"****************"<<endl;

    //Q8
    cout<<"Question 8:"<<endl;
    int arr[] = {12, 45, 67, 89, 344, 100, 56};
    int size = sizeof(arr) / sizeof(arr[0]);
    int largest = findLargest(arr, size);
    cout << "The largest element in the array is: " << largest << endl;
    cout<<"****************"<<endl;


    //Q9
    cout<<"Question 9:"<<endl;
    int decimal;
    cout<<"converts decimal numbers into binary numbers."<<endl;
    cout << "Enter a decimal number: ";
    cin >> decimal;
    string binary = decimalToBinary(decimal);
    cout << "Binary representation: " << binary << endl;
    cout<<"****************"<<endl;
    
    //Q10
    cout<<"Question 10:"<<endl;
    int Primenumber;
    cout<<"Enter a positive integer to check if it is a prime number:";
    cin>>Primenumber;
    if (Primenumber < 2) 
    {
        cout << Primenumber << " is not a prime number." << endl;
    } 
    else 
    {
        if (isPrime(Primenumber)) 
        {
            cout << Primenumber << " is a prime number." << endl;
        } 
        else 
        {
            cout << Primenumber << " is not a prime number." << endl;
        }
    }
    cout<<"****************"<<endl;
    return 0;
}