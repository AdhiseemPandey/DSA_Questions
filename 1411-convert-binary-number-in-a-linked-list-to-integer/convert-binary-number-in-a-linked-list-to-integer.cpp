//Approach-1 (Using bit manipulation to form the decimal number)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;

        while(head) {
            result = (result << 1) | (head->val);

            head = head->next;
        }        
        return result;
    }
};