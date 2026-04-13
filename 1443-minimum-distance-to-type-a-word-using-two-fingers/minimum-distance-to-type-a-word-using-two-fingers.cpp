class Solution {
public:
    // dp[i][f1+1][f2+1] stores the minimum distance starting from index i
    // f1 and f2 are finger positions (-1 means unused, 0–25 means letter index)
    int dp[301][27][27];

    pair<int,int> getCoordinate(int pos) {
        return { pos / 6, pos % 6 };
    }

    int getDistance(int pos1, int pos2) {
        auto [x1, y1] = getCoordinate(pos1);
        auto [x2, y2] = getCoordinate(pos2);
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string &word, int i, int f1, int f2) {
        if (i >= word.length()) return 0;

        int curr = word[i] - 'A';

        if (dp[i][f1+1][f2+1] != -1) return dp[i][f1+1][f2+1];

        int res;
        if (f1 == -1 && f2 == -1) {
            // both unused, assign to f1
            res = solve(word, i+1, curr, f2);
        } else if (f2 == -1) {
            // only f1 used
            int moveF2 = solve(word, i+1, f1, curr);
            int moveF1 = getDistance(f1, curr) + solve(word, i+1, curr, f2);
            res = min(moveF1, moveF2);
        } else {
            // both fingers used
            int moveF1 = getDistance(f1, curr) + solve(word, i+1, curr, f2);
            int moveF2 = getDistance(f2, curr) + solve(word, i+1, f1, curr);
            res = min(moveF1, moveF2);
        }

        return dp[i][f1+1][f2+1] = res;
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, -1, -1);
    }
};
