class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, h = arr.size() - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            int missed = arr[mid] - (mid + 1);
            if (missed < k)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return l + k;
    }
};
