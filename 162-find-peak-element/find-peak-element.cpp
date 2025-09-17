class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // You're on a downward slope, peak is to the left or at mid
                high = mid;
            } else {
                // You're on an upward slope, peak is to the right
                low = mid + 1;
            }
        }

        return low; // or high, since low == high
    }
};



// Brute Force : TC => O(N)
// int n = nums.size();
//         for(int i=0;i<n;i++){
//             if((i==0 || nums[i-1] < nums[i]) && (i==n-1 || nums[i] > nums[i+1])){
//                 return i;
//             }
//         }
//         return -1;