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
    ListNode* deleteMiddle(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow->next;
        slow->next = slow->next->next;

        // Delete middle node
        delete middle;

        return head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr)
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

    cout << "\nOriginal list: ";
    printList(head);

    Solution obj;

    head = obj.deleteMiddle(head);

    cout << "After deleting middle: ";
    printList(head);

    return 0;
}