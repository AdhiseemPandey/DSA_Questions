class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end - start)/2;
        while(start<=end){
        if ( target == nums[mid])
            return mid;
        else if (target > nums[mid]){
            start = mid +1;
        }
        else {
            end = mid-1;
        }
        mid= start + (end-start)/2;
        }
         return mid;
    }
};
