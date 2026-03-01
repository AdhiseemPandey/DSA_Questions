// class Solution {
//     int LIS(int ind, int prev_ind, vector<int>& nums, int n) {
//         if (ind == n) return 0;

//         int len = LIS(ind + 1, prev_ind, nums, n); // NOT TAKE
//         if (prev_ind == -1 || nums[ind] > nums[prev_ind]) { // TAKE
//             len = max(len, 1 + LIS(ind + 1, ind, nums, n));
//         }

//         return len;
//     }

// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         return LIS(0, -1, nums, n);
//     }
// };


// /*

class Solution {
    int LIS(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (ind == n) return 0;

        if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        int len = LIS(ind + 1, prev_ind, nums, n, dp); // NOT TAKE
        
        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) { // TAKE
            len = max(len, 1 + LIS(ind + 1, ind, nums, n, dp));
        }

        return dp[ind][prev_ind + 1] = len;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return LIS(0, -1, nums, n, dp);
    }
};
