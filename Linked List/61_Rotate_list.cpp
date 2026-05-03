// Problem: Rotate list
// Problem No.: 61
// Platform: LeetCode
// Difficulty: Medium

// Approach:
// Base case : if k==0  that rotating by k will make no difference in linked list so return 0
// or the head or next of head is null then , return head

//  find the length of the linked list and the tail,
// if k > n then k = k%n, and if then k=0 , means the k is multiple of n, so again it will have no change
// by rotating,
// make the linked list circular by tail to the head (tail->next = head )
// move  the newTail by (length-k) steps
// and now the newHead will be the next of the newTail,
// and make the next of newTail as NULL and return the newHead, which will be the head of the rotated list


// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( head == NULL || head->next == NULL || k==0){
            return head;
        }

  
        ListNode* tail = head;
        int length=1;
        while(tail->next != NULL){
            tail=tail->next;
            length++;

        }

        k = k% length;
        if(k == 0)
        return head;


        tail->next = head;


        int steps = (length - k);
        ListNode* newTail = head;
         for(int i=1;i<steps;i++){
            newTail=newTail->next;

        }

        ListNode* newHead = newTail->next; 
          newTail->next = NULL;  
          return newHead; 
    }
};
