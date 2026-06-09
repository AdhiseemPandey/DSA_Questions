class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxVal = *max_element(nums.begin(), nums.end());
        long long minVal = *min_element(nums.begin(), nums.end());
        long long diff = maxVal - minVal;

        long long ans = diff * k ; 

        return ans;
    }
};