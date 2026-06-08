class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int smaller = 0, equal = 0, greater = 0;

        // Count smaller, equal, greater
        for (int num : nums) {
            if (num < pivot) smaller++;
            else if (num == pivot) equal++;
            else greater++;
        }

        vector<int> temp(n);
        int idx = 0;

        // smaller
        for (int num : nums) {
            if (num < pivot) temp[idx++] = num;
        }

        //  equal
        for (int num : nums) {
            if (num == pivot) temp[idx++] = num;
        }

        //  greater
        for (int num : nums) {
            if (num > pivot) temp[idx++] = num;
        }

        return temp;
    }
};
