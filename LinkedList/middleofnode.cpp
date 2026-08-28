#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;       // slow points to head
        ListNode* fast = head;       // fast points to head

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;       // slow moves 1 step
            fast = fast->next->next; // fast moves 2 steps
        }

        return slow;                 // slow is at the middle
    }
};


int main() {

    // Create linked list:
    // 1 → 2 → 3 → 4 → 5

    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);


    // Create Solution object
    Solution obj;

    // Find middle node
    ListNode* middle = obj.middleNode(head);

    // Print middle node
    cout << "Middle node: " << middle->val << endl;

    return 0;
}