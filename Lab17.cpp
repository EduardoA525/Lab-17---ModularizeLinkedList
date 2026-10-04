//Eduardo Avila
//COMSC - 210 - 5293
//Lab 17 - Modularize Linked List

//I am passing by reference so I can easily modify the head pointer
//without dealing with copies. 

#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    float value;
    Node *next;
};

//Prototypes
void addNodeFront(Node *&);
void addNodeTail(Node *&);
void deleteNode(Node *&);
void insertNode(Node *&);
void deleteList(Node *&);
void output(Node *);

int main() {
    Node *head = nullptr;
    int menuChoice;

    do {
        cout << "\n > Choose a number to do < " << endl;
        cout << "-------------------------" << endl;
        cout << "1. Add node to front" << endl;
        cout << "2. Add node to end" << endl;
        cout << "3. Delete a node" << endl;
        cout << "4. Insert a node" << endl;
        cout << "5. Delete the list" << endl;
        cout << "6. Print the list" << endl;
        cout << "7. Exit" << endl;
        cout << "Choice --> ";
        cin >> menuChoice;

        switch (menuChoice) {
            case 1:
                addNodeFront(head);
                break;

            case 2:
                addNodeTail(head);
                break;

            case 3:
                deleteNode(head);
                break;

            case 4:
                insertNode(head);
                break;
            
            case 5:
                deleteList(head);
                break;
            
            case 6:
                output(head);
                break;
            
            case 7:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter 1-7.\n";
        }

    } while (menuChoice != 7); 

    return 0;
}

//Definitions
void addNodeFront(Node *&head){

    Node *newVal = new Node;

    cout << "Enter a valid value: ";
    cin >> newVal -> value;

    newVal->next = head;
    head = newVal;
}

void addNodeTail(Node *&head){

    Node *newVal = new Node;

    cout << "Enter a valid value: ";
    cin >> newVal -> value;

    newVal -> next = nullptr;

    if (!head){
        head = newVal;
        return;
    }

    Node *current = head;

    while (current -> next) {
        current = current -> next;
    }

    current -> next = newVal;
}

void deleteNode(Node *&head){

    if (!head){
        cout << "There is nothing to delete." << endl;
        return;
    }

    output(head);

    int entry;
    cout << "Which node do you want to delete?";
    cin >> entry;

    Node *current = head;
    Node *prev = nullptr;

    for (int i = 0; i < (entry - 1); i++){
        prev = current;
        current = current -> next;
    }

    if (prev == nullptr){
        head = current -> next;
    }
    else{
        prev -> next = current -> next;
    }

    delete current;
    current = nullptr;
}

void insertNode(Node *&head){

    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    output(head);

    int entry;
    float value; //in case of decimal number

    cout << "After which node to insert value: ";
    cin >> entry;

    cout << "Enter a valid value: ";
    cin >> value;

    Node *current = head;
    Node *prev = nullptr;

    for (int i = 0; i < entry; i++){
        prev = current;
        current = current -> next;
    }

    Node *newnode = new Node;
    newnode -> value = value;
    newnode -> next = current;

    if (prev == nullptr){
        head = newnode;
    }
    else {
        prev -> next = newnode;
    }
}

void deleteList(Node *&head){

    if (!head){
        cout << "There is nothing to delete." << endl;
        return;
    }

    Node *current = head;

    while (current){
        head = current -> next;
        delete current;
        current = head;
    }

    head = nullptr;

    cout << "\nList deleted." << endl;
}

void output(Node *hd) {

    if (!hd) {
        cout << "Empty list.\n";
        return;
    }

    int count = 1;
    Node *current = hd;
    cout << "\n";
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }

    cout << endl;
}