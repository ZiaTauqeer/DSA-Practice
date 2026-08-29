#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
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

    int cyclePosition = -1;

    if (choice == 1) {
        cout << "Enter position where the last node should connect (1-" << n << "): ";
        cin >> cyclePosition;

        if (cyclePosition >= 1 && cyclePosition <= n) {
            ListNode* cycleNode = head;

            // Move to the node where cycle should start
            for (int i = 1; i < cyclePosition; i++) {
                cycleNode = cycleNode->next;
            }

            // Connect last node to cycle starting node
            temp->next = cycleNode;
        }
        else {
            cout << "Invalid position. No cycle created." << endl;
            cyclePosition = -1;
        }
    }

    Solution obj;

    ListNode* cycleNode = obj.detectCycle(head);

    if (cycleNode != NULL) {
        cout << "\nCycle is present." << endl;
        cout << "Cycle starts at node with value: "
             << cycleNode->val << endl;
    }
    else {
        cout << "\nCycle is not present." << endl;
    }

    return 0;
}                                                     