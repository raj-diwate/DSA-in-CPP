// Problem: Linked List Cycle II
// Problem No.: 142
// Platform: LeetCode
// Difficulty: Medium

// Approach:  Slow fast approach.
// We need to return the start of the cycle if there exists a cycle in a list.
// for that we need to first check if there exists a cycle or not.
// Using the slow and fast pointer check if cycle exists or not, if there is no cycle in the list
// then return NULL , but if there is cycle , initialize the slow pointer back to the head,
// and now while (slow != fast ) move slow by one step and fast too one by 1 step, then the slow and fast will 
// meet at some point and that will be the start of the cycle.

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow= head;
        ListNode* fast= head;
        bool iscycle=false;

        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
                if(slow == fast){
                    iscycle =true;
                    break;
                }   
        }
        if(!iscycle){
            return NULL;

        }
        slow= head;
        while(slow != fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;

    }
};

