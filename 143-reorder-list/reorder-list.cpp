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
// Read the Solution in Discusiions 

// Approaches 1 : LL & Reverse LL and remake the LL ( use GPT and try )
// Approaches 2 : Slow and fast -> middle -> spiral form observation ( use GPT and try  )
// Approaches 3 : Stack approaches 
// Approaches 4 : Two Pointers + Reverse + Merge
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<int> list;
        ListNode* curr = head;
        while( curr != nullptr ){
            list.push_back(curr->val);
            curr = curr -> next;
        }

        curr = head;
        for( int i = 0 ; i < list.size() ; i++ ){
            curr -> val = list[ i%2 == 0 ? i/2 : list.size()-(i+1)/2 ];
            curr = curr -> next;
        }
        
    }
};