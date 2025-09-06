class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> ap;
        for(int i = 0 ; i < nums.size() ; i++){
            ap[nums[i]]++;
        }
        for(auto it : ap){
            if(it.second > (nums.size() / 2 )){
                return it.first;
            }
        }
        return -1;
    }
};