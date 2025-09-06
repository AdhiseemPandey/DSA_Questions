class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> ap;
        for (int i = 0 ; i < n ; i++ ){
            int a = nums[i];
            int rem = target - a;
            if(ap.find(rem) != ap.end()){
                return {ap[rem], i};
            }
            ap[a] = i; 
        }
        return {};
    }
};
