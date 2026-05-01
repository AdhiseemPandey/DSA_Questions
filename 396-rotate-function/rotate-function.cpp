// DP Approach and Recurrve approach 
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0, F = 0;

        // Step 1: Compute sum and F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long long)i * nums[i];
        }

        long long ans = F;

        /*
        When you rotate:
            Every element moves +1 index
            So total increases by totalSum
            BUT the last element jumps from (n-1) to 0, losing (n-1)*value

            That’s why we subtract:
                                    n*nums[n−k]
        */
        // Step 2: Compute next rotations
        for (int k = 1; k < n; k++) {
            F = F + sum - (long long)n * nums[n - k];
            ans = max(ans, F);
        }

        return ans;
    }
};





/******************************************************************************************/

// TC = n^2 & BRUTE FORCE  

// class Solution {
// public:
//     // function to find the rotation
//     vector<int> rotate(vector<int> &nums, int k, vector<int> &arr, int n) {
//         k = k % n;
//         map<int,int> mp;

//         // build mapping: new index -> value
//         for (int i = 0; i < n; i++) {
//             int newIdx = (i + k) % n;
//             mp[newIdx] = nums[i];
//         }

//         // fill arr using map
//         for (auto &p : mp) {
//             arr[p.first] = p.second;
//         }

//         return arr;
//     }

//     // function to compute value of rotated array
//     int maxValue(vector<int> &arr, int maxi) {
//         int temp = 0;
//         for (int i = 0; i < arr.size(); i++) {
//             temp += i * arr[i];
//         }
//         if (temp > maxi) maxi = temp;
//         return maxi;
//     }

//     int maxRotateFunction(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> arr(n, 0);
//         int maxi = INT_MIN; // store max function value

//         for (int k = 0; k < n; k++) {
//             rotate(nums, k, arr, n);
//             maxi = maxValue(arr, maxi);
//         }

//         return maxi;
//     }
// };
