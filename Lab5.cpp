/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *  
 *  
 */
#include <iostream>
using namespace std; 
#define capacity 10
class Stack
{
    public:
    int top;
    int A[capacity];
    Stack();
    //~Stack();
    bool isFull();
    bool isEmpty();
    double Pop();
    void Push(int x);
    void display();
    private:
        double* s;
        int size;
    
    
};

Stack::Stack(){
    top=0;
}

bool Stack::isEmpty()
{
    if(top==0)
        return true;
    return false;
}
bool Stack::isFull()
{
    if(top==capacity)
        return true;
    return false;
}

void Stack::Push(int x){
    if(top!=capacity){
        A[top]=x;
        top++;
        cout<<"you have pushed"<<x<<endl;
        return;
    }
    cout<<"stackoverflow"<<endl;
}

double Stack::Pop()
{
    if(!isEmpty()){
        top--;
        cout<<A[top]<<"has been popped"<<endl;
        return A[top+1];
    }
    cout<<"Stack Underflow"<<endl;
    return -999;
}


int main()
{   
    Stack stack; 
    for(int i=0; i<=90; i=i+10)
        stack.Push(i);
    cout<< stack.isFull()<<endl;
    for(int i=0; i<8; i++)
        stack.Pop();
    return 0;


}