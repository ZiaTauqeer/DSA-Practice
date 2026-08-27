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


// ============================================================
// DELETE HEAD
// ============================================================

Node* deleteHead(Node* head) {

    // If linked list is empty
    if (head == nullptr) {
        return nullptr;
    }

    // Store current head
    Node* temp = head;

    // Move head to the second node
    head = head->next;

    // Delete old head
    delete temp;

    // Return new head
    return head;
}


// ============================================================
// REMOVE TAIL
// ============================================================

Node* removeTail(Node* head) {

    // If list is empty OR has only one node
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    // Start from head
    Node* temp = head;

    // Move to second-last node
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // Delete last node
    delete temp->next;

    // Second-last node now points to NULL
    temp->next = nullptr;

    return head;
}


// ============================================================
// DELETE GIVEN ELEMENT
// ============================================================

Node* deleteElement(Node* head, int value) {

    // If list is empty
    if (head == nullptr) {
        return nullptr;
    }

    // If the element to delete is the head
    if (head->data == value) {

        Node* temp = head;

        // Move head to next node
        head = head->next;

        // Delete old head
        delete temp;

        return head;
    }

    // Start from head
    Node* temp = head;

    // Search for the node whose data == value
    while (temp->next != nullptr) {

        if (temp->next->data == value) {

            // Store the node we want to delete
            Node* deleteNode = temp->next;

            // Skip over the node
            temp->next = temp->next->next;

            // Delete the node
            delete deleteNode;

            // Stop after deleting the first occurrence
            return head;
        }

        // Move to next node
        temp = temp->next;
    }

    // Element was not found
    return head;
}


// ============================================================
// PRINT LINKED LIST
// ============================================================

void printList(Node* head) {

    Node* temp = head;

    while (temp != nullptr) {

        cout << temp->data << " ";

        temp = temp->next;
    }

    cout << endl;
}


// ============================================================
// MAIN
// ============================================================

int main() {

    vector<int> arr = {12, 7, 8, 2};

    // Create linked list
    Node* head = new Node(arr[0], nullptr);

    head->next = new Node(arr[1], nullptr);
    head->next->next = new Node(arr[2], nullptr);
    head->next->next->next = new Node(arr[3], nullptr);


    // Original list
    cout << "Original list: ";
    printList(head);


    // Delete the element 8
    head = deleteElement(head, 8);

    cout << "After deleting 8: ";
    printList(head);


    return 0;
}