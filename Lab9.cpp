/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *
 *
 */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* newNode(int key) {
    Node* temp = new Node(key);
    return temp;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

Node* merge(Node* h1, Node* h2) 
{ 
	if (!h1) 
		return h2; 
	if (!h2) 
		return h1; 

	Node* temp = h1;
	while (temp->next) {
		temp = temp->next;
	}

	temp->next = h2;

	return h1; 
}

void append(Node*& head, int value) {
    if (!head) {
        head = newNode(value);
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newNode(value);
}

void quicksort(Node* low, Node* high) {
    if (low && high && low != high && low != high->next) {
        int pivot = high->data;
        Node* i = low;

        for (Node* j = low; j != high; j = j->next) {
            if (j->data < pivot) {
                swap(i->data, j->data);
                i = i->next;
            }
        }

        swap(i->data, high->data);

        quicksort(low, i);
        quicksort(i->next, high);
    }
}

void quicksort(Node*& head) {
    Node* tail = head;
    while (tail && tail->next) {
        tail = tail->next;
    }
    quicksort(head, tail);
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    append(head1, 1);
    append(head1, 3);
    append(head1, 5);

    append(head2, 0);
    append(head2, 2);
    append(head2, 4);

    cout << "List 1: ";
    printList(head1);
    cout << endl;

    cout << "List 2: ";
    printList(head2);
    cout << endl;

    Node* mergedhead = merge(head1, head2);
    cout << "Merged List: ";
    printList(mergedhead);
    cout << endl;

    quicksort(mergedhead);
    cout << "Sorted List: ";
    printList(mergedhead);
    cout << endl;

    return 0;
}
