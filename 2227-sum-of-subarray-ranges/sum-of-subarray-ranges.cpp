using ll = long long;

class Solution {
public:
    ll subArrayRanges(vector<int>& nums) {
        ll n = nums.size();
        ll sum = 0; 
        for (ll i = 0; i < n; i++) {
            ll largest  = nums[i];
            ll smallest = nums[i];
            for (ll j = i + 1; j < n; j++) {
                largest = max(largest, (ll)nums[j]);
                smallest = min(smallest, (ll)nums[j]);
                sum += (largest - smallest);
            }
        }
        return sum;
    }
};
/*
TC => O(N^2)
SC => O(N)
*/