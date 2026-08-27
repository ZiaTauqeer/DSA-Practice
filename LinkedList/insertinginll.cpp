#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;       // data1 is stored in data
        next = next1;       // next1 is stored in next
    }
};


// ============================================================
// INSERT ELEMENT AT GIVEN POSITION
// ============================================================

Node* insertElement(Node* head, int value, int position) {

    if (position <= 0) {                    // position must be 1 or greater
        return head;                        // return the unchanged head
    }

    if (position == 1) {                    // inserting at the beginning
        Node* newNode = new Node(value, head); // newNode points to old head
        return newNode;                     // newNode becomes the new head
    }

    Node* temp = head;                      // temp points to the head

    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;                  // temp moves to the next node
    }

    if (temp == nullptr) {                  // position is outside the list
        return head;                        // return the unchanged head
    }

    Node* newNode = new Node(value, temp->next); // newNode points to temp's next
    temp->next = newNode;                   // temp now points to newNode

    return head;                            // head remains unchanged
}


// ============================================================
// PRINT LINKED LIST
// ============================================================

void printList(Node* head) {

    Node* temp = head;                      // temp points to head

    while (temp != nullptr) {               // continue until temp is NULL
        cout << temp->data << " ";          // print current node's data
        temp = temp->next;                  // temp moves to the next node
    }

    cout << endl;                           // move to the next line
}


// ============================================================
// MAIN
// ============================================================

int main() {

    vector<int> arr = {12, 7, 8, 2};

    Node* head = new Node(arr[0], nullptr); // create first node

    head->next = new Node(arr[1], nullptr); // second node
    head->next->next = new Node(arr[2], nullptr); // third node
    head->next->next->next = new Node(arr[3], nullptr); // fourth node


    cout << "Original list: ";               // print message
    printList(head);                         // print the linked list


    head = insertElement(head, 10, 3);       // insert 10 at position 3

    cout << "After inserting 10: ";         // print message
    printList(head);                         // print the updated list


    return 0;                                // end program
}