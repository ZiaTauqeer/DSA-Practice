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

    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;

        front->next = head;
        head->next = NULL;

        return newhead;
    }

    ListNode* getkthNode(ListNode* temp, int k) {
        k -= 1;

        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL) {

            ListNode* kthNode = getkthNode(temp, k);

            // Less than k nodes remaining
            if (kthNode == NULL) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }

            // Store next group
            ListNode* nextNode = kthNode->next;

            // Disconnect current group
            kthNode->next = NULL;

            // Reverse current group
            reverse(temp);

            // First group
            if (temp == head) {
                head = kthNode;
            }
            // Other groups
            else {
                prevLast->next = kthNode;
            }

            // temp is now the last node of reversed group
            prevLast = temp;

            // Move to next group
            temp = nextNode;
        }

        return head;
    }
};


// Create linked list from vector
ListNode* createList(vector<int> nums) {
    if (nums.empty()) {
        return NULL;
    }

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

        if (head->next != NULL) {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}


int main() {

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int k = 5;

    // Create linked list
    ListNode* head = createList(nums);

    cout << "Original list:" << endl;
    printList(head);

    // Reverse in groups of k
    Solution solution;
    head = solution.reverseKGroup(head, k);

    cout << "After reversing in groups of " << k << ":" << endl;
    printList(head);

    return 0;
}

