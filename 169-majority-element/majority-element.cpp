class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int cnt = 1 ; 
       int res = nums[0];
       for( int i = 1 ; i < nums.size() ; i++){
        if(cnt == 0 ) res = nums[i];

        if(res == nums[i]) cnt++;
        else cnt--;
       }
       return res;
    }
};
// Bayer - Moore Voting Algorithm