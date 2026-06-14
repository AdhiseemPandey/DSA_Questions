// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         vector<int> a1;
//         vector<int> a2;
//         int n = 0;

//         // Step 1: Store values in a1
//         ListNode* temp = head;
//         while (temp != nullptr) {               // O(n)
//             a1.push_back(temp->val);
//             temp = temp->next;
//             n++; // track no. of element
//         }

//         // Step 2:a2 with reversed values of a1
//         for (int j = n - 1; j >= 0; j--) {      // O(n)
//             a2.push_back(a1[j]);
//         }

//         // Step 3: twin sums
//         int maxi = INT_MIN;
//         for (int i = 0; i < n / 2; i++) {       // O(n/2)
//             int sum = a1[i] + a2[i];
//             maxi = max(maxi, sum);
//         }

//         return maxi;
//     }
// };
// TC : O(3n)
// SC : O(2n)


/*

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vals;
        while (head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }

        int n = vals.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n / 2; i++) {
            int sum = vals[i] + vals[n - 1 - i];
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};

*/




class Solution {
public:
    int pairSum(ListNode* head) {
        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Traverse both halves
        int maxi = INT_MIN;
        ListNode* first = head;
        ListNode* second = prev; // head of reversed second half
        while (second) {
            maxi = max(maxi, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return maxi;
    }
};




/*

//Approach-2 (Using Stack)
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        
        while(curr) {
            st.push(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        int count = 1;
        int N = st.size();
        int result = 0;
        
        while(count <= N/2) {
            result = max(result, curr->val + st.top());
            curr = curr->next;
            st.pop();
            count++;
        }
        
        return result;
    }
};

*/