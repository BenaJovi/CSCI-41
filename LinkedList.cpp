#include <iostream>
using namespace std;


class Node 
{
public:
    int Value;
    Node* Next;

};

void printList(Node*n)
{
    while(n!=NULL) {
        cout<< n->Value <<endl;
        n=n->Next;
    }
}

void insertAtTheFront(Node**head,int newValue)
{
    // prepare a newNode
    Node* newNode= new Node();
    newNode->Value=newValue;
    // put it in fron of the current head
    newNode->Next= *head;
    // move head of the list to point ot the newNode
    *head= newNode;

}

void insertAtTheEnd(Node**head,int newValue)
{
    // prepare a newNode
    Node* newNode=new Node();
    newNode->Value=newValue;
    newNode-> Next=NULL;
    // if linked list is empty, newNode will be a head Node
    if(*head==NULL)
    {
        *head =newNode;
        return;
    }
    // find the last node
    Node* last= *head;
    while(last->Next!=NULL){
        last=last->Next;
    }
    // insert the newNode after last node (at the end)
    last->Next=newNode;

}

void insertAfter(Node*previous,int newValue)
{
    // check if previous node is NULL;
    if(previous==NULL){
        cout<<"previous cannot be NULL"<<endl;
        return;
    }
    // prepare new node
    Node* newNode= new Node();
    newNode->Value=newValue;
    // insert the newNode after the previous
    newNode->Next=previous->Next;
    previous->Next=newNode;
    
}

int main()
{
    Node* head= new Node();
    Node* second= new Node();
    Node* third= new Node();

    head->Value=1;     //head.Value = head -> Value
    head->Next=second;

    second->Value=2;
    second->Next=third;

    third->Value=3;
    third->Next=NULL;

    //insertAfter(second,-2);
    //insertAfter(third,-3);
    

    //insertAtTheEnd(&head,20);
    insertAtTheFront(&head,10);
        insertAfter(head,-1);

    //insertAtTheFront(&head,11);
    printList(head);



    return 0;
}