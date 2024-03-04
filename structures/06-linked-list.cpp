#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
        void traverseLinkedList();
        void findNode(int nodeValue);
        void sortLinkedList();
};

void Node::traverseLinkedList() {
    Node* head = this;
    while(head != NULL) {
        cout << head->value << " -> ";
        head = head->next;
    }
    cout << "X" << endl;
}

void Node::findNode(int nodeValue) {
    Node* head = this;
    int position = 0;
    while (head != NULL) {
        position++;
        if(head->value == nodeValue) {
            cout << "Node found at position " << position << "." << endl;
            return;
        }    
        head = head->next;    
    }
    cout << "Node not found." << endl;
    return;
}

void Node::sortLinkedList() {
    Node* current = this;
    Node* index = NULL;
    int temp;

    while(current != NULL) {
        index = current->next;
        while(index != NULL) {
            if (current->value > index->value) {
                temp = current->value;
                current->value = index->value;
                index->value = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

int main() {

    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    one = new Node();
    two = new Node();
    three = new Node();

    one->value = 1;
    two->value = 2;
    three->value = 3;

    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;

    head->traverseLinkedList();

    // Inserting new node at the beginning

    Node* zero = NULL;
    zero = new Node();
    zero->value = 0;
    zero->next = one;

    head = zero;

    head->traverseLinkedList();

    // Inserting new node at the end

    Node* four = NULL;
    four = new Node();
    four->value = 4;
    four->next = NULL;

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = four;

    head->traverseLinkedList();

    // Inserting new node at desired position

    int position = 3;

    Node* five = NULL;
    five = new Node();
    five->value = 5;

    temp = head;

    for(int i = 2; i < position; i++) {
        if (temp->next != NULL) {
            temp = temp->next;
        }
    }

    five->next = temp->next;
    temp->next = five;

    head->traverseLinkedList();

    // Sort Node
    head->sortLinkedList();
    head->traverseLinkedList();

    // Delete node at beginning

    head = head->next;
    head->traverseLinkedList();

    // Delete node at end

    temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next = NULL;

    head->traverseLinkedList();

    // Delete node at desired position

    position = 2;

    temp = head;

    for (int i = 2; i < position - 1; i++) {
        if (temp->next != NULL) {
            temp = temp->next;
        }
    }
    temp->next = temp->next->next;

    head->traverseLinkedList();

    head->findNode(4);
    head->findNode(5);

    return 0;
}