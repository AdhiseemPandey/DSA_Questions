class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2*limit + 2, 0);

        for (int i = 0; i < n/2; i++) {
            int a = nums[i], b = nums[n-1-i];
            int low = min(a, b) + 1;
            int high = max(a, b) + limit;

            // Default: 2 moves for all sums
            diff[2] += 2;
            diff[2*limit+1] -= 2;

            // 1 move for sums in [low, high]
            diff[low] += -1;
            diff[high+1] -= -1;

            // 0 move for exact sum
            diff[a+b] += -1;
            diff[a+b+1] -= -1;
        }

        int res = INT_MAX, curr = 0;
        for (int s = 2; s <= 2*limit; s++) {
            curr += diff[s];
            res = min(res, curr);
        }
        return res;
    }
};
