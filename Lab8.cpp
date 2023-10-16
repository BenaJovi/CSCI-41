/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *
 *
 */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void createList(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printForward() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

void removeDuplicates() {
        Node* current = head;
        while (current) {
            Node* runner = current->next;
            while (runner) {
                if (current->data == runner->data) {
                    Node* toDelete = runner;
                    runner = runner->next;

                    if (toDelete == head) {
                        head = toDelete->next;
                        if (head) {
                            head->prev = nullptr;
                        }
                    } else if (toDelete == tail) {
                        tail = toDelete->prev;
                        if (tail) {
                            tail->next = nullptr;
                        }
                    } else {
                        toDelete->prev->next = toDelete->next;
                        toDelete->next->prev = toDelete->prev;
                    }

                    delete toDelete;
                } else {
                    runner = runner->next;
                }
            }

            current = current->next;
        }
    }
    int countOccurrences(int value) {
        int count = 0;
        Node* current = head;

        while (current) {
            if (current->data == value) {
                count++;
            }
            current = current->next;
        }

        return count;
    }


    ~DoubleLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }
};

int main() {
    DoubleLinkedList Sortedlist;
    Sortedlist.createList(1);
    Sortedlist.createList(2);
    Sortedlist.createList(3);
    Sortedlist.createList(3);
    Sortedlist.createList(3);
    Sortedlist.createList(4);
    Sortedlist.createList(4);
    Sortedlist.createList(5);

    cout << "Original sorted List: ";
    Sortedlist.printForward();
    int num1 = Sortedlist.countOccurrences(1);
    cout << "Number of occurrences of 1: " << num1 << endl; 
    int num2 = Sortedlist.countOccurrences(3);
    cout << "Number of occurrences of 3: " << num2 << endl;
    int num3 = Sortedlist.countOccurrences(4);
    cout << "Number of occurrences of 4: " << num3 << endl; 

    cout<<"Removed duplicates list: ";
    Sortedlist.removeDuplicates();
    Sortedlist.printForward();

    cout<<endl;

    DoubleLinkedList Unortedlist;
    Unortedlist.createList(5);
    Unortedlist.createList(2);
    Unortedlist.createList(3);
    Unortedlist.createList(5);
    Unortedlist.createList(3);
    Unortedlist.createList(5);
    Unortedlist.createList(1);

    cout << "Original unsorted List: ";
    Unortedlist.printForward();
    int num4 = Unortedlist.countOccurrences(5);
    cout << "Number of occurrences of 5: " << num4 << endl; 
    int num5 = Unortedlist.countOccurrences(2);
    cout << "Number of occurrences of 2: " << num5 << endl;
    int num6 = Unortedlist.countOccurrences(3);
    cout << "Number of occurrences of 3: " << num6 << endl; 

    cout<<"Removed duplicates list: ";
    Unortedlist.removeDuplicates();
    Unortedlist.printForward();

    return 0;
}
