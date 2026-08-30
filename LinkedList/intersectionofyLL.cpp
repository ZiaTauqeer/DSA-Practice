#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 != t2) {

            t1 = t1->next;
            t2 = t2->next;

            if (t1 == t2)
                return t1;

            if (t1 == NULL)
                t1 = headB;

            if (t2 == NULL)
                t2 = headA;
        }

        return t1;
    }
};

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

    /*
        Create two lists that intersect:

        List A:
        1 -> 2 -> 3
                  \
                   7 -> 8 -> 9
                  /
        List B:
        4 -> 5 -> 6

        Both lists point to the SAME node 7.
    */

    ListNode* common1 = new ListNode(7);
    ListNode* common2 = new ListNode(8);
    ListNode* common3 = new ListNode(9);

    common1->next = common2;
    common2->next = common3;

    // List A
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);

    headA->next->next->next = common1;

    // List B
    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = new ListNode(6);

    headB->next->next->next = common1;

    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    Solution obj;

    ListNode* intersection = obj.getIntersectionNode(headA, headB);

    if (intersection != NULL) {
        cout << "Intersection node: " << intersection->val << endl;
    }
    else {
        cout << "No intersection." << endl;
    }

    return 0;
}