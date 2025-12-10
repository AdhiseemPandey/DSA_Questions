class Solution {
public:
    int learn(vector<int>& nums, int k) {
        if( k < 0 ) return 0 ; 
        int l = 0; 
        int r = 0; 
        long long sum = 0; 
        long long cnt = 0;
        while (r < nums.size()) {
            sum += ( nums[r] % 2 );
            while (sum > k && l < nums.size()) { 
                sum -= ( nums[l] % 2 );
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return (int)cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return learn(nums, k) - learn(nums, k - 1);
    }
};