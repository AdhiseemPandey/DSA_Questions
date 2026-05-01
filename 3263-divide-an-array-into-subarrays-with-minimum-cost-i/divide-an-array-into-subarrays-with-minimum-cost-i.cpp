class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        // always take the first element 
        int cost = nums[0];

        // idea peak ke side me 
        // aur sink me 


        // kadane type se ? two viriable 
        
        int firstMin = INT_MAX, secondMin = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (nums[i] < firstMin) {
                secondMin = firstMin;
                firstMin = nums[i];
            } else if (nums[i] < secondMin) {
                secondMin = nums[i];
            }
        }

        cost += firstMin + secondMin;
        return cost;
    }
};

// leetcode soluiton 
// class Solution {
// public:
//     int minimumCost(vector<int>& nums) {
//         sort(nums.begin() + 1, nums.end());
//         return reduce(nums.begin(), nums.begin() + 3, 0);
//     }
// };