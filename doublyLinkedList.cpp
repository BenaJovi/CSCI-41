#include <iostream>
using namespace std;


struct Node{
    int value;
   struct Node* next;
   struct Node* previous;
};

void printFoward(Node*head)
{
    Node* traverse=head;
    while(traverse!=nullptr){
        cout<<traverse->value<<endl;
        traverse=traverse->next;
    }

}




void delteNode(){

}

int main()
{
    Node* head;
    Node* tail;
    //First node
    Node* node= new Node();
    node->value =4;
    node-> next= nullptr;
    node-> previous=nullptr;
    head = node;
    tail=node;
    // second node
    node=new Node();
    node-> value = 5;
    node-> next=nullptr;
    node-> previous= tail;
    tail->next=node;
    tail=node; 

    node=new Node();
    node-> value = 6;
    node-> next=nullptr;
    node-> previous= tail;
    tail->next=node;
    tail=node;

    node=new Node();
    node-> value = 7;
    node-> next=nullptr;
    node-> previous= tail;
    tail->next=node;
    tail=node;

    printFoward(head);
    //printBackward(tail);

    return 0;
}