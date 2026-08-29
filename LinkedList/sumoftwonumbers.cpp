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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode(-1);
        ListNode* curr = dummyhead;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;

        while (t1 != NULL || t2 != NULL) {
            int sum = carry;

            if (t1) sum += t1->val;// for t1 add value of list one to sum
            if (t2) sum += t2->val;// for t2 add value of list two to sum

            ListNode* newnode = new ListNode(sum % 10);
            carry = sum / 10;

            curr->next = newnode;//current ka next becomes newnode
            curr = curr->next;// current becomes newnode

            if (t1) t1 = t1->next;// if it is a t1 pointer it now points to next node in first list
            if (t2) t2 = t2->next;//if it is a t2 pointer it now points to  next node in second list
        }

        if (carry) {
            ListNode* newnode = new ListNode(carry);// if only carry is present new node has carry value
            curr->next = newnode;// current ka next ab points to new node
        }

        return dummyhead->next;
    }
};

// Function to create a linked list from user input
ListNode* createList(int n) {
    if (n == 0)
        return nullptr;

    int value;

    cout << "Enter " << n << " values: ";

    cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> value;
        temp->next = new ListNode(value);
        temp = temp->next;
    }

    return head;
}

// Function to print the linked list
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
    int n1, n2;

    cout << "Enter number of nodes in first list: ";
    cin >> n1;

    ListNode* l1 = createList(n1);

    cout << "Enter number of nodes in second list: ";
    cin >> n2;

    ListNode* l2 = createList(n2);

    Solution obj;

    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}