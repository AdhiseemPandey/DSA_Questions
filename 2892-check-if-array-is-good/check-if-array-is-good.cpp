// MINE code => O(n^2)
// class Solution {
// public:
//     bool isGood(vector<int>& nums) {
//         int n = nums.size() - 1; 
//         if (*max_element(nums.begin(), nums.end()) != n) return false;
//         if (count(nums.begin(), nums.end(), n) != 2) return false;
//         for (int i = 1; i < n; i++) {
//             if (count(nums.begin(), nums.end(), i) != 1) return false;
//         }
//     return true;
//     }
// };


// OPtimizsed STL Version : 
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;

        // Sort once → O(n log n)
        sort(nums.begin(), nums.end());

        // Check max element == n
        if (nums.back() != n) return false;

        // Check n appears twice (last two elements must be n)
        if (nums[n] != n || nums[n-1] != n) return false;

        // Check 1..n-1 appear exactly once
        for (int i = 0; i < n-1; i++) {
            if (nums[i] != i+1) return false;
        }

        return true;
    }
};

// iota_view
// class Solution {
// public: 
//     bool isGood(vector<int>& nums) {
//         int n = nums.size() - 1;
//         sort(nums.begin(), nums.end());

//         // Check sequence 1..n-1
//         if (!equal(nums.begin(), nums.begin() + (n-1), 
//                    iota_view(1, n))) return false;

//         // Check last two are n
//         return nums[n-1] == n && nums[n] == n;
//     }
// };
