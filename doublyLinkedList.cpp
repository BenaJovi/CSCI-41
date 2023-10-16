#include <iostream>
using namespace std;


struct Node {
	double data;
    int count;
	struct Node* next;
	struct Node* prev;
};

void printFoward(Node*head)
{
    Node* traverse=head;
    while(traverse!=nullptr){
        cout<<traverse->data<<endl;
        traverse=traverse->next;
    }

}
void deleteNode(struct Node** head_ref, struct Node* del)
{
	// base case
	if (*head_ref == NULL || del == NULL)
		return;

	// If node to be deleted is head node
	if (*head_ref == del)
		*head_ref = del->next;

	// Change next only if node to be deleted
	// is NOT the last node
	if (del->next != NULL)
		del->next->prev = del->prev;

	// Change prev only if node to be deleted
	// is NOT the first node
	if (del->prev != NULL)
		del->prev->next = del->next;

	// Finally, free the memory occupied by del
	free(del);
}
// function to remove duplicates from
// an unsorted doubly linked list
void removeDuplicates(struct Node** head_ref)
{
	// if DLL is empty or if it contains only
	// a single node
	if ((*head_ref) == NULL || 
		(*head_ref)->next == NULL)
		return;

	struct Node* ptr1, *ptr2;

	// pick elements one by one
	for (ptr1 = *head_ref; ptr1 != NULL; ptr1 = ptr1->next) {
		ptr2 = ptr1->next;

		// Compare the picked element with the
		// rest of the elements
		while (ptr2 != NULL) {

			// if duplicate, then delete it
			if (ptr1->data == ptr2->data) {

				// store pointer to the node next to 'ptr2'
				struct Node* next = ptr2->next;

				// delete node pointed to by 'ptr2'
				deleteNode(head_ref, ptr2);

				// update 'ptr2'
				ptr2 = next;
			}

			// else simply move to the next node
			else
				ptr2 = ptr2->next;
		}
	}
}

void getCount(Node* head)
{
    Node* current = head;
    int count=0;
    while (current) {
        cout << "(" << current->data << "," << current->count << ")";
        current = current->next;
    }
    cout << endl;
}


int main()
{

    Node* head;
    Node* tail;
    //First node
    Node* node= new Node();
    node->data =10;
    node-> next= nullptr;
    node-> prev=nullptr;
    head = node;
    tail=node;
    // second node
    node=new Node();
    node-> data = 5;
    node-> next=nullptr;
    node-> prev= tail;
    tail->next=node;
    tail=node; 

    node=new Node();
    node-> data = 15;
    node-> next=nullptr;
    node-> prev= tail;
    tail->next=node;
    tail=node;

    node=new Node();
    node-> data = 15;
    node-> next=nullptr;
    node-> prev= tail;
    tail->next=node;
    tail=node;

    node=new Node();
    node-> data = 7;
    node-> next=nullptr;
    node-> prev= tail;
    tail->next=node;
    tail=node;

    node=new Node();
    node-> data = 7;
    node-> next=nullptr;
    node-> prev= tail;
    tail->next=node;
    tail=node;

    node=new Node();
    node-> data = 7;
    node-> next=nullptr;
    node-> prev= tail;
    tail->next=node;
    tail=node;

    cout << "Original Doubly linked list:\n";
	printFoward(head);
    getCount(head);

	/* remove duplicate nodes */
	removeDuplicates(&head);

	cout << "\nDoubly linked list after "
			"removing duplicates:\n";
	printFoward(head);
    getCount(head);

    

    return 0;
}