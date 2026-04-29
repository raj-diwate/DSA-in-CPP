// Problem: Linked List Cycle
// Problem No.: 141
// Platform: LeetCode
// Difficulty: Easy

// Approach:
//  Using the slow fast approach, if there exists a cycle then the slow and fast pointer
// will meet.

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};



