#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};

ListNode* createList(int arr[], int n) {

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* first = head;
        ListNode* prev = NULL;
        ListNode* second = head->next;
        

        while(first != NULL && second != NULL){
            ListNode* third = second->next;
            second->next = first;
            first->next = third;
            if(prev != NULL){
                prev->next = second;
            }
            else{
                head = second;
            }

            prev = first;
            first = third;
            if(third != NULL){
                second = third->next;
            }
            else{
                second = NULL;
            }
        }
        return head;
    }

    int main(){
        int arr[] = {1,2,3,4};
       ListNode* l1 = createList(arr, 4);
        l1 = swapPairs(l1);

        ListNode* temp = l1;

        while(temp != NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        return 0;
    }
