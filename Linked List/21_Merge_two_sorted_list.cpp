// Problem: Merge Two Sortd List
// Problem No.: 21
// Platform: LeetCode
// Difficulty: Easy


//Approach: Create a dummy node, and its pointer as temp, 
// compare the  l1 and l2 while(l1 != NULL && l2 != NULL) , starting from the heada, check which,
// list has the smaller head, the smaller one will be the temp->next and the the head will of that list will
// be updated to next, and temp will be updated to temp->next.

// if any of the list gets over, then add the remaining nodes of the left lsit to the temp->next, until that
//list also gets over,

// at the end return the dummy->next, which will be the head of the merged of sorted list
// l1 and l2.

//T.C = O(n+m)
//S.C = O(1)



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                temp->next= list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;

        }

        if(list1 != NULL)
        temp->next=list1;
        else
        temp->next=list2;
        
        return dummy->next;

        
    }
};
