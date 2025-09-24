// TC => O(n) * O(max. ele.)
// Replacing LInear search by binary search 
// Striver Code 
// class Solution {
// public:
//     int findmaxelement(vector<int>& piles){
//         int maximum = INT_MIN;
//         int n = piles.size();
//         for (int i=0; i<n; i++){
//             maximum = max(maximum,piles[i]);
//         }
//         return maximum;
//     }
//     long long calculate_hour(vector<int>& piles, int h){
//         long long total_hour = 0;
//         int n = piles.size();
//         for(int i=0; i<n; i++){
//             total_hour += ceil((double)piles[i]/(double)h);
//         }
//         return total_hour;
//     }

//     int minEatingSpeed(vector<int>& piles, int h) {
//         int low = 1; 
//         int high = findmaxelement(piles);
//         int ans;
//         while(low<=high){
//             int mid = (low+high)/2;
//             long long total_hour = calculate_hour(piles,mid);
//             if(total_hour <= h) {
//                 high = mid-1;
//             }
//             else {
//                 low = mid+1;
//             }
//         }
//         return low;
//     }
// };

class Solution {
public:
    bool checker(int mid, vector<int>& piles, int h) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (ceil(piles[i] * 1.0 / mid));
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = INT_MAX;  // Set r to a large value initially
        for (int i = 0; i < piles.size(); i++) r = max(r, piles[i]);
        int ans = r;  // Initialize ans to the maximum value
        while (l <= r) {
            int mid = l + (r - l) / 2;  // Avoid potential overflow
            if (checker(mid, piles, h)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
