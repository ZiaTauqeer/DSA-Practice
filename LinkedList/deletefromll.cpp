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

    // If the linked list is empty
    if (head == nullptr) {
        return nullptr;
    }

    // Store the current head temporarily
    Node* temp = head;

    // Move head to the second node
    head = head->next;

    // Delete the old first node
    delete temp;

    // Return the new head
    return head;
}


// ============================================================
// DELETE TAIL
// ============================================================

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


// ============================================================
// DELETE Kth NODE
// ============================================================

Node* deleteK(Node* head, int k) {

    // If list is empty
    if (head == nullptr) {
        return nullptr;
    }

    // If k = 1, we are deleting the head
    if (k == 1) {
        Node* temp = head;

        // Move head to the second node
        head = head->next;

        // Delete old head
        delete temp;

        return head;
    }

    // Start from head
    Node* temp = head;

    // Move temp to the node BEFORE the kth node
    //
    // Example: k = 3
    //
    // 12 → 7 → 8 → 2
    //      ↑
    //     temp
    //
    // temp should stop at 7

    for (int i = 1; i < k - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // If k is greater than the length of the list
    // or temp is invalid
    if (temp == nullptr || temp->next == nullptr) {
        return head;
    }

    // Store the kth node
    Node* deleteNode = temp->next;

    // Skip over the kth node
    temp->next = temp->next->next;

    // Delete the kth node
    delete deleteNode;

    return head;
}


// ============================================================
// PRINT LINKED LIST
// ============================================================

void printList(Node* head) {

    // Start from head
    Node* temp = head;

    // Continue until temp becomes NULL
    while (temp != nullptr) {

        cout << temp->data << " ";

        // Move to next node
        temp = temp->next;
    }

    cout << endl;
}


// ============================================================
// MAIN
// ============================================================

int main() {

    vector<int> arr = {12, 7, 8, 2};

    // Create the linked list
    Node* head = new Node(arr[0], nullptr);

    head->next = new Node(arr[1], nullptr);
    head->next->next = new Node(arr[2], nullptr);
    head->next->next->next = new Node(arr[3], nullptr);


    // --------------------------------------------------------
    // ORIGINAL LIST
    // --------------------------------------------------------

    cout << "Original list: ";
    printList(head);


    // --------------------------------------------------------
    // DELETE HEAD
    // --------------------------------------------------------

    head = deleteHead(head);

    cout << "After deleting head: ";
    printList(head);


    // Current list:
    //
    // 7 → 8 → 2


    // --------------------------------------------------------
    // DELETE Kth NODE
    // --------------------------------------------------------

    // Delete position 2
    //
    // Current list:
    //
    // 7 → 8 → 2
    //      ↑
    //      k = 2
    //
    // After deletion:
    //
    // 7 → 2

    head = deleteK(head, 2);

    cout << "After deleting position 2: ";
    printList(head);


    // --------------------------------------------------------
    // DELETE TAIL
    // --------------------------------------------------------

    // Current list:
    //
    // 7 → 2
    //
    // Remove tail (2)
    //
    // Result:
    //
    // 7

    head = removeTail(head);

    cout << "After removing tail: ";
    printList(head);


    return 0;
}