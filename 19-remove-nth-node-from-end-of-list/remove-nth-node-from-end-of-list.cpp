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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;
// dummy = head 
        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            if (fast->next == NULL) return head; // n is larger than list size
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the target node
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;  // Use delete instead of free for C++ objects

        return dummy->next;
    }
};
