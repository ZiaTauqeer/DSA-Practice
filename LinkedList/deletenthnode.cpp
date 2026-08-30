#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If we need to delete the head
        if (fast == NULL) {
            ListNode* delnode = head;
            head = head->next;
            delete delnode;
            return head;
        }

        ListNode* slow = head;

        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* delnode = slow->next;
        slow->next = slow->next->next;

        delete delnode;

        return head;
    }
};

// Function to create a linked list
ListNode* createList(int n) {

    if (n <= 0)
        return NULL;

    int value;

    cout << "Enter value of node 1: ";
    cin >> value;

    ListNode* head = new ListNode(value);
    ListNode* temp = head;

    for (int i = 2; i <= n; i++) {

        cout << "Enter value of node " << i << ": ";
        cin >> value;

        temp->next = new ListNode(value);
        temp = temp->next;
    }

    return head;
}

// Function to print the linked list
void printList(ListNode* head) {

    while (head != NULL) {

        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "List is empty." << endl;
        return 0;
    }

    ListNode* head = createList(n);

    cout << "\nOriginal list: ";
    printList(head);

    int removePosition;

    cout << "\nEnter n (node to remove from the end): ";
    cin >> removePosition;

    if (removePosition <= 0 || removePosition > n) {
        cout << "Invalid n." << endl;
        return 0;
    }

    Solution obj;

    head = obj.removeNthFromEnd(head, removePosition);

    cout << "After removing " << removePosition
         << "th node from the end: ";

    printList(head);

    return 0;
}