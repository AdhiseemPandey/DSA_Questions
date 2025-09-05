class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ap = 0; 
        int cnt = 0;        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                cnt++;
                ap = max(ap, cnt);
            } else {
                cnt = 0;
            }
        }
        return ap;
    }
};