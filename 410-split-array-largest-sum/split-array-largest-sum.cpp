int countStudents(vector<int> &arr, int maxPages) {
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (pagesStudent + arr[i] <= maxPages) {
            pagesStudent += arr[i];
        } else {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, nums.size(), k);
    }
};
