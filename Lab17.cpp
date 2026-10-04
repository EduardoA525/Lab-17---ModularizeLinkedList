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
        cout << "\n";

        //In case user does not use numbers
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Only numbers allowed. Enter a number from 1-7.\n";
            continue;
        }

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

    int size = 0;
    Node *temp = head;

    while (temp) {
        size++;
        temp = temp -> next;
    }

    int entry;

    //In case user inputs a node that doesnt exist
    do {
        cout << "Which node do you want to delete: ";
        cin >> entry;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Only numbers allowed. Please enter a valid node." << endl;
            continue;
        }

        if (entry < 1 || entry > size) {
            cout << "Node not found. Choose 1-" << size << "." << endl;
        }

    } while (entry < 1 || entry > size);

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

    int size = 0;
    Node *temp = head;

    while (temp) {
        size++;
        temp = temp->next;
    }

    int entry;
    float value; //in case of decimal number

    //In case user inputs invalid values
    do {
        cout << "After which node to insert: ";
        cin >> entry;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Only numbers allowed. Enter a valid node." << endl;
            continue;
        }

        if (entry < 0 || entry > size) {
            cout << "Node not found. Choose 0-" << size << "." << endl;
        }

    } while (entry < 0 || entry > size);

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

    cout << "List deleted." << endl;
}

void output(Node *hd) {

    if (!hd) {
        cout << "Empty list.\n";
        return;
    }

    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
}