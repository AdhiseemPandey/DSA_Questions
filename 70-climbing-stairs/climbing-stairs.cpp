class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if (n <= 1) return 1; // base cases: 1 way to climb 0 or 1 step
        if (dp[n] != -1) return dp[n]; // already computed

        // recurrence: ways to climb n = ways(n-1) + ways(n-2)
        dp[n] = helper(n-1, dp) + helper(n-2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};
