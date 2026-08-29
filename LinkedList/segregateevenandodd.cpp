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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = head->next;

        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenhead;

        return head;
    }
};

// Create linked list
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

// Print linked list
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

    Solution obj;

    head = obj.oddEvenList(head);

    cout << "After odd-even rearrangement: ";
    printList(head);

    return 0;
}