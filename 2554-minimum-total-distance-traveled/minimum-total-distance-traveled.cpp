
class Solution {
public:
    long long solve(int ri, int fi, vector<int>& robot, vector<int>& positions, vector<vector<long long>>& t) {
        if (ri >= robot.size()) return 0;  // all robots assigned
        if (fi >= positions.size()) return 1e12;  // no factories left

        if (t[ri][fi] != -1) return t[ri][fi];

        // Option 1: assign current robot to current factory position
        long long take_current = abs(robot[ri] - positions[fi]) +
                                 solve(ri + 1, fi + 1, robot, positions, t);

        // Option 2: skip current factory position
        long long skip = solve(ri, fi + 1, robot, positions, t);

        return t[ri][fi] = min(take_current, skip);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Expand factory positions based on capacity
        vector<int> positions;
        for (auto& f : factory) {
            int pos = f[0], limit = f[1];
            for (int j = 0; j < limit; j++) {
                positions.push_back(pos);
            }
        }

        int m = robot.size();
        int n = positions.size();

        // Memoization table
        vector<vector<long long>> t(m + 1, vector<long long>(n + 1, -1));

        return solve(0, 0, robot, positions, t);
    }
};
