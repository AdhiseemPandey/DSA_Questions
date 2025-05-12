class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp; // a particular sum occurred for 1st time at which index
        int sum = 0;
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) sum -= 1;
            else sum += 1;

            if(sum == 0) ans = i + 1; 
            else {
                if(mp.find(sum) != mp.end()) {
                    ans = max(ans, i - mp[sum]);
                }
                else {
                    mp[sum] = i;
                }
            }
        }
        return ans;
    }
};