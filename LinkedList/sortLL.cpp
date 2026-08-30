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

    ListNode* sortList(ListNode* head) {

        //If List Contain a Single or 0 Node
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while (fast != NULL && fast->next != NULL) {
            temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast->next->next;    //fast incremented by 2
        }

        temp->next = NULL;              //end of first left half

        ListNode* l1 = sortList(head);  //left half recursive call
        ListNode* l2 = sortList(slow);  //right half recursive call

        return mergelist(l1, l2);       //mergelist Function call
    }

    //MergeSort Function O(n*logn)
    ListNode* mergelist(ListNode* l1, ListNode* l2) {

        ListNode* ptr = new ListNode(0);
        ListNode* curr = ptr;

        while (l1 != NULL && l2 != NULL) {

            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }

            curr = curr->next;
        }

        //for unqual length linked list

        if (l1 != NULL) {
            curr->next = l1;
        }

        if (l2 != NULL) {
            curr->next = l2;
        }

        ListNode* result = ptr->next;

        delete ptr;

        return result;
    }
};

// Function to create linked list
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

// Function to print linked list
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

    head = obj.sortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}