class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            vector<int> digits;
            while (temp > 0) {
                digits.push_back(temp % 10);
                temp /= 10;
            }
            for (int j = digits.size() - 1; j >= 0; j--) {
                ans.push_back(digits[j]);
            }
        }
        return ans;
    }
};
