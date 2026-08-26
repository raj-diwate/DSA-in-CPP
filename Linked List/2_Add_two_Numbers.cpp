#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Creates a linked list
ListNode* createList(int arr[], int n) {

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Solution function
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;

    ListNode* t1 = l1;
    ListNode* t2 = l2;

    int carry = 0;

    while (t1 != NULL || t2 != NULL) {

        int sum = carry;

        if (t1)
            sum += t1->val;

        if (t2)
            sum += t2->val;

        ListNode* newNode = new ListNode(sum % 10);

        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;

        if (t1)
            t1 = t1->next;

        if (t2)
            t2 = t2->next;
    }

    if (carry) {
        ListNode* newNode = new ListNode(carry);
        curr->next = newNode;
    }

    return dummy->next;
}


int main() {

    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    ListNode* result = addTwoNumbers(l1, l2);

    ListNode* temp = result;

    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}