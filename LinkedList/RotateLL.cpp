
#include <iostream>
#include <vector>
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

    ListNode* findNthNode(ListNode* temp, int k) {
        int cnt = 1;

        while (temp != NULL) {
            if (cnt == k)
                return temp;

            cnt++;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || k == 0)
            return head;

        ListNode* tail = head;
        int len = 1;

        // Find tail and length
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        // If k is a multiple of length
        if (k % len == 0)
            return head;

        k = k % len;

        // Make the list circular
        tail->next = head;

        // Find the new last node
        ListNode* newLastNode = findNthNode(head, len - k);

        // New head
        head = newLastNode->next;

        // Break the circular list
        newLastNode->next = NULL;

        return head;
    }
};


// Create linked list
ListNode* createList(vector<int> nums) {

    if (nums.empty())
        return NULL;

    ListNode* head = new ListNode(nums[0]);
    ListNode* temp = head;

    for (int i = 1; i < nums.size(); i++) {
        temp->next = new ListNode(nums[i]);
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

    vector<int> nums = {1, 2, 3, 4, 5};

    int k = 2;

    // Create list
    ListNode* head = createList(nums);

    cout << "Original list: ";
    printList(head);

    // Rotate list
    Solution solution;
    head = solution.rotateRight(head, k);

    cout << "After rotating right by " << k << ": ";
    printList(head);

    return 0;
}

