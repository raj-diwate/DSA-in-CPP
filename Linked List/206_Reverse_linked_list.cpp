// Problem: Reverse linked list
// Problem No.: 206
// Platform: LeetCode
// Difficulty: Easy

// Approach: Reverse the linked list using the three pointers.
//         ListNode* prev = NULL
//           ListNode* curr = head
//           ListNOde* next = curr->next

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr =head;
        ListNode* prev = NULL;
    
    while(curr != NULL){
      ListNode* next = curr->next;
      curr->next =prev;
      prev = curr;
      curr = next;
    }
        return prev;
    }
};
