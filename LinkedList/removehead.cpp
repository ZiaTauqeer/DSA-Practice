#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int data1,Node* next1){
        data = data1; //data1 gets stored in data
        next = next1; // next1 gets stored in next
    }
};

Node* deleteHead(Node* head){
    if (head == nullptr){ //if linked list is empty head becomes null ptr
        return nullptr;
    }

    // Store the address of the current first node in temp
    //
    // Before:
    // head
    //  ↓
    // [2] → [5] → [7] → NULL
    //
    // Now both head and temp point to [2]
    Node* temp = head;

    head = head -> next;
    delete temp;
    return head;
}

int main() {
    Node* head = new Node(2, nullptr);
    
    head->next = new Node(5, nullptr);
    head->next->next = new Node(7, nullptr);

    head = deleteHead(head);

    cout << head->data;

    return 0;
}