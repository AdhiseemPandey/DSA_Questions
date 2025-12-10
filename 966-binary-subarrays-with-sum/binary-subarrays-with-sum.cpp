class Solution {
public:
    int learn(vector<int>& nums, int goal) {
        if( goal < 0 ) return 0 ; 
        int l = 0; 
        int r = 0; 
        long long sum = 0; 
        long long cnt = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while (sum > goal && l < nums.size()) { 
                sum -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return (int)cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return learn(nums, goal) - learn(nums, goal - 1);
    }
};
