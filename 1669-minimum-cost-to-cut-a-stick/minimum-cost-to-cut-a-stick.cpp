class Solution {
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int ind = i; ind <= j; ind++) {
            int cost = cuts[j+1] - cuts[i-1] 
                       + f(i, ind-1, cuts, dp) 
                       + f(ind+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        int c = cuts.size(); // total number of points including 0 and n
        vector<vector<int>> dp(c, vector<int>(c, -1));

        return f(1, c-2, cuts, dp); 
        // we only consider cuts between 1 and c-2 (excluding 0 and n)
    }
};
