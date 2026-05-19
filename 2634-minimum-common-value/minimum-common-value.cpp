class Solution {
public:
    // TC => small log(large array)
    bool bs(int target, vector<int>& nums){
        int left = 0 ; 
        int right = nums.size() - 1;
        while( left <= right ){
            int mid = left + ( right - left ) / 2; 
            if( nums[mid] > target ){
                right = mid -1 ; 
            }
            else if ( nums[mid] < target ){
                left = mid + 1; 
            }
            else { return true; }
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // choosing the larger array as it is superset 
        if( nums1.size() > nums2.size() ){
            return getCommon(nums2, nums1);
        }

        for( int &it: nums1 ){
            if(bs(it, nums2)){
                return it;
            }
        }
        return -1;
    }
};