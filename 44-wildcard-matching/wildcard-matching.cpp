class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;

        // Handle leading '*' in pattern
        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*') dp[0][j] = dp[0][j-1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j-1] == s[i-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};


// class Solution {
//     int f(int i, int j, string &s, string &p) {
//         if (i < 0 && j < 0) return true;
//         if (i < 0 && j >= 0) return false;
//         if (j < 0 && i >= 0) {
//             for (int ii = 0; ii <= i; ii++) {
//                 if (p[ii] != '*') return false;
//             }
//             return true;
//         }
//         if (s[i] == p[j] || p[j] == '?') {
//             return f(i-1, j-1, s, p);
//         }
//         if (p[j] == '*') {
//             return f(i, j-1, s, p) || f(i-1, j, s, p);
//         }
//         return false;
//     }
// public:
//     bool isMatch(string s, string p) {
//         int n = s.size();
//         int m = p.size();
//         return f(n-1, m-1, s, p);
//     }
// };
