class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> a1;
        vector<int> a2;
        int n = 0;

        // Step 1: Store values in a1
        ListNode* temp = head;
        while (temp != nullptr) {               // O(n)
            a1.push_back(temp->val);
            temp = temp->next;
            n++; // track no. of element
        }

        // Step 2:a2 with reversed values of a1
        for (int j = n - 1; j >= 0; j--) {      // O(n)
            a2.push_back(a1[j]);
        }

        // Step 3: twin sums
        int maxi = INT_MIN;
        for (int i = 0; i < n / 2; i++) {       // O(n/2)
            int sum = a1[i] + a2[i];
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};
// TC : O(3n)
// SC : O(2n)