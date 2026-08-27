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

Node* removeTail(Node* head){
    if (head == nullptr||head->next==NULL){ //if linked list is empty head becomes null ptr
        return nullptr;
    }
    Node* temp = head;

    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    
    delete temp->next;
    temp->next=nullptr;

    return head;
}
int main() {
    vector<int> arr = {12, 7, 8, 2};

    // Create first node
    Node* head = new Node(arr[0], nullptr);

    // Create and connect remaining nodes
    head->next = new Node(arr[1], nullptr);
    head->next->next = new Node(arr[2], nullptr);
    head->next->next->next = new Node(arr[3], nullptr);

    // Remove the last node
    head = removeTail(head);

    // Print new head's data
    cout << head->data;

    return 0;
}