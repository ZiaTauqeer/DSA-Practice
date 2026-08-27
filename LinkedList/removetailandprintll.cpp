#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};


// Function to remove the last node
Node* removeTail(Node* head) {

    // If list is empty OR has only one node
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    // Start from the head
    Node* temp = head;

    // Move temp until it reaches the second-last node
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // Delete the last node
    delete temp->next;

    // Make second-last node point to NULL
    temp->next = nullptr;

    return head;
}


// Function to print the linked list
void printList(Node* head) {

    // Start from the first node
    Node* temp = head;

    // Continue until temp becomes NULL
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


int main() {

    vector<int> arr = {12, 7, 8, 2};

    // Create the linked list
    Node* head = new Node(arr[0], nullptr);

    head->next = new Node(arr[1], nullptr);
    head->next->next = new Node(arr[2], nullptr);
    head->next->next->next = new Node(arr[3], nullptr);


    // Print list BEFORE removing tail
    cout << "Before removing tail: ";
    printList(head);


    // Remove the last node
    head = removeTail(head);


    // Print list AFTER removing tail
    cout << "After removing tail: ";
    printList(head);


    return 0;
}