/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head; 
        ListNode* prev = NULL; 
        while (temp != NULL) {
            ListNode* front = temp->next; 
            temp->next = prev; 
            prev = temp; 
            temp = front; 
        }
        return prev;
    }
};



// recursive way 
/*
reverse (head){
    if( head ==NULL || head -> next == NULL ){
        return head ;
    }
    NOde* newHead = reverse ( head -> next );
    NOde* front = head -> next ; 
    front -> next = head ;
    had -> next = NULL ;
    return newHead;
}



*/