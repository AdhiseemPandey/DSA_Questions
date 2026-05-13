class NumArray {
public:
    vector<int> prefixsum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixsum.resize(n);
        prefixsum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if(left==0)return prefixsum[right];
        return prefixsum[right] - prefixsum[left - 1];
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */