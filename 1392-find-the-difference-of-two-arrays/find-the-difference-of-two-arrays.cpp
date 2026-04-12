class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        vector<int> only1, only2;
        
        // in the num1
        for (int x : s1) {
            if (s2.find(x) == s2.end()) {
                only1.push_back(x);
            }
        }
        
        // int the num2
        for (int x : s2) {
            if (s1.find(x) == s1.end()) {
                only2.push_back(x);
            }
        }
        
        return {only1, only2};
    }
};