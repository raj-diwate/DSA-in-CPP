// Problem: Middle of Linked lists
// Problem No.: 876
// Platform: LeetCode
// Difficulty: Easy

// Approach: find the size of the linked list by 
// ListNode* temp = head;
 // and the while(head != NULL){
// size = count the number of nodes.
// middle one is size/2 
// then again traverse to the middle node and then return it.

// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        temp = head;
        for (int i = 0; i < n / 2; i++) {
            temp = temp->next;
        }

        return temp;
    }
};


// Slow fast method is better although same TC becoz , it gives the middle in one traverse.

// Approach:
// using the slow fast approach,initialze the slow and fast to head and 
// move the slow by +1 and fast by +2 untill 
// condtion 1: for even fast != NULL
//            &&
//condtion 2 :  for odd fast->next != NULL

// when the loop ends at that point the slow is at the middle of the linked list.

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast != NULL && fast->next != NULL){
            slow= slow->next;
            fast=fast->next->next;
        }
        return slow;
        
    }
};
