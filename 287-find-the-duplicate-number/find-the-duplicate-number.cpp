class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int m = nums.size();
        vector<int> temp(m+1, 0);
        temp[0] = 1;
        for( int i = 0 ; i < m ; i++ ){
            temp[nums[i]] += 1;
        }
        for( int i = 0 ; i < m ; i++ ){
            if(temp[i] > 1) return i;
        }

        return -1;

    }
};