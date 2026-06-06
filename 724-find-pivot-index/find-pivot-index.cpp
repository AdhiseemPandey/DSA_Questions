class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int rightSum = 0;
        int leftSum = 0 ; 
        vector<int>left(n);
        vector<int>right(n);
        for(int i = 0 ; i < n ; i++ ){
            leftSum += nums[i];
            left[i] = leftSum;
        }
        for( int i = n-1; i >= 0 ; i-- ){
            rightSum += nums[i];
            right[i] = rightSum;
        }

        for(int i = 0 ; i < n ; i++ ) {
            if( left[i] == right[i]) return i;
        }

        return -1;
    }
};