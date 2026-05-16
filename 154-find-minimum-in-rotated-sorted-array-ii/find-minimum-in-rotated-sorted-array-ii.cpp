class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            // duplicates ko skrink 
            while ( low < high && nums[low] == nums[low+1] ){
                low++;
            }
            while( low < high && nums[high] == nums[high-1] ) {
                high--;
            }
            int mid = low + (high - low) / 2;

            // If the left half is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // If the right half is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};