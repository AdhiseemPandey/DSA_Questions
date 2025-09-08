class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ap = -1;
        int n = nums.size();

        // Step 1: Find the first decreasing element from the end
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ap = i;
                break;
            }
        }

        // Step 2: If no such element is found, reverse the entire array
        if (ap == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the next larger element to swap with
        for (int i = n - 1; i > ap; i--) {
            if (nums[i] > nums[ap]) {
                swap(nums[i], nums[ap]);
                break;
            }
        }

        // Step 4: Reverse the suffix
        reverse(nums.begin() + ap + 1, nums.end());
    }
};
