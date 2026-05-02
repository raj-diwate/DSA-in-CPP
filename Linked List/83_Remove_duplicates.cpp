// Problem: Remove Duplicates from Sorted List
// Problem No.: 83
// Platform: LeetCode
// Difficulty: Easy

// Approach: Optimal
// create a new node as curr, which is the head of the list, while( curr != NUULL && curr->next !+ NULL )
// since the list is the sorted, the duplicates will be side of each other, compare the curr->val and curr->next->val if they are same, make 
// curr->next as curr->next->next.
// else move to the next node by curr= curr->next.

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       
        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next;

            }
            else{
            curr = curr->next;
            }
        }
        return head;
    }
};
