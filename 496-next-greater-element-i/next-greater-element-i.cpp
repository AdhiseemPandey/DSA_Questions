class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> nge; // map each element to its NGE
        stack<int> st;

        // Traverse nums2 from back
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            // If stack is empty, no greater element exists
            nge[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        // Build result for nums1 using the map
        vector<int> result;
        for (int x : nums1) {
            result.push_back(nge[x]);
        }
        return result;
    }
};
