class Solution {
public:
    int sum_dig( vector<int> &nums, int i ){
        int temp = nums[i];
        int res = 0; 
        while( temp > 0 ){
            int dig = temp % 10;
            res = res+dig;
            temp /= 10; 
        }
        return res;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>tempz(n,0);
        for(int i = 0 ; i < n ; i++ ){   
            tempz[i] = sum_dig(nums, i);
        }

        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++ ){
            mini = min(mini, tempz[i]);
        }
        return mini;
    }
};