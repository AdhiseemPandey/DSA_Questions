int robLinear(vector<int>& nums) {
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++) {
        int take = nums[i];
        if (i > 1) take += prev2;
        int not_take = prev;
        int curi = max(take, not_take);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> temp1(nums.begin(), nums.end()-1); // exclude last
        vector<int> temp2(nums.begin()+1, nums.end()); // exclude first

        return max(robLinear(temp1), robLinear(temp2));
    }
};
