#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCyclePresent = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                isCyclePresent = true;
                break;
            }
        }

        return isCyclePresent;
    }
};

int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Linked list is empty." << endl;
        return 0;
    }

    // Create the first node
    int value;
    cout << "Enter value of node 1: ";
    cin >> value;

    ListNode* head = new ListNode(value);
    ListNode* temp = head;

    // Create remaining nodes
    for (int i = 2; i <= n; i++) {
        cout << "Enter value of node " << i << ": ";
        cin >> value;

        temp->next = new ListNode(value);
        temp = temp->next;
    }

    // Ask user whether to create a cycle
    int choice;

    cout << "\nDo you want to create a cycle?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        int position;

        cout << "Enter position where the last node should connect (1-" << n << "): ";
        cin >> position;

        if (position >= 1 && position <= n) {
            ListNode* cycleNode = head;

            // Move to the node at the given position
            for (int i = 1; i < position; i++) {
                cycleNode = cycleNode->next;
            }

            // Connect last node to the selected node
            temp->next = cycleNode;
        }
        else {
            cout << "Invalid position. No cycle created." << endl;
        }
    }

    Solution obj;

    bool result = obj.hasCycle(head);

    if (result) {
        cout << "\nCycle is present." << endl;
    }
    else {
        cout << "\nCycle is not present." << endl;
    }

    return 0;
}