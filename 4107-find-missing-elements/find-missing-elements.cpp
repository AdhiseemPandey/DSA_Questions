class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        vector<bool> present(101, false);
    
        int maxEl = nums[0];
        int minEl = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            maxEl = max(maxEl, nums[i]);
            minEl = min(minEl, nums[i]);
            present[nums[i]] = true;
        }

        vector<int> result;
        for(int curr = minEl; curr <= maxEl; curr++) {
            if(!present[curr]) {
                result.push_back(curr);
            }
        }

        return result;
    }
};