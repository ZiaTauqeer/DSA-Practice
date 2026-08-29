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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        while (second != NULL) {
            if (first->val != second->val) {
                reverse(newHead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        reverse(newHead);
        return true;
    }
};

int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "The linked list is empty." << endl;
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

    Solution obj;

    bool result = obj.isPalindrome(head);

    if (result) {
        cout << "\nThe linked list is a palindrome." << endl;
    }
    else {
        cout << "\nThe linked list is not a palindrome." << endl;
    }

    return 0;
}