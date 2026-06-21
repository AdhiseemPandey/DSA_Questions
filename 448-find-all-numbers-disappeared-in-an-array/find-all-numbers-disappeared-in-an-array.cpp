class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen(nums.begin(), nums.end()); 
        vector<int> missing;

        for (int i = 1; i <= n; i++) {
            if (seen.find(i) == seen.end()) {
                missing.push_back(i);
            }
        }
        return missing;
    }
};
