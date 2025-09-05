class Solution {
public:
    int singleNumber(vector<int>& nums) {
     int n = nums.size();
     int ap = 0;
     for ( int i = 0 ; i < n ; i++ ){
        ap ^= nums[i];
     }   
     return ap;
    }
};